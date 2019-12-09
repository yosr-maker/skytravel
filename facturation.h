	#include <gtk/gtk.h>

typedef struct 
{

char idf[30];
char montant[30];
char date[30];
char ncarte[30];
char code[30];

}Facturation;

void ajouter_facturation(Facturation a);
void afficher_facturation(GtkWidget *liste);
void supprimer_facturation(char test ,Facturation fa);
void modifier ( Facturation p );
