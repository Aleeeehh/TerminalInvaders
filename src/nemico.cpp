/*
 * nemico.cpp
 *
 *  Created on: 27 gen 2023
 *      Author: alessioprato
 */
#include "nemico.h"
	nemico::nemico(int nemicoX, int nemicoY,int x, int y,int max_count,int px[4], int py[4], int pny[4], int pnx[4], bool shootingn[4],
			  int tipo)
	{
		void azione(int x,int y, int px[4], int py[4]);
		int getpunteggio();
		void morte();
		void vivo();
		int getnemicoX();
		int getnemicoY();
		bool getsh();
		bool getsh1();
		bool getsh2();
		bool getsh3();
		int getvita();
		this->nemicovivo=true;
		this->nemicospara=false;
		this->nemicoX=nemicoX;
		this->nemicoY=nemicoY;
		this->x=x;
		this->y=y;
		this->contatore_movimento=0;
	    this->max_count=max_count;
		this->punteggio=0;
		this->px[4]=px[4];
		this->py[4]=py[4];
		this->pny[4]=pny[4];
		this->pnx[4]=pnx[4];
		this->contatore_sparo=0;
	    this->max_sparo=3;
		this->shootingn[4]=shootingn[4];
		this->PROJECTILE_SPEED=1;
		this->contatore_sinistro=0;
		this->tipo=tipo;
		this->vita=0;
		this->p=false;


		for(int i=0;i<4;i++)
			shootingn[i]=false;

	}

	nemico::nemico(){

		}

