#ifndef EMBER_H
#define EMBER_H
#include <cstring>
#include "memtrace.h"
class Ember{
protected:
	char* nev;
	int szulEv;
public:
	Ember():szulEv(2002)
	{
		nev = new char[7];
		strcpy(nev,"IB72D1");
	}
	Ember   (const char* n,int ev);
	Ember   (const Ember& e);
	Ember&  operator=(const Ember& es);
	const   char* getNev() const;
	virtual int getKor(int ev) const;
	virtual const char* foglalkozas() const;
	virtual ~Ember();
};
#endif
