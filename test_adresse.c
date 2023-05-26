#include <stdio.h>
#include <stdlib.h>

struct employe {
    unsigned id;
    char* nom;
    float salaire;
};

int main(void) {
    struct employe paul = {0, "Paul", 1203.45f};
    struct employe jacques = {1, "Jacques", 1587.33f};

    struct employe* employe_du_mois = &jacques;
    printf(" Félicitations %s\n", employe_du_mois->nom);
}
