#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include<stdio.h>
#include<string.h>
#include "facturation.h"
#include <gtk/gtk.h>

enum
{
     IDF,
     MONTANT,
     DATE,
     NCARTE,
     CODE,
     COLUMNS
};
void ajouter_facturation(Facturation a)
{
 FILE *f;
 f=fopen("facturation.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s\n",a.idf,a.montant,a.date,a.ncarte,a.code);
 fclose(f);

}}

void afficher_facturation(GtkWidget *liste)
{
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter  iter;
   GtkListStore *store;

   char idf[30];
   char montant[30];
   char date[30];
   char ncarte[30];
   char code[30];
   store=NULL;

   FILE *f;
   
  store=gtk_tree_view_get_model(liste);
  if ( store==NULL )
{ 
     renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes(" idf",renderer, "txt",IDF,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes(" montant",renderer, "txt",MONTANT,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes(" date",renderer, "txt",DATE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes(" ncarte",renderer, "txt",NCARTE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer = gtk_cell_renderer_text_new ();
     column = gtk_tree_view_column_new_with_attributes(" code",renderer, "txt",CODE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
  store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
 f= fopen("facturation.txt", "r");
	if(f==NULL)
	{
	return;
	}
	else 
	{ f = fopen("facturation.txt" , "a+");
	while(fscanf(f,"%s %s %s %s %s \n" ,idf,montant,date,ncarte,code)!=EOF)
{
   gtk_list_store_append(store, &iter);
   gtk_list_store_set(store, &iter, IDF, idf, MONTANT, montant, DATE, date, NCARTE, ncarte, CODE, code -1);
}
  fclose(f);
   gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
void supprimer_facturation(char test,Facturation fa)
{FILE *f,*h;
f=fopen("facturation.txt","r");
if (f!=NULL)
{h=fopen("facturations.txt","w+");
while(fscanf(f,"%s %s %s %s %s\n",&fa.idf,fa.montant,fa.date,&fa.ncarte,fa.code)!=EOF)
if(fa.idf!=test)
fprintf(h,"%s %s %s %s %s\n",&fa.idf,fa.montant,fa.date,&fa.ncarte,fa.code);
}
fclose(f);
fclose(h);
f=fopen("facturation.txt","w+");
h=fopen("facturations.txt","r");
while(fscanf(h,"%s %s %s %s %s \n",&fa.idf,fa.montant,fa.date,&fa.ncarte,fa.code)!=EOF)
fprintf(f,"%s %s %s %s %s\n",fa.idf,fa.montant,fa.date,&fa.ncarte,fa.code);
fclose(f);fclose(h);
}

