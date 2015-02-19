#include "batchastrologicgrabdata.h"
#include "ui_batchastrologicgrabdata.h"

batchAstrologicGrabData::batchAstrologicGrabData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::batchAstrologicGrabData),
    trstring("<TR>"),
    htmlstring("html"),
    basicinfostring("Julian Day (UT)"),
    clipboard(QApplication::clipboard())
{
    ui->setupUi(this);

    starFisher = new QProcess(this);
    starFisherParser = new QProcess(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadFechas()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(next()));

    /* starfisher parser */
    ui->logTableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Stamp" << "Mensaje";
    ui->logTableWidget->setHorizontalHeaderLabels(headers);

    file = 0;

    //connect(ui->actionPegar_Clipboard, SIGNAL(triggered()), this, SLOT(clipboardChanged()));
    //connect(ui->actionGenerar_Archivo, SIGNAL(triggered()), this, SLOT(parseData()));
    connect(clipboard, SIGNAL(dataChanged()), this, SLOT(clipboardChanged()));

    //connect(ui->genPushButton, SIGNAL(clicked()), this, SLOT(parseData()));
    //connect(ui->pastePushButton, SIGNAL(clicked()), this, SLOT(clipboardChanged()));
    log(tr("Programa iniciado"));
}


batchAstrologicGrabData::~batchAstrologicGrabData()
{
    delete ui;
}

void batchAstrologicGrabData::loadFechas(){
    QSqlQuery *query = new QSqlQuery();

    query->exec(QString("SELECT fecha, tipo FROM estadotiempos WHERE fecha >= '%1'").arg(ui->dateEdit->date().toString("yyyy-MM-dd")));

    qDebug() << query->lastQuery() << query->lastError();
    while(query->next()){
        fechas << query->record().field("fecha").value().toDateTime();
        tipos  << query->record().field("tipo").value().toString();
    };
    for(int i = 0; i < fechas.count(); i++){
        query->exec(QString("SELECT * FROM aspectariums WHERE fecha = '%1'").arg(fechas.at(i).toString("yyyy-MM-dd hh:mm:ss")));
        //qDebug() << query->lastQuery() << query->lastError();
        if(query->next()){
            //qDebug() << "Remove: " + fechas.at(i).toString("yyyy-MM-dd hh:mm:ss");
            fechas.removeAt(i);
            i--;
        };
    };
    if(!fechas.isEmpty()) ui->nextButton->setEnabled(true);
    delete query;

}

void batchAstrologicGrabData::next(){
    ui->nextButton->setEnabled(false);
    if(fechas.isEmpty()){
        QMessageBox::warning(this, "Advertencia!", "No hay mas fechas para cargar", QMessageBox::Yes);
    }else{
        // creo el sfs y llamo a todo
        currentDate = fechas.takeFirst();
        currentType = tipos.takeFirst();
        QFile starfisherfile("test.sfs");
        starfisherfile.open(QIODevice::WriteOnly);
        starfisherfile.write(QString("EventData.New(_auto);"
                                     "_eventData.Latitude = \"38S43'00\";"
                                     "_eventData.Longitude = \"62W17'00\";"
                                     "_eventData.Date = \"%1 GMT-3:00\";"
                                     "_eventData.Caption = \"test\";"
                                     "_eventData.Location = \"Bahía Blanca\";"
                                     "_eventData.Zone = \"America/Argentina/Buenos_Aires\";"
                                     "_eventData.Note = \"\";"
                                     "_eventData.Keywords = \"\";"
                                     "Horoscope.New(\"test\", _settings, _eventData);").arg(currentDate.toString("yyyy-MM-dd hh:mm:ss")).toAscii());
        starfisherfile.close();

        QSettings sets("config.ini");
        sets.beginGroup("program");
        qDebug() << starFisher->state();
        qDebug() << starFisherParser->state();
        qDebug() << sets.value("SFfile").toString();
        if(starFisher->state() == QProcess::NotRunning){
            starFisher->start(sets.value("SFfile").toString());
        };
        if(starFisherParser->state() == QProcess::NotRunning){
            starFisherParser->start("starFisherParser.exe");
        };

        connect(starFisherParser, SIGNAL(finished(int)), this, SLOT(saveData()));
        //qDebug() << starFisher->waitForStarted(-1);
        sets.endGroup();
    };
}

