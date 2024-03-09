#include "personaggio.h"
#include "nemico.h"
#include "mappa.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include "dynmap.h"
#include "interfacce.h"
using namespace std;
int main()
{
	int ROWS, COLS;
	getmaxyx(stdscr, ROWS, COLS);
	string scelte[3]={"INIZIA PARTITA","COMANDI","ESCI "};
	string scelteover[2]={"RIPROVA","ESCI"};
	string sceltenegozio[6]={"CONTINUA","COMPRA VITA(5$)","COMPRA TELEPORT(7$)","COMPRA TRAPPOLA(15$)","ESCI"};
	int trappola=0;
	int teleport=0;
	int evidenzia=0;
	int input;
	char vita1[5];
	char monete1[5];
	char punteggio1[5];
	int level=0;
	int x1=0;
	int y1=0;
	int monete=0;
	int x = (rand()%15)+15, y = (rand()%4)+2;
	    int punteggio = 0 ;
	  int nemicoX = 20 , nemicoY = 20 ;
	    int muoviNemico = 0 ;
	    int px[4], py[4];
	    int pnx[4], pny[4];
	    bool shooting[4];
	    bool shootingn[4];
	       bool nemicovivo =true;
	       int max_count=3;
	       int porta=0;
	       int vita=3;
	       int v=8;
	       int mm=10;
	       int n=0;
	       int h=18;
	       int portaindietro=0;
	       Livello* m1=NULL;
	       int livello=0;
	       char map [50] [50];
	       int tipo;
	       int goteleport,gomonete,govita,gotrappola;
	    initscr();
	    noecho();
	    curs_set(FALSE);
	    keypad(stdscr,true);
	    menu(evidenzia,input,scelte);
	    refresh();
	    mappa m(x,y);
	    m.posizionemuri(h);
	    m.disegnamappa();
	    m.disegnamuri();
	    m.disegnaspazi();
	    m.disegnaspazi2();
    	m.disegnacolonnadestra();
	    m.disegnacolonna();
	    m.disegnariga();
	    m.disegnavita(v);
	    m.disegnaMonete(mm);
	    refresh();
	    personaggio p(x,y,muoviNemico,shooting,px,py,x1,y1,nemicovivo,monete,punteggio);
	    int s=1;
	    int t=0;
	    nemico *sentinella = new nemico[s];
	    nemico *ladroRaptor=new nemico[t];

	                      for (int i = 0 ; i < s ; i ++ ) {
	                    	  nemicoX=(rand()%30)+6;
	                    	  nemicoY=(rand()%15)+4;
	                     	 sentinella[i]=nemico (nemicoX,nemicoY,x,y,max_count, px, py,pny, pnx,shootingn,1);
	                      }
	    while (true) {
	    	m.disegnacolonnadestra();
		      m.disegnacolonna();
		      m.disegnariga();
	    	refresh();
	    	sprintf(vita1, "%04d", vita);
	    	sprintf(monete1, "%04d", monete);
	    	sprintf(punteggio1, "%04d", punteggio);
	    	mvprintw(6,55,"LEVEL: %d ",livello);
	    	mvprintw(8, 55, "POINTS: %s",punteggio1);
	    	mvprintw(10,55,"MONEY: %s $", monete1);
	    	mvprintw(12,55,"LIFE: %s", vita1);
	    	if(trappola>0) mvprintw(13,55,"TRAP x%d ",trappola);
	    	else mvprintw(13,55,"           ");
	    	if(teleport>0) mvprintw(14,55,"TELEPORT x%d ",teleport);
	    	else mvprintw(14,55,"                       ");
if (vita<0) vita=0;
if (vita==0) {

initscr();
    while(1)
    {
    for(int i=0;i<2;i++)
    {
    	if(i==evidenzia) attron(A_REVERSE);
    	mvprintw(i+1,55,scelteover[i].c_str());
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
    	if(evidenzia==2) evidenzia=1;
    	break;
    default: break;
    }
   vita=3;
    	endwin();
        if (input==10 && evidenzia==0) {
            for (int i = 0; i <= 6; i++) {
                mvhline(i, 52, ' ', 14);
            }

            refresh();

      	  m.cambiamappa(mm,v,h);
      	  for ( int i = 0 ; i <s ; i ++ ) {
      	  	  nemicoX=(rand()%30)+6;
      		  nemicoY=(rand()%15)+4;
   sentinella[i]=nemico (nemicoX,nemicoY,x,y,max_count,px, py,pny, pnx,shootingn,1);
   }
	        	  for ( int i = 0 ; i <t ; i ++ ) {
	        	  	  nemicoX=(rand()%30)+6;
	        		  nemicoY=(rand()%15)+4;
	        	  	  nemicoX=(rand()%30)+6;
    	        		  nemicoY=(rand()%15)+4;
    	        		  tipo=(rand()%3)+1;
    	        		  if (tipo==1) tipo=2;
	     ladroRaptor[i]=nemico (nemicoX,nemicoY,x,y,max_count, px, py,pny, pnx,shootingn,tipo);
	     }

      	  p.azione('o',nemicoX,nemicoY,1,teleport,trappola);
      	  if(livello>0){
      	p.monete=gomonete;
      	monete=gomonete;
      	punteggio=p.getpunteggio();
      	teleport=goteleport;
      	trappola=gotrappola;
      	p.vita=govita;
      	vita=govita;
      	  }
      	  else {
      		  p.monete=0;
      		  p.vita=3;
      		  p.punteggio=0;
      	  }
        refresh();
    	break;

    }
    if (input==10 && evidenzia==1) {
    	endwin();
    	exit(0);
    }
    }

}

sprintf(vita1, "%04d", vita);
sprintf(monete1, "%04d", monete);
sprintf(punteggio1, "%04d", punteggio);
mvprintw(6,55,"LEVEL: %d ",livello);
mvprintw(8, 55, "POINTS: %s",punteggio1);
mvprintw(10,55,"MONEY: %s $", monete1);
mvprintw(12,55,"LIFE: %s", vita1);
if(trappola>0) mvprintw(13,55,"TRAP x%d ",trappola);
else mvprintw(13,55,"           ");
if(teleport>0) mvprintw(14,55,"TELEPORT x%d ",teleport);
else mvprintw(14,55,"                       ");
            refresh();
	        int ch = getch();
	        n=0;
	        p.azione(ch, nemicoX, nemicoY,n,teleport,trappola);
	        n=0;
	        x=p.getx();
	        y=p.gety();
	        trappola=p.gettrappola();
	        teleport=p.getteleport();
	        monete=p.getmonete();
	        vita=vita+p.getvita();
	        portaindietro=p.getportaindietro();
	        px[0]=p.getpx();
	        py[0]=p.getpy();
	        px[1]=p.getpx1();
	        py[1]=p.getpy1();
	        px[2]=p.getpx2();
	        py[2]=p.getpy2();
	        px[3]=p.getpx3();
	        py[3]=p.getpy3();
	        refresh();

	        for (int i=0;i<s;i++)
	        sentinella[i].azione(x, y, px, py);
	        refresh();
	        refresh();
	        for (int i=0;i<t;i++)
	        ladroRaptor[i].azione(x, y, px, py);
	       for(int i=0;i<s;i++)
	      punteggio=punteggio+sentinella[i].getpunteggio();
	       for(int i=0;i<t;i++)
	       punteggio=punteggio+ladroRaptor[i].getpunteggio();
	       for(int i=0;i<s;i++)
	    	   vita=vita+sentinella[i].getvita();
	       for(int i=0;i<t;i++)
	    	   vita=vita+ladroRaptor[i].getvita();
	       bool door = false;
	               door = drawDoor(sentinella, s);
	             if (t>0 && door) door = drawDoor(ladroRaptor, t);
	               if (door) {
	                         m.disegnaporta(21, 43);
	                        if (livello!=0) m.disegnaportaindietro();
	                     }
	    	if ( portaindietro == 1 ) {
	    		copy_screen(map,50,50);
	    		  m1 = addToTail(m1,livello,map);
	              livello--;
	              Livello* m2=NULL;
	    m2 = cercaLivello(m1,livello);
	              draw_map(m2->map,50,50,x,y);
	    		portaindietro = 0 ;
	    		p.azione('o',nemicoX,nemicoY,1,teleport,trappola);
	    	}
	        porta = p.getposporta();
	        	          if ( porta == 1){
	        	        	  goteleport=teleport;
	        	        	  gotrappola=trappola;
	        	        	  govita=vita;
	        	        	  gomonete=monete;
	        	        	  p.azione('w', nemicoX, nemicoY,n,teleport,trappola); //EVITA CHE NON MUOVENDOSI E PREMENDO TASTI A CASO, FACCIA LIVELLO++
	        	        	  copy_screen(map,50,50);
	        	        	  m1=addToTail(m1,livello,map);
	        	        	  livello++;
	        	              Livello* m2 = NULL;
	        	              m2 = cercaLivello(m1, livello);
	        	              if (m2) {
	        	                  draw_map(m2->map, 50, 50, x, y);
	        	              } else {

	        	        	  level=level+1;
	        	        	  if(level%3==0)
	        	        		  h=h - 1;
	        	        	  if (level%2==0 && mm>=3)
	        	        	  mm=mm - 1;
	        	        	  if(level%5==0)
	        	        	  v=v - 1;
	        	        	 if(level%3==0)
	        	        	  s = s + 1 ;
	        	        	  if(level%1==0)
	        	        	    t=t + 1;
	        	        	  m.cambiamappa(mm,v,h);
	        	        	  for ( int i = 0 ; i <s ; i ++ ) {
	        	        	  	  nemicoX=(rand()%30)+6;
	        	        		  nemicoY=(rand()%15)+4;
	        	     sentinella[i]=nemico (nemicoX,nemicoY,x,y,max_count,px, py,pny, pnx,shootingn,1);
	        	     }
		        	        	  for ( int i = 0 ; i <t ; i ++ ) {

		        	        	  	  nemicoX=(rand()%30)+6;
		        	        		  nemicoY=(rand()%15)+4;
		        	        		  tipo=(rand()%3)+1;
		        	        		  if (tipo==1) tipo=2;
		        	     ladroRaptor[i]=nemico (nemicoX,nemicoY,x,y, max_count,px, py,pny, pnx,shootingn,tipo);
		        	     }
	        	        	  porta=0;

	        	          	  if(level%3==0)
	        	    	        	  {
	        	    	        		initscr();
	        	    	        		    while(1)
	        	    	        		    {
	        	    	        		    for(int i=0;i<5;i++)
	        	    	        		    {
	        	    	        		    	if(i==evidenzia) attron(A_REVERSE);
	        	    	        		    	mvprintw(i+18,55,sceltenegozio[i].c_str());
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
	        	    	        		    	if(evidenzia==5) evidenzia=4;
	        	    	        		    	break;
	        	    	        		    default: break;
	        	    	        		    }

	        	    	        		        if (input==10 && evidenzia==0) {
	        	    	        		            for (int i = 15; i <= 25; i++) {
	        	    	        		                mvhline(i, 52, ' ', 25);
	        	    	        		            }

	        	    	        		            endwin();
	        	    	        		            refresh();
	        	    	        		            p.azione(ch, nemicoX, nemicoY,0,teleport,trappola);

	        	    	        		            break;
	        	    	        		        }
	        	    	        		        if (input==10 && evidenzia==1)
	        	    	        		        {
	        	    	        		            for (int i = 15; i <= 25; i++) {
	        	    	        		                mvhline(i, 52, ' ', 25);
	        	    	        		            }
	        	    	        		            if (monete>=5){p.monete=monete-5;
	        	    	        		            monete=monete-5;
	        	    	        		            vita=vita+1;
	        	    	        		            }
	        	    	        			    	sprintf(vita1, "%04d", vita);
	        	    	        			    	sprintf(monete1, "%04d", monete);
	        	    	        			    	sprintf(punteggio1, "%04d", punteggio);
	        	    	        			    	mvprintw(8, 55, "POINTS: %s",punteggio1);
	        	    	        			    	mvprintw(10,55,"MONEY: %s $", monete1);
	        	    	        			    	mvprintw(12,55,"LIFE: %s", vita1);

	        	    	        		        }
	        	    	        		        if (input==10 && evidenzia==2)
	        	    	        		        {
	        	    	        		            for (int i = 15; i <= 25; i++) {
	        	    	        		                mvhline(i, 52, ' ', 25);
	        	    	        		            }
	        	    	        		            if (monete>=7){p.monete=monete-7;
	        	    	        		            monete=monete-7;
	        	    	        		           teleport=teleport+1;
	        	    	        			    	sprintf(vita1, "%04d", vita);
	        	    	        			    	sprintf(monete1, "%04d", monete);
	        	    	        			    	sprintf(punteggio1, "%04d", punteggio);
	        	    	        			    	mvprintw(8, 55, "POINTS: %s",punteggio1);
	        	    	        			    	mvprintw(10,55,"MONEY: %s $", monete1);
	        	    	        			    	mvprintw(12,55,"LIFE: %s", vita1);
	        	    	        		        }
	        	    	        		        }
	        	    	        		        if(input==10 && evidenzia==3)
	        	    	        		        {
	        	    	        		            for (int i = 15; i <= 25; i++) {
	        	    	        		                mvhline(i, 52, ' ', 25);
	        	    	        		            }
	        	    	        		            if(monete>=15 && trappola<=2){p.monete=monete-15;
	        	    	        		            monete=monete-15;
	        	    	        		            trappola=trappola+1;
	        	    	        			    	sprintf(vita1, "%04d", vita);
	        	    	        			    	sprintf(monete1, "%04d", monete);
	        	    	        			    	sprintf(punteggio1, "%04d", punteggio);
	        	    	        			    	mvprintw(8, 55, "POINTS: %s",punteggio1);
	        	    	        			    	mvprintw(10,55,"MONEY: %s $", monete1);
	        	    	        			    	mvprintw(12,55,"LIFE: %s", vita1);

	        	    	        		            }
	        	    	        		        }

	        	    	        		        if (input==10 && evidenzia==4) {
	        	    	        		        	endwin();
	        	    	        		        	exit(0);
	        	    	        		        }

	        	    	        		    }

	        	    	        	  }
	        	        	  goteleport=teleport;
	        	        	  gotrappola=trappola;
	        	        	  govita=vita;
	        	        	  gomonete=monete;
	        	        	  refresh();
	        	          }
	        	          }

	    }
	    endwin();
	    return 0;
	    }
