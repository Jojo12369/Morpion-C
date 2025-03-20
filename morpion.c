#include <stdio.h>

// Fonction permetant d'afficher le plateau de jeu
char plateau(char cases[]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c\n", cases[(2 - i) * 3], cases[(2 - i) * 3 + 1], cases[(2 - i) * 3 + 2]);
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
}

// Fonction permetant d'afficher le message de victoire
void victoire(char cases[], int joueur) {
    plateau(cases);
    printf("joueur %d a gagner !", (joueur + 1));
}

// Fonction permetant de gérer la partie
void morpion() {
    char symboles[2] = {'X', 'O'};
    char cases[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int tour = 0;
    while (1) {
        int joueur = tour % 2;
        int choix;

        plateau(cases);

        printf("choisir une case joueur %d (1-9) : ", (joueur + 1));
        scanf("%d", &choix);
        while (cases[choix - 1] != ' ') {
            printf("case invalide, choisir une case joueur %d (1-9) : ", (joueur + 1));
            scanf("%d", &choix);
        }
        cases[choix - 1] = symboles[joueur];
        tour++;

        // Cette partie gère les victoires
        for (int i = 0; i < 3; i++) {

            // Ici ce fait la gestion des victoires en lignes
            if (cases[i * 3] == symboles[joueur] && cases[i * 3 + 1] == symboles[joueur] && cases[i * 3 + 2] == symboles[joueur]) {
                victoire(cases, joueur);
                return;
            }

            // Ici ce fait la gestion des victoires en colonnes
            if (cases[i] == symboles[joueur] && cases[i + 3] == symboles[joueur] && cases[i + 6] == symboles[joueur]) {
                victoire(cases, joueur);
                return;
            }
        }

        // Ici ce fait la gestion des victoires en diagonales
        if (cases[0] == symboles[joueur] && cases[4] == symboles[joueur] && cases[8] == symboles[joueur]) {
            victoire(cases, joueur);
            return;
        }
        if (cases[6] == symboles[joueur] && cases[4] == symboles[joueur] && cases[2] == symboles[joueur]) {
            victoire(cases, joueur);
            return;
        }

        // Cette partie gère les matchs nuls
        if (tour == 9) {
            plateau(cases);
            printf("Match nul !");
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    morpion();
    return 0;
}