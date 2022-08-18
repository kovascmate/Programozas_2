#include "memtrace.h"
#include "input.h"
void uj_adat(Lista<Nevjegy>& l)
{
    bool kilepes = false;
    bool van_lista = false;
    Lista<Kontakt> kl;
    Nevjegy input;

    while(kilepes == false)
    {
    char adat[100];
    char valaszto[2];
    std::cout<<"Melyik adatot szeretne megadni?"<<std::endl;
    std::cout<<"1. Nev"                         <<std::endl;
    std::cout<<"2. Magan elerhetoseg"           <<std::endl;
    std::cout<<"3. Munkahelyi elerhetoseg"      <<std::endl;
    std::cout<<"4. Megjegyzes"                  <<std::endl;
    std::cout<<"5. Ki szeretnek lepni"          <<std::endl;
    std::cin>>valaszto;
    int oszto = valaszto[0]-'0';
    switch (oszto)
        {
        case 1:{
                std::cout<<"Adja meg a keresztnevet:"<<std::endl;
                std::cin>>adat;
                String kereszt(adat);
                std::cout<<"Adja meg a vezeteknevet:"<<std::endl;
                std::cin>>adat;
                String vezetek(adat);
                std::cout<<"Adja meg a becenevet:"<<std::endl;
                std::cin>>adat;
                String bece(adat);
                Nev nevinput(vezetek,kereszt,bece);
                input.setnev(nevinput);
            break;
        }
        case 2:
            {
                std::cout<<"Adja meg a telefonszamot:"<<std::endl;
                std::cin>>adat;
                String tel(adat);
                std::cout<<"Adja meg az emailt:"<<std::endl;
                std::cin>>adat;
                String mail(adat);
                std::cout<<"Adja meg a revolutfelhasznalonevet:"<<std::endl;
                std::cin>>adat;
                String rev(adat);
                Magan maganinput(tel,mail,rev);
                if(van_lista == false)
                {
                    input.setkontaktok(kl);
                    input.listapushback(maganinput);
                    van_lista = true;
                }
                else
                    {
                    input.listapushback(maganinput);
                    }
                break;
            }
        case 3:{
            std::cout<<"Adja meg a telefonszamot:"<<std::endl;
                std::cin>>adat;
                String tel(adat);
                std::cout<<"Adja meg az emailt:"<<std::endl;
                std::cin>>adat;
                String mail(adat);
                std::cout<<"Adja meg az irodaszamot:"<<std::endl;
                std::cin>>adat;
                String iroda(adat);
                Munkahelyi munkahelyiinput(tel,mail,iroda);
                if(van_lista == false)
                {
                    input.setkontaktok(kl);
                    input.listapushback(munkahelyiinput);
                    van_lista = true;
                }
                else
                    {
                    input.listapushback(munkahelyiinput);
                    }
                break;
        }
        case 4:
            {
                std::cout<<"Adja meg a commentet:"<<std::endl;
                std::cin>>adat;
                String com(adat);
                input.setcomment(com);
                break;
            }
        case 5:
            kilepes = true;
            break;
        default:
            break;
        }
    }
    l.pushback(input);

}
int indexbeker(Lista<Nevjegy>& l)
{
    while(1)
    {
    int adat = -1;
    std::cout<<"Adat meg a nevjegy sorszamat melyen szeretne muveletet vegrehajtani:"<<std::endl;
    std::cin>>adat;
    adat++;
    if(adat>0 && adat<l.size())
    {
        return adat;
    }
    else
    {
        throw "HIBA, ROSSZ BEMENET";
        std::cout<<"Probalkozzon ujra"<<std::endl;
    }
    }
}