void batchAstrologicGrabData::saveData(){
    //read files
    /*TODO retrieve kind of type
            change dates*/
    QSqlQuery *query = new QSqlQuery();
    QFile file;
    file.setFileName("aspectarium.dat");
    //qDebug() << file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        //qDebug() << readed;
        query->exec(QString("INSERT INTO aspectariums (fecha, planeta1, planeta2, conjuncion, totaldif, mindif, segdif, tipo)"
                            "VALUES ('%1', %2, %3, '%4', %5, %6,%7, '%8')")
                    .arg(currentDate.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0,2))
                    .arg(readed.mid(2,2))
                    .arg(readed.mid(4,2))
                    .arg(readed.mid(6))
                    .arg(readed.mid(6,2))
                    .arg(readed.mid(8))
                    .arg(currentType));
        //qDebug() << query->lastQuery() << query->lastError();
        /*
Tabla grande (ASPECTARIUM)
P1P2CCMMSS.SS

P1,P2 Planetas en conjuncion
CC codigo de conjuncion
MM    Minutos Diferencia
*/
    };
    file.close();

    file.setFileName("distributionsigns.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        //qDebug() << readed;
        query->exec(QString("INSERT INTO `signos` (fecha, signo, columna, planeta, tipo) VALUES"
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(currentDate.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(currentType));
        //qDebug() << query->lastQuery() << query->lastError();
    };
    file.close();

    file.setFileName("distributionhouses.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        //qDebug() << readed;
        query->exec(QString("INSERT INTO `casas` (fecha, codigocasa, codigocurrentType, planeta, tipo) VALUES "
                            "('%1', %2, '%3', %4, '%5')")
                    .arg(currentDate.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(currentType));
        //qDebug() << query->lastQuery() << query->lastError();
    };
    file.close();

    file.setFileName("distributionquadrants.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();qDebug() << readed;
        query->exec(QString("INSERT INTO `cuadrantes` (fecha, codigo, esteoeste, planeta, tipo) VALUES "
                            "('%1', '%2', '%3', %4, '%5')")
                    .arg(currentDate.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0, 2))
                    .arg(readed.mid(2, 2))
                    .arg(readed.mid(4, 2))
                    .arg(currentType));
        //qDebug() << query->lastQuery() << query->lastError();
    };
    file.close();

    file.setFileName("positions.dat");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        QString readed = file.readLine();
        //qDebug() << readed;
        query->exec(QString("INSERT INTO posiciones (fecha, planeta, signo, Glon, Mlon, Slon, Glat, Mlat, Slat, Gvel, Mvel, Svel, distancia, casa, tipo) VALUES "
                            "('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12, %13, %14, '%15')")
                    .arg(currentDate.toString("yyyy-MM-dd hh:mm:ss"))
                    .arg(readed.mid(0,2))
                    .arg(readed.mid(2,2))
                    .arg(readed.mid(4,2))
                    .arg(readed.mid(6,2))
                    .arg(readed.mid(8,2))
                    .arg(readed.mid(10,2))
                    .arg(readed.mid(12,2))
                    .arg(readed.mid(14,2))
                    .arg(readed.mid(16,2))
                    .arg(readed.mid(18,2))
                    .arg(readed.mid(20,2))
                    .arg(readed.mid(22,7))
                    .arg(readed.mid(29,2))
                    .arg(currentType));
        //qDebug() << query->lastQuery() << query->lastError();

    };
    file.close();

    delete query;
    ui->nextButton->setEnabled(true);
}

/*
* StarFisher Parser
*/

void batchAstrologicGrabData::clipboardChanged(){
    //ui->textEdit->clear();
;
    QString clipboarddata = clipboard->text(htmlstring, QClipboard::Clipboard);
    //if(!clipboarddata.contains("<!--StartFragmnet-->")) return;
    if(clipboarddata.contains(basicinfostring)){
        ui->basicinfoTextEdit->setText(clipboarddata);
    }else{
        ui->aspectariumTextEdit->setText(clipboarddata);
    };
    log(tr("Datos del clipboard capturados"));
}

