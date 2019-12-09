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
on_ajout_clicked (GtkWidget *objet, gpointer user_data)
{
            GtkWidget *window;
            GtkWidget *window1;


             window=lookup_widget(objet, "window");
             window1 = create_window1 ();
             gtk_widget_show(window1);
             gtk_widget_hide(window);

}


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	Vol p;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;

	GtkWidget *window1;

	window1=lookup_widget(objet,"window1");

	input4=lookup_widget(objet,"Duree_vol");
	input6=lookup_widget(objet,"Nbre_voyageurs");
	input7=lookup_widget(objet,"Prix_vol");
	input8=lookup_widget(objet,"Id_vol");

	GtkWidget *spinbutton1;
	GtkWidget *spinbutton2;
	GtkWidget *spinbutton3;

	GtkWidget *combobox1;
	GtkWidget *combobox2;
	GtkWidget *combobox3;

	spinbutton1=lookup_widget(objet, "Jour");
	spinbutton2=lookup_widget(objet, "Mois");
	spinbutton3=lookup_widget(objet, "Annee");

	combobox1=lookup_widget(objet, "combobox1");
	combobox2=lookup_widget(objet, "combobox2");
	combobox3=lookup_widget(objet, "combobox3");

	int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton1));
	int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton2));
	int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton3));

	char ville_depart[20];
	strcpy(p.Ville_depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	char ville_arrivee[20];
	strcpy(p.Ville_arrivee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	char classe_vol[20];
	strcpy(p.Classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

	
p.Jour=JJ;
p.Mois=MM;
p.Annee=AA;

	strcpy(p.Duree_vol,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(p.Nbre_voyageurs,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(p.Prix_vol,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(p.Id_vol,gtk_entry_get_text(GTK_ENTRY(input8)));
	ajouter_vol(p);
}

void
on_afficher_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window;
	GtkWidget *windowaffichage;
	GtkWidget *treeview1;

	window=lookup_widget(objet, "window");

	gtk_widget_destroy(window);
	windowaffichage=lookup_widget(objet,"windowaffichage");
	windowaffichage=create_windowaffichage();

	gtk_widget_show(windowaffichage);
	gtk_widget_hide(window);

	treeview1=lookup_widget(windowaffichage,"treeview1");
	afficher_vol(treeview1);
}

void on_retour_clicked (GtkWidget *objet, gpointer user_data)
{
	GtkWidget *windowaffichage;
	GtkWidget *window;

	windowaffichage=lookup_widget(objet,"windowaffichage");
	
	gtk_widget_destroy(windowaffichage);
	window=create_window();
	gtk_widget_show(window);
}







void
on_modifier_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window4;

window=lookup_widget(objet,"window");
window4=create_window4();
gtk_widget_show(window4);
gtk_widget_hide(window);

}



/*
void
on_confirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ville_depart, *Ville_arrivee, *Jour, *Mois, *Annee, *Duree_vol, *Classe, *Nbre_voyageurs, *Prix_vol, *Id_vol, *current, *window2, *window3, *liste;
	char Ville_departy[40], Ville_arriveey[40], Duree_voly[40],Classey[40], Nbre_voyageursy[40], Prix_voly[40], Id_voly[40];
	int Joury,Moisy,Anneey;
	Ville_depart=lookup_widget(objet,"combobox4");
	Ville_arrivee=lookup_widget(objet,"combobox5");
	
	Jour=lookup_widget(objet,"spinbutton1");
	Mois=lookup_widget(objet,"spinbutton2");
	Annee=lookup_widget(objet,"spinbutton3");
	
	Duree_vol=lookup_widget(objet,"entry1");
	Classe=lookup_widget(objet,"combobox6");
	Nbre_voyageurs=lookup_widget(objet,"entry2");
	Prix_vol=lookup_widget(objet,"entry3");
	Id_vol=lookup_widget(objet,"entry4");

	strcpy(Ville_departy,gtk_combo_box_get_active_text(GTK_COMBO_BOX(GTK_ENTRY(Ville_depart))));
	strcpy(Ville_arriveey,gtk_combo_box_get_active_texdt(GTK_COMBO_BOX(GTK_ENTRY(Ville_arrivee))));
	Joury = gtk_spin_button_get_value_as_int(Jour);
	Moisy = gtk_spin_button_get_value_as_int(Mois);
	Anneey = gtk_spin_button_get_value_as_int(Annee);
	strcpy(Duree_voly,gtk_entry_get_text(GTK_ENTRY(Duree_vol)));
	strcpy(Classey,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
	strcpy(Nbre_voyageursy,gtk_entry_get_text(GTK_ENTRY(Nbre_voyageurs)));
	strcpy(Prix_voly,gtk_entry_get_text(GTK_ENTRY(Prix_vol)));
	strcpy(Id_voly,gtk_entry_get_text(GTK_ENTRY(Id_vol)));
	
	confirmer(Ville_departy, Ville_arriveey, Joury, Moisy, Anneey, Duree_voly, Classey, Nbre_voyageursy, Prix_voly, Id_voly);
	window2=create_window2();
	gtk_widget_show (window2);
	current=lookup_widget(objet,"window3");
	gtk_widget_hide(current);
	liste=lookup_widget(window2,"treeview1");
	afficher_vol(liste);
}
*/



void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window4;

window=lookup_widget(objet,"window");
window4=create_window4();
gtk_widget_show(window4);
gtk_widget_hide(window);
}


void
on_supprr_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input120;
 Vol p;

            char ch1[50];
            FILE *f1 ;
            FILE *ftempvol;
input120=lookup_widget(objet,"entrysupmod");
            strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input120)));
