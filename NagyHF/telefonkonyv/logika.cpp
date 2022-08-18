#include "memtrace.h"
#include "logika.h"
Lista<int> keres(String& keresett,Lista<Nevjegy>& l)
{
    Lista<int> talalt;
    for(int i = 0; i < l.size();i++)
    {
        if(matches(l[i].getvnev(),keresett) ||  matches(l[i].getbnev(),keresett)||  matches(l[i].getknev(),keresett))
        {
            talalt.pushback(i);
            break;
        }
        else if(matches(l[i].getcomment(),keresett))
        {
            talalt.pushback(i);
            break;
        }
        else
        {
            Lista<Kontakt> lk = l[i].getkontaktlista();
                for(int k = 0; k < lk.size();k++)
                {
                    if(matches(lk[k].gettel(),keresett) || matches(lk[k].getemail(),keresett) || matches(lk[k].getspec(),keresett))
                    {
                       talalt.pushback(i);
                       break;
                    }
                }
        }
    }
    return talalt;
}

void modositas_adat(Lista<Nevjegy>& l)
{
    char valaszto[2];
    char adat[100];
    bool kilepes = false;
    int index = indexbeker(l);
    Lista<Kontakt> kl = l[index].getkontaktlista();
    while(kilepes == false)
    {
    std::cout<<"Melyik adatot szeretne modositani?" <<std::endl;
    //std::cout<<"Ha egy megadott informacio tomb elemet modositja akkor az egesz modosul"<<std::endl;
    std::cout<<"1. Nev"                             <<std::endl;
    std::cout<<"2. Magan elerhetoseg"               <<std::endl;
    std::cout<<"3. Munkahelyi elerhetoseg"          <<std::endl;
    std::cout<<"4. Megjegyzes"                      <<std::endl;
    std::cout<<"5. Ki szeretnek lepni"              <<std::endl;
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
                l[index].setnev(nevinput);

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
                for(int i = 0; i <kl.size();i++)
                if(kl[i].getform()== "M")
                {
                    kl[i];
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
               break;
        }
        case 4:
            {
                std::cout<<"Irja le a megjegyzeset"<<std::endl;
                std::cin>>adat;
                String com(adat);
                l[index].setcomment(com);
                break;
            }
        case 5:
            kilepes = true;
            break;
        default:
            break;
        }
    }
}
