
#ifndef NEVJEGY_HPP
#define NEVJEGY_HPP

#include "memtrace.h"
#include "nev.hpp"
#include "string.hpp"
#include "kontakt.hpp"
#include "lancoltlista.hpp"
/////////////////////////////////////////////////////////////////////
/// Nevjegy osztaly, minden adat osszefogo tarolasara szolgal
//
// Fuggvenyek:
//          -konstruktor
//          -destruktor
//          -getvnev:{
//                      adott felhasznalo vezetekneve eleresere szolgal}
//          -getknev:{
//                      adott felhasznalo keresztneve eleresere szolgal}
//          -getbnev:{
//                      adott felhasznalo beceneve eleresere szolgal}
//          -getcomment:{
//                      adott felhasznalo commentjevel visszater}
//          -setnev
/////////////////////////////////////////////////////////////////////
class Nevjegy{
    Nev neve;
    Lista<Kontakt> kontaktok;
    String comment;
public:
    ////////////////////////////////////////////////
    String getvnev() const                      {return neve.getvezetek();}
    String getknev() const                      {return neve.getkereszt();}
    String getbnev() const                      {return neve.getbece();}
    String getcomment()                         {return comment;}
    Nevjegy()                                   {std::cout<<"nevjegy konst\n";}
    void setnev(Nev& input)                     {std::cout<<"nev hozzaad";this->neve = input;}
    void setkontaktok(Lista<Kontakt>& input)    {this->kontaktok = input;}
    void listapushback(Kontakt& input)          {kontaktok.pushback(input);}
    void setcomment(String& input)              {this->comment = input;}
    ~Nevjegy()                                  {std::cout<<"nevjegy dest\n";}
    Lista<Kontakt> getkontaktlista() const      {return kontaktok;}
};
#endif // NEVJEGY_HPP