ftempvol=fopen ("/home/rihab/projectvol/tempvol.txt","a+");
f1=fopen("/home/rihab/projectvol/uservol.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];


                       while (fscanf(f1,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(ch1,pId_vol)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol);
}
} 
fclose(ftempvol);
fclose(f1);
remove ("/home/rihab/projectvol/uservol.txt");
rename ("/home/rihab/projectvol/tempvol.txt","/home/rihab/projectvol/uservol.txt");
}




/*void
on_modifr_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
           GtkWidget *window6y;
            GtkWidget *window7y;
            GtkWidget *input16y, *output16y;
	    personne p;
            char ch[50];
            FILE* f ;
            window6y=lookup_widget(objet_graphique, "window6y");
            input16y=lookup_widget(objet_graphique,"entry21y");
            output16y=lookup_widget(objet_graphique,"label59y");
            strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input16y)));
f=fopen("/home/yassmine/Projects/project1/src/ajout.txt","r");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime)!=EOF)
{ 
if (strcmp(ch,p.cin)==0)
{
             window7y = create_window7y ();
             gtk_widget_show(window7y);
             gtk_widget_hide(window6y);
}
else
{gtk_label_set_text(GTK_LABEL(output16y),"cin incompatible");}
}
}
*/



void
on_button4return_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window1");
gtk_widget_hide(window);
window1=create_window();
gtk_widget_show_all(window1);
}


void
on_retour1enterid_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window4");
gtk_widget_hide(window);
window1=create_window();
gtk_widget_show_all(window1);
}


void
on_button1gestionvol_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window5");
gtk_widget_hide(window);
window1=create_window();
gtk_widget_show_all(window1);
}


void
on_modifyvol1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input120;
FILE *idtemp ;
FILE *uservol;
int a=0;
char x[50];
input120=lookup_widget(button,"entrysupmod");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input120)));
idtemp=fopen ("/home/rihab/projectvol/idtemp.txt","a+");
uservol=fopen ("/home/rihab/projectvol/uservol.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];
 while (fscanf(uservol,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(x,pId_vol)==0)
{
fprintf(idtemp,"%s",x);
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window4");
gtk_widget_hide(window);
window1=create_window3();
gtk_widget_show_all(window1);
a=1;


}
}
fclose(idtemp);
fclose(uservol);
if (a==0){

char ext[50];
GtkWidget *output;
strcpy(ext,"id n'existe pas");
output=lookup_widget(button,"label34");
gtk_label_set_text(GTK_LABEL(output),ext);
}
}


void
on_buttonconfirm_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *idtemp ;
FILE *uservol;
FILE *ftempvol;

idtemp=fopen ("/home/rihab/projectvol/idtemp.txt","a+");
char x[20];

fscanf(idtemp,"%s",x);

ftempvol=fopen ("/home/rihab/projectvol/tempvol.txt","a+");
uservol=fopen ("/home/rihab/projectvol/uservol.txt","a+");


char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];


                       while (fscanf(uservol,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(x,pId_vol)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol);
}
}
char a[20],b[20],c[50],d[50],e[50],f[50],g[50],h[50],i[50],j[50];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;

GtkWidget *combobox4;
GtkWidget *combobox5;
GtkWidget *combobox6;
GtkWidget *spinbutton123;
GtkWidget *spinbutton223;
GtkWidget *spinbutton323;

spinbutton123=lookup_widget(button, "spinbutton123");
spinbutton223=lookup_widget(button, "spinbutton223");
spinbutton323=lookup_widget(button, "spinbutton323");
input1= lookup_widget(button,"entry123");
input2= lookup_widget(button,"entry223");
input3= lookup_widget(button,"entry323");
input4= lookup_widget(button,"entry423");

strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(c,gtk_entry_get_text(GTK_ENTRY(input3)));

strcpy(d,gtk_entry_get_text(GTK_ENTRY(input4)));

int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton123));
int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton223));
int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton323));

combobox4=lookup_widget(button, "combobox4");
combobox5=lookup_widget(button, "combobox5");
combobox6=lookup_widget(button, "combobox6");

char role[20];
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

char role1[20];
strcpy(role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));

