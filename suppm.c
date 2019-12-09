#include "suppm.h"




void supprimerm(char idf[])
{
        char  IDF[50] ;
        char  MONTANT[50] ;
        char  NCARTE[50] ;
        char  DATE[50] ;
        char  CODE[50] ;
	
FILE *u=fopen("facturation.txt","r");
FILE *t=fopen("tamp.txt","a+");
if (u!=NULL) 
{ 
while(fscanf(u,"%s %s %s %s %s \n",IDF,MONTANT,NCARTE,DATE,CODE)!=EOF)
{
if (strcmp(IDF,idf)!=0)
{

fprintf(t,"%s %s %s %s %s \n",IDF,MONTANT,NCARTE,DATE,CODE);
}
}
}
fclose(u);
fclose(t);
remove("facturation.txt");
rename("tamp.txt","facturation.txt");
}
