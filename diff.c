#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"
#include "diff.h"

struct renvoie diff(void){	
	ChargerImageFond("menu/wallpaper/fond.jpg");	
	
	ChargerImage("dif/bouton/menu.png",50,50,-0,-0,100,50);

	ChargerImage("dif/bouton/b_facile.png",50,200,-0,-0,300,100);
	ChargerImage("dif/bouton/b_moyenne.png",50,350,-0,-0,300,100);
	ChargerImage("dif/bouton/b_difficle.png",50,500,-0,-0,300,100);

	while (0!=1)
	{
		if(SourisCliquee()== 1){

			/* bouton menu */
			if(_X>=50 && _X<=150){
				if(_Y>=50 && _Y<=100){
					struct renvoie s_retour = {0, "RETOUR"};
					return s_retour;
				}
			} if(_X>=50 && _X<=350){
				if(_Y>=200 && _Y<=300){
					struct renvoie s_facile = {1, "F"};
					return s_facile;
				}
			} if(_X>=50 && _X<=350){
				if(_Y>=350 && _Y<=450){
                    struct renvoie s_moyenne = {2, "M"};
					return s_moyenne;
				}
			} if(_X>=50 && _X<=350){
				if(_Y>=500 && _Y<=600){
                    struct renvoie s_difficile = {3, "D"};
					return s_difficile;
				}
			} 
		}
	}
}