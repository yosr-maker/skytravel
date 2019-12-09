#include <gtk/gtk.h>


typedef struct 
{
	char Ville_depart[40];
	char Ville_arrivee[40];
	int Jour;
	int Mois;
	int Annee;
	char Duree_vol[40];
	char Classe[40];
	char Nbre_voyageurs[40];
	char Prix_vol[40];
	char Id_vol[40];
	
}Vol;



void ajouter_vol(Vol p);
void afficher_vol(GtkWidget *liste);
void modifier(Vol p, Vol m);
void afficher_hotel(GtkWidget *liste);

