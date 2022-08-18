#ifndef FILEKEZELES_H
#define FILEKEZELES_H
#include "lancoltlista.hpp"
#include "kontakt.hpp"
//betoltes:
//          a nevjegyeket betolti a fajlbol, parameterkent megadjuk neki a lista melybe kell mentenie az adatokat
void betoltes(Lista<Nevjegy>&);
//mentes:
//          a nevjegyeket elmenti fajlba, parameterkent kapott listat menti el
void mentes(Lista<Nevjegy>&);
//makevCard:
//          fajlban letrehozza a vCardot, parameterkent megadjuk azt a nevjegyet melybol letre akarjuk hozni a vCardot
void makevCard(Nevjegy&);
//indexes_lista
//          konzolon megjeleniti az elso parameterkent kapott listanak a masik lista elemei szerinti tagjait
void indexes_lista(Lista<Nevjegy>,Lista<int>);
//konzol_kiir_lista
//          konzolon megjeleniti a parameterkent kapott lista osszes elemet
void konzol_kiir_lista(Lista<Nevjegy>&) ;
#endif // FILEKEZELES_H
