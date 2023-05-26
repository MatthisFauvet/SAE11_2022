#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"

int jeux(void){ /*Ajouter deux args pour le theme et la diff*/
    int i, j, aleatoire;
    int longueur=90;
	int hauteur=80;
    char crocs[50];

    ChargerImageFond("menu/wallpaper/fond.jpg");

    for(j=0;j<4;j++){   
		for(i=0;i<6;i++){
			longueur +=150;
            aleatoire = rand() %12;
			snprintf(crocs,50,"jeu/im_dbd/0%d.png",aleatoire);
			ChargerImage(crocs, longueur, hauteur, 0, 0,150, 208);
		}
		hauteur+= 150;
		longueur = 90;
	}
	

	Touche();
    FermerGraphique();

    return EXIT_SUCCESS;
}