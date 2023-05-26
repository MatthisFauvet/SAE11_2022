#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graph.h>

#include "main.h"
#include "menu.h"
#include "theme.h"
#include "start.h"
#include "diff.h"
#include "jeux.h"
#include "final.h"

int menu(void){
	struct renvoie var_s, var_t, var_d;
	while(0!=1){
		var_s = start();
		if(var_s.type_renvoi==1){
			/*START*/
			var_t = theme();
			if(var_t.type_renvoi == 1){

				var_d = diff();
				if(var_d.type_renvoi == 0) {
					/**/
					return RETOUR_M;
				} 
				else if(var_d.type_renvoi > 0){
					/**/
					jeux(&var_t, &var_d);
					final();
					return RETOUR_M;
				}
			}
		} 

		else if(var_s.type_renvoi==2) {
			/*Options();*/
		}
	}
}