#ifndef _MAIN_H /* L'écriture ici présente n'est pas universelle */
#define _MAIN_H /* Edit suite aux corrections des posts suivants -> */

/* Cette structure permet un renvoie contenant plus d'informations 
dans un premier temps, un int qui permettera de donner suite aux programme
dans un second temp un char qui contient le choix du joueur */

#include "main.h"

struct renvoie { 
	unsigned short int type_renvoi; /*Donne suite au programme*/
	char* valeur; /*Choix du joueur*/
};

int main(void);

#endif