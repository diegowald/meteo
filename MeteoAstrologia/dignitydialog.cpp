#include "dignitydialog.h"
#include "ui_dignitydialog.h"

dignityDialog::dignityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dignityDialog)
{
    ui->setupUi(this);

    ui->planetaComboBox->addItem("Sol", 0);
    ui->planetaComboBox->addItem("Luna", 1);
    ui->planetaComboBox->addItem("Mercurio", 2);
    ui->planetaComboBox->addItem("Vernus", 3);
    ui->planetaComboBox->addItem("Marte", 4);
    ui->planetaComboBox->addItem("Jupiter", 5);
    ui->planetaComboBox->addItem("Saturno", 6);

    ui->dignidadComboBox->addItem("Rige", metAstro::Rules);
    ui->dignidadComboBox->addItem("Exaltado", metAstro::Exaltation);
    ui->dignidadComboBox->addItem("Detrimado", metAstro::Detriment);
    ui->dignidadComboBox->addItem("Caida", metAstro::Fall);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

dignityDialog::~dignityDialog()
{
    delete ui;
}

void dignityDialog::accepted(){
    metAstro::dignityParam param;
    param.planet = ui->planetaComboBox->itemData(ui->planetaComboBox->currentIndex()).toInt();
    param.dignity = (metAstro::dignityType)ui->dignidadComboBox->itemData(ui->dignidadComboBox->currentIndex()).toInt();
    emit addDignity(param);
    accept();
}
