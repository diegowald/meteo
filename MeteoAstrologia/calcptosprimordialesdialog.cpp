#include "calcptosprimordialesdialog.h"
#include "ui_calcptosprimordialesdialog.h"
#include "sweph.h"
#include <QMessageBox>

calcPtosPrimordialesDialog::calcPtosPrimordialesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calcPtosPrimordialesDialog)
{
    ui->setupUi(this);
    setWindowTitle("Calculos de Ptos. Primordiales");
    ui->planetaComboBox->addItem("sol", 0);
    ui->planetaComboBox->addItem("luna", 1);
    ui->planetaComboBox->addItem("mercurio", 2);
    ui->planetaComboBox->addItem("venus", 3);
    ui->planetaComboBox->addItem("marte", 4);
    ui->planetaComboBox->addItem("jupiter", 5);
    ui->planetaComboBox->addItem("saturno", 6);
    ui->planetaComboBox->addItem("urano", 7);
    ui->planetaComboBox->addItem("neptuno", 8);
    ui->planetaComboBox->addItem("pluton", 9);
    ui->planetaComboBox->addItem("ascendente", 15);
    ui->planetaComboBox->addItem("MC", 13);
    ui->planetaComboBox->addItem("Nodo", 10);
    ui->planetaComboBox->addItem("Lilith", 12);
    ui->planetaComboBox->addItem("Fortuna", 11);

    ui->signoComboBox->addItem("Aries", 1);
    ui->signoComboBox->addItem("Taurus", 2);
    ui->signoComboBox->addItem("Gemini", 3);
    ui->signoComboBox->addItem("Cancer", 4);
    ui->signoComboBox->addItem("Leo", 5);
    ui->signoComboBox->addItem("Virgo", 6);
    ui->signoComboBox->addItem("Libra", 7);
    ui->signoComboBox->addItem("Scorpio", 8);
    ui->signoComboBox->addItem("Sagittarius", 9);
    ui->signoComboBox->addItem("Capricorn", 10);
    ui->signoComboBox->addItem("Aquarius", 11);
    ui->signoComboBox->addItem("Pisces", 12);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(doCalc()));
}

calcPtosPrimordialesDialog::~calcPtosPrimordialesDialog()
{
    delete ui;
}

void calcPtosPrimordialesDialog::doCalc()
{
    //QProgressDialog dialog(tr("Calculando ptos primordiales"), tr("Abortar"), 0, ui->hastaDateEdit->date().toJulianDay() - ui->desdeDateEdit->date().toJulianDay());
    QDateTime fecha, fin;

    sweph swe;// = new sweph();
    swe.swe_set_ephe_path(QDir::currentPath().replace("/", "\\") + "\\sweph\\ephe");

    fecha.setDate(ui->desdeDateEdit->date());
    fecha.setTime(QTime(0, 0, 0));
    fin.setDate(ui->hastaDateEdit->date());
    fin.setTime(QTime(0, 0, 0));

    QSqlQuery query;
    QProgressDialog dialog;
    QTime current;
    int count = 0;
    int total = 0;
    int inserted = 0;

    dialog.setWindowTitle("Calculando Ptos. Primordiales: ");
    dialog.setMaximum(fecha.date().daysTo(fin.date()));
    dialog.setValue(0);
    dialog.setLabelText("Limpiando base de datos...");

    query.exec("BEGIN TRANSACTION");
    query.exec("DELETE FROM puntosprimordiales_sec WHERE 1 = 1");
    dialog.show();
    current.start();
    double result[6];
    double longmax, longmin;
    longmax = ui->signoComboBox->itemData(ui->signoComboBox->currentIndex()).toInt();
    longmax--; longmax *= 30;
    longmax += ui->gradosDeSignoDoubleSpinBox->value();
    longmin = longmax;
    longmax += ui->toleranciaDoubleSpinBox->value();
    longmin -= ui->toleranciaDoubleSpinBox->value();

    while(fecha < fin && !dialog.wasCanceled()){
        QDateTime toUse;

        toUse = fecha.addSecs(+3*3600);
        double julday = swe.swe_julday(toUse.date().day(), toUse.date().month(), toUse.date().year(), toUse.time().hour());
        double* res = swe.swe_calc_ut(julday, ui->planetaComboBox->itemData(ui->planetaComboBox->currentIndex(), Qt::UserRole).toInt());
        for(int i = 0; i < 6; ++i) /*qDebug() << i << " : " << result[i];*/ result[i] = res[i];
        double longitud = result[0];
        int sign = (((int)longitud / 30) % 12) + 1;
        if(longmax >= longitud && longitud >= longmin){
            query.exec(QString("INSERT INTO puntosprimordiales_sec (fecha, degress, planeta, signo) VALUES ('%1', %2, %3, %4)").arg(fecha.toString("yyyy-MM-dd hh:mm:ss")).arg(longitud).arg(ui->planetaComboBox->itemData(ui->planetaComboBox->currentIndex(), Qt::UserRole).toInt()).arg(sign));
            qDebug() << query.lastQuery() << query.lastError();
            inserted++;
        }
        fecha = fecha.addSecs(3600);
        count++;
        dialog.setValue((total++)/24);
        if(current.elapsed() > 1000){
            dialog.setLabelText(QString("%1 %2 calc/seg. ETA: %3 seg.").arg(fecha.toString("yyyy-MM-dd hh:mm:ss")).arg(count).arg((dialog.maximum() - dialog.value()) * 24 / count));
            count = 0;
            current.restart();
        }
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
        longitud = 0;
    }
    query.exec("END TRANSACTION");
    QMessageBox::information(this, tr("Proceso completo"), QString("Calculo completado, se han encontrado %1 fechas que cumplen con los parametros establecidos").arg(inserted), QMessageBox::Ok);
}
