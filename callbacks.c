#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonct.h"


void
on_buttonajouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *aceuil;
window=lookup_widget(button,"aceuil");
gtk_widget_hide(window);
aceuil=create_ajout();
gtk_widget_show_all(aceuil);
}


void
on_buttonmodifier_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *aceuil;
window=lookup_widget(button,"aceuil");
gtk_widget_hide(window);
aceuil=create_modification();
gtk_widget_show_all(aceuil);
}


void
on_buttonsuprimer_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *aceuil;
window=lookup_widget(button,"aceuil");
gtk_widget_hide(window);
aceuil=create_supression();
gtk_widget_show_all(aceuil);
}


void
on_buttonafficher_clicked               (GtkWidget       *button,
                                         gpointer         user_data)
{
GtkWidget *window;
GtkWidget *aceuil;
GtkWidget *treeview1;
window=lookup_widget(button,"aceuil");
gtk_widget_hide(window);
aceuil=create_affichage();
gtk_widget_show_all(aceuil);
treeview1=lookup_widget(aceuil,"treeview1");
affich(treeview1);
}



void
on_buttonback1_clicked                 (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *ajout;
window=lookup_widget(button,"ajout");
gtk_widget_hide(window);
ajout=create_aceuil();
gtk_widget_show_all(ajout);

}


void
on_buttonback2_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *modification;
window=lookup_widget(button,"modification");
gtk_widget_hide(window);
modification=create_aceuil();
gtk_widget_show_all(modification);

}


void
on_buttonback3_clicked                 (GtkWidget        *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *supression;
window=lookup_widget(button,"supression");
gtk_widget_hide(window);
supression=create_aceuil();
gtk_widget_show_all(supression);

}


void
on_buttonback4_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *affichage;
window=lookup_widget(button,"affichage");
gtk_widget_hide(window);
affichage=create_aceuil();
gtk_widget_show_all(affichage);

}

//ajouter ajouter ajouter ajouter ajouter ajouter ajouter ajouter //

void
on_buttoncree_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *entryCin;
GtkWidget *entrynom;
GtkWidget *entryprenom;
GtkWidget *entrymail;
GtkWidget *entrypass;
GtkWidget *output;
GtkWidget *spinbutton1;

FILE *ag;

char a[20], b[20], c[20], d[20], e[20],civ[20];

spinbutton1=lookup_widget(button, "spinbutton1");
int age=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton1));

entryCin=lookup_widget(button,"entryCin");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryCin)));

combobox1=lookup_widget(button, "combobox1");
strcpy(civ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

entrynom=lookup_widget(button,"entrynom");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(entrynom)));

entryprenom=lookup_widget(button,"entryprenom");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(entryprenom)));

entrymail=lookup_widget(button,"entrymail");
strcpy(d,gtk_entry_get_text(GTK_ENTRY(entrymail)));

entrypass=lookup_widget(button,"entrypass");
strcpy(e,gtk_entry_get_text(GTK_ENTRY(entrypass)));

ag=fopen("/home/baha/Projets/projet1/src/agnt.txt","a+");

char a1[20],age1[12], b1[20], c1[20], d1[20], e1[20],civ1[20], ext[60];
int x=0;

while (fscanf(ag,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1)!=EOF)
{
   if ((strcmp(a, a1)== 0))
    { 
	strcpy(ext,"ce compte existe");
	output=lookup_widget(button,"labelexist");
	gtk_label_set_text(GTK_LABEL(output),ext);
        x=1;	
        break;
    }
}
if(x==0) {fprintf(ag,"%s %d %s %s %s %s %s\n",civ,age,a,b,c,d,e);
strcpy(ext,"ajoute avec succée");
	output=lookup_widget(button,"labelexist");
	gtk_label_set_text(GTK_LABEL(output),ext);
char a2[20]="", b2[20]="", c2[20]="", d2[20]="", e2[20]="";
gtk_entry_set_text(GTK_ENTRY(entryCin),a2);
gtk_entry_set_text(GTK_ENTRY(entrynom),b2);
gtk_entry_set_text(GTK_ENTRY(entryprenom),c2);
gtk_entry_set_text(GTK_ENTRY(entrymail),d2);
gtk_entry_set_text(GTK_ENTRY(entrypass),e2);


}
fclose(ag);
}