void batchAstrologicGrabData::parseData(){
    parseAspectarium(ui->aspectariumTextEdit->toPlainText());
    parseBasicInfo(ui->basicinfoTextEdit->toPlainText());
    //QMessageBox::information(this, tr("StarFisher Parser"), tr("Proceso completado! cierre este programa para continuar."), QMessageBox::Close | QMessageBox::Ok, QMessageBox::Close);
    if(QMessageBox::information(this, tr("StarFisher Parser"), tr("Proceso completado! cierre este programa para continuar."), QMessageBox::Close | QMessageBox::Ok) == QMessageBox::Close){
        close();
    };
}

void batchAstrologicGrabData::parseAspectarium(QString basedata){
    //qDebug() << basedata;
    int tr = basedata.indexOf(trstring);
    int trclose;
    QString trclosestring = "</TR>";
    QString tdstring = "<TD";
    QString tdclosestring = "</TD>";

    QString titlestring = "title=\"";

    file = new QFile("aspectarium.dat");
    if(!file->open(QIODevice::WriteOnly)){
        QMessageBox::warning(this, QString("Error"), QString("No se pudo abrir el archivo de aspectos"), QMessageBox::Yes);
        delete file;
        file = 0;
        return;
    };

    int cuerpo = 1;
    //parseo por lineas
    while(tr != -1){
        trclose = basedata.indexOf(trclosestring, tr);
        QString linedata = basedata.mid(tr, trclose - tr);

        int td = linedata.indexOf(tdstring);
        int tdclose;
        bool first = true;
        int cuerpo2 = 0;
        while((td != -1) && (cuerpo != cuerpo2)){
            int nexttd = linedata.indexOf(tdstring, td + 1);
            tdclose = linedata.indexOf(tdclosestring, td);
            if(nexttd < tdclose) tdclose = nexttd;
            QString blockdata = linedata.mid(td, tdclose - td);
            //qDebug() << blockdata;

            if(!first){
                if(blockdata.contains(titlestring)){
                    //tiene un aspecto
                    qDebug() << "cuerpo1: " << cuerpo << " cuerpo2: " << cuerpo2 << " data " << blockdata;
                    //ToDo: sacar el aspecto
                    int aspecto = 0;
                    QString aspectostring;

                    if(blockdata.contains("Conjunction")){
                        aspecto = 1;
                        aspectostring = "Conjunction";
                    };
                    if(blockdata.contains("Opposition")){
                        aspecto = 2;
                        aspectostring = "Opposition";
                    };
                    if(blockdata.contains("Trine")){
                        aspecto = 3;
                        aspectostring = "Trine";
                    };
                    if(blockdata.contains("Square")){
                        aspecto = 4;
                        aspectostring = "Square";
                    };
                    if(blockdata.contains("Quintile")){
                        aspecto = 5;
                        aspectostring = "Quintile";
                    };
                    if(blockdata.contains("Biquintile")){
                        aspecto = 6;
                        aspectostring = "Biquintile";
                    };
                    if(blockdata.contains("Sextile")){
                        aspecto = 7;
                        aspectostring = "Sextile";
                    };
                    if(blockdata.contains("Septile")){
                        aspecto = 8;
                        aspectostring = "Septile";
                    };
                    if(blockdata.contains("Biseptile")){
                        aspecto = 9;
                        aspectostring = "Biseptile";
                    };
                    if(blockdata.contains("Triseptile")){
                        aspecto = 10;
                        aspectostring = "Triseptile";
                    };
                    if(blockdata.contains("Octile")){
                        aspecto = 11;
                        aspectostring = "Octile";
                    };
                    if(blockdata.contains("Trioctile")){
                        aspecto = 12;
                        aspectostring = "Trioctile";
                    };
                    if(blockdata.contains("Novile")){
                        aspecto = 13;
                        aspectostring = "Novile";
                    };
                    if(blockdata.contains("Decile")){
                        aspecto = 14;
                        aspectostring = "Decile";
                    };
                    if(blockdata.contains("Tridecile")){
                        aspecto = 15;
                        aspectostring = "Tridecile";
                    };
                    if(blockdata.contains("Semisextile")){
                        aspecto = 16;
                        aspectostring = "Semisextile";
                    };
                    if(blockdata.contains("Quincunx")){
                        aspecto = 17;
                        aspectostring = "Quincunx";
                    };
                    if(blockdata.contains("Undecile")){
                        aspecto = 18;
                        aspectostring = "Undecile";
                    };

                    int begin = blockdata.indexOf(aspectostring) + QString(aspectostring).length() + 1;
                    int end = blockdata.indexOf(">", begin) - 1;
                    //qDebug() << "begin: " << begin << " end: " << end;
                    qDebug() << aspectostring << " : " <<  blockdata.mid(begin, end - begin);
                    QString angulo = blockdata.mid(begin, end - begin);
                    QString min, seg, mil;
                    int beginAng = angulo.indexOf(':');
                    min = angulo.left(beginAng).rightJustified(2, '0');
                    seg = angulo.mid(beginAng + 1, 2);
                    mil = angulo.mid(beginAng + 4, 2);
                    //qDebug() << min << seg << "." << mil;
                    QString f;
                    f = QString("%1").arg(cuerpo).rightJustified(2, '0');
                    f += QString("%1").arg(cuerpo2).rightJustified(2, '0');
                    f += QString("%1").arg(aspecto).rightJustified(2, '0');
                    f += min + seg + "." + mil;
                    qDebug() << f;
                    file->write(f.toAscii());
                    file->write("\r\n");
                };
            }else{
                first = false;
            };
            cuerpo2++;
            td = nexttd;
        };
        tr = basedata.indexOf(trstring, tr + 1);
        cuerpo++;
    };

    file->close();
    delete file;
    file = 0;
}

