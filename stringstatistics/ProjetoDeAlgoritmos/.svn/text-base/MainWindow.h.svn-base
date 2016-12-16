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

class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();
     ~MainWindow();

 private slots:
     void newFile();
     void exportFile();
     void fillTable();
     void resetStatistics();

 private:
     void createMenus();
     void createActions();
     void createTable();
     void emptyTable();
     void handleMap();

     StatisticMap wordMap;

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
     QString fileName;

     std::string name;
     map<string,int>::iterator mit;
     int numOfWords;

};

#endif  /* MAINWINDOW_H */