//suprimer suprimer suprimer suprimer suprimer suprimer suprimer suprimer//

void
on_buttonsupp_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)

{
GtkWidget *entrycinsupp;
GtkWidget *output;
char a[20];
char a2[20]="";

entrycinsupp=lookup_widget(button,"entrycinsupp");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrycinsupp)));

FILE *ag;
FILE *sup;
char b[20], c[20], d[20], e[20],civ[20],age[12];
ag=fopen("/home/baha/Projets/projet1/src/agnt.txt","a+");

char a1[20],age1[12],b1[20], c1[20], d1[20], e1[20],civ1[20], ext[60];
int x=0;
sup=fopen("/home/baha/Projets/projet1/src/sup.txt","w+");
while (fscanf(ag,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1)!=EOF)
{
   if ((strcmp(a, a1)!= 0))
    {  
        

        fprintf(sup,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1);
        
	strcpy(ext,"ce compte n'existe pas");
	output=lookup_widget(button,"labelexist1");
	gtk_label_set_text(GTK_LABEL(output),ext);
        gtk_entry_set_text(GTK_ENTRY(entrycinsupp),a2);
        x=1;	
        
    }
}
if(x==0) {fprintf(ag,"%s %s %s %s %s %s %s\n",civ,age,a,b,c,d,e);
strcpy(ext,"supprimé avec succée");
	output=lookup_widget(button,"labelexist1");
	gtk_label_set_text(GTK_LABEL(output),ext);
        gtk_entry_set_text(GTK_ENTRY(entrycinsupp),a2);
}
fclose(ag);
fclose(sup);
remove("/home/baha/Projets/projet1/src/agnt.txt");
rename("/home/baha/Projets/projet1/src/sup.txt","/home/baha/Projets/projet1/src/agnt.txt");
}


//modifier modifier modifier modifier modifier modifier modifier modifier//

void
on_buttonediter_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *entrycinagent;
GtkWidget *output;



char a[20],v2[20],v[20];
entrycinagent=lookup_widget(button,"entrycinagent");
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entrycinagent)));


FILE *ag;
FILE *temp;
FILE *emp;
emp=fopen("/home/baha/Projets/projet1/src/emp.txt","a+");

char b[20], c[20], d[20], e[20],civ[20],age[12];
ag=fopen("/home/baha/Projets/projet1/src/agnt.txt","a+");
temp=fopen("/home/baha/Projets/projet1/src/temp.txt","w+");
char a1[20],age1[12],b1[20], c1[20], d1[20], e1[20],civ1[20], ext[80];
int x=0;
while (fscanf(ag,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1)!=EOF)
{
   if ((strcmp(a, a1)!= 0))
    {  
        
        strcpy(ext,"ce compte n'existe pas ou pass admin non correct");
	output=lookup_widget(button,"labelexiste2");
	gtk_label_set_text(GTK_LABEL(output),ext);
        x=1;	
        
    }
   else 
    {
	GtkWidget *window;
	GtkWidget *modification;
	window=lookup_widget(button,"modification");
	gtk_widget_hide(window);
	modification=create_modification2();
	gtk_widget_show_all(modification);
        fprintf(temp,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1);
        fprintf(emp,"%s \n",a1);
     }
}


fclose(ag);
fclose(temp);
fclose(emp);
}


void
on_buttonedit_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *combobox2;
 GtkWidget *entry;
 GtkWidget *entrynom1;
 GtkWidget *entrypass2;
 GtkWidget *entryprenom1;
 GtkWidget *entrymail1;
 GtkWidget *spinbutton2;
 GtkWidget *output;
 
 
FILE *ag;
FILE *mod;
FILE *emp;


char z[50];
emp=fopen("/home/baha/Projets/projet1/src/emp.txt","a+");
fscanf(emp,"%s \n",z);

ag=fopen("/home/baha/Projets/projet1/src/agnt.txt","a+");

