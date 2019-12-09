#include <string.h>
#include "fonct.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>

void affich(GtkWidget *plistview)
{ 
enum { 
       COL_CIN,
       COL_CIVILITE,
       COL_NAME,
       COL_FAMILY,
       COL_AGE,
       COL_MAIL,
       COL_PASS,
       NUM_COLS
      };

char civ[20],a[20],age[12],b[20],c[20],d[20],e[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f1;
f1=fopen("/home/baha/Projets/projet1/src/agnt.txt","r");
if(f1!=NULL){
       while(fscanf(f1,"%s %s %s %s %s %s %s\n",civ,age,a,b,c,d,e)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_CIN, a,
		          COL_CIVILITE, civ,
		          COL_NAME, b,
			  COL_FAMILY, c,
			  COL_AGE,age,
			  COL_MAIL,d,
			  COL_PASS,e,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Cin",celrender,"text",COL_CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Civilité",celrender,"text",COL_CIVILITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NAME,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Prenom",celrender,"text",COL_FAMILY,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes   ("Age",celrender,"text",COL_AGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Mail",celrender,"text",COL_MAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
     
        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Passwd",celrender,"text",COL_PASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f1);
}


