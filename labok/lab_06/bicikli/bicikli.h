#ifndef BICIKLI_H
#define BICIKLI_H
class Jarmu {
    double vMax;
public:
    Jarmu(double v) :vMax(v) {std::cout<<"\tJarmu ctor vMax="<<vMax<<"\n";}
    Jarmu(const Jarmu& j){std::cout<<"\tJarmu copy vMax="<<vMax<<"\n";this->vMax=j.vMax;}
    virtual ~Jarmu(){std::cout<<"\tJarmu dtor vMax="<<vMax<<"\n";}

};
class  Kerek
{
    int atmero;
    public:
        Kerek(){std::cout << "\tKerek ctor\n";}
        Kerek(int ertek)  {this->atmero =   ertek; std::cout << "\tKerek ctor\n";}
        virtual ~Kerek() { std::cout << "\tKerek dtor\n";}
        Kerek(const Kerek& k){ this->atmero = k.atmero; std::cout<< "\tKerek copy"<<std::endl;}
        void kiir(){ std::cout << "atmero=" << atmero << std::endl; }

};
class Szan : public Jarmu
{
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n) {std::cout<<"\tSzan ctor kutyaSzama="<<kutyakSzama<<"\n";}
    ~Szan() {std::cout<<"\tSzan dtor kutyakSzama="<<kutyakSzama<<"\n";}
    Szan(const Szan& s):Jarmu(s),kutyakSzama(s.kutyakSzama){std::cout<<"\tSzan copy kutyakSzama="<<kutyakSzama<<"\n";}
};

class Bicikli : public Jarmu
{
    Kerek elso;
    Kerek hatso;
public:
    Bicikli(double v=0,double d=16):Jarmu(v), elso(d),hatso(d){std::cout<<"\tBicikli ctor atmero="<<d<<"\n";}
    ~Bicikli() {std::cout << "\tBicikli dtor ";elso.kiir();}
    Bicikli(const Bicikli& b):Jarmu(b),elso(b.elso),hatso(b.hatso){std::cout<<"\tBicikli copy atmero=";elso.kiir();}
};




#endif // BICIKLI_H
