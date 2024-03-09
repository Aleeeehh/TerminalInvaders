/*
 * mappa.h
 *
 *  Created on: 25 gen 2023
 *      Author: alessioprato
 */

#ifndef MAPPA_H_
#define MAPPA_H_
#include <curses.h>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "personaggio.h"
using namespace std;

class mappa
{
public:
	mappa(int x, int y); //costruttore mappa
	void disegnamappa(); // disegna la mappa sullo schermo
	void posizionemuri(int p); //genera le posizioni dei muri casualmente;
	void disegnamuri(); //disegna i muri
	void disegnaspazi2();
	void cambiamappa(int m, int v, int p);
	void disegnaMonete(int m);
	void disegnacolonna();
	void disegnariga();
	void disegnacolonnadestra();
	void disegnaspazi();
	void disegnavita(int v);
	void disegnaporta(int doorX,int doorY);
	void disegnaportaindietro();
	int getx();
	int gety();
	int wallsX[30], wallsY[30], wallslen[30];
	int x,y;
	int doorX,doorY;
	int numeromuri;
private:

};




#endif /* MAPPA_H_ */
