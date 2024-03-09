/*
 * mappa.cpp
 *
 *  Created on: 25 gen 2023
 *      Author: alessioprato
 */

#include "mappa.h"

mappa::mappa(int x, int y)
{
	/*void disegnamappa();
	void disegnaspazi();
	void disegnacolonnadestra();
	void disegnaportaindietro();
	void disegnaspazi2();
	void disegnavita(int s);
	void disegnamuri();
	void posizionemuri(int p);
	void cambiamappa(int m,int v, int p);
	void disegnaMonete(int m);
	void disegnacolonna();
	void disegnariga();
	void disegnaporta(int doorY,int doorX);
	int getx();
	int gety();*/

	this->x=y;
	this->x=y;
	this->doorX=doorX;
	this->doorY=doorY;
}


void mappa::posizionemuri(int p){
    // genera posizioni casuali per i muri
	this->numeromuri = p;
    srand(time(NULL));
    for (int i = 0; i < p; i++) {
        wallsX[i] = rand() % 36 + 6;
        wallsY[i] = rand() % 15 + 4;
        wallslen[i] = rand() % 3 + 3; // lunghezza minima di 3 caselle
    }
}

void mappa::disegnamappa() {

    // disegna la mappa
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 50; j++) {
            if (i == 0 || i == 23 || j == 0 || j == 49) {
                // disegna i bordi
                mvaddch(i, j, '#');
            } else {
                // disegna gli spazi vuoti
                mvaddch(i, j, ' ');
            }
        }
    }
}
    void mappa::disegnamuri(){
    // disegna i muri
    for (int i = 0; i < this->numeromuri; i++) {
        for (int j = 0; j < wallslen[i]; j++) {
            mvaddch(wallsY[i], wallsX[i] + j, '-');
        }
    }

 }

    void mappa::disegnaMonete(int m) {
    	start_color();
    	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
         //disegna le monete
    	int l=0;
        	 for (int i =0;i<m;i++) {
        		    	for(int j=0;j<m;j++) {
        		    		//attron(COLOR_PAIR(2));
        		    		if (l%5==0){
        		    		mvaddch((rand()%20)+1,(rand()%40)+1,'$');
        		    		}
        		    		l++;
        		    	}
        		    }
        }
    void mappa::disegnavita(int v){
    	start_color();
    	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    	int l=0;
   	 for (int i =0;i<v;i++) {
   		    	for(int j=0;j<v;j++) {
   		    		if(l%5==0){
   		    		mvaddch((rand()%20)+1,(rand()%40)+1,'+');
   		    	}
   		    		l++;
   		    	}
   		    }
   }
    void mappa::disegnacolonnadestra()
    {
    	for(int i=0;i<=23;i++)
    		mvaddch(i,49,'#');
    }
    void mappa::disegnacolonna()
    {
    	for(int i=0;i<=23;i++)
    		mvaddch(i,0,'#');

    }

    void mappa::disegnaporta(int doorY,int doorX)
    {
    	mvaddch(doorY,doorX,'H');
    }
    void mappa::disegnariga()
    {
    	for(int i=0;i<48;i++)
    		mvaddch(0,i,'#');
    }
    void mappa::disegnaportaindietro()
    {
    	mvaddch(21,5,'A');
    }
    void mappa::disegnaspazi()
    {
    	for (int i = 0; i < 90; i++) {
    	mvaddch(1,i,' ');
    	}
    }
    void mappa::disegnaspazi2()
    {
    	for(int i=0;i<90;i++)
    	{
    		mvaddch(2,i,' ');
    	}
    }
    void mappa::cambiamappa(int m, int v, int p)
    {

    	posizionemuri(p);
    	disegnamappa();
    	disegnamuri();
    	disegnaspazi();
    	disegnaspazi2();
    	disegnacolonnadestra();
	        disegnacolonna();
	        disegnariga();
    	disegnaMonete(m);
    	disegnavita(v);
        	refresh();


    }

int mappa::getx()
{
	return this->x;
}
int mappa::gety()
{
	return this->y;
}
