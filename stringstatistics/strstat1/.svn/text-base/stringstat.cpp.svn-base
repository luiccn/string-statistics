/* 
 * File:   main.cpp
 * Author: Luiz Carlos Ciafrino Neto, UFRJ.
 *
 * Created on 13 de Abril de 2012, 16:23
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "stringstat.h"


using namespace std;

/*
 * 
 */

void MapPrint(map<string,int>::iterator mit,map<string,int> MyMap)
{ 
    cout << "============== Dumping Map! ==============" << endl;
    for(mit=MyMap.begin() ; mit!=MyMap.end() ; mit++)
        cout << mit->first << " = " << mit->second << endl;
}

void StringStatistic(const char * Text)
{       
    cout << "=========String Statistics Module ==========" << endl << endl;
    
    map<string,int> WordCount;
    map<string,int>::iterator mit;

    vector<string> myWords;
    vector<string>::iterator vit;

    int i, j;
    int pos=0 ;
    string aux = "" ;
    string word="" ;
    string line ;

    ifstream myFile ; 

    myFile.open(Text);
   
    if (myFile.is_open())
    {
        while (myFile.good())
        {
            getline (myFile,line);
            aux+=line;

        }
        aux+=32;
        myFile.close();
        
        for (i=0; i<aux.length(); i++)
	{
                if (aux[i]== 32 || aux[i]== 00 || aux[i]== 44 || aux[i]== 46 || aux[i]== 28 ||
                    aux[i]== 58 || aux[i]== 59 || aux[i]== 33 || aux[i]== 63 || aux[i]== 34 || aux[i]==03 )
                {
                    if (aux[i]==34)
                    {
                        aux.erase(i,0);
                    }
                                   
                    for (j=pos; j<i; j++)
                    {
                        word+=aux[j];                       
                    }
                    pos=i+1;
                    myWords.push_back(word);
                    word="";
                    
                }
                
                
	}      
    }
    
    
    else cout << "Unable to open file.";
    
    for (vit=myWords.begin(); vit<myWords.end();vit++)
        {        
                WordCount[*vit]=(int) count (myWords.begin(), myWords.end(), *vit);
        }
    
    MapPrint(mit, WordCount);
}




