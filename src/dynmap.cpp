/*
 * dynmap.cpp
 *
 *  Created on: 10 feb 2023
 *      Author: alessioprato
 */
#include "dynmap.h"
#include <iostream>
#include <fstream>
#include <curses.h>
#include <random>
#include <time.h>
#include <string>
#include "personaggio.h"
#include "nemico.h"
bool drawDoor(nemico* n, int len) {
    for (int i = 0; i < len; i++) {
        if (n[i].nemicovivo) {
            return false;
        }
    }
    return true;
}

void copy_screen(char (&screen)[50][50], int y, int x) {
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      screen[i][j] = mvwinch(stdscr, i, j) & A_CHARTEXT;
    }
  }
}

void draw_map(char map[50][50], int rows, int cols, int xPorta, int yPorta) {
    clear();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] != '@') mvaddch(i, j, map[i][j]);
        }
    }
    refresh();
}
Livello* addToTail(Livello* head, int level, char map[50][50]) {
	Livello* tmp = head;
	    Livello* found = NULL;
	    while (!found && tmp != NULL) {
	        if (tmp->level == level) {
	            found = tmp;
	        }
	        tmp = tmp->next;
	    }

	    if (found) {
	        for (int i = 0; i < 50; i++) {
	            for (int j = 0; j < 50; j++) {
	                found->map[i][j] = map[i][j];
	            }
	        }
	        return head;
	    }
    Livello* newNode = new Livello;
    newNode->level = level;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            newNode->map[i][j] = map[i][j];
        }
    }
    newNode->previous = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Livello* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
    return head;
}

Livello* cercaLivello (Livello* m1, int livello){
bool d=false;
Livello* tmp2 = m1;
Livello* found = NULL ;
   while (tmp2 != NULL && !d) {
       if (tmp2->level == livello) {
    	   found = tmp2;
    	   d=true;
       }
       tmp2 = tmp2->next;
   }
   return found;
}



