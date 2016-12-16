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

#include "StatisticMap.h"
#include "iso2ascii.h"

using namespace std;

/*
 *
 * This class is a container in which each element is a composed by a word and
 * the number of occurences of that word in some set of files. For each call
 * to StatisticMap::addFile , we include that file in our set of words.
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

void StatisticMap::addFile(vector<string> files){
    vector<string>::iterator i;
    for (i = files.begin();i<files.end();i++)
        this->addFile(*i);
}

void StatisticMap::addCharFile(vector<string> files){
    vector<string>::iterator i;
    for (i = files.begin();i<files.end();i++)
        this->addCharFile(*i);
}

void StatisticMap::addFile(string filename)
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
        aux[i] = tolower(iso2ascii( (unsigned char)(aux[i]) )); //turning every position of aux into ASCII and lowercase
        if (!isalnum(aux[i]))                                   //removing positions that aren't alphanumeric
        {
            aux.erase(i,1);

            for (unsigned j = pos; j<i; j++)
            {
                word+=aux[j];
            }
            if (word != "")
            {
                (*this)[word] += 1;				//adding string "word" to the Map, if "word" is already present, map[word] value is incremented
            }
            pos = i;
            i--;
            word="";
        }

    
    }

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
        aux[i] = tolower(iso2ascii( (unsigned char)(aux[i]) )); //turning every position of aux into ASCII and lowercase
        if (!isalnum(aux[i]))                                   //removing positions that aren't alphanumeric
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

void StatisticMap::print()
{
    map<string,int>::iterator mit;

    ofstream DumpFile;
    DumpFile.open("dump.txt");
            
    DumpFile << "============== Dumping Word Map! ==============" << "\n";
    cout << "============== Dumping Word Map! ==============" << endl;

    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        cout << mit->first << " : " << mit->second << " : " <<
                this->getPercentage(mit->first) << "%" << endl;
        DumpFile << mit->first << " : " << mit->second << " : " <<
                this->getPercentage(mit->first) << "%" << "\n";
    }

    cout << endl << "Number of different words: " << this->size() << endl;
    DumpFile << "\n" << "Number of different words: " << this->size() << "\n";       
}

void StatisticMap::Charprint()
{
    map<string,int>::iterator mit;

    ofstream DumpFile;
    DumpFile.open("chardump.txt");
            
    DumpFile << "============== Dumping Character Map! ==============" << "\n";
    cout << "============== Dumping Character Map! ==============" << endl;

    for(mit=this->begin() ; mit!=this->end() ; mit++)
    {
        cout << mit->first << " : " << mit->second << " : " <<
                this->getPercentage(mit->first) << "%" << endl;
        DumpFile << mit->first << " : " << mit->second << " : " <<
                this->getPercentage(mit->first) << "%" << "\n";
    }

    cout << endl << "Number of different characters: " << this->size() << endl;
    DumpFile << "\n" << "Number of different characters: " << this->size() << "\n";       
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