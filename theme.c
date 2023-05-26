#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"
#include "theme.h"

struct renvoie theme(void){
    ChargerImageFond("theme/wallpaper/fond.jpg");
	ChargerImage("theme/texte.png",250,70,-0,-0,750,56);
	
	ChargerImage("theme/sao.png",200,250,-0,-0,1200,1600);
	ChargerImage("theme/dbd.png",800,250,-0,-0,1200,1600);
	
	while (0!=1)
	{
		if(SourisCliquee()== 1){

			/* Bouton choix SAO */
			if(_X>=200 && _X<=480){
				if (_Y>=250 && _Y<=1850){
					struct renvoie struct_sao = {1, "S"};
					return struct_sao;
				}
			}
			/* Bouton choix DBD*/
			else if(_X>=800 && _X<=1094){
				if (_Y>=250 && _Y<=1850){
					struct renvoie struct_dbd = {1, "D"};
					return struct_dbd;
				}
			}
		}
	}
}