void nemico::vivo()
{
	nemicovivo=true;
}
	void nemico::morte()
	{
		nemicovivo=false;
	}
	void nemico::azione(int x, int y, int px[4], int py[4])
	{
        if(mvinch((pny[0]-1),pnx[0])=='%'){
                        	  shootingn[0]=false;
                        	  mvprintw(pny[0]+1,pnx[0]," ");
                          }
        if(mvinch((pny[1]+1),pnx[1])=='%'){
      	  shootingn[1]=false;
      	  mvprintw(pny[1]-1,pnx[1]," ");
        }
   	 if(mvinch(pny[2],(pnx[2]-1))=='%'){
        	          	                	  shootingn[2]=false;
        	          	                	  mvprintw(pny[2],pnx[2]+1," ");
        	          	                  }
	  if(mvinch(pny[3],pnx[3]+1)=='%'){
	                 	  shootingn[3]=false;
	                 	  mvprintw(pny[3],pnx[3]-1," ");
	                   }

		vita=0;
		punteggio=0;
		if(tipo==2) max_count=1;
        if (nemicovivo)
        {


        	 if(contatore_movimento>=max_count) //nemico rallentato
        	 {


        	 if (tipo==2 || tipo==1 || (tipo==3 && p==true) ){
        		 mvaddch(nemicoY,nemicoX,' ');
        	 if (nemicoY > y ) {
        		 if((mvinch(nemicoY-1,nemicoX)!='H')&&(mvinch(nemicoY-1,nemicoX)!='-')){
        			 if (( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '(' ) && ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != 'y' )
        					&& ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '&' ) && ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '%' ) )
        		 nemicoY--;
        		 }
        		 else {
        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        			 nemicoX++;
        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        			 nemicoY--;
        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        			 nemicoY--;

        		 }
        		              // fa un movimento alla volta (non più in diagonale)
        	 }
        	 else if(nemicoY< y) {

        		 if((mvinch(nemicoY+1,nemicoX)!='H')&&(mvinch(nemicoY+1,nemicoX)!='-')){
        			 if ((mvinch ( ( nemicoY + 1 ) , nemicoX ) != '(' )&& (mvinch ( ( nemicoY + 1 ) , nemicoX ) != 'y' ) &&
        					 (mvinch ( ( nemicoY + 1 ) , nemicoX ) != '&' ) && (mvinch ( ( nemicoY + 1 ) , nemicoX ) != '%' )  )
        		 nemicoY++;
        		 }
        		 else
        		 {
        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        			 nemicoX--;
        			 if ( mvinch ( nemicoY+1,nemicoX) != '%' )
        			 nemicoY++;
        			 if ( mvinch ( nemicoY+1,nemicoX) != '%' )
        			 nemicoY++;
        		 }
        	 }
        	 if(nemicoX > x ){
        		 if((mvinch(nemicoY,nemicoX-1)!='H')&&(mvinch(nemicoY,nemicoX-1)!='-')){
        			 if (( mvinch ( nemicoY ,nemicoX - 1 ) != '(' ) &&( mvinch ( nemicoY ,nemicoX - 1 ) != 'y' )&&
        					 ( mvinch ( nemicoY ,nemicoX - 1 ) != '&' ) && ( mvinch ( nemicoY ,nemicoX - 1 ) != '%' ))
        		 nemicoX--;
        		 }
        		 else {
        			 if ( mvinch ( nemicoY+1 ,nemicoX) != '%' )
        			 nemicoY++;
        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        			 nemicoX--;
        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        			 nemicoX--;
        		 }
        	 }
        	 else if (nemicoX < x) {
        		 if((mvinch(nemicoY,nemicoX+1)!='H')&&(mvinch(nemicoY,nemicoX+1)!='-')){
        			 if (( mvinch (  nemicoY , nemicoX+1 ) != '(' ) &&( mvinch (  nemicoY , nemicoX+1 ) != 'y' ) &&
        					 ( mvinch (  nemicoY , nemicoX+1 ) != '&' ) && ( mvinch (  nemicoY , nemicoX+1 ) != '%' ))
        		 nemicoX++;
        		 }
        		 else {
        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        			 nemicoY--;
        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        			 nemicoX++;
        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        			 nemicoX++;
        		 }
        	 }
        	 contatore_movimento=0;
        	 }
        	 if (tipo==3 && p==false){
        			int distanzaMinima = 1000;
        			int monetaX=-1;
        			int monetaY=-1;
        			mvaddch(nemicoY,nemicoX,' ');
        			for (int y = 0; y < 22; y++) {
        			  for (int x = 0; x < 48; x++) {
        			    if ((mvinch(y, x) == '$') ||(mvinch(y, x) == '+'))   {
        			      int distanza = abs(nemicoY - y) + abs(nemicoX - x);
        			      if (distanza < distanzaMinima) {
        			        distanzaMinima = distanza;
        			        monetaX = x;
        			        monetaY = y;
        			      }
        			    }
        			  }
        			}
        			if (monetaX==-1 && monetaY==-1) {
        				p=true;
        				max_count=1;
        			}
        			if (monetaX != -1 && monetaY != -1) {
        			  if (nemicoY > monetaY) {
        	        		 if((mvinch(nemicoY-1,nemicoX)!='H')&&(mvinch(nemicoY-1,nemicoX)!='-')){
        	        			 if (( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '(' ) && ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != 'y' ) &&
        	        					 ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '&' ) && ( mvinch ( ( nemicoY - 1 ) , nemicoX ) != '%' ))
        	        		 nemicoY--;
        	        		 }
        	        		 else {
        	        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        	        			 nemicoX++;
        	        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        	        			 nemicoY--;
        	        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        	        			 nemicoY--;

        	        		 }
        			    contatore_movimento=0;
        			  } else if (nemicoY < monetaY) {

        	        		 if((mvinch(nemicoY+1,nemicoX)!='H')&&(mvinch(nemicoY+1,nemicoX)!='-')){
        	        			 if ((mvinch ( ( nemicoY + 1 ) , nemicoX ) != '(' )&& (mvinch ( ( nemicoY + 1 ) , nemicoX ) != 'y' )
        	        					 && (mvinch ( ( nemicoY + 1 ) , nemicoX ) != '&' ) && (mvinch ( ( nemicoY + 1 ) , nemicoX ) != '%' ))
        	        		 nemicoY++;
        	        		 }
        	        		 else
        	        		 {
        	        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        	        			 nemicoX--;
        	        			 if ( mvinch ( nemicoY+1,nemicoX) != '%' )
        	        			 nemicoY++;
        	        			 if ( mvinch ( nemicoY+1,nemicoX) != '%' )
        	        			 nemicoY++;
        	        		 }
        	        	 }
        			    contatore_movimento=0;
        			  }
        			  if (nemicoX > monetaX) {
        		       		 if((mvinch(nemicoY,nemicoX-1)!='H')&&(mvinch(nemicoY,nemicoX-1)!='-')){
        		        			 if (( mvinch ( nemicoY ,nemicoX - 1 ) != '(' ) &&( mvinch ( nemicoY ,nemicoX - 1 ) != 'y' )
        		        					 && ( mvinch ( nemicoY ,nemicoX - 1 ) != '&' ) && ( mvinch ( nemicoY ,nemicoX - 1 ) != '%' ))
        		        		 nemicoX--;
        		        		 }
        		        		 else {
        		        			 if ( mvinch ( nemicoY+1,nemicoX) != '%' )
        		        			 nemicoY++;
        		        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        		        			 nemicoX--;
        		        			 if ( mvinch ( nemicoY,nemicoX-1) != '%' )
        		        			 nemicoX--;
        		        		 }
        			    contatore_movimento=0;
        			  } else if (nemicoX < monetaX) {
        	        		 if((mvinch(nemicoY,nemicoX+1)!='H')&&(mvinch(nemicoY,nemicoX+1)!='-')){
        	        			 if (( mvinch (  nemicoY , nemicoX+1 ) != '(' ) &&( mvinch (  nemicoY , nemicoX+1 ) != 'y' )
        	        					 && ( mvinch (  nemicoY , nemicoX+1 ) != '&' ) && ( mvinch (  nemicoY , nemicoX+1 ) != '%' ))
        	        		 nemicoX++;
        	        		 }
        	        		 else {
        	        			 if ( mvinch ( nemicoY-1,nemicoX) != '%' )
        	        			 nemicoY--;
        	        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        	        			 nemicoX++;
        	        			 if ( mvinch ( nemicoY,nemicoX+1) != '%' )
        	        			 nemicoX++;
        	        		 }
        			    contatore_movimento=0;
        			  }

        			}
        	 if (tipo==1)mvaddch(nemicoY,nemicoX,'(');
        	 if(tipo==2)mvaddch(nemicoY,nemicoX,'y');
        	 if(tipo==3)mvaddch(nemicoY,nemicoX,'&');


        	 }
        	 else contatore_movimento++;





          if (nemicoX == x && nemicoY == y) {
        	  vita--;
          }

          if ((nemicoX==px[0] && nemicoY == py[0]) || (nemicoX==px[0] && nemicoY==py[0]+1)|| (mvinch(nemicoY+1,nemicoX)=='%')) //se colpito, muore e punteggio++
         {
        	  nemicovivo=false;
        	  punteggio++;
         }
          if ((nemicoX==px[1] && nemicoY == py[1]) || (nemicoX==px[1] && nemicoY==py[1]-1) || (mvinch(nemicoY-1,nemicoX)=='%'))
         {
        	  nemicovivo=false;
        	  punteggio++;
         }
          if ((nemicoX==px[2] && nemicoY == py[2]) || (nemicoX==px[2]+1 && nemicoY==py[2]) || (mvinch(nemicoY,nemicoX+1)=='%'))
         {
        	  nemicovivo=false;
        	  punteggio++;
         }
          if ((nemicoX==px[3] && nemicoY == py[3]) || (nemicoX==px[2]-1 && nemicoY==py[2])|| (mvinch(nemicoY,nemicoX-1)=='%'))
         {
        	  nemicovivo=false;
        	  punteggio++;
         }

          if (!nemicospara)
          {
        	  contatore_sparo++;
        	  contatore_sinistro++;
          }