char a1[20],age1[12],b1[20], c1[20], d1[20], e1[20],civ1[20]; 
char a[20],age[12],b[20], c[20], d[20], e[20],civ[20];
int x=0;
mod=fopen("/home/baha/Projets/projet1/src/mod.txt","a+");
while (fscanf(ag,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1)!=EOF)
{
   if ((strcmp(z, a1)!= 0))
    {  
        

        fprintf(mod,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1);	
        
    }
}

fclose(ag);
fclose(emp);
fclose(mod);
remove("/home/baha/Projets/projet1/src/emp.txt");
remove("/home/baha/Projets/projet1/src/agnt.txt");
rename("/home/baha/Projets/projet1/src/mod.txt","/home/baha/Projets/projet1/src/agnt.txt");



ag=fopen("/home/baha/Projets/projet1/src/agnt.txt","a+");
char a3[20], b3[20], e3[20], c3[20], d3[20],civ3[20], ext[60];
int w=0;
spinbutton2=lookup_widget(button, "spinbutton2");
int age3=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton2));

entry=lookup_widget(button,"entry");
strcpy(a3,gtk_entry_get_text(GTK_ENTRY(entry)));

combobox2=lookup_widget(button, "combobox2");
strcpy(civ3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

entrynom1=lookup_widget(button,"entrynom1");
strcpy(b3,gtk_entry_get_text(GTK_ENTRY(entrynom1)));

entryprenom1=lookup_widget(button,"entryprenom1");
strcpy(c3,gtk_entry_get_text(GTK_ENTRY(entryprenom1)));

entrymail1=lookup_widget(button,"entrymail1");
strcpy(d3,gtk_entry_get_text(GTK_ENTRY(entrymail1)));

entrypass2=lookup_widget(button,"entrypass2");
strcpy(e3,gtk_entry_get_text(GTK_ENTRY(entrypass2)));


while (fscanf(ag,"%s %s %s %s %s %s %s\n",civ1,age1,a1,b1,c1,d1,e1)!=EOF)
{
   if ((strcmp(a3, a1)== 0))
    { 
	strcpy(ext,"ce compte existe");
	output=lookup_widget(button,"label19");
	gtk_label_set_text(GTK_LABEL(output),ext);
        w=1;	
        break;
    }
}
if(w==0) {fprintf(ag,"%s %d %s %s %s %s %s \n",civ3,age3,a3,b3,c3,d3,e3);
strcpy(ext,"modifier avec succée");
	output=lookup_widget(button,"label19");
	gtk_label_set_text(GTK_LABEL(output),ext);}
char a2[20]="", b2[20]="", c2[20]="", d2[20]="";
gtk_entry_set_text(GTK_ENTRY(entry),a2);
gtk_entry_set_text(GTK_ENTRY(entrynom1),b2);
gtk_entry_set_text(GTK_ENTRY(entryprenom1),c2);
gtk_entry_set_text(GTK_ENTRY(entrymail1),d2);
gtk_entry_set_text(GTK_ENTRY(entrypass2),d2);



fclose(ag);
}





void
on_buttonact_clicked                   (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *input;
FILE *temp;
temp=fopen("/home/baha/Projets/projet1/src/temp.txt","a+");
char a[20],b[20], c[20], d[20], e[20],civ[20],age[12];
fscanf(temp,"%s %s %s %s %s %s %s \n",civ,age,a,b,c,d,e);
input=lookup_widget(button,"entry");
gtk_entry_set_text(GTK_ENTRY(input),a);
input=lookup_widget(button,"entrynom1");
gtk_entry_set_text(GTK_ENTRY(input),b);
input=lookup_widget(button,"entryprenom1");
gtk_entry_set_text(GTK_ENTRY(input),c);
input=lookup_widget(button,"entrymail1");
gtk_entry_set_text(GTK_ENTRY(input),d);
input=lookup_widget(button,"entrypass2");
gtk_entry_set_text(GTK_ENTRY(input),e);
}


void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *modification2;
window=lookup_widget(button,"modification2");
gtk_widget_hide(window);
modification2=create_modification();
gtk_widget_show_all(modification2);

}


void
on_buttonhome_clicked                  (GtkWidget        *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *modification2;
window=lookup_widget(button,"modification2");
gtk_widget_hide(window);
modification2=create_aceuil();
gtk_widget_show_all(modification2);

}