char role2[20];
strcpy(role2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox6)));

fprintf(ftempvol,"%s %s %d/%d/%d %s %s %s %s %s",role,role1,JJ,MM,AA,a,role2,b,c,d);

fclose(idtemp);
fclose(ftempvol);
fclose(uservol);
remove ("/home/rihab/projectvol/idtemp.txt");
remove ("/home/rihab/projectvol/uservol.txt");
rename ("/home/rihab/projectvol/tempvol.txt","/home/rihab/projectvol/uservol.txt");

}


void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button9hotel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window6");
gtk_widget_hide(window);
window1=create_window7();
gtk_widget_show_all(window1);
}


void
on_button6hotel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window9;
GtkWidget *treeview22;
window=lookup_widget(button,"window6");
gtk_widget_hide(window);
window9=create_window9();
gtk_widget_show_all(window9);
treeview22=lookup_widget(window9,"treeview22");
	afficher_hotel(treeview22);
}


void
on_button7hotel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window6");
gtk_widget_hide(window);
window1=create_window10();
gtk_widget_show_all(window1);
}


void
on_button8hotel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button13hotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window7");
gtk_widget_hide(window);
window1=create_window6();
gtk_widget_show_all(window1);
}


void
on_button12hotel_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *spinbutton327hotel;
GtkWidget *spinbutton329hotel;
GtkWidget *spinbutton328hotel;
GtkWidget *combobox11hotel;
FILE *hotel;
char a[20], b[20], c[20], d[20], e[20], f[20], g[20],h[20];


spinbutton327hotel=lookup_widget(button, "spinbutton327hotel");
int jourjour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton327hotel));

spinbutton329hotel=lookup_widget(button, "spinbutton329hotel");
int moismois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton329hotel));

spinbutton328hotel=lookup_widget(button, "spinbutton328hotel");
int anneeannee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton328hotel));

input1=lookup_widget(button,"entry429hotel");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(button,"entry431hotel");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));

input3=lookup_widget(button,"entry432hotel");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input3)));

combobox11hotel=lookup_widget(button, "combobox11hotel");
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11hotel)));

input4=lookup_widget(button,"entry433hotel");
strcpy(e,gtk_entry_get_text(GTK_ENTRY(input4)));


hotel=fopen("/home/rihab/projectvol/hotel.txt","a+");
fprintf(hotel,"%s %s %d %d %d %s %s %s\n",a,b,jourjour,moismois,anneeannee,d,c,e);
fclose(hotel);

}


void
on_button2hotel_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"window5");
gtk_widget_hide(window);
window1=create_window6();
gtk_widget_show_all(window1);
}


void
on_button15hotel_clicked               (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *window7;
GtkWidget *window10;
GtkWidget *input160, *output160;
	   
            char cp[50];
           FILE *f3 ;
           FILE *fhotel;
            window7=lookup_widget(button,"window7");
            input160=lookup_widget(button,"entry428hotel");
            output160=lookup_widget(button,"label6432");
            strcpy(cp,gtk_entry_get_text(GTK_ENTRY(input160)));
       f3=fopen("/home/rihab/projectvol/hotel.txt","r");
char ville[20], hotel[20], jour[20], mois[20], annee[20], gamme[20], id_hotel[20], tarif[20];
while (fscanf(f3,"%s %s %s %s %s %s %s %s \n",ville, hotel, jour, mois, annee, gamme, id_hotel, tarif)!=EOF)
{ 
if (strcmp(cp,id_hotel)==0)
{
             window7 = create_window7();
             gtk_widget_show(window7);
             gtk_widget_hide(window10);
}
else
{gtk_label_set_text(GTK_LABEL(output160),"id incompatible");}
}


void
on_button13shotel_clicked              (GtkButton       *button,
                                        gpointer         user_data)


{ 

GtkWidget *input80;

            char ch[50];
            FILE *f2 ;
            FILE *fhotel;
input80=lookup_widget(button,"entry428hotel");
            strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input80)));
fhotel=fopen ("/home/rihab/projectvol/hotel.txt","a+");
f2=fopen("/home/rihab/projectvol/userhotel.txt","a+");
char ville[20], hotel[20], jour[20], mois[20], annee[20], gamme[20], id_hotel[20], tarif[20];


                       while (fscanf(f2,"%s %s %s %s %s %s %s %s \n",ville, hotel, jour, mois, annee, gamme, id_hotel, tarif)!=EOF)
{ 
if (strcmp(ch,id_hotel)!=0)
{
fprintf(fhotel,"%s %s %s %s %s %s %s %s\n",ville, hotel, jour, mois, annee,gamme, id_hotel, tarif);}
 }
fclose(fhotel);
fclose(f2);
remove ("/home/rihab/projectvol/userhotel.txt");
rename ("/home/rihab/projectvol/hotel.txt","/home/rihab/projectvol/userhotel.txt");

}


 

}