void batchAstrologicGrabData::parseBasicInfo(QString basedata){
    file = new QFile("distributionsigns.dat");
    file->open(QIODevice::WriteOnly);

    //qDebug() << basedata;
    QString bodybeginstring = "<TBODY>";
    QString bodyendstring = "</TBODY>";
    QString trbegin = "<TR>";
    QString trend = "</TR>";
    QString tdbegin = "<TD>";
    QString tdend = "</TD>";
    QString basetitle = "Distribution in Signs";
    int rowbegin;
    int rowend;
    int blockbegin;
    int blockend;
    QString tablestring;


    int basetitleindex = basedata.indexOf(basetitle);
    int tbodybegin = basedata.indexOf(bodybeginstring, basetitleindex);
    int tbodyend = basedata.indexOf(bodyendstring, basetitleindex);
    tablestring = basedata.mid(tbodybegin, tbodyend - tbodybegin);
    //qDebug() << tablestring;
    rowbegin = tablestring.indexOf(trbegin);
    int indexy = 0;
    while(rowbegin != -1){
        rowend = tablestring.indexOf(trend, rowbegin);
        QString rowstring = tablestring.mid(rowbegin + trbegin.length(), rowend - rowbegin);
        blockbegin = rowstring.indexOf(tdbegin);
        int indexx = 0;
        while(blockbegin != -1){
            blockend = rowstring.indexOf(tdend, blockbegin);
            QString blockdata = rowstring.mid(blockbegin, blockend - blockbegin);
            //qDebug() << "y: " << indexy << " x: " << indexx << " data: " << blockdata;
            //ToDo: guardar a un archivo
            saveSignLine(indexx, indexy, blockdata, file);

            blockbegin = rowstring.indexOf(tdbegin, blockbegin + 3);
            indexx++;
        };
        //qDebug() << rowstring;
        rowbegin = tablestring.indexOf(trbegin, rowbegin + 3);
        indexy++;
    };

    file->close();
    file->setFileName("distributionhouses.dat");
    file->open(QIODevice::WriteOnly);

    basetitle = "Distribution in Houses";

    basetitleindex = basedata.indexOf(basetitle);
    tbodybegin = basedata.indexOf(bodybeginstring, basetitleindex);
    tbodyend = basedata.indexOf(bodyendstring, basetitleindex);
    tablestring = basedata.mid(tbodybegin, tbodyend - tbodybegin);
    //qDebug() << tablestring;
    rowbegin = tablestring.indexOf(trbegin);
    indexy = 0;
    while(rowbegin != -1){
        rowend = tablestring.indexOf(trend, rowbegin);
        QString rowstring = tablestring.mid(rowbegin + trbegin.length(), rowend - rowbegin);
        blockbegin = rowstring.indexOf(tdbegin);
        int indexx = 0;
        while(blockbegin != -1){
            blockend = rowstring.indexOf(tdend, blockbegin);
            QString blockdata = rowstring.mid(blockbegin, blockend - blockbegin);
            //qDebug() << "y: " << indexy << " x: " << indexx << " data: " << blockdata;
            //ToDo: guardar a un archivo
            saveHouseLine(indexx, indexy, blockdata, file);

            blockbegin = rowstring.indexOf(tdbegin, blockbegin + 3);
            indexx++;
        };
        //qDebug() << rowstring;
        rowbegin = tablestring.indexOf(trbegin, rowbegin + 3);
        indexy++;
    };

    file->close();
    file->setFileName("distributionquadrants.dat");
    file->open(QIODevice::WriteOnly);

    basetitle = "Distribution in Quadrants";

    basetitleindex = basedata.indexOf(basetitle);
    tbodybegin = basedata.indexOf(bodybeginstring, basetitleindex);
    tbodyend = basedata.indexOf(bodyendstring, basetitleindex);
    tablestring = basedata.mid(tbodybegin, tbodyend - tbodybegin);
    //qDebug() << tablestring;
    rowbegin = tablestring.indexOf(trbegin);
    indexy = 0;
    while(rowbegin != -1){
        rowend = tablestring.indexOf(trend, rowbegin);
        QString rowstring = tablestring.mid(rowbegin + trbegin.length(), rowend - rowbegin);
        blockbegin = rowstring.indexOf(tdbegin);
        int indexx = 0;
        while(blockbegin != -1){
            blockend = rowstring.indexOf(tdend, blockbegin);
            QString blockdata = rowstring.mid(blockbegin, blockend - blockbegin);
            //qDebug() << "y: " << indexy << " x: " << indexx << " data: " << blockdata;
            //ToDo: guardar a un archivo
            saveQuadrantLine(indexx, indexy, blockdata, file);

            blockbegin = rowstring.indexOf(tdbegin, blockbegin + 3);
            indexx++;
        };
        //qDebug() << rowstring;
        rowbegin = tablestring.indexOf(trbegin, rowbegin + 3);
        indexy++;
    };

    file->close();
    file->setFileName("positions.dat");
    file->open(QIODevice::WriteOnly);

    basetitle = "Positions";

    basetitleindex = basedata.indexOf(basetitle);
    tbodybegin = basedata.indexOf(bodybeginstring, basetitleindex);
    tbodyend = basedata.indexOf(bodyendstring, basetitleindex);
    tablestring = basedata.mid(tbodybegin, tbodyend - tbodybegin);
    //qDebug() << tablestring;
    rowbegin = tablestring.indexOf(trbegin);
    tdbegin = "<TD";
    indexy = 0;
    while(rowbegin != -1){
        rowend = tablestring.indexOf(trend, rowbegin);
        QString rowstring = tablestring.mid(rowbegin + trbegin.length(), rowend - rowbegin);
        blockbegin = rowstring.indexOf(tdbegin);
        int indexx = 0;
        while(blockbegin != -1){
            blockend = rowstring.indexOf(tdend, blockbegin);
            QString blockdata = rowstring.mid(blockbegin, blockend - blockbegin);
            qDebug() << "y: " << indexy << " x: " << indexx << " data: " << blockdata;
            //ToDo: guardar a un archivo
            savePositionLine(indexx, indexy, blockdata, file);

            blockbegin = rowstring.indexOf(tdbegin, blockbegin + 3);
            indexx++;
        };
        //qDebug() << rowstring;
        rowbegin = tablestring.indexOf(trbegin, rowbegin + 3);
        indexy++;
    };

    //basetitle = "Positions";
    file->close();
    file->setFileName("houses.dat");
    file->open(QIODevice::WriteOnly);

    basetitleindex = tbodyend;//basedata.indexOf(basetitle);
    tbodybegin = basedata.indexOf(bodybeginstring, basetitleindex);
    tbodyend = basedata.indexOf(bodyendstring, basetitleindex);
    tablestring = basedata.mid(tbodybegin, tbodyend - tbodybegin);
    //qDebug() << tablestring;
    rowbegin = tablestring.indexOf(trbegin);
    tdbegin = "<TD";
    indexy = 0;
    while(rowbegin != -1){
        rowend = tablestring.indexOf(trend, rowbegin);
        QString rowstring = tablestring.mid(rowbegin + trbegin.length(), rowend - rowbegin);
        blockbegin = rowstring.indexOf(tdbegin);
        int indexx = 0;
        while(blockbegin != -1){
            blockend = rowstring.indexOf(tdend, blockbegin);
            QString blockdata = rowstring.mid(blockbegin, blockend - blockbegin);
            qDebug() << "y: " << indexy << " x: " << indexx << " data: " << blockdata;
            //ToDo: guardar a un archivo
            savePosition2Line(indexx, indexy, blockdata, file);

            blockbegin = rowstring.indexOf(tdbegin, blockbegin + 3);
            indexx++;
        };
        //qDebug() << rowstring;
        rowbegin = tablestring.indexOf(trbegin, rowbegin + 3);
        indexy++;
    };

    file->close();
    delete file;
    file = 0;
}

void batchAstrologicGrabData::log(QString msg){
    int row = ui->logTableWidget->rowCount() + 1;
    ui->logTableWidget->setRowCount(row);
    ui->logTableWidget->setItem(row - 1, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString()));
    ui->logTableWidget->setItem(row - 1, 1, new QTableWidgetItem(msg));
}

QList<int> batchAstrologicGrabData::getPlanetaNumber(QString data){
    QList<int> toReturn;
    if(data.contains(">a<")) toReturn << 1;
    if(data.contains(">b<")) toReturn << 2;
    if(data.contains(">c<")) toReturn << 3;
    if(data.contains(">d<")) toReturn << 4;
    if(data.contains(">e<")) toReturn << 5;
    if(data.contains(">f<")) toReturn << 6;
    if(data.contains(">g<")) toReturn << 7;
    if(data.contains(">h<")) toReturn << 8;
    if(data.contains(">i<")) toReturn << 9;
    if(data.contains(">j<")) toReturn << 10;
    if(data.contains(">s<")) toReturn << 14;
    if(data.contains(">p<")) toReturn << 15;

    return toReturn;
}


int batchAstrologicGrabData::getHoroscopeNumber(QString data){
    int toReturn = 0;
    if(data.contains("title=Aries")) toReturn = 1;
    if(data.contains("title=Taurus")) toReturn = 2;
    if(data.contains("title=Gemini")) toReturn = 3;
    if(data.contains("title=Cancer")) toReturn = 4;
    if(data.contains("title=Leo")) toReturn = 5;
    if(data.contains("title=Virgo")) toReturn = 6;
    if(data.contains("title=Libra")) toReturn = 7;
    if(data.contains("title=Scorpio")) toReturn = 8;
    if(data.contains("title=Sagittarius")) toReturn = 9;
    if(data.contains("title=Capricorn")) toReturn = 10;
    if(data.contains("title=Aquarius")) toReturn = 11;
    if(data.contains("title=Pisces")) toReturn = 12;
    return toReturn;
}


