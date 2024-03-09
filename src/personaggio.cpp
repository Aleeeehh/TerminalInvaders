/*
 * personaggio.cpp
 *
 *  Created on: 26 gen 2023
 *      Author: alessioprato
 */

#include "personaggio.h"
#include <curses.h>
#include <ctime>
personaggio::personaggio(int x, int y, int muoviNemico, bool shooting[4],
		int px[4], int py[4], int x1, int y1, bool nemicovivo, int monete, int punteggio)
{

	void azione(int ch, int nemicoX, int nemicoY, int n, int t, int tr);
	int gettrappola();
	int getteleport();
	int getpunteggio();
	int getportaindietro();
	int getx();
	int gety();
	int getpx();
	int getpy();
	int getpx1();
	int getpy1();
	int getpx2();
	int getpy2();
	int getpx3();
	int getpy4();
	int getx1();
	int gety1();
	int getvita();
	int getmonete();
	bool getnemicovivo();
	int getposporta();
	this->nemicovivo=nemicovivo;
	this->x=x;
	this->y=y;
	this->muoviNemico=muoviNemico;
	this->PROJECTILE_SPEED=1;
	this->shooting[4]=shooting[4];
	this->px[4]=px[4];
	this->py[4]=py[4];
	this->x1=x1;
	this->y1=y1;
	this->monete=monete;
	this->punteggio=punteggio;
	this->vita=0;
    for(int i=0;i<4;i++)
    {
    	this->shooting[i]=false;
    }
    this->posPorta=0;

}
void personaggio::azione(int ch, int nemicoX, int nemicoY,int n, int t, int tr)
{
	trappola=tr;
	teleport=t;
	vita=0;
	//MOVIMENTI DEL PROTAGONISTA
    switch(ch) {
        case 'w':
        case 'W':

        	if (mvinch((y-1),x)== '-') y++;
        	if (mvinch((y-1),x)== '#') y++;
        	if (mvinch((y-1),x) == '$') monete++;
        	if (mvinch((y-1),x) == '+') vita++;
        	if (mvinch((y-1),x) == '%') trappola++;
        	if (mvinch((y-1),x) == 'A') portaindietro=1;
        	else portaindietro=0;
        	if (mvinch((y-1),x) == 'H')
        		{
        		posPorta = 1;
        		x=(rand()%15)+15;
        		y=(rand()%4)+2;
        		}
        	        	 else posPorta = 0 ;
                     muoviNemico = 1 ;
                mvaddch(y, x, ' ');
                y--;
                mvaddch(y, x, '@');




                refresh();

            	 break;




        case 'h':
        case 'H':
        	if(trappola>0 && (mvinch(y+1,x)!='#')){
        	mvaddch(y+1, x, '%');
        	trappola=trappola-1;
        	break;
        	}
        	else break;
        case 's':
        case 'S':
        	if (mvinch((y+1),x)== '-') y--;
        	if (mvinch((y+1),x)== '#') y--;
        	if (mvinch((y+1),x) == '$') monete++;
        	if (mvinch((y+1),x) == '+') vita++;
        	if (mvinch((y+1),x) == '%') trappola++;
        	if (mvinch((y+1),x) == 'A') portaindietro=1;
        	else portaindietro=0;
        	if (mvinch((y+1),x) == 'H'){

        		posPorta = 1;
        		x=(rand()%15)+15;
        		y=(rand()%4)+2;

        	}
        	        	 else posPorta = 0 ;

                mvaddch(y, x, ' ');
                y++;
                mvaddch(y, x, '@');

                refresh();


            	 break;


        case 'a':
        case 'A':
        	if (mvinch(y,(x-1))== '-') x++;
        	if (mvinch(y,(x-1))== '#') x++;
        	if (mvinch(y,(x-1)) == '$') monete++;
        	if (mvinch(y,(x-1)) == '%') trappola++;
            if (mvinch(y,(x-1)) == '+') vita++;
            if (mvinch(y,(x-1)) == 'A') portaindietro=1;
            else portaindietro=0;
        	if (mvinch(y,(x-1)) == 'H')
        		{
        		posPorta = 1;
        		        		x=(rand()%15)+15;
        		        		y=(rand()%4)+2;
        		}
        	        	 else posPorta = 0 ;

                mvaddch(y, x, ' ');
                x--;
                mvaddch(y, x, '@');

                refresh();



            break;
        case 'd':
        case 'D':
        	if (mvinch(y,(x+1))== '-') x--;
        	if (mvinch(y,(x+1))== '#') x--;
        	if (mvinch(y,(x+1)) == '$') monete++;
            if (mvinch(y,(x+1)) == '+') vita++;
            if (mvinch(y,(x+1)) == '%') trappola++;
            if (mvinch(y,(x+1)) == 'A') portaindietro=1;
            else portaindietro=0;
        	if (mvinch(y,(x+1)) == 'H')
        		{
        		posPorta = 1;
        		        		x=(rand()%15)+15;
        		        		y=(rand()%4)+2;
        		}
        	        	 else posPorta = 0 ;

               mvaddch(y, x, ' ');
                x++;
                mvaddch(y, x, '@');

                refresh();



            break;



        case 'o' :
        case 'O' :
        	if (n==1){
            	mvaddch(y,x,' ');
            	x = (rand()%15)+15;
            	y = (rand()%4)+2;
            	mvaddch(y,x,'@');
            	punteggio=0;
            	refresh();
            	break;
        	}
        	if(teleport>0){
        	mvaddch(y,x,' ');
        	x = (rand()%46)+1;
        	y = (rand()%20)+2;
        	mvaddch(y,x,'@');
        	teleport=teleport-1;
        	refresh();
        	break;
        	}
        	break;


//-----------



        case 'i':
        case 'I':	//spara in alto
        	if(!shooting[0] && !shooting[1] && !shooting[2] && !shooting[3])
        	{

        		if((mvinch(y-1,x)!= 'H') &&(mvinch(y-2,x)!= 'H') && (mvinch(y-1,x)!='#') && (mvinch(y-1,x)!='-')){
        	 px[0] = x;
        	            py[0] = y-1; // posiziona il proiettile sopra il personaggio
        	            shooting[0] = true; // inizia il tiro
        	            refresh();

        		}
        		if (mvinch(y-1,x)=='-'){
        			mvprintw(y-1,x," ");
        		}
        	}
        	break;
        case 'k':
        case 'K'://spara in basso
        	if(!shooting[0] && !shooting[1] && !shooting[2] && !shooting[3])
        	{
        		if((mvinch((y+1),x)!= 'H')&&((mvinch((y+2),x)!= 'H') && (mvinch(y+1,x)!= '#'))&& (mvinch(y+1,x)!='-')){
        	px[1]=x;
        	py[1]=y+1; //posizionsa il proiettile sotto il personaggio
        	shooting[1]=true;
        	refresh();
        		}
        		if (mvinch(y+1,x)=='-'){
        			mvprintw(y+1,x," ");
        		}
        	}
        	break;
        case 'j':
        case 'J':
        if(!shooting[0] && !shooting[1] && !shooting[2] && !shooting[3])
        {
        	if((mvinch(y,x-1)!= 'H')&&(mvinch(y,x-2)!= 'H') && (mvinch(y,x-1)!='#')&& (mvinch(y,x-1)!='-')){
        	px[2]=x-1;
        	py[2]=y;
        	shooting[2]=true;
        	refresh();
        	}
    		if (mvinch(y,x-1)=='-'){
    			mvprintw(y,x-1," ");
    		}
        }
        break;
        case 'l':
        case 'L':
        	if (!shooting[0] && !shooting[1] && !shooting[2] && !shooting[3])
        	{
        		if((mvinch(y,x+1)!= 'H')&&(mvinch(y,x+2)!= 'H') &&(mvinch(y,x+1)!='#')&& (mvinch(y,x+1)!='-')){
        		px[3]=x+1;
        		py[3]=y;
        		shooting[3]=true;
        		refresh();
        		}
        		if (mvinch(y,x+1)=='-'){
        			mvprintw(y,x+1," ");
        		}
        	}
        	break;
        default:
        	break;
    }
	  // stampa il proiettile se è stato sparato dal protagonista
	          if (shooting[0]) {
	              if((py[0]+1)!=y) mvprintw(py[0]+1,px[0]," ");
	              mvprintw(py[0], px[0], "*");
	              py[0] -= PROJECTILE_SPEED; // sposta il proiettile verso l'alto
	              if (py[0] < 1) {
	            	  shooting[0] = false; // se il proiettile esce dalla schermata, ferma il tiro
	            	  mvprintw(py[0]+1,px[0], " ");

	              }
                  if(mvinch((py[0]-1),px[0])=='H'){
                	  shooting[0]=false;
                	  mvprintw(py[0]+1,px[0]," ");
                  }
                  if(mvinch((py[0]),px[0])=='-'){
                                     	  shooting[0]=false;
                                     	  mvprintw(py[0],px[0]," ");
                                     	  mvprintw(py[0]+1,px[0]," ");
                                       }

	          }
	          if (shooting[1])
	          {

	        	 if ((py[1]-1)!=y) mvprintw(py[1]-1,px[1], " ");
	        	  mvprintw(py[1],px[1], "*");
	        	  py[1]+= PROJECTILE_SPEED;
	        	  if (py[1]>22) {
	        		  shooting[1]=false;
	        		  mvprintw(py[1]-1,px[1]," ");
	        	  }
                  if(mvinch((py[1]+1),px[1])=='H'){
                	  shooting[1]=false;
                	  mvprintw(py[1]-1,px[1]," ");
                  }
                  if(mvinch((py[1]),px[1])=='-'){
                                     	  shooting[1]=false;
                                     	  mvprintw(py[1],px[1]," ");
                                     	  mvprintw(py[1]-1,px[1]," ");
                                       }

	          }
	          if (shooting[2])
	          {
	        	  if((px[2]+1)!=x)mvprintw(py[2],px[2]+1, " ");
	        	          	  mvprintw(py[2],px[2], "*");
	        	          	  px[2]-= PROJECTILE_SPEED;
	        	          	  if (px[2]<1) {
	        	          		  shooting[2]=false;
	        	          		  mvprintw(py[2],px[2]+1," ");
	        	          	  }
	        	          	 if(mvinch(py[2],(px[2]-1))=='H'){
	        	          	                	  shooting[2]=false;
	        	          	                	  mvprintw(py[2],px[2]+1," ");
	        	          	                  }
	                         if(mvinch((py[2]),px[2])=='-'){
	                                            	  shooting[2]=false;
	                                            	  mvprintw(py[2],px[2]," ");
	                                            	  mvprintw(py[2],px[2]+1," ");

	                         }

	          }
	          if(shooting[3])
	          {
	        	  if ((px[3]-1)!=x)mvprintw(py[3],px[3]-1," ");
	        	  mvprintw(py[3],px[3],"*");
	        	  px[3]+=PROJECTILE_SPEED;
	        	  if(px[3]>48) {
	        		  shooting[3]=false;
	        		  mvprintw(py[3],px[3]-1," ");
	        	  }
	        	  if(mvinch(py[3],px[3]+1)=='H'){
	        	                 	  shooting[3]=false;
	        	                 	  mvprintw(py[3],px[3]-1," ");
	        	                   }
                  if(mvinch((py[3]),px[3])=='-'){
                                     	  shooting[3]=false;
                                     	  mvprintw(py[3],px[3]," ");
                                     	  mvprintw(py[3],px[3]-1," ");
                                       }

	          }


}

int personaggio::getx()
{
return this->x;
}

int personaggio::gety()
{
	return this->y;
}
int personaggio::getpx()
{
	return this->px[0];
}
int personaggio::getpy()
{
	return this->py[0];
}
int personaggio::getpx1()
{
	return this->px[1];
}
int personaggio::getpy1()
{
	return this->py[1];
}
int personaggio::getpx2()
{
	return this->px[2];
}
int personaggio::getpy2()
{
	return this->py[2];
}
int personaggio::getpx3()
{
	return this->px[3];
}
int personaggio::getpy3()
{
	return this->py[3];
}
int personaggio::getx1()
{
	return this->x1;
}
int personaggio::gety1()
{
	return this->y1;
}
bool personaggio::getnemicovivo()
{
	return this->nemicovivo;
}
int personaggio::getmonete()
{
	return this->monete;
}
int personaggio::getposporta()
{
	return posPorta;
}

int personaggio::getvita()
{

	return vita;
}
int personaggio::getpunteggio()
{
	return punteggio;
}
int personaggio::getteleport()
{
	return teleport;
}
int personaggio::gettrappola()
{
	return trappola;
}
int personaggio::getportaindietro()
{
	return portaindietro;
}
