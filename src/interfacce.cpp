/*
 * interfacce.cpp
 *
 *  Created on: 8 feb 2023
 *      Author: alessioprato

*/
#include "interfacce.h"
#include <curses.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void mostracomandi()
{
    clear(); // Pulisci lo schermo
    attron(A_BOLD);
    attron(A_UNDERLINE);
    mvprintw(3, 32, "Comandi di gioco");
    attroff(A_UNDERLINE);
    attroff(A_BOLD);
    mvprintw(5, 20, "Movimento: 'W','A','S','D'.");
    mvprintw(6, 20, "Sparare: 'I','J','K','L'.");
    mvprintw(7, 20, "Usa teleport: 'O'.");
    mvprintw(8, 20, "Piazza trappola: 'H'.");
    mvprintw(10,20, "Premi qualsiasi tasto per tornare al menu principale");
    getch();
    clear();
}
void menu(int evidenzia,int input,string scelte[3]){
    while(1)
    {
    	attron(A_BOLD);
    	attron(A_UNDERLINE);
    	mvprintw(8, 32, "Terminal Invaders");
    	attroff(A_UNDERLINE);
    	attroff(A_BOLD);
    for(int i=0;i<3;i++)
    {
    	if(i==evidenzia) attron(A_REVERSE);
    	mvprintw(i+10, (COLS - scelte[i].length()) / 2, scelte[i].c_str());
    	attroff(A_REVERSE);
    }
    input=getch();
    switch(input)
    {
    case KEY_UP:
    	evidenzia--;
    	if(evidenzia==-1) evidenzia=0;
    	break;
    case KEY_DOWN:
    	evidenzia++;
    	if(evidenzia==3) evidenzia=2;
    	break;
    default: break;
    }
    if (input==10 && evidenzia==0) break;
    if (input==10 && evidenzia==1) mostracomandi();
    if (input==10 && evidenzia==2) {
    	endwin();
    	exit(0);
    }
    }
}