if((contatore_sparo>=max_sparo) && (nemicospara==false))
        	  nemicospara=true;



          if (nemicospara)
          {
        	  contatore_sparo=0;
        	  contatore_sinistro++;


        	  //spara a sinistra

        	  }
         // if(contatore_sinistro>=25){
        	//  mvprintw(pny[2],pnx[2]+1," ");
        	 if (nemicoX>x && nemicoY==y && (mvinch(pny[2],pnx[2]+1)!='*' && contatore_sinistro>8))
        	  {
        		  contatore_sinistro=0;
        		  if((mvinch(nemicoY,nemicoX-1)!= 'H') &&(mvinch(nemicoY,nemicoX-2)!= 'H') && (mvinch(nemicoY,nemicoX-1)!='#') &&
        				  (mvinch(nemicoY,nemicoX)=='(') && (mvinch(nemicoY,nemicoX-1)!= '%') && (mvinch(nemicoY,nemicoX-2)!= '%'))
        		  {
        	  pnx[2]=nemicoX-1;
        	  pny[2]=nemicoY;
        	  shootingn[2]=true;


        	   }
        	  }
        	  //spara a destra
        	  if (nemicoX< x && nemicoY==y&& !shootingn[3] )
        	  {
        		  if((mvinch(nemicoY,nemicoX+1)!= 'H') &&(mvinch(nemicoY,nemicoX+2)!= 'H') && (mvinch(nemicoY,nemicoX+1)!='#')
        				  && (mvinch(nemicoY,nemicoX)=='(') && (mvinch(nemicoY,nemicoX+1)!= '%') && (mvinch(nemicoY,nemicoX+2)!= '%')){

        		  pnx[3]=nemicoX+1;
        		  pny[3]=nemicoY;
        		  shootingn[3]=true;
        		  }
        	  }
              //spara in alto
        	  if(nemicoY > y && nemicoX==x && !shootingn[0])
        	  {
        		  if((mvinch(nemicoY-1,nemicoX)!= 'H') &&(mvinch(nemicoY-2,nemicoX)!= 'H') && (mvinch(nemicoY-1,nemicoX)!='#')
        				  && (mvinch(nemicoY,nemicoX)=='(') && (mvinch(nemicoY-1,nemicoX)!= '%') && (mvinch(nemicoY-2,nemicoX)!= '%')){

        		  pny[0]=nemicoY-1;
        		  pnx[0]=nemicoX;
        	  shootingn[0]=true;
        		  }

        	  }
        	  //spara in basso
        	  if (nemicoY < y && nemicoX==x && !shootingn[1])
        	  {
        		  if((mvinch(nemicoY+1,nemicoX)!= 'H') &&(mvinch(nemicoY+2,nemicoX)!= 'H') && (mvinch(nemicoY+1,nemicoX)!='#')
        				  && (mvinch(nemicoY,nemicoX)=='(') && (mvinch(nemicoY+1,nemicoX)!='%') && (mvinch(nemicoY+2,nemicoX)!= '%')){
        		  pny[1]=nemicoY+1;
        		  pnx[1]=nemicoX;
        		  shootingn[1]=true;
        	  }



    	  nemicospara=false;

        }
        }



          //shooting del nemico;
          if (shootingn[0]) {
        	  /*
        	  if(shootingn[2]==true) {
        		  shootingn[2]=false;
        		  mvprintw(pny[2],pnx[2]+1," ");
        	  }*/

                      if((pny[0]+1)!=nemicoY) mvprintw(pny[0]+1,pnx[0]," ");
                       mvprintw(pny[0], pnx[0], "*");
                        pny[0] -= PROJECTILE_SPEED; // sposta il proiettile verso l'alto
                        if (pny[0] < 1)
                        	{
                        	shootingn[0] = false;
                        	mvprintw(pny[0]+1,pnx[0]," ");// se il proiettile esce dalla schermata, ferma il tiro
                        	}
                        if(mvinch((pny[0]-1),pnx[0])=='H'){
                                        	  shootingn[0]=false;
                                        	  mvprintw(pny[0]+1,pnx[0]," ");
                                          }
                        if(mvinch((pny[0]-1),pnx[0])=='%'){
                                        	  shootingn[0]=false;
                                        	  mvprintw(pny[0]+1,pnx[0]," ");
                                          }
                        if(mvinch((pny[0]),pnx[0])=='-'){
                                        	  shootingn[0]=false;
                                        	  mvprintw(pny[0],pnx[0]," ");
                                        	  mvprintw(pny[0]+1,pnx[0]," ");
                                          }
                    	  if((pnx[0]==x && pny[0]==y) || (pnx[0]==x && pny[0]+1==y))
                    	  {
                    		  vita--;
                    	  shootingn[0]=false;
                    	  mvprintw(pny[0]+1,pnx[0]," ");
                    	  }
          }

                    if (shootingn[1])
                    {
                    	if(pny[1]>4){
                      if((pny[1]-1)!=nemicoY) mvprintw(pny[1]-1,pnx[1], " ");
                      (mvprintw(pny[1],pnx[1], "*"));
                  	 pny[1]+= PROJECTILE_SPEED;
                  	  if (pny[1]>22){
                  		  shootingn[1]=false;
                  		  mvprintw(pny[1]-1,pnx[1]," ");
                  	  }
                      if(mvinch((pny[1]+1),pnx[1])=='H'){
                    	  shootingn[1]=false;
                    	  mvprintw(pny[1]-1,pnx[1]," ");
                      }
                      if(mvinch((pny[1]+1),pnx[1])=='%'){
                    	  shootingn[1]=false;
                    	  mvprintw(pny[1]-1,pnx[1]," ");
                      }
                      if(mvinch((pny[1]),pnx[1])=='-'){
                                      	  shootingn[1]=false;
                                      	  mvprintw(pny[1],pnx[1]," ");
                                      	  mvprintw(pny[1]-1,pnx[1]," ");
                                        }

                  	  if((pnx[1]==x && pny[1]==y) || (pnx[1]==x && pny[1]-1==y))
                  	  {
                  	  		  vita--;
                  	  		  shootingn[1]=false;
                  	  		mvprintw(pny[1]-1,pnx[1]," ");
                  	  }
                    	}
                    	else shootingn[1]=false;

                   }
                    if (shootingn[2])
                    {
                    	if((pnx[2]+1)!=nemicoX)  mvprintw(pny[2],pnx[2]+1, " ");
                    	(mvprintw(pny[2],pnx[2], "*"));
                  	  pnx[2]-= PROJECTILE_SPEED;
                  	  if (pnx[2]<1){
                  		  shootingn[2]=false;
                  		  mvprintw(pny[2],pnx[2]+1," ");
                  	  }

                    	 if(mvinch(pny[2],(pnx[2]-1))=='H'){
             	        	          	                	  shootingn[2]=false;
             	        	          	                	  mvprintw(pny[2],pnx[2]+1," ");
             	        	          	                  }
                    	 if(mvinch(pny[2],(pnx[2]-1))=='%'){
             	        	          	                	  shootingn[2]=false;
             	        	          	                	  mvprintw(pny[2],pnx[2]+1," ");
             	        	          	                  }
                         if(mvinch((pny[2]),pnx[2])=='-'){
                                         	  shootingn[2]=false;
                                         	  mvprintw(pny[2],pnx[2]," ");
                                         	  mvprintw(pny[2],pnx[2]+1," ");
                                           }
                  	  if((pnx[2]==x && pny[2]==y) || (pnx[2]+1==x && pny[2]==y))
                  	  {
                  	  		  vita--;
                  	  		  shootingn[2]=false;
                  	  		mvprintw(pny[2],pnx[2]+1," ");
                  	  }



                }

                    if(shootingn[3])
                    {

                    	if (pnx[3]>4){
                    	if((pnx[3]-1)!=nemicoX) mvprintw(pny[3],pnx[3]-1," ");
                    	if(mvinch(nemicoY,nemicoX+1)!='*' && mvinch(nemicoY,nemicoX+2)!='*' ) (mvprintw(pny[3],pnx[3], "*"));
                  	  pnx[3]+=PROJECTILE_SPEED;
                  	  if(pnx[3]>48){
                  		  shootingn[3]=false;
                  	      mvprintw(pny[3],pnx[3]-1," ");
                  	  }
    	        	  if(mvinch(pny[3],pnx[3]+1)=='H'){
    	        	                 	  shootingn[3]=false;
    	        	                 	  mvprintw(pny[3],pnx[3]-1," ");
    	        	                   }
    	        	  if(mvinch(pny[3],pnx[3]+1)=='%'){
    	        	                 	  shootingn[3]=false;
    	        	                 	  mvprintw(pny[3],pnx[3]-1," ");
    	        	                   }
                      if(mvinch((pny[3]),pnx[3])=='-'){
                                      	  shootingn[3]=false;
                                      	  mvprintw(pny[3],pnx[3]," ");
                                      	  mvprintw(pny[3],pnx[3]-1," ");
                                        }
                  	  if((pnx[3]==x && pny[3]==y) || (pnx[3]-1==x && pny[3]==y))
                  	  {
                  	  		  vita--;
                  	  		mvprintw(pny[3],pnx[3]-1," ");
                  	  	 shootingn[3]=false;

                    }


          }
                    	else shootingn[3]=false;

	     }
	}



	int nemico::getpunteggio()
	{
		return this->punteggio;
	}
	int nemico::getnemicoX()
	{
		return this->nemicoX;
	}
	int nemico::getnemicoY()
	{
		return this->nemicoY;
	}
	int nemico::getvita()
	{
		return this->vita;
	}

