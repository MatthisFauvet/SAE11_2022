#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>
#include <time.h>
int main(void){
	srand(time(NULL));
	InitialiserGraphique();
	CreerFenetre(250,200,1280,720);
	ChargerImageFond("menu/wallpaper/fond.jpg");
	char crocs[50];
	int i;
	int j;
	int longueur=90;
	int hauteur=80;
	int aleatoire;
	for(j=0;j<4;j++){
		for(i=0;i<6;i++){
			longueur +=150;
			aleatoire = rand() %12;
			snprintf(crocs,50,"imdbd/0%d.png",aleatoire);
			ChargerImage(crocs, longueur, hauteur, 0, 0,150, 208);
		}
		hauteur+= 150;
		longueur = 90;
	}
	Touche();
	return EXIT_SUCCESS;
}
		
	