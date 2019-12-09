#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>
#include "client.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_valider_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
/*char combobox1;
int a,b,e;
client c;

GtkWidget *input1,*input2, *input3, *input4,*input6,*input7,*input8,*input9,*input10;
GtkWidget *sexe;
char j[20];


input1=lookup_widget(objet, "identifiant");
input2=lookup_widget(objet, "nom");
input3=lookup_widget(objet, "prenom");
input4=lookup_widget(objet, "cin");
sexe=lookup_widget(objet, "combobox3");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));

input6=lookup_widget(objet, "jour");
input7=lookup_widget(objet, "mois");
input8=lookup_widget(objet, "annee");
input9=lookup_widget(objet, "mail");
input10=lookup_widget(objet, "password");

strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(combobox1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input10)));

ajouter_client(c);*/
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *input10;
FILE *f;
char a[30],b[30],i[30],j[30],k[30],l[30],m[30]; int c,d,e;
/*char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30],a11[30],a12[30];*/
input1=lookup_widget(button,"identifiant");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(button,"nom");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));

input6=lookup_widget(button,"prenom");
strcpy(i,gtk_entry_get_text(GTK_ENTRY(input6)));

input8=lookup_widget(button,"cin");
strcpy(k,gtk_entry_get_text(GTK_ENTRY(input8)));

input7=lookup_widget(button, "combobox3");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

input3=lookup_widget(button, "jour");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

input4=lookup_widget(button,"mois");
d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

input5=lookup_widget(button,"annee");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));

input9=lookup_widget(button,"mail");
strcpy(l,gtk_entry_get_text(GTK_ENTRY(input9)));

input10=lookup_widget(button,"password");
strcpy(m,gtk_entry_get_text(GTK_ENTRY(input10)));

f=fopen("/home/zac/Projects/crudi/src/clieent.txt","a+");
	if(f!=NULL)
	{
   		fprintf(f,"%s %s %s %s %s %d %d %d %s %s \n",a,b,i,k,j,c,d,e,l,m); 
   

	}
	fclose(f);
		


}




void
on_buttonconfirmer_clicked             (GtkWidget        *button,
                                        gpointer         user_data)
{
FILE *f;
GtkWidget *entryid2;
GtkWidget *ancienn,*ancienp,*ancienc,*anciens,*ancienj,*ancienm,*anciena,*ancienmail,*ancienmdp;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30];
char a[30];

entryid2=lookup_widget(button,"identifiant2");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryid2)));

ancienn=lookup_widget(button,"ancienn");
ancienp=lookup_widget(button,"ancienp");
ancienc=lookup_widget(button,"ancienc");
anciens=lookup_widget(button,"anciens");
ancienj=lookup_widget(button,"ancienj");
ancienm=lookup_widget(button,"ancienm");
anciena=lookup_widget(button,"anciena");
ancienmail=lookup_widget(button,"ancienmail");
ancienmdp=lookup_widget(button,"ancienmdp");






f = fopen("/home/zac/Projects/crudi/src/clieent.txt", "r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)!=EOF)
{
if(strcmp(a,a1)==0)
{gtk_label_set_text(GTK_LABEL(ancienn),a2);
gtk_label_set_text(GTK_LABEL(ancienp),a3);
gtk_label_set_text(GTK_LABEL(ancienc),a4);
gtk_label_set_text(GTK_LABEL(anciens),a5);
gtk_label_set_text(GTK_LABEL(ancienj),a6);
gtk_label_set_text(GTK_LABEL(ancienm),a7);
gtk_label_set_text(GTK_LABEL(anciena),a8);
gtk_label_set_text(GTK_LABEL(ancienmail),a9);
gtk_label_set_text(GTK_LABEL(ancienmdp),a10);

}


}
}

void
on_buttonn_modifier_clicked            (GtkWidget        *button,
                                        gpointer         user_data)
{ GtkWidget *entryid2;
GtkWidget *entrynom, *entryprenom,*entrycin,*entrysexe,*entryjour,*entrymois,*entryannee,*entrymail,*entrymdp;
FILE *f,*fich;
char a[30],b[30],c[30],d[30],h[30],i[30],k[30]; int e,f1,g;
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30],a10[30];


entryid2=lookup_widget(button,"identifiant2");
strcpy(k,gtk_entry_get_text(GTK_ENTRY(entryid2)));

entrynom=lookup_widget(button,"nnom");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrynom)));

entryprenom=lookup_widget(button,"nprenom");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

entrycin=lookup_widget(button,"ncin");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(entrycin)));

entrysexe=lookup_widget(button, "combobox2");
strcpy(d,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));

entryjour=lookup_widget(button,"njour");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));

entrymois=lookup_widget(button,"nmois");
f1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrymois));

entryannee=lookup_widget(button,"nannee");
g=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));

entrymail=lookup_widget(button,"nmail");
strcpy(h,gtk_entry_get_text(GTK_ENTRY(entrymail)));


entrymdp=lookup_widget(button,"npassword");
strcpy(i,gtk_entry_get_text(GTK_ENTRY(entrymdp)));


f=fopen("/home/zac/Projects/crudi/src/clieent.txt","r");
fich=fopen("/home/zac/Projects/crudi/src/tempclieent.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10)!=EOF)
{
if(strcmp(k,a1)==0)
{
fprintf(fich,"%s %s %s %s %s %d %d %d %s %s\n",a1,a,b,c,d,e,f1,g,h,i); 

}
else fprintf(fich,"%s %s %s %s %s %s %s %s %s %s\n",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);


}

fclose(f);
fclose(fich);
remove("/home/zac/Projects/crudi/src/clieent.txt");
rename("/home/zac/Projects/crudi/src/tempclieent.txt","/home/zac/Projects/crudi/src/clieent.txt");
FILE* fichier = NULL;

fichier = fopen("home/zac/Projects/crudi/src/tempclieent.txt", "w");
if (fichier != NULL)
{
fputs("", fichier);
fclose(fichier);
}




}


void
on_supprimer_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
char a[30];
char a1[30],a2[30],a3[30],a4[30],a5[30],a6[30],a7[30],a8[30],a9[30];
GtkWidget *entrysupclient;
GtkWidget *output2;
FILE *f;
output2=lookup_widget(objet,"labelerrorclient");

entrysupclient=lookup_widget(objet,"suppclient");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrysupclient)));

int n=0;

f=fopen("/home/zac/Projects/crudi/src/clieent.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s ",a1,a2,a3,a4,a5,a6,a7,a8,a9)!=EOF){

	if(strcmp(a1,a)==0) n++;	
	
}


fclose(f);
if(n!=0) {gtk_label_set_text(GTK_LABEL(output2),"suppression réussite");
sup_offre(a,f);}
else gtk_label_set_text(GTK_LABEL(output2),"Id client inexistant");


}


void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *notebook;
GtkWidget *window1;
window1=lookup_widget(button,"window1");
notebook=lookup_widget(window1,"notebook1");
treeview1=lookup_widget(window1,"treeview1");
afficher1(treeview1);
}


void
on_affich1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *notebook;
GtkWidget *window1;
window1=lookup_widget(button,"window1");
notebook=lookup_widget(window1,"notebook1");
treeview1=lookup_widget(window1,"treeview1");
afficher1(treeview1);
}

