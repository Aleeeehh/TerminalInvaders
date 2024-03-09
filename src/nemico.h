/*
 * nemico.h
 *
 *  Created on: 27 gen 2023
 *      Author: alessioprato
 */
#include <curses.h>
#include <iostream>
#ifndef NEMICO_H_
#define NEMICO_H_
class nemico
{
public:
	nemico(int nemicoX, int nemicoY,int x, int y,int max_count,int px[4], int py[4], int pny[4], int pnx[4], bool shootingn[4],
 int tipo);
	nemico();
	void azione(int x,int y, int px[4], int py[4]);
	void vivo();
	bool getsh();
	bool getsh1();
	bool getsh2();
	bool getsh3();
	void morte();
	int getpunteggio();
	int getnemicoX();
	int getnemicoY();
	int getvita();
	bool nemicovivo;
	bool nemicospara;
	int nemicoX;
	int nemicoY;
	int x;
	int y;
	int contatore_movimento;
    int max_count;
	int punteggio;
	int px[4];
	int py[4];
	int pny[4];
	int pnx[4];
	bool shootingn[4];
	int PROJECTILE_SPEED;
	int max_sparo;
	int contatore_sparo;
	int contatore_sinistro;
	int tipo;
	int vita;
	bool p;

private:

};





#endif /* NEMICO_H_ */
