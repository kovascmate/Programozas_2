#ifndef KONTAKT_HPP
#define KONTAKT_HPP
#include "memtrace.h"

/////////////////////////////////////////////////////////////////////
/// Kontakt osztaly, ez egy ososztaly, belole szarmazik majd le a Munkahelyi es a Magan osztaly, felhasznalok elerhetosegit lehet itt tarolni
//
// Fuggvenyek:
//          -konstruktor
//          -destruktor
//          -gettel:{
//                      felhasznalo kontaktjaban levo telefonszam elereset biztositja,
//                      virtualis, tehat az alosztalyok fuggvenyei lesznek a lenyegesebbek}
//          -getemail:{
//                      felhasznalo kontaktjaban levo email elereset biztositja,
//                      virtualis, tehat az alosztalyok fuggvenyei lesznek a lenyegesebbek}
//          -getform:{
//                      megkulonbozteti a leszarmazotak fajtait}
//          -getspec:{
//                      visszater a leszarmazott egyedi adattagjaval}
/////////////////////////////////////////////////////////////////////


class Kontakt{
private:
    protected:
	String telefonszam;
	String email;
public:
    Kontakt(String& tel = String::nd,String& mail = String::nd){std::cout<<"kontakt kons\n";}
    Kontakt( Kontakt& input)   {this->telefonszam = String(input.telefonszam);
    this->email = input.email;

        std::cout<<"kontakt mas konst\n";}
     ~Kontakt()           {std::cout<<"kontakt dest\n";}
    virtual String gettel()     const{return telefonszam;}
    virtual String getspec()    const{return String::nd;}
    virtual String getemail()   const{return email;}
    virtual char* getform()     const{return "S";}

};

class Magan :public Kontakt{
	String revolut;
public:
    Magan(Magan& input)
    {
        std::cout<<"magan mas konst\n";
        this->email = String(input.email);
        this->telefonszam = String(input.telefonszam);
        this->revolut = String(input.revolut);
    }
    Magan(String& tel = String::nd,String& a = String::nd,String& rev = String::nd):Kontakt(tel,a){setspec(rev);std::cout<<"magan kons\n";}
    ~Magan()                    {std::cout<<"magan dest\n";}
    void setspec(String& spec)  {this->revolut = spec;}
    String gettel()             const{return telefonszam;}
    String getemail()           const{return email;}
    String getrevolut()         const{return revolut;}
    String getspec()            const{return this->revolut;}
    char* getform()             const{return "M";}
};



class Munkahelyi :public Kontakt{
	String irodaszam;
public:
    Munkahelyi(Munkahelyi& input)
    {

        std::cout<<"munka mas konst\n";
        this->email = String(input.email);
        this->telefonszam = String(input.telefonszam);
        this->irodaszam = String(input.irodaszam);
    }
    Munkahelyi(String& tel = String::nd,String& a = String::nd,String& iroda = String::nd):Kontakt(tel,a){setspec(iroda);std::cout<<"munka kons\n";}
    void setspec(String& spec)  {this->irodaszam= spec;}
    ~Munkahelyi(){std::cout<<"munka dest\n";}
    String gettel()             const{return telefonszam;}
    String getemail()           const{return email;}
    String getspec()            const{return this->irodaszam;}
    char* getform()             const{return "W";}
};

#endif // KONTAKT_HPP
