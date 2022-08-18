#include <fstream>
#include "memtrace.h"
#include "nevjegy.hpp"
#include "filekezeles.h"

////////////////////////////////////////////////////
void betoltes(Lista<Nevjegy>& l)
{
        std::cout<<"betoltes\n";
        bool kon = true;
        char munka[] ="W\0";
        char mag[] ="M\0";
        char adat_1[100];
        char adat_2[100];
        char adat_3[100];
        std::ifstream filepointer;
        filepointer.open("telefonkonyv.txt");
        if(filepointer){
            std::cout<<"pointer check"<<std::endl;
        while(!filepointer.eof())
        {
            kon = true;
            Nevjegy a_nevjegy;
            filepointer>>adat_1>>adat_2>>adat_3;
            String  egy(adat_1);
            String  ketto(adat_2);
            String  harom(adat_3);
            Nev neve(egy,ketto,harom);
            a_nevjegy.setnev(neve);
            std::cout<<adat_1<<"\n";
            while(kon == true)
            {
                filepointer>>adat_1;
                if(adat_1[0] == munka[0] && adat_1[1] == munka[1])
                {       std::cout<<"BENT munka\n";
                        filepointer>>adat_1>>adat_2>>adat_3;
                        String  munkaegy(adat_1);
                        String  munkaketto(adat_2);
                        String  munkaharom(adat_3);
                        Munkahelyi input(munkaegy,munkaketto,munkaharom);
                        a_nevjegy.listapushback(input);
                }
                else if((adat_1[0]) == mag[0] &&adat_1[1] == mag[1])
                {
                        std::cout<<"BENT magan\n";
                        filepointer>>adat_1>>adat_2>>adat_3;
                        String  maganegy(adat_1);
                        String  maganketto(adat_2);
                        String  maganharom(adat_3);
                        Magan input(maganegy,maganketto,maganharom);
                        a_nevjegy.listapushback(input);
                }
                else
                {
                        std::cout<<"BENT commment\n";
                        kon = false;
                        String commentegy(adat_1);
                        a_nevjegy.setcomment(commentegy);
                }
            }
            std::cout<<"teljes beol\n";
            l.pushback(a_nevjegy);

        }
        filepointer.close();
        }
        else
        {
            throw "HIBA, fajlt nem lehet megnyitni";
        }
}
void mentes(Lista<Nevjegy>& l)
{
    std::ofstream filepointer;
    filepointer.open("telefonkonyv.txt");
    for(int i = 0; i < l.size();i++)
    {
            filepointer<<l[i].getvnev()<<"\t"<<l[i].getknev()<<"\t"<<l[i].getbnev()<<"\n";
            Lista<Kontakt> lk = l[i].getkontaktlista();
            for(int k = 0; k < lk.size();k++)
            {
                filepointer<<lk[k].getform()<<"\n"<<lk[k].gettel()<<"\t"<<lk[k].getemail()<<"\t"<<lk[k].getspec()<<"\n";
            }
            filepointer<<l[i].getcomment()<<"\n";
    }
    filepointer.close();
}
void makevCard(Nevjegy& input)
{
    if(matches(input.getbnev(),String::nd) || matches(input.getvnev(),String::nd)  || matches(input.getknev(),String::nd))
    {
        throw "Nem lehet ezzel a nevjeggyel vCardot letrehozni, keves adat van megadva";
    }
    else
    {
        Lista<Kontakt> kontaktok;
        kontaktok = input.getkontaktlista();
        std::ofstream filepointer;
        filepointer.open("vCard_kimenet.vcf");
        filepointer<<"BEGIN:VCARD"<<"\n";
        filepointer<<"VERSION:3.0"<<"\n";
        filepointer<<"N:"<<input.getknev();
        filepointer<<";"<<input.getvnev()<<"\n";
        filepointer<<"FN:"<<input.getbnev()<<"\n";
        for(int i = 0; i < kontaktok.size();i++)
        {
            if(kontaktok[i].getform() == "M")
            {
                if(kontaktok[i].gettel() != String::nd)
                {
                    filepointer<<"TEL;WORK:"<<kontaktok[i].gettel()<<"\n";
                }
                if(kontaktok[i].getemail() != String::nd)
                {
                    filepointer<<"EMAIL;WORK:"<<kontaktok[i].getemail()<<"\n";
                }
                if(kontaktok[i].getspec() != String::nd)
                {
                    filepointer<<"ADR:"<<kontaktok[i].getspec()<<"\n";
                }
            }
            else if(kontaktok[i].getform() == "W")
            {
                if(kontaktok[i].gettel() != String::nd)
                {
                    filepointer<<"TEL;HOME:"<<kontaktok[i].gettel()<<"\n";
                }
                if(kontaktok[i].getemail() != String::nd)
                {
                    filepointer<<"EMAIL;HOME:"<<kontaktok[i].getemail()<<"\n";
                }
            }
        }
        filepointer<<"NOTE:"<<input.getcomment()<<"\n";
    }
}
void indexes_lista(Lista<Nevjegy> l,Lista<int> li)
{
    for(int i =  0; i < li.size();i++)
    {
        std::cout<<li[i]<<"\t"<<l[li[i]].getvnev()<<"\t"<<l[li[i]].getknev()<<"\t"<<l[li[i]].getbnev()<<std::endl;
        Lista<Kontakt> lk = l[li[i]].getkontaktlista();
            for(int k = 0; k < lk.size();k++)
            {
                std::cout<<lk[k].gettel()<<"\t"<<lk[k].getemail()<<"\t"<<lk[k].getspec()<<std::endl;
            }
            std::cout<<l[i].getcomment()<<std::endl;
    }
}
void konzol_kiir_lista(Lista<Nevjegy>& l)
{
    std::cout<<"konzol kiir lista\n";
    for(int i = 0;i<l.size();i++)
    {

        std::cout<<l[i].getvnev()<<"\t"<<l[i].getknev()<<"\t"<<l[i].getbnev()<<"\n";
    }
    return;
}
