#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"
#include "start.h"

struct renvoie start(void){	
    ChargerImageFond("menu/wallpaper/fond.jpg");
	
    ChargerImage("menu/start.png",500,75,-0,-0,317,163);
    ChargerImage("menu/engrenage.png",1180,0,-0,-0,100,100);
	
    while(0!=1){
		if(SourisCliquee()== 1){

			/* Bouton start */
			if(_X<=817 && _X>=500){
				if (_Y>=75 && _Y<=238){
                    struct renvoie s_start = {1, "START"};
					return s_start;
                }
            }
		
			/* Bouton d'engrennages */
			if (_X>=1180 && _X<=1280){
				if(_Y>=0 && _Y<=100){
					struct renvoie s_options = {2, "OPTIONS"};
					return s_options;
				}
			}
		}
    }
}