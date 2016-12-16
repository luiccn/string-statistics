/*
 * File:  StatisticMap.h
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

#ifndef STATISTICMAP_H_
#define STATISTICMAP_H_

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <locale>

using namespace std;

#define FILE_ERROR_EXCEPTION    1

class StatisticMap : public map<string,int>{
public:
    float getPercentage(string);
    void exportMap();
    void exportCharMap();
    //void Charprint();
    int getTotalCount();
    void addFile(string);
    void addCharFile(string);
};

#endif /* STATISTICMAP_H_ */

