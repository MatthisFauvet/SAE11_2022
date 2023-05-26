#ifndef _JEUX_H /* L'écriture ici présente n'est pas universelle */
#define _JEUX_H /* Edit suite aux corrections des posts suivants -> */


#define MODE_CHT_ACT 1
#define MODE_CHT_DESACT 2

/* Cette structure permet un renvoie contenant plus d'informations 
dans un premier temps, un int qui permettera de donner suite aux programme
dans un second temp un char qui contient le choix du joueur */

#include "jeux.h"

struct renvoie jeux(struct renvoie *theme, struct renvoie *difficulte);

#endif