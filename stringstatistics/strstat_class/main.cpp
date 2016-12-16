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
#include "StatisticMap.h"

using namespace std;

/*
 *
 */

int main(int argc, char** argv) {

    // We won't quit the program if there is an error in some file. We
    //   will still open the files that we can.

    StatisticMap wordMap;
    StatisticMap charMap;
    ////////////////////////////////////////////////////////////////////////

    try
    {
        wordMap.addFile("test_dataset/data-1.txt");
        charMap.addCharFile("test_dataset/data-1.txt");
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

    ////////////////////////////////////////////////////////////////////////

    try
    {
        wordMap.addFile("test_dataset/data-2.txt");
        charMap.addCharFile("test_dataset/data-2.txt");
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
    
    ////////////////////////////////////////////////////////////////////////

    try
    {
        wordMap.addFile("test_dataset/datta-3.txt");
    }
    catch (int e)
    {
        if (e==FILE_ERROR_EXCEPTION)
            cout << "Unable to open file test_dataset/data-3.txt" << endl;
        else
        {
            cout << e << " Unknown error" << endl;
            return e;
        }
    }

    ////////////////////////////////////////////////////////////////////////


    try
    {
        wordMap.addFile("test_dataset/data-inexistente.txt");
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

    ////////////////////////////////////////////////////////////////////////
    charMap.Charprint();
    wordMap.print();

    return 0;
}
