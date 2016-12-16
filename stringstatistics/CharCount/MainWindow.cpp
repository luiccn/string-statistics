/*
 * File:  MainWindow.cpp
 *
 * Group: Isabela Apolinário
 *        Raquel Azeredo
 *        Filipe Barretto
 *        David Britto
 *        Marcelle Campos
 *        Luiz Ciafrino
 *        Pedro Fonini
 *        Eduardo Frimer
 *        Pedro Machado
 *
 */

#include "MainWindow.h"

MainWindow::MainWindow() {

    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    //create vertical and horizontal layouts:
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *horLayout = new QHBoxLayout();
    QHBoxLayout *horLayout2 = new QHBoxLayout();

    createActions();
    createMenus(); 
    createTable();

    //create title:
    title = new QLabel(
        tr("<h2><font color=black> String Character Statistics </font></h2>")
    );
    title->setFixedSize(400,50);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { background-color : white }");

    QLabel *auxLabel = new QLabel(tr("  "));

    //create QLabel to show number of words:
    QLabel *label1 = new QLabel(tr("<h3> Number of different characters: </h3>"));
    label1->setFixedSize(300,30);
    label1->setAlignment(Qt::AlignLeft);
    label1->setAlignment(Qt::AlignVCenter);

    numberOfWords = new QLabel(QString::number(0));
    numberOfWords->setFixedSize(200,30);
    numberOfWords->setAlignment(Qt::AlignLeft);
    numberOfWords->setAlignment(Qt::AlignVCenter);

    //layout:
    horLayout->addWidget(auxLabel);
    horLayout->addWidget(title);
    horLayout->addWidget(auxLabel);
    horLayout->setMargin(5);

    horLayout2->addWidget(label1);
    horLayout2->addWidget(numberOfWords);
    horLayout2->addWidget(auxLabel);
    //horLayout2->setMargin(5);

    mainLayout->addLayout(horLayout);
    mainLayout->addWidget(wordTable);
    mainLayout->addLayout(horLayout2);
    mainLayout->setMargin(10);

    widget->setLayout(mainLayout);

    setWindowTitle(tr("String Statistics"));
    resize(500, 700);
}

MainWindow::~MainWindow(){

}

void MainWindow::newFile(){

    /* newFile opens a file dialog box and gets the name of the selected
     * file */

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                            "", tr("Files (*.*)"));

    name =  fileName.toLocal8Bit().constData();

    handleMap();
}

void MainWindow::fillTable(){

    /* fillTable fills the QTableView with the words in the text, 
     * their frequencies and percentages */

    int i = 0;

    for(mit=wordMap.begin() ; mit!=wordMap.end() ; mit++) {

        QString aux1 = QString::fromStdString(mit->first);
        QStandardItem *item1 = new QStandardItem(aux1);
        QString aux2;
        aux2.setNum(mit->second);
        QStandardItem *item2 = new QStandardItem(aux2);
        QString aux3;
        aux3.setNum(wordMap.getPercentage(mit->first), 'f', 3 ); 
        QStandardItem *item3 = new QStandardItem(aux3);

        wordModel->setItem(i,0, item1);
        wordModel->setItem(i,1,item2);
        wordModel->setItem(i,2,item3);

        i = i+1;
        numOfWords = i;
    }

    //Resizing columns:
    wordTable->setColumnWidth(0, 232);
    wordTable->setColumnWidth(1, 100);
    wordTable->setColumnWidth(2, 100);

    //refreshing numberOfWords:
    numberOfWords->setText(QString::number(numOfWords));

}

void MainWindow::resetStatistics(){

    /* resetStatistics resets wordMap */

    wordMap.clear();
    emptyTable();
}

void MainWindow::emptyTable(){

    /* emptyTable fills the table with empty spaces */

    //Fill table with empty spaces:
    for (int i=0; i<numOfWords; i++) {
        wordModel->setItem(i,0, new QStandardItem(QString(" ")));
        wordModel->setItem(i,1, new QStandardItem( QString(" ")));
        wordModel->setItem(i,2, new QStandardItem( QString(" ")));
    }

    numberOfWords->setText(QString::number(0));
}

void MainWindow::createActions(){

    /* createActions creates the actions */

    newAct = new QAction(tr("&Add"), this);
    //newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Add a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    saveAct = new QAction(tr("&Export"),this);
    //saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Export the created file"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(exportFile()));

    exitAct = new QAction(tr("&Quit"), this);
    //exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close())); 

    resetAct = new QAction(tr("&Reset"),this);
    resetAct->setStatusTip(tr("Reset the statistics"));
    connect(resetAct, SIGNAL(triggered()), this, SLOT(resetStatistics()));

}

void MainWindow::createMenus(){

    /* createMenus creates the menus fileMenu and editMenu */

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(resetAct);

}

void MainWindow::createTable(){

    /* createTable creates the table with 3 columns (words, frequency and 
     * percentage) and 100 rows */

    int nColumnWords = 3;
    int nRowWords = 30;

    //Create wordTable:
    wordTable = new QTableView();
    wordTable->setSelectionBehavior(QAbstractItemView::SelectItems );
    wordTable->setSelectionMode( QAbstractItemView::ExtendedSelection );

    wordModel = new QStandardItemModel(nRowWords, nColumnWords, this );

    //create QTableview Horizontal Header
    wordModel->setHorizontalHeaderItem(0,new QStandardItem(
        QString("Characters: ").arg(0))
    );
    wordModel->setHorizontalHeaderItem(1, new QStandardItem(
        QString("Frequency: " ).arg(1))
    );
    wordModel->setHorizontalHeaderItem(2, new QStandardItem(
        QString("Percentage (%): " ).arg(2))
    );

    //set model
    wordTable->setModel(wordModel);

    //Resizing columns:
    wordTable->setColumnWidth(0, 232);
    wordTable->setColumnWidth(1, 100);
    wordTable->setColumnWidth(2, 100);
}

void MainWindow::exportFile(){

    /* exportFile saves the data in the table to a file .txt */

    wordMap.exportCharMap();

}

void MainWindow::handleMap(){

    /* handleMap handles wordMap. A warning dialog pops if the program
     * couldn't open a file */

    try
    {
        wordMap.addCharFile(name);
    }
    catch (int e)
    {
        if (e==FILE_ERROR_EXCEPTION){
            //Abrir um diálogo de aviso
        }
        else{
            //E aqui vai..?
        }
    }

    fillTable();

}
