/*w
 * personaggio.h
 *
 *  Created on: 26 gen 2023
 *      Author: alessioprato
 */

#ifndef PERSONAGGIO_H_
#define PERSONAGGIO_H_
#include <curses.h>
#include "mappa.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
class personaggio
{
public:
	personaggio(int x, int y,int muoviNemico, bool shooting[4],
			int px[4], int py[4], int x1,int y1, bool nemicovivo, int monete, int punteggio);
	void azione(int ch,int nemicoX, int nemicoY, int n, int t, int tr);
	int gettrappola();
	int getpunteggio();
	int getteleport();
	int getx();
	int getportaindietro();
	int gety();
	int getpx();
	int getpy();
	int getpx1();
	int getpy1();
	int getpx2();
	int getpy2();
	int getpx3();
	int getpy3();
	int getmonete();
	bool getnemicovivo();
	int getx1();
	int gety1();
	int getposporta();
	int getvita();
	bool nemicovivo;
	int x;
	int y;
	int cambiaMappa;
	int cambiaMappa1;
	int ch;
	int muoviNemico;
	int PROJECTILE_SPEED;
	bool shooting[4];
	int monete;
	int punteggio;
	int px[4];
	int py[4];
	int x1,y1;
	int posPorta;
	int vita;
	int teleport;
	int trappola;
	int portaindietro;

};




#endif /* PERSONAGGIO_H_ */
