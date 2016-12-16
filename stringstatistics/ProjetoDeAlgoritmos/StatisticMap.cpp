/*
 * File:  StatisticMap.cpp
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

#include "iso2ascii.h"
#include "StatisticMap.h"

using namespace std;

/*
 *
 * This class is a container in which each element is composed by a word and
 * the number of its occurences in some set of plain text files. For each call
 * to StatisticMap::addFile, the words' statistics are updated from that file.
 *
 * Usage:
 *
 * StatisticMap myMap;
 * myMap.addFile("file1.txt")
 * myMap.addFile("file2.txt")
 *
 * The caller of addFile must look out for the exception FILE_ERROR_EXCEPTION
 *
 */

void StatisticMap::addFile(string filename)
{

    /* pos records the position of the beginning of the curent word */
    int pos = 0;

    /* word temporarily stores single words of the file */
    string word = "";

    ifstream myFile;

    myFile.open(filename.c_str());

    if (!myFile.is_open())
        throw FILE_ERROR_EXCEPTION;

    while (myFile.good())
    {
        string line;
        getline (myFile,line);

        // looping through the input
        for (unsigned i=0; i<line.length(); i++)
        {
            // turning every position of line into ASCII and lowercase
            line[i] = tolower(iso2ascii( (unsigned char)(line[i]) ));

            // removing positions that aren't alphanumeric
            if (!isalnum(line[i]))
            {
                line.erase(i,1);
                for (unsigned j = pos; j<i; j++)
                {
                    word+=line[j];
                }
                if (word != "")
                {
                    // adding string "word" to the Map, if "word" is already
                    // present, map[word] value is incremented
                    (*this)[word] += 1;
                }
                pos = i;
                i--;
                word="";
            }
        }
    }
    myFile.close();
}

void StatisticMap::addCharFile(string filename)
{

    int pos = 0;
    string aux = "";
    string word = "";
    string line;

    ifstream myFile;

    myFile.open(filename.c_str());

    if (!myFile.is_open())
        throw FILE_ERROR_EXCEPTION;

    while (myFile.good())
    {
        getline (myFile,line);
        // +'\n' ensures that the last word from a line won't concatenate
        // with the first word of the next line:
        if (line !="")
            aux += line+'\n';
    }
    myFile.close();

        // looping throughout the input
    for (unsigned i=0; i<aux.length(); i++)
    {
        //turning every position of aux into ASCII and lowercase
        aux[i] = tolower(iso2ascii( (unsigned char)(aux[i]) ));

        //removing positions that aren't alphanumeric
        if (!isalnum(aux[i]))
        {
            aux.erase(i,1);
        }

        if (isalnum(aux[i]))
        {
            word+=tolower(aux[i]);
            (*this)[word]+= 1;
            word="";
        }
    }
}

void StatisticMap::exportMap(){

    map<string,int>::iterator mit;

    ofstream DumpFile;
    DumpFile.open("dump.txt");

    DumpFile << "============== Dumping Word Map! ==============" << "\n";
    //cout << "============== Dumping Word Map! ==============" << endl;

    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        //cout << mit->first << " : " << mit->second << " : " <<
        //        this->getPercentage(mit->first) << "%" << endl;
        DumpFile << mit->first << " : " << mit->second << " : " <<
                this->getPercentage(mit->first) << "%" << "\n";
    }

    //cout << endl << "Number of different words: " << this->size() << endl;
    DumpFile << "\n" << "Number of different words: " << this->size() << "\n";

}

float StatisticMap::getPercentage(string key){
    return (float) (*this)[key] * 100.0 / getTotalCount();
}

int StatisticMap::getTotalCount(){

    map<string,int>::iterator mit;
    int tcount=0;
    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        tcount+= mit->second ;
    }
    return tcount;
}
