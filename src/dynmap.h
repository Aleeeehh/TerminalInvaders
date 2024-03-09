/*
 * dynmap.h
 *
 *  Created on: 10 feb 2023
 *      Author: alessioprato
 */

#ifndef DYNMAP_H_
#define DYNMAP_H_
#include <iostream>
#include <fstream>
#include <curses.h>
#include <random>
#include <time.h>
#include <string>
#include "personaggio.h"
#include "nemico.h"
using namespace std;
struct Livello {
  int level;
  char map[50][50];
  Livello* previous;
  Livello* next;
};
bool drawDoor(nemico* n, int len);
void copy_screen(char (&screen)[50][50], int y, int x);
void draw_map(char map[50][50], int rows, int cols, int xPorta, int yPorta);
Livello* addToTail(Livello* head, int level, char map[50][50]);
Livello* cercaLivello (Livello* m1, int livello);





#endif /* DYNMAP_H_ */
