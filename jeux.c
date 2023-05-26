#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>
#include <time.h>
#include <unistd.h>

#include "main.h"
#include "menu.h"
#include "jeux.h"

struct renvoie jeux(struct renvoie *theme, struct renvoie *difficulte){ /*Ajouter deux args pour le theme et la diff*/
	/* Mise en place de toutes la variables */
    int i, j, Acc, Lolea, Lalea, taille_x, taille_y, pos_X, pos_Y, loc_tab_x, loc_tab_y;

	int distMnX, distMxX, distMnY, distMxY;
	int score, scoreMax, cvalable = True;
	int check = 1, img_ne=0;
	int longueur=90;
	int hauteur=80;
	int tableau[6][4];

	/* VAriables chrono */
	unsigned long var;
	unsigned long var2;

	var= Microsecondes();
	unsigned long cycle = 1000000;
	char str[70];
	couleur coo;
	couleur coul;
	

	/*Variable de Save */
	int Save_ltab_x, Save_ltab_y, Save_pos_X, Save_pos_Y;
	char save[50];

	/*Variable réservé à la reconnaissance di'image*/
	int find_pict[12];
	for(i=0; i<12; i++){
		find_pict[i] = -1;
	}

	/*Renvoie*/
	struct renvoie reussi = {0, "FIN"};


	/*Affectations des plus grande valeurs possible*/
	taille_x=6;
	taille_y=4;

	/* Mise a jour des variables en fonctions de la difficulté que le joueur a choisit */
    if (difficulte->type_renvoi != 3){
    	longueur += 150;
    	taille_x = 4;
    	if(difficulte->type_renvoi == 1){
    		taille_y = 3;
			scoreMax=6;
    	}
    	else{
    		taille_y = 4;
			scoreMax=8;
    	}
    } else{
		scoreMax=12;
	}

	Acc = ((taille_x*taille_y)/2)-1;
	pos_X=longueur;
	pos_Y=hauteur;

    srand(time(NULL));
    /* Chargement des images de fond */
    ChargerImageFond("menu/wallpaper/fond.jpg");
	ChargerImage("jeu/planche.png", 50,-350,-0,-0,1298,1214);

	/* On remplit toutes les cases qui ne seront pas utilisée */ 
	for(i=0; i<taille_y; i++){
		for(j=0;j<7; j++){
			tableau[j][i] = -1;
		}
	}
	/* Permet de vérifier si une image est déja présente dans le tableau pour éviter les triplettes */
    for(j=0; j<(taille_x*taille_y)/2; j++){ 
		for(i=0;i<2;i++){
			Lolea = rand() %taille_x;
			Lalea = rand() %taille_y;
			if(tableau[Lolea][Lalea] == -1){
				tableau[Lolea][Lalea] = Acc;
			}
			else{
				i-=1;
			}
		}
	Acc -= 1;
	}

	/*Afficher les diférentes images de dos sur la grille (interface graphique)*/
    for(j=0;j<taille_y;j++){ 
		for(i=0;i<taille_x;i++){
			longueur +=150;
			ChargerImage("jeu/inverse.png", longueur, hauteur, -0, -0, 100, 139);
		}
		hauteur+= 150;
		if(difficulte->type_renvoi != 3){
			longueur = 90+150;
		}
		else{
			longueur = 90;
		}
	}

	/* ================================================================================================================================================ */
	/* BOUCLE INFINI */
	/* ================================================================================================================================================ */

	coo=CouleurParNom("blue");
	coul=CouleurParNom("black");

