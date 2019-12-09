#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "facturation.h"
#include "suppm.h"
void
on_afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;

window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
window2=lookup_widget(objet, "window2");
window2=create_window2();
gtk_widget_show(window2);

}


void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;
window2=lookup_widget(objet,"window2");
gtk_widget_destroy(window2);
window1=create_window1();
gtk_widget_show(window1);

}


void
on_button1_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
Facturation a;
GtkWidget *input1, *input2,*input3,*input4,*input5;
GtkWidget *window1,*erreur,*dialog1;

window1=lookup_widget(objet,"window1");


input1=lookup_widget(objet,"idf");
input2=lookup_widget(objet,"montant");
input3=lookup_widget(objet,"date");
input4=lookup_widget(objet,"ncarte");
input5=lookup_widget(objet,"code");

strcpy(a.idf,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.montant,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.ncarte,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(a.code,gtk_entry_get_text(GTK_ENTRY(input5)));
ajouter_facturation(a);
dialog1 = create_dialog1 ();
  erreur=lookup_widget(dialog1,"label6");
  gtk_label_set_text (GTK_LABEL (erreur), _("ajout avec succés"));
gtk_widget_show (dialog1);
}





void
on_button_auct_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *treeview1;
window2=lookup_widget(objet, "window2");
treeview1=lookup_widget(window2,"treeview1");
afficher_facturation(treeview1);
}


void
on_okbutton1_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *dialog;
 dialog=lookup_widget(objet, "dialog1");
 gtk_widget_hide (dialog);

}








void
on_button2_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window3;
window3=lookup_widget(objet,"window3");

gtk_widget_destroy(window1);

window3=create_window3();
gtk_widget_show(window3);



}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_button4_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget	*input	=	lookup_widget(objet,"idff");
	
char	idf[30];
strcpy(idf,gtk_entry_get_text(GTK_ENTRY(input)));
supprimerm(idf);
}





