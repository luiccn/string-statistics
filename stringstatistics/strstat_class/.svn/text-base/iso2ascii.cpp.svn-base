/*
 * File:  iso2ascii.cpp
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

using namespace std;

/*
 * iso2ascii()
 *   Converts a char in the ISO 8859-15 character set (Western European) to
 *   its ASCII counterpart, mainly by removing diacritics.
 *
 */
char iso2ascii(unsigned char c)
{
    if (c < 0x80) return c;
    if (c < 0xA0) return '\0';
    switch (c)
    {

        case 0xA0 : return ' '; break;
        case 0xA1 : return '!'; break;
        case 0xA2 : return 'C'; break;
        case 0xA3 : return 'L'; break;
        case 0xA4 : return 'E'; break;
        case 0xA5 : return 'Y'; break;
        case 0xA6 :
        case 0xA7 :
        case 0xA8 : return 'S'; break;
        case 0xA9 : return 'c'; break;
        case 0xAA : return 'a'; break;
        case 0xAB : return '<'; break;
        case 0xAC : return '?'; break;
        case 0xAD : return '-'; break;
        case 0xAE : return 'R'; break;
        case 0xAF : return '-'; break;

        case 0xB0 : return 'o'; break;
        case 0xB1 : return '?'; break;
        case 0xB2 : return '?'; break;
        case 0xB3 : return '?'; break;
        case 0xB4 : return 'Z'; break;
        case 0xB5 : return 'u'; break;
        case 0xB6 : return '?'; break;
        case 0xB7 : return '.'; break;
        case 0xB8 : return 'Z'; break;
        case 0xB9 : return '?'; break;
        case 0xBA : return 'o'; break;
        case 0xBB : return '>'; break;
        case 0xBC : return '?'; break;
        case 0xBD : return '?'; break;
        case 0xBE : return 'Y'; break;
        case 0xBF : return '?'; break;

        case 0xC0 :
        case 0xC1 :
        case 0xC2 :
        case 0xC3 :
        case 0xC4 :
        case 0xC5 : return 'A'; break;
        case 0xC6 : return '?'; break;
        case 0xC7 : return 'C'; break;
        case 0xC8 :
        case 0xC9 :
        case 0xCA :
        case 0xCB : return 'E'; break;
        case 0xCC :
        case 0xCD :
        case 0xCE :
        case 0xCF : return 'I'; break;

        case 0xD0 : return 'D'; break;
        case 0xD1 : return 'N'; break;
        case 0xD2 :
        case 0xD3 :
        case 0xD4 :
        case 0xD5 :
        case 0xD6 : return 'O'; break;
        case 0xD7 : return 'x'; break;
        case 0xD8 : return '0'; break;
        case 0xD9 :
        case 0xDA :
        case 0xDB :
        case 0xDC : return 'U'; break;
        case 0xDD : return 'Y'; break;
        case 0xDE : return 'P'; break;
        case 0xDF : return 's'; break;

        case 0xE0 :
        case 0xE1 :
        case 0xE2 :
        case 0xE3 :
        case 0xE4 :
        case 0xE5 : return 'a'; break;
        case 0xE6 : return '?'; break;
        case 0xE7 : return 'c'; break;
        case 0xE8 :
        case 0xE9 :
        case 0xEA :
        case 0xEB : return 'e'; break;
        case 0xEC :
        case 0xED :
        case 0xEE :
        case 0xEF : return 'i'; break;

        case 0xF0 : return 'o'; break;
        case 0xF1 : return 'n'; break;
        case 0xF2 :
        case 0xF3 :
        case 0xF4 :
        case 0xF5 :
        case 0xF6 : return 'o'; break;
        case 0xF7 : return '?'; break;
        case 0xF8 : return 'o'; break;
        case 0xF9 :
        case 0xFA :
        case 0xFB :
        case 0xFC : return 'u'; break;
        case 0xFD : return 'y'; break;
        case 0xFE : return '?'; break;
        case 0xFF : return 'y'; break;

        default: return '?';

    }
}