	while(0!=1){

		ChoisirCouleurDessin(coo);
		DessinerRectangle(950,130,200,30);
		RemplirRectangle(950,130,200,30);
		var2=(Microsecondes()-var)/cycle;
		snprintf(str,20,"Temps de jeu : %ld", var2);
		ChoisirCouleurDessin(coul);
		EcrireTexte(960,150,str,1);

		if(SourisCliquee()==1){
			distMnY=80;
			distMxY=680;

			if(difficulte->type_renvoi!=3){ /* Si la diificulté est facile ou moyenne */
				pos_X=390;
				pos_Y=80;
				distMnX=390;
				distMxX=990;
				if(difficulte->type_renvoi==1){
					distMxY -=150;
				}

			} else { /* Si la difficulté est : difficile */
				pos_X=240;
				pos_Y=80;
				distMnX=240;
				distMxX=1090;
			}
			/*Puisque dans tous les cas on devra incrémenter de 1 notre place dans le tableau, 
			on commence a -1 pour éviter ce prblm */
			
			loc_tab_x = -1;
			loc_tab_y = -1;

			/*pos_X : coordonnée de parcours qui évolue
			pos_Y : same
			_X coordonnée du clic 
			_Y same
			taille_x : nombre d'elt par ligne dans le tableau
			taille_y : nombre d'elt par colonne dans le tableau */

			/* Test pour savoir si le click est valable en X */
			for(j=0; j<taille_x; j++) { 
				if(pos_X < _X){ 
					/* Test pour savoir si on a la bonne image */ 
					if(pos_X+100 > _X){
						j=taille_x;
					}
				}
				pos_X+=100;
				loc_tab_x += 1;

				if ((pos_X < _X && _X < pos_X+50) || (_X < distMnX || _X > distMxX)){ 
					/* Test pour savoir si le clique n'est pas valable (entre les images ou hors du tableau)*/
					cvalable = False;
					j=taille_x;
					loc_tab_x = 12;
					loc_tab_y = 12;
				}
				pos_X +=50;
			}

			/* Click pour savoir si le click est valable en Y*/
			for(j=0; j<taille_y; j++) {
				if(pos_Y < _Y){
					if(pos_Y+139 > _Y){
						j=taille_y;
					}
				}
				pos_Y+=139;
				loc_tab_y += 1;
				if((pos_Y < _Y && _Y < pos_Y+11) || (_Y < distMnY || _Y > distMxY)){
					cvalable = False;
					j=taille_y;
					loc_tab_x = 12;
					loc_tab_y = 12;
				}
				pos_Y +=11;	
			}

			/* On retourne l'image sur la quelle le joueur a cliqué */
			snprintf(save,50,"jeu/im_%s/0%d.png", theme->valeur, tableau[loc_tab_x][loc_tab_y]);
			ChargerImage(save, pos_X-150, pos_Y-150, 0, 0,100, 139);

			if(check==1){
				/*Si c'est la premiere image que le joueur click*/
				if(cvalable==False){
					/* Si elle n'est pas valide : On met check à 1 et on remet
					notre variable sur true pour eviter une boucle infini */
					check=1;
					cvalable=True;
				} else if(0<=tableau[loc_tab_x][loc_tab_y] && tableau[loc_tab_x][loc_tab_y]<=11){
					/* SI alors, l'image existe et est valide, on enregistre ses informations */
					Save_ltab_x = loc_tab_x;
					Save_ltab_y = loc_tab_y;
					Save_pos_X = pos_X;
					Save_pos_Y = pos_Y;
					check=2;
				}
			} else if(check==2){
				/*  SI c'est la deuxieme image */
				if(cvalable==False){
					cvalable=True;
					check=2;
				} else if((tableau[loc_tab_x][loc_tab_y]==tableau[Save_ltab_x][Save_ltab_y]) && ((Save_pos_X != pos_X) || (Save_pos_Y != pos_Y))){
					for(i=0; i<11; i++){
						if(tableau[loc_tab_x][loc_tab_y] != find_pict[i]){
							img_ne = 1;
						}
						else {
							img_ne = 0;
							break;
						}
					}
					if(img_ne == 1){
						/* SI il est valide :*/
						if(score==scoreMax){
							/* SI le score vaut le score max, le jeu est finit */
							return reussi;
						} else {
							/* Sinon, on ajoute +1 au score et aux coups */
							find_pict[score] = tableau[loc_tab_x][loc_tab_y];
							score+=1;
							check=1;
						}
					}
				} else {
					/* SINON, si le click est valide mais que ce n'est pas la 
					meme image*/
					check=1;
					sleep(1);
					ChargerImage("jeu/inverse.png", pos_X-150, pos_Y-150, -0, -0, 100, 139);
					ChargerImage("jeu/inverse.png", Save_pos_X-150, Save_pos_Y-150, -0, -0, 100, 139);
				}
			}
		}
		/* ================================================================================================================== */
		/* Mode tricheur */
		/* ================================================================================================================== */
	}
	Touche();
    FermerGraphique();
	struct renvoie exit = {EXIT_SUCCESS, "Exit_Success"};
	return exit;
}