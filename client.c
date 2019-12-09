#include <stdio.h>
#include <string.h>
#include "client.h"
#include <gtk/gtk.h>
#include <stdlib.h>


enum
{
	ID,
	NOM,
	PRENOM,
	CIN,
	SEXE,
	JOUR,
	MOIS,
	AN,
	MAIL,
	PASSW,
	COLUMNS
};
void afficher1(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;	

	GtkListStore *store;

 char id[30];
 char nom[30];
 char prenom[15];
 char cin[15];
 char sexe[15];
 char jour[15];
 char mois[15];
 char an[15];
 char mail[15];
 char passw[18];

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(",nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom ", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("sexe ", renderer, "text",SEXE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee", renderer, "text",AN, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("passw", renderer, "text",PASSW, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		

		
	}

	

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);
	
	f = fopen("/home/zac/Projects/crudi/src/clieent.txt", "r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("/home/zac/Projects/crudi/src/clieent.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s  ",id,nom,prenom,cin,sexe,jour,mois,an,mail,passw)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store, &iter,ID,id,NOM,nom,PRENOM,prenom,CIN,cin,SEXE,sexe,JOUR,jour,MOIS,mois,AN,an,MAIL,mail,PASSW,passw,-1);

}

		fclose(f);

		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}	


}






void sup_offre(char chaine[30],FILE *f)
{
char id[30];
 char nom[30];
 char prenom[15];
 char cin[15];
 char sexe[15];
 char jour[15];
 char mois[15];
 char annee[15];
 char mail[15];
 char passwd[18];
FILE *pf;
f=fopen("/home/zac/Projects/crudi/src/clieent.txt","r");
pf=fopen("/home/zac/Projects/crudi/src/clieentsup.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s ",id,nom,prenom,cin,sexe,jour,mois,annee,mail,passwd)!=EOF)
{
	if(strcmp(id,chaine)!=0)	
	{fprintf(pf,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,jour,mois,annee,mail,passwd);}
}
fclose(pf);
fclose(f);

pf=fopen("/home/zac/Projects/crudi/src/clieentsup.txt","r");
f=fopen("/home/zac/Projects/crudi/src/clieent.txt","w+");
while(fscanf(pf,"%s %s %s %s %s %s %s %s %s %s ",id,nom,prenom,cin,sexe,jour,mois,annee,mail,passwd)!=EOF)
{
		
	{fprintf(f,"%s %s %s %s %s %s %s %s %s %s  \n",id,nom,prenom,cin,sexe,jour,mois,annee,mail,passwd);}
}
fclose(f);
fclose(pf);



}


















