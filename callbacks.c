#ifdef HAVE_CONFIG_H
#  include <config.h>
#include <string.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "vol.h"



void
on_buttongestresvol_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation");
gtk_widget_hide(window);
window1=create_reservation_vol();
gtk_widget_show_all(window1);
}


void
on_buttongestreshot_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation");
gtk_widget_hide(window);
window1=create_reservation_hotel();
gtk_widget_show_all(window1);
}


void
on_buttonretourreservation_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation_vol_reserver");
gtk_widget_hide(window);
window1=create_reservation_vol();
gtk_widget_show_all(window1);
}


void
on_buttonafficherlistvol_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview22;
window=lookup_widget(button,"reservation");
gtk_widget_hide(window);
window1=create_reservation_vol_reserver();
gtk_widget_show_all(window1);
treeview22=lookup_widget(window1,"treeviewvoloffres");
	afficher_vol(treeview22);
}


void
on_buttonmesvolreservee_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview4;
window=lookup_widget(button,"reservation");
gtk_widget_hide(window);
window1=create_mes_reservation_vol();
gtk_widget_show_all(window1);
treeview4=lookup_widget(window1,"treeview4");
	afficher_volreservee(treeview4);
}


void
on_buttonretourresevol_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation_vol");
gtk_widget_hide(window);
window1=create_reservation();
gtk_widget_show_all(window1);
}


void
on_buttonmeshotreserver_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeviewhotres1;
window=lookup_widget(button,"reservation_hotel");
gtk_widget_hide(window);
window1=create_mes_reservation_hotel();
gtk_widget_show_all(window1);
treeviewhotres1=lookup_widget(window1,"treeviewhotres1");
	afficher_hotelreservee(treeviewhotres1);
}


void
on_buttonafficherlisthot_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
GtkWidget *treeview22;
window=lookup_widget(button,"reservation");
gtk_widget_hide(window);
window1=create_reservation_hotel_reserver();
gtk_widget_show_all(window1);
treeview22=lookup_widget(window1,"treeviewhotoffres");
	afficher_hotel(treeview22);
}


void
on_buttonvalidervolres_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;

	char nomhotel[50];

	input1=lookup_widget(button,"entrynomhotel");
	strcpy(nomhotel,gtk_entry_get_text(GTK_ENTRY(input1)));

	GtkWidget *spinbuttonjourhot;
	GtkWidget *spinbuttonmoishot;
	GtkWidget *spinbuttonanneehot;
	GtkWidget *spinbuttonnbperso;
	GtkWidget *spinbuttonnbch;



	spinbuttonjourhot=lookup_widget(button, "spinbuttonjourhot");
	spinbuttonmoishot=lookup_widget(button, "spinbuttonmoishot");
	spinbuttonanneehot=lookup_widget(button, "spinbuttonanneehot");
	spinbuttonnbperso=lookup_widget(button, "spinbuttonnbperso");
	spinbuttonnbch=lookup_widget(button, "spinbuttonnbch");


	int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonjourhot));
	int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonmoishot));
	int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonanneehot));
	int nbp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonnbperso));
	int nbc=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonnbch));

char a[20],b[20],f[50],g[50],h[50];
char ws[50];
int c,d,e;
FILE *f0;
FILE *f2;
f2=fopen("/home/yosr/Projects/projectreservation/hotelreserver.txt","a+");
f0=fopen("/home/yosr/Projects/projectvol/hotel.txt","a+");
int x=0;
while (fscanf(f0,"%s %s %d %d %d %s %s %s \n",a, b, &c, &d, &e, f, g, h)!=EOF)
{ 
if (strcmp(nomhotel,b)==0)
{
	if(c==JJ){if(MM==d){if(e==AA){x=1;
	break;}}}
	
}
}
char a1[20], b1[20], c1[20], d1[20], e1[20], f1[20], g1[20], h1[20],i1[20],j1[20],k1[20];
int idres=0;
while (fscanf(f2,"%s %s %s %s %s %s %s %s %s %s %s \n",a1, b1, c1, d1, e1, f1, g1, h1,i1,j1,k1)!=EOF)
{ idres=idres+1;}
if(x==1){
idres=idres+1;
fprintf(f2,"%d %s %s %d %d %d %s %s %s %d %d\n",idres,a, b, c, d, e, f, g, h,nbp,nbc);
strcpy(ws,"reservation validé");
output=lookup_widget(button,"labelerrorreshot");
gtk_label_set_text(GTK_LABEL(output),ws);
}
fclose(f0);
fclose(f2);

if (x==0){
strcpy(ws,"reservation non validé");
output=lookup_widget(button,"labelerrorreshot");
gtk_label_set_text(GTK_LABEL(output),ws);}


}


void
on_buttonreshotdel_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char x[50];
GtkWidget *input1;
input1= lookup_widget(button,"entryidresdel");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f1 ;
FILE *ftempvol;

