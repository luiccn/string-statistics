/*
 * File:  MainWindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "StatisticMap.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QString>
#include <QTableView>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QGroupBox>
#include <QRadioButton>

class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();
     ~MainWindow();

 private slots:
     void newFile();
     void exportFile();
     void resetStatistics();
     void handleMap();
     void emptyFill();

 private:
     void createMenus();
     void createActions();
     QGroupBox *createExclusiveGroup();
     void createTable();
     void fillTable();
     void emptyTable();

     StatisticMap wordMap;
     StatisticMap letterMap;

     QTableView *wordTable;
     QStandardItemModel *wordModel;
     QLabel *title;
     QLabel *numberOfWords;
     QMenu *fileMenu;
     QMenu *editMenu;
     QAction *newAct;
     QAction *saveAct;
     QAction *exitAct;
     QAction *resetAct;
     QGroupBox *groupBox;
     QRadioButton *radio1;
     QRadioButton *radio2;
     QString fileName;

     std::string name;
     map<string,int>::iterator mit;
     int numOfWords;
     int numOfLetters;

};

#endif  /* MAINWINDOW_H */