void batchAstrologicGrabData::saveSignLine(int x, int y, QString data, QFile *file){
    if((x == 0) || (y == 0)) return;
    QList<int> planets = getPlanetaNumber(data);
    for(int i = 0; i < planets.count(); ++i){
        QString elem, asp;
        switch(x){
        case 1:
            asp = "ca";
            break;
        case 2:
            asp = "fi";
            break;
        case 3:
            asp = "mu";
            break;
        };

        switch(y){
        case 1:
            elem = "fu";
            break;
        case 2:
            elem = "ti";
            break;
        case 3:
            elem = "ai";
            break;
        case 4:
            elem = "ag";
            break;
        };

        //qDebug() << elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0');
        file->write((elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0')).toAscii());
        file->write("\r\n");

    };

};

void batchAstrologicGrabData::saveHouseLine(int x, int y, QString data, QFile *file){
    if((x == 0) || (y == 0)) return;
    QList<int> planets = getPlanetaNumber(data);
    for(int i = 0; i < planets.count(); ++i){
        QString elem, asp;
        switch(x){
        case 1:
            asp = "an";
            break;
        case 2:
            asp = "su";
            break;
        case 3:
            asp = "ca";
            break;
        };

        switch(y){
        case 1:
            elem = "01";
            break;
        case 2:
            elem = "10";
            break;
        case 3:
            elem = "07";
            break;
        case 4:
            elem = "04";
            break;
        };

        //qDebug() << elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0');
        file->write((elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0')).toAscii());
        file->write("\r\n");
    };
}

void batchAstrologicGrabData::saveQuadrantLine(int x, int y, QString data, QFile *file){
    if((x == 0) || (y == 0)) return;
    QList<int> planets = getPlanetaNumber(data);
    for(int i = 0; i < planets.count(); ++i){
        QString elem, asp;
        switch(x){
        case 1:
            asp = "es";
            break;
        case 2:
            asp = "we";
            break;
        };

        switch(y){
        case 1:
            elem = "ab";
            break;
        case 2:
            elem = "be";
            break;
        };

        //qDebug() << elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0');
        file->write((elem+asp+QString("%1").arg(planets.at(i)).rightJustified(2, '0')).toAscii());
        file->write("\r\n");
    };
}

void batchAstrologicGrabData::savePositionLine(int x, int y, QString data, QFile *file){
    static QString f;
    int begin;
    int end;
    int begin2;
    int horoscopenumber;
    QString number;

    if(y == 0) return;
    qDebug () << f;

    switch(x){
        case 0:
            f = QString("%1").arg(getPlanetaNumber(data).at(0)).rightJustified(2, '0');
            break;
        case 1:
            qDebug() << "data : " << data;
            begin = data.indexOf(">") + 1;
            end = data.indexOf("<", begin);
            begin2 = data.indexOf(">", end + 5) + 1;
            begin2 = data.indexOf(">", begin2) + 1;
            number = data.mid(begin, end - begin).rightJustified(2 ,'0');
            horoscopenumber = getHoroscopeNumber(data);
            //qDebug() << "begin: " << begin << " end: " << end << " begin2: " << begin2;
            //qDebug() << "number: " << number;
            f += QString("%1").arg(horoscopenumber).rightJustified(2, '0') + number + data.mid(begin2, 2) + data.mid(begin2 + 3, 2);
            //qDebug() << f;
            break;
        case 2:
        case 3:
            begin = data.indexOf(">") + 1;
            end = data.indexOf("°", begin) - 1;
            f += data.mid(begin, (end + 1) - begin).rightJustified(2, '0') + data.mid(end + 2, 2) + data.mid(end + 5, 2);
            //break;

            break;
        case 4:
            begin = data.indexOf(">") + 1;
            f += data.mid(begin).rightJustified(7, '0');
            break;
        case 5:
            begin = data.indexOf(">") + 1;
            f += data.mid(begin).rightJustified(2, '0');
            f = f + "\r\n";
            //qDebug() << f;
            file->write(f.toAscii());
            //guardar en archivo
            f = "";
            break;
    };
}

void batchAstrologicGrabData::savePosition2Line(int x, int y, QString data, QFile *file){
    static QString f;
    int begin;
    int end;
    int begin2;
    int horoscopenumber;
    QString number;

    if((x % 2) == 0){
        begin = data.indexOf(">") + 1;
        f = data.mid(begin);
        f.chop(1);
        f = f.rightJustified(3, '0');
        qDebug() << "pos2: " << f;
    }else{
        begin = data.indexOf(">") + 1;
        end = data.indexOf("<", begin);
        begin2 = data.indexOf(">", end + 5) + 1;
        begin2 = data.indexOf(">", begin2) + 1;
        number = data.mid(begin, end - begin);
        horoscopenumber = getHoroscopeNumber(data);
        qDebug() << "begin: " << begin << " end: " << end << " begin2: " << begin2;
        qDebug() << "number: " << number;
        f += QString("%1").arg(horoscopenumber).rightJustified(2, '0') + number.rightJustified(2, '0') + data.mid(begin2, 2) + data.mid(begin2 + 3, 2);
        qDebug() << "pos2: " << f;
        file->write(f.toAscii());
        file->write("\r\n");
        f = "";
    };
}

