#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */
namespace sajat{
int atoi(const char *p, int base)
{
    int i = 0;
    int temp = 0;
    const char* neptun = "IB72D1";
    while(p[i] != '\t' && p[i] != '\0')
    {
        if(p[i]-'0' < 0 || p[i]-'0' >= base)
        {
            throw(neptun);
        }
        i++;
    }
    for(int i = 0; p[i] != ' ' && p[i] != '\t' && p[i] != '\0';i++)
        {
            temp = temp*base+p[i]-'0';
        }
    return temp;
}
char *strcat(const char *p1, const char *p2)
{
    char* vissza;
    vissza = new char[strlen(p1)+strlen(p2)+1];
    std::strcpy(vissza, p1);
    std::strcat(vissza, p2);
    return vissza;
}
char *unique(char *first, char *last)
{
    char temp = first[0];
    char* mozgo;
    mozgo = last;
    for(int i = 1; i <mozgo-first;i++)
    {
        if(temp == first[i])
        {
            for(int j = 0;j <mozgo-first+i;j++)
            {
                first[i+j] = first[i+j+1];
            }
            mozgo--;
            i--;
        }
        temp = first[i];
    }
    return mozgo;
}
}
