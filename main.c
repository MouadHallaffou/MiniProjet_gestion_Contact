#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

/**struct**/

struct Contact {
    char nom[50];
    char numero[20];
    char email[50];
};

// Tableau pour stocker les contacts:

struct Contact carnet[MAX_CONTACTS];

int nombre_contacts = 0;


void ajouter_contact() {
    if (nombre_contacts < MAX_CONTACTS) {
        struct Contact nouveau;
        printf("Entrez le nom : ");
        scanf("%s", nouveau.nom);
        printf("Entrez le numero de telephone : ");
        scanf("%s", nouveau.numero);
        printf("Entrez l'adresse e-mail : ");
        scanf("%s", nouveau.email);

        carnet[nombre_contacts] = nouveau;
        nombre_contacts++;
        printf("Contact ajoutee avec succes !\n");
    } else {
        printf("Carnet de contacts plein !\n");
    }
}

void modifier_contact() {
    char nom[50];
    printf("Entrez le nom du contact a modifier : ");
    scanf("%s", nom);

    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {
            printf("Entrez le nouveau numero de telephone : ");
            scanf("%s", carnet[i].numero);
            printf("Entrez la nouvelle adresse e-mail : ");
            scanf("%s", carnet[i].email);
            printf("Contact est modifie!\n");
            return;
        }
    }
    printf("Contact non trouvee !!!\n");
}

void supprimer_contact() {
    char nom[50];
    printf("Entrez le nom du contact a supprimer : ");
    scanf("%s", nom);

    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {

            for (int j = i; j < nombre_contacts - 1; j++) {
                carnet[j] = carnet[j + 1];
            }
            nombre_contacts--;
            printf("Contact est supprimee!\n");
            return;
        }
    }
    printf("Contact non trouve !!!!\n");
}

void afficher_contacts() {
    if (nombre_contacts == 0) {
        printf("Aucun contact a afficher.\n");
        return;
    }

    printf("Liste des contacts :\n");
    for (int i = 0; i < nombre_contacts; i++) {
        printf("Nom: %s, Telephone: %s, Email: %s\n", carnet[i].nom, carnet[i].numero, carnet[i].email);
    }
}

void rechercher_contact() {
    char nom[50];
    printf("Entrez le nom du contact a rechercher : ");
    scanf("%s", nom);

    for (int i = 0; i < nombre_contacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {
            printf("Contact trouvé :\n");
            printf("Nom: %s, telephone: %s, Email: %s\n", carnet[i].nom, carnet[i].numero, carnet[i].email);
            return;
        }
    }
    printf("Contact non trouve !!!!\n");
}

int main() {
    int choix;

    do {
        printf("\t\n ====== Menu de Gestion de Contact =======\n");
        printf("\t1. Ajouter un contact\n");
        printf("\t2. Modifier un contact\n");
        printf("\t3. Supprimer un contact\n");
        printf("\t4. Afficher tous les contacts\n");
        printf("\t5. Rechercher un contact\n");
        printf("\t6. Quitter\n");
        printf("\n");
        printf("\tEntrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_contact();
                break;
            case 2:
                modifier_contact();
                break;
            case 3:
                supprimer_contact();
                break;
            case 4:
                afficher_contacts();
                break;
            case 5:
                rechercher_contact();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, reessayer!!!!!!\n");
        }
    } while (choix != 6);

    return 0;
}
