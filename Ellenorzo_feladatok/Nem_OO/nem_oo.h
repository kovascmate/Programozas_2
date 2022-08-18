#ifndef NEM_OO_H
#define NEM_OO_H
/**
 * \file nem_oo.h
 * (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * A C++ nem OO bővítéseinek gyakorlásához.
 *
 */

#include <cmath>
#include <iostream>
#include "memtrace.h"


namespace sajat {	/// saját névtér

/**
 * Saját atoi.
 * Számjegyeket tartalmazó karaktersorozat átalakítása int-re.
 * Helyes számjegysorozat végét white space, vagy sztring vége ('\0') jelzi.
 *   Ha a számjegysorozatban olyan számjegy, vagy betű fordul elő,
 *   ami nem érvényes az adott számrendszerben, az hiba.
 *   Pl. hármas számrendszerben nem fordulhat elő a 3-as számjegy, de az A betű sem.
 * Hiba esetén egy const char* típusú kivételt kell dobni, melynek értéke
 * az Ön neptun azonosítója!
 * @param p    - pointer a sztringre
 * @param base - számrendszer alapja (0-10)
 * @return     - base számrendszerben értelmezett szám
 */
int atoi(const char *p, int base = 10);
/*{
    int i = 0;
    int temp = 0;
    while(p[i] != ' ' || p[i] != '\t' || p[i] != '\0')
    {
        if(!(p[i]>=0 && p[i]<base))
        {
            throw("IB72D1");
        }
    }
    for(int i = 0; p[i] != ' ' || p[i] != '\t' || p[i] != '\0';i++)
        {
            temp = temp*base+p[i]-'0';
        }
        return temp;
}*/
/**
 * Sajat strcat.
 * Két C stílusú sztring (nullával lezárt karaktersorozat) összefűzése
 * A függvény dinamikusan foglal helyet az eredménynek.
 * @param p1   - pointer az első sztringre
 * @param p2   - pointer az másik sztringre
 * @return     - dinamikusan foglalt terület címe, ahova az eredmény kerül (hívónak kell felszabadítania)
 */
char *strcat(const char *p1, const char *p2);
/*{
    int size1 = 0;
    int size2 = 0;
    int i = 0;
    while(p1[i] != 0)
    {
        size1++;
        i++;
    }
    i =0;
    while(p2[i] != 0)
    {
        size2++;
        i++;
    }
    char* vissza = new char(size1+size2+1);
    for(int j = 0; j <size1;j++)
    {
        vissza[j] = p1[j];
    }
    for(int j = 0; j <size2;j++)
    {
        vissza[j+size1] = p2[j];
    }
    vissza[size1+size2+1] = '\0';
    return vissza;
}*/

/**
 * unique
 * A paraméterként kapott két pointer közötti karaktersorozatból kihagyja az egymás után ismétlődő
 * karaktereket (char). A sorozatot az eredeti helyén hagyja!
 * @param first - pointer az adatok kezdetére
 * @param last  - pointer, ami az utolsó adat után mutat
 * @return      - pointer, ami az új sorozat utolsó adata után mutat (a kihagyással rövidült a sorozat)
 */
char *unique(char *first, char *last);
/*{
    char temp = first[0];
    for(int i = 1; i< last-first;i++)
    {
        if(first[i] == temp)
        {
            for(int j = 0;j < last-first-i;j++)
            {
                first[i+j]=first[i+j+1];
            }
        }
        temp = first[i];
    }
}*/

/**
 * Az alább megvalósított adatstruktúra és a hozzá tartózó függvények
 * A max sablonnal kapcsolatos feladat megvalósításához kellenek.
 *
 * Értse meg a működésüket!
 * A feladat részletes leírását a max.hpp fájlban találja.
 * A kapcsolódó feladatot a max.hhp-ben oldja meg, azaz
 * abban valósítsa meg a várt sablont és annak specializációját!
 */

/**
 * Adatstruktúra komplex szám tárolásához
 */
struct Komplex {
    double re;  // valós rész
    double im;  // képzetes rész
};

/**
 * Komplex szám abszolút értéke
 * @param k - komplex szám
 * @return valós - a komplex szám abszolút értéke
 */
inline double absKomplex(const Komplex& k) {
    return sqrt(k.re*k.re + k.im*k.im);
}

/**
 * Komplex szám kiírása egy ostream típusú adatfolyamra
 * @param os - ostream típusú objektum
 * @param k - komplex szám
 * @return os
 */
inline std::ostream& operator<<(std::ostream& os, const Komplex& k) {
    os << "(" << k.re << "," << k.im << "j)";
    return os;
}


}/// ----------  névtér vége ---------------

#endif
