/*
 * File:  main.cpp
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

#include <cstdlib>
#include "stringstat.h"

using namespace std;

/*
 *
 */

int main(int argc, char** argv) {

    // We won't quit the program if there is an error in some file. We
    //   will still open the files that we can.

    map<string,int> wordMap;
    int totalWordCount = 0;

    try
    {
        StringStatistic("test_dataset/data-1.txt", &wordMap, &totalWordCount);
    }
    catch (int e)
    {
        if (e==FILE_ERROR_EXCEPTION)
            cout << "Unable to open file test_dataset/data-1.txt" << endl;
        else
        {
            cout << e << " Unknown error" << endl;
            return e;
        }
    }

    cout << endl << endl << endl << "===============" << endl << endl;

    try
    {
        StringStatistic("test_dataset/data-2.txt", &wordMap, &totalWordCount);
    }
    catch (int e)
    {
        if (e==FILE_ERROR_EXCEPTION)
            cout << "Unable to open file test_dataset/data-2.txt" << endl;
        else
        {
            cout << e << " Unknown error" << endl;
            return e;
        }
    }

    cout << endl << endl << endl << "===============" << endl << endl;

    try
    {
        StringStatistic("test_dataset/data-inexistente.txt",
                        &wordMap, &totalWordCount);
    }
    catch (int e)
    {
        if (e==FILE_ERROR_EXCEPTION)
            cout << "Unable to open file test_dataset/data-inexistente.txt" <<
                    endl;
        else
        {
            cout << e << " Unknown error" << endl;
            return e;
        }
    }

    MapPrint(&wordMap, &totalWordCount);


    return 0;
}
