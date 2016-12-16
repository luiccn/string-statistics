/*
 * File:  stringstat.cpp
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

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <locale>
#include "stringstat.h"
#include "iso2ascii.h"


using namespace std;

/*
 * MapPrint()
 * Given a map and its iterator, the function prints to the screen the
 *   contents of the map. In this case, the contents are the number of
 *   occurrences of each word in the map.
 *
 */
void MapPrint(map<string,int> * pMyMap, int * pTotalWordCount)
{
	map<string,int>::iterator mit;

    cout << "============== Dumping Map! ==============" << endl;
    for(mit=pMyMap->begin() ; mit!=pMyMap->end() ; mit++)
        cout << mit->first << ": " << mit->second << " : " <<
                (mit->second)*100.0/(*pTotalWordCount) << "%" << endl;
}

/*
 * StringStatistic()
 * We are given a map; empty or perhaps already filled by a previuos call to
 *   this function. The keys are words present in some text, and the contents
 *   are the number of occurrences of each word. We are also given the
 *   filename of a text file that contains some new text. We modify the map so
 *   that it now includes the data from the current file.
 *
 */
void StringStatistic(const char * filename, map<string,int> * pWordMap, int * pTotalWordCount)
{

    vector<string> myWords;
    vector<string>::iterator vit;

    int pos = 0;
    string aux = "" ;
    string word = "";
    string line;

    ifstream myFile;

    myFile.open(filename);

    if (!myFile.is_open())
        throw FILE_ERROR_EXCEPTION;

    while (myFile.good())
    {
        getline (myFile,line);
        // +'\n' ensures that the last word from a line won't concatenate
        // with the first word of the next line:
        aux += line+'\n';
    }
    myFile.close();

    for (unsigned i=0; i<aux.length(); i++)
    {
        aux[i] = tolower(iso2ascii( (unsigned char)(aux[i]) ));
        if (!isalnum(aux[i]))
        {
            aux.erase(i,1);

            for (unsigned j = pos; j<i; j++)
            {
                word+=aux[j];
            }
            pos = i;
            if (word != "")
            {
                myWords.push_back(word);
            }
            word="";
            i--;
        }
    }

    for (vit=myWords.begin(); vit<myWords.end();vit++)
    {
        (*pWordMap)[*vit] += 1;
    }
    int wordCount = myWords.size();
    *pTotalWordCount += wordCount;

}
