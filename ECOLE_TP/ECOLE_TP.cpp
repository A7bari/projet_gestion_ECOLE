
#include "Header.h"

void afficher(Etudiant t) {

    cout << t;
}

int main()
{
    
    Ecole* ensa = new Ecole("ENSAF", "route Emouzar");

    Etudiant* med = new Etudiant("mohammed ", 22, "n13425256", "genie info");
    

    ensa->initialiser();

    ensa->menu();


}
