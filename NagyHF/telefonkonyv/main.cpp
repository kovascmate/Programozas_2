#include <iostream>
#include "memtrace.h"
#include "input.h"
#include "filekezeles.h"
#include "lancoltlista.hpp"
#include "logika.h"
int main()
{
    std::cout<<"main\n";
    Lista<Nevjegy> l;
    betoltes(l);
    char adat[2] = " ";
    bool kilep = false;
    do
    {
        std::cout<<"\tTelefonkonyv"     <<std::endl;
        std::cout<<"Lehetosegek:"       <<std::endl;
        std::cout<<"1. Listazas"        <<std::endl;
        std::cout<<"2. Uj adat"         <<std::endl;
        std::cout<<"3. Adat modositas"  <<std::endl;
        std::cout<<"4. Adat torles"     <<std::endl;
        std::cout<<"5. Kereses"         <<std::endl;
        std::cout<<"6. vCard keszites"  <<std::endl;
        std::cout<<"7. Kilepes"         <<std::endl;
        std::cout<<"8. Teszt"           <<std::endl;
        std::cin>>adat;
        int oszto = adat[0]-'0';
        switch(oszto)
        {
            ///listazas
            case 1:
                {
                    konzol_kiir_lista(l);
                    break;
                }
            case 2:
                {
                    uj_adat(l);
                    break;
                }
            ///adat_modositas
            case 3:
                {
                    modositas_adat(l);
                    break;
                }
            ///adat_torles
            case 4:
                {
                    std::cout<<"Adja meg a torlendo nevjegy sorszamat"<<std::endl;
                    break;
                }
            ///adat_kereses
            case 5:{
                    char adat[100];
                    std::cout<<"Kereses"<<std::endl;
                    std::cout<<"Adja meg a keresendo kifejezest:"<<std::endl;
                    std::cin>>adat;
                    String keresett(adat);
                    Lista<int> talalat= keres(keresett, l);
                    indexes_lista(l,talalat);
                    break;
            }
            ///vCard keszites
            case 6:{
                    int i = indexbeker(l);
                    makevCard(l[i]);
                    std::cout<<"A vCard a program mappajaban megtalalhato"<<std::endl;
                    std::cout<<"Ha uj vCardot akar letrehozni az elozo megszunik"<<std::endl;
                    break;
                }
            ///kilepes
            case 7:
                {
                    kilep = true;
                    break;
                }
                ///test
            case 8:
                {
                    break;
                }
        char bejon[100] = " ";
        std::cin>>bejon;
        String input(bejon);
        }

    }while(kilep != true);
    return 0;
}