ftempvol=fopen ("/home/yosr/Projects/projectreservation/ftempvol.txt","a+");
f1=fopen("/home/yosr/Projects/projectreservation/hotelreserver.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20],kl[20],jl[20],hk[20];
int y=0;


                       while (fscanf(f1,"%s %s %s %s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol,kl,jl,hk)!=EOF)
{ 
if (strcmp(x,pVille_depart)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol,kl,jl,hk);}
if  (strcmp(x,pVille_depart)==0) {y=1;}

} 
fclose(ftempvol);
fclose(f1);
remove ("/home/yosr/Projects/projectreservation/hotelreserver.txt");
rename ("/home/yosr/Projects/projectreservation/ftempvol.txt","/home/yosr/Projects/projectreservation/hotelreserver.txt");
if(y==0){
char ext[50];
GtkWidget *output;
strcpy(ext,"reservation n'existe pas");
output=lookup_widget(button,"labelerrordelete");
gtk_label_set_text(GTK_LABEL(output),ext);}
if(y==1){
char ext[50];
GtkWidget *output;
strcpy(ext,"suppression avec succée");
output=lookup_widget(button,"labelerrordelete");
gtk_label_set_text(GTK_LABEL(output),ext);


GtkWidget *window1;
window1=lookup_widget(button,"mes_reservation_hotel");
GtkWidget *treeviewhotres1;
treeviewhotres1=lookup_widget(window1,"treeviewhotres1");
	afficher_hotelreservee(treeviewhotres1);
}




}


void
on_buttonreservol_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output;

	char idvol[50];

	input1=lookup_widget(button,"entryidreservation");
	strcpy(idvol,gtk_entry_get_text(GTK_ENTRY(input1)));




char a[20],b[20],f[50],g[50],h[50],c[50],d[50],e[50];
char ws[50];
FILE *f0;
FILE *f2;
f2=fopen("/home/yosr/Projects/projectreservation/volreserver.txt","a+");
f0=fopen("/home/yosr/Projects/projectvol/uservol.txt","a+");
int x=0;
while (fscanf(f0,"%s %s %s %s %s %s %s %s \n",a, b, c, d, e, f, g, h)!=EOF)
{ 
if (strcmp(idvol,h)==0)
{
	x=1;
	break;
	
}
}

if(x==1){
fprintf(f2,"%s %s %s %s %s %s %s %s \n",a, b, c, d, e, f, g, h);
strcpy(ws,"reservation validé");
output=lookup_widget(button,"label30000");
gtk_label_set_text(GTK_LABEL(output),ws);
}
fclose(f0);
fclose(f2);

if (x==0){
strcpy(ws,"reservation non validé");
output=lookup_widget(button,"label30000");
gtk_label_set_text(GTK_LABEL(output),ws);}
}


void
on_buttonsupprimervolres_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
char x[50];
GtkWidget *input1;
input1= lookup_widget(button,"entry50000");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f1 ;
FILE *ftempvol;

ftempvol=fopen ("/home/yosr/Projects/projectreservation/ftempvol.txt","a+");
f1=fopen("/home/yosr/Projects/projectreservation/volreserver.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20],kl[20],jl[20],hk[20];
int y=0;


                       while (fscanf(f1,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(x,pId_vol)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol);}
if  (strcmp(x,pId_vol)==0) {y=1;}

} 
fclose(ftempvol);
fclose(f1);
remove ("/home/yosr/Projects/projectreservation/volreserver.txt");
rename ("/home/yosr/Projects/projectreservation/ftempvol.txt","/home/yosr/Projects/projectreservation/volreserver.txt");
if(y==0){
char ext[50];
GtkWidget *output;
strcpy(ext,"reservation n'existe pas");
output=lookup_widget(button,"label3100");
gtk_label_set_text(GTK_LABEL(output),ext);}
if(y==1){
char ext[50];
GtkWidget *output;
strcpy(ext,"suppression avec succée");
output=lookup_widget(button,"label3100");
gtk_label_set_text(GTK_LABEL(output),ext);
}
}

void
on_buttonretour8_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation_hotel");
gtk_widget_hide(window);
window1=create_reservation();
gtk_widget_show_all(window1);
}


void
on_button16retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"me_reservation_vol");
gtk_widget_hide(window);
window1=create_reservation_vol();
gtk_widget_show_all(window1);
}


void
on_button11retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"reservation_hotel_reserver");
gtk_widget_hide(window);
window1=create_reservation_hotel();
gtk_widget_show_all(window1);
}


void
on_button13retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"me_reservation_hotel");
gtk_widget_hide(window);
window1=create_reservation_hotel();
gtk_widget_show_all(window1);
}


void
on_button14retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"me_reservation_hotel");
gtk_widget_hide(window);
window1=create_reservation_hotel();
gtk_widget_show_all(window1);
}


void
on_button1800_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1801_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}

