#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"

int main(void){	
    int var_m;
    InitialiserGraphique();
    CreerFenetre(250,200,1280,720);

    var_m = menu();
    while(0!=1){
        if(var_m==RETOUR_M){
            menu();
        }

    }

    /**/

	Touche();
    FermerGraphique();

    return EXIT_SUCCESS;
}