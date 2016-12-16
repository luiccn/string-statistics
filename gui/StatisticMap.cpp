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
 * The StatisticMap class is a container in which each element is composed by
 * a word and the number of its occurences in some set of plain text files.
 * For each call to StatisticMap::addFile, the words' statistics are updated
 * from that file.
 *
 * Usage:
 *
 * StatisticMap wordMap, charMap;
 * wordMap.addFile("word-file1.txt");
 * wordMap.addFile("word-file2.txt");
 * charMap.addCharFile("char-file.txt");
 *
 * The caller of either of these functions must look out for
 * the exception FILE_ERROR_EXCEPTION
 *
 */

void StatisticMap::addFile(string filename)
{
    ifstream myFile;
    myFile.open(filename.c_str());

    if (!myFile.is_open())
        throw FILE_ERROR_EXCEPTION;

    // loops through each line of the file
    while (myFile.good())
    {
        // `pos' records the position of the beginning of the curent word
        int pos = 0;

        string line;
        getline (myFile, line);

        // looping through the input
        for (unsigned i=0; i<line.length(); i++)
        {
            // turning every position of line into ASCII and lowercase
            line[i] = tolower(iso2ascii( (unsigned char)(line[i]) ));

            // removing positions that aren't alphanumeric
            if (!isalnum(line[i]))
            {
                // `word' temporarily stores a word of the file
                string word = line.substr(pos, i - pos);

                if (word != "")
                {
                    // adding string "word" to the Map; if "word" is already
                    // present, map[word] value is incremented
                    (*this)[word] += 1;
                }

                pos = i+1;
            }

            // for the case there is no new line at the end of the file, and
            // the last character is valid (is alphanumeric)
            if ( !myFile.good() and
                 isalnum(line[i]) and
                 (i == line.length()-1) )
            {
                (*this)[ line.substr(pos,i+1-pos) ] += 1;
            }

        }

    }

    myFile.close();
}

void StatisticMap::addCharFile(string filename)
{
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

            if (isalnum(line[i]))
            {
                string ch;
                ch += line[i];
                (*this)[ch]+= 1;
            }
        }
    }

    myFile.close();
}

void StatisticMap::exportMap(){

    map<string,int>::iterator mit;

    ofstream DumpFile;
    DumpFile.open("dump_Word.txt");

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

void StatisticMap::exportCharMap(){

    map<string,int>::iterator mit;

    ofstream DumpFile;
    DumpFile.open("dump_Char.txt");

    DumpFile << "============== Dumping Character Map! ==============" << "\n";
    //cout << "============== Dumping Word Map! ==============" << endl;

    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        //cout << mit->first << " : " << mit->second << " : " <<
        //        this->getPercentage(mit->first) << "%" << endl;
        DumpFile << mit->first << " : " << mit->second << " : " <<
        this->getPercentage(mit->first) << "%" << "\n";
    }

    //cout << endl << "Number of different words: " << this->size() << endl;
    DumpFile << "\n" << "Number of different characters: " << this->size() << "\n";

}

float StatisticMap::getPercentage(string key){
    return (float) (*this)[key] * 100.0 / getTotalCount();
}

int StatisticMap::getTotalCount(){
    map<string,int>::iterator mit;
    int tcount = 0;
    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        tcount += mit->second ;
    }
    return tcount;
}
