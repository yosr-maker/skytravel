#include <string.h>
#include "log.h"

void ajouter(char login[], char password[],int role) 

{file *f;
f=fopen("users.txt","a+");
if(f!=NULL) {
for (i=0;i<20;i++);
printf("saisir les données");
fflush(stdin);
gets(login);
fflush(stdin);
gets(password);
scanf("%d",&role);
fprintf(f,"%s %s %d \n", login, password,role);}
fclose(f);
}
else printf("impossible d'ouvrir le fichier");

void afficher (char login[], char password[],int role)
f=fopen("users.txt","r");
if(f!=NULL)
{
while (fscanf(f,"%s %s %d \n" ,login , password,role)!= EOF 
printf(f,"%s %s %d \n" ,login , password,role);
 

 int verifier (char login[], char password[],int role );
{file *f;
char login2[35],password2[35];
int r;
f=f open("user.txt","r");
if (f!=NULL)
{while (fscanf("f,%s %s %d \n",login2,password2,&role)=EOF)
{if strcmp(login,login2)==0 && strcmp(password,password2)==0)}
r=role;
return r;
}
