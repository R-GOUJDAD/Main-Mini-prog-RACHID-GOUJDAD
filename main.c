#include <stdio.h>
#include <stdlib.h>

typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;
client cl;

typedef struct dat{
int jour;
int mois;
int annee;
}date;
typedef struct contratLocation
{
 float numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int cout;
} contrat;
contrat cont;
typedef struct Voiture
{
 int idVoiture;
 char marque[15];
 char nomVoiture[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 char EnLocation[4];
}voiture;
voiture voitur;




int reche(int Idvoitur){

FILE *F;
F=fopen("voitures.txt","r");
do{
fscanf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,&voitur.idVoiture,&voitur.marque,&voitur.nomVoiture,&voitur.couleur,&voitur.nbplaces,&voitur.prixJour,&voitur.EnLocation);
fflush(stdin);
if(voitur.idVoiture==Idvoitur){
    fclose(F);
    return 1;
}
}
while(!feof(F));
fclose(F);
return -1;
}


void Ajotervoitur(){
FILE *F;
int Idvoitur;
F=fopen("voitures.txt","a");
printf("\n Entre le Idvoiture :");
scanf("%d",&Idvoitur);
fflush(stdin);
while(reche(Idvoitur)==1){
    printf("\n cette voiture existe deja : ");
    printf("Entre le Idvoiture :");
    scanf("%d",&Idvoitur);
}
voitur.idVoiture=Idvoitur;
printf("\n Entre la marque :");
gets(voitur.marque);
fflush(stdin);
printf("\n Entre NomVoiture :");
gets(voitur.nomVoiture);
fflush(stdin);
printf("\n Entre couleur :");
gets(voitur.couleur);
fflush(stdin);
printf("\n Entre nbplaces :");
scanf("%d",&voitur.nbplaces);
fflush(stdin);
printf("\n Entre prixJour :");
scanf("%d",&voitur.prixJour);
fflush(stdin);
printf("\n Entre Elocation :");
gets(voitur.EnLocation);
fflush(stdin);
fprintf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,voitur.idVoiture,voitur.marque,voitur.nomVoiture,voitur.couleur,voitur.nbplaces,voitur.prixJour,voitur.EnLocation);
fclose(F);
}


void afechList(){

FILE *F;
F=fopen("voitures.txt","r");
do{
  fscanf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,&voitur.idVoiture,&voitur.marque,&voitur.nomVoiture,&voitur.couleur,&voitur.nbplaces,&voitur.prixJour,&voitur.EnLocation);

    printf("les information sur le voiture\n\n");
    printf("idVoiture :%d\n",voitur.idVoiture);
    printf("marque :%s\n",voitur.marque);
    printf("nomVoiture :%s\n",voitur.nomVoiture);
    printf("couleur :%s\n",voitur.couleur);
    printf("nbplaces :%d\n",voitur.nbplaces);
    printf("prixJour :%d\n",voitur.prixJour);
    printf("EnLocation :%s\n",voitur.EnLocation);



}while(!feof(F));
fclose(F);
}


void SupprimerVoiture(){
    char rep;
    int Idvoiture;
    printf("Entre Idvoiture a Supprimer :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche(Idvoiture)==1){
    printf("\n vouler vous vraimment Supprimer o ? \n:");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){
        FILE *fich, *F;
        F=fopen("voitures.txt","r");
        fich=fopen("fichTemp.txt","a");
        do{
            fscanf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,&voitur.idVoiture,&voitur.marque,&voitur.nomVoiture,&voitur.couleur,&voitur.nbplaces,&voitur.prixJour,&voitur.EnLocation);
           if(Idvoiture!=voitur.idVoiture){
            fprintf(fich,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,voitur.idVoiture,voitur.marque,voitur.nomVoiture,voitur.couleur,voitur.nbplaces,voitur.prixJour,voitur.EnLocation);

           }
        }while(!feof(F));
        fclose(fich);
        fclose(F);
        remove("voitures.txt");
        rename("fichTemp.txt","voitures.txt");
        printf("suppression Effecter avec succees");
    }
    }
}

void ModifierVoiture(){
    char rep='n';
     FILE *fich, *F;
    int Idvoiture,i;
    printf("Entre Idvoiture de voiture a Modifier :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche(Idvoiture)==1){
    printf("\n vouler vous vraimment Modifier o/n? :");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){

        F=fopen("voitures.txt","r");
        fich=fopen("fichTemp.txt","a");
        do{
            fscanf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,&voitur.idVoiture,&voitur.marque,&voitur.nomVoiture,&voitur.couleur,&voitur.nbplaces,&voitur.prixJour,&voitur.EnLocation);
           if(Idvoiture==voitur.idVoiture){

printf("\n Entre noveu Idvoiture  :");
scanf("%d",&voitur.idVoiture);
 fflush(stdin);
printf("\n Entre la marque :");
gets(voitur.marque);

printf("\n Entre NomVoiture :");
gets(voitur.nomVoiture);

printf("\n Entre couleur :");
gets(voitur.couleur);

printf("\n Entre nbplaces :");
scanf("%d",&voitur.nbplaces);
 fflush(stdin);
printf("\n Entre prixJour :");
scanf("%d",&voitur.prixJour);
 fflush(stdin);
printf("\n Entre Elocation :");
gets(voitur.EnLocation);

           }
fprintf(fich,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,voitur.idVoiture,voitur.marque,voitur.nomVoiture,voitur.couleur,voitur.nbplaces,voitur.prixJour,voitur.EnLocation);
           }while(!feof(F));
           fclose(F);
           fclose(fich);
           remove("voitures.txt");
        rename("fichTemp.txt","voitures.txt");

        printf("\n la modification a reussi ");
    }else{
        printf("la modification a ete annule \n");
    }
    }else{
        printf("\n Ce Idvoiture n'existe pas");
    }
}

 void gestionVoiture(){
   int chox;char rep;
   do{
    system("cls");
    printf("gestion des voitures  :\n======================\n");
    printf(" listes des voitures..............1\n Ajouter voiturs..................2\n Modifier voitures................3\n supprimer voitures...............4\n retour...........................5\n:");
   do{
    printf("\nEntre votr choix :");
    scanf("%d",&chox);
   }while(chox<1||chox>5);
   switch(chox){
   case 1:
    afechList();
     break;
       case 2:
    Ajotervoitur();
     break;
       case 3:
    ModifierVoiture();
     break;
       case 4:
    SupprimerVoiture();
     break;
       case 5:
           rep='n';
           break;
   }

   }while(rep=='o');
    }




    int reche1(int Idvoitur){

FILE *F;
F=fopen("contra.txt","r");
do{
fscanf(F,"%f %d %d %d %d %d %d %d %d %d" ,&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
fflush(stdin);
if(cont.numContrat==Idvoitur){
    fclose(F);
    return 1;
}
}
while(!feof(F));
fclose(F);
return -1;
}




void afechContrat(){
    int Idvoitur;
    printf("Entre idContrat ");
    scanf("%d",&Idvoitur);
FILE *F;
F=fopen("contra.txt","r");
do{
fscanf(F,"%f %d %d %d %d %d %d %d %d %d" ,&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
fflush(stdin);
if(cont.numContrat==Idvoitur){
         printf("les information sur le contrate\n\n");
    printf("numContra :%f\n",cont.numContrat);
    printf("idVoiture :%d\n",cont.idVoiture);
    printf("idClien :%d\n",cont.idClient);
    printf("la date :   debute :");
    printf("jour :%d ",cont.debut.jour);
    printf("mois :%d ",cont.debut.mois);
    printf("annee :%d    ",cont.debut.annee);
    printf(" fin :");
    printf("jour :%d  ",cont.fin.jour);
    printf("mois :%d  ",cont.fin.mois);
    printf("annee :%d  \n",cont.fin.annee);
    printf("Cout :%d  \n",cont.cout);
}

}
while(!feof(F));

fclose(F);


}





void louercontrat(){
FILE *F;
F=fopen("contra.txt","a");

printf("\n Entre le numContrat  :");
scanf("%f",&cont.numContrat);

printf("\n Entre le idVoiture  :");
scanf("%d",&cont.idVoiture);

printf("\n Entre le idClient   :");
scanf("%d",&cont.idClient);

printf("\n Entre le debut.jour :");
scanf("%d",&cont.debut.jour);

printf("\n Entre le debut.mois  :");
scanf("%d",&cont.debut.mois);

printf("\n Entre le debut.annee  :");
scanf("%d",&cont.debut.annee);

printf("\n Entre le fin.jour :");
scanf("%d",&cont.fin.jour);

printf("\n Entre le fin.mois  :");
scanf("%d",&cont.fin.mois);

printf("\n Entre le fin.annee  :");
scanf("%d",&cont.fin.annee);

printf("\n Entre le cout :");
scanf("%d",&cont.cout);

 fprintf(F,"%f %d %d %d %d %d %d %d %d %d " ,cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);
fclose(F);
}


void supprumcontra(){

    int Idvoiture;
    printf("Entre Idcontra  :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche1(Idvoiture)==1){
        FILE *fich, *F;
        F=fopen("contra.txt","r");
        fich=fopen("contraTemp.txt","a");
        do{
           fscanf(F,"%f %d %d %d %d %d %d %d %d %d" ,&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
           if(Idvoiture!=cont.numContrat){
           fprintf(fich,"%f %d %d %d %d %d %d %d %d %d " ,cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);
           }
        }while(!feof(F));

        fclose(F);
        fclose(fich);
          remove("contra.txt");
        rename("contraTemp.txt","contra.txt");
        printf("suppression Effecter avec succees");

    }
}




void Modifiercontrat(){
    char rep='n';
     FILE *fich, *F;
    int Idvoiture;
    printf("Entre Idvoiture de idcontrat a Modifier :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche1(Idvoiture)==1){
    printf("\n vouler vous vraimment Modifier o\n? :");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){

        F=fopen("contra.txt","r");
        fich=fopen("contraTemp.txt","a");
        do{
         fscanf(F,"%f %d %d %d %d %d %d %d %d %d " ,&cont.numContrat,&cont.idVoiture,&cont.idClient,&cont.debut.jour,&cont.debut.mois,&cont.debut.annee,&cont.fin.jour,&cont.fin.mois,&cont.fin.annee,&cont.cout);
           if(Idvoiture==cont.numContrat){

printf("\n Entre le numContrat  :");
scanf("%f",&cont.numContrat);

printf("\n Entre le idVoiture  :");
scanf("%d",&cont.idVoiture);

printf("\n Entre le idClient   :");
scanf("%d",&cont.idClient);

printf("\n Entre le debut.jour :");
scanf("%d",&cont.debut.jour);

printf("\n Entre le debut.mois  :");
scanf("%d",&cont.debut.mois);

printf("\n Entre le debut.annee  :");
scanf("%d",&cont.debut.annee);

printf("\n Entre le fin.jour :");
scanf("%d",&cont.fin.jour);

printf("\n Entre le fin.mois  :");
scanf("%d",&cont.fin.mois);

printf("\n Entre le fin.annee  :");
scanf("%d",&cont.fin.annee);

printf("\n Entre le cout :");
scanf("%d",&cont.cout);
           }
 fprintf(fich,"%f %d %d %d %d %d %d %d %d %d " ,cont.numContrat,cont.idVoiture,cont.idClient,cont.debut.jour,cont.debut.mois,cont.debut.annee,cont.fin.jour,cont.fin.mois,cont.fin.annee,cont.cout);




           }while(!feof(F));
           fclose(F);
           fclose(fich);
           remove("contra.txt");
        rename("contraTemp.txt","contra.txt");

        printf("\n la modification a reussi ");
    }else{
        printf("la modification a ete annule \n");
    }
    }else{
        printf("\n Ce Idvoiture n'existe pas");
    }
}







void retournvoiture(){
     char rep='n';
     FILE *fich, *F;
    int Idvoiture,i;
    printf("Entre Idvoiture de voiture a Modifier :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche(Idvoiture)==1){
    printf("\n vouler vous vraimment Modifier o/n? :");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){

        F=fopen("voitures.txt","r");
        fich=fopen("fichTemp.txt","a");
        do{
            fscanf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,&voitur.idVoiture,&voitur.marque,&voitur.nomVoiture,&voitur.couleur,&voitur.nbplaces,&voitur.prixJour,&voitur.EnLocation);
           if(Idvoiture==voitur.idVoiture){


printf("\n Entre (Non) dans Elocation :");
gets(voitur.EnLocation);

           }
fprintf(fich,"%d ;%s ;%s ;%s ;%d ;%d ;%s " ,voitur.idVoiture,voitur.marque,voitur.nomVoiture,voitur.couleur,voitur.nbplaces,voitur.prixJour,voitur.EnLocation);
           }while(!feof(F));
           fclose(F);
           fclose(fich);
           remove("voitures.txt");
        rename("fichTemp.txt","voitures.txt");

        printf("\n la modification a reussi ");
    }else{
        printf("la modification a ete annule \n");
    }
    }else{
        printf("\n Ce Idvoiture n'existe pas");
    }
    printf("\nsuppreme le contrat de cette voiture\n");
    supprumcontra();
}




void LocationVoiture(){
int chox;char rep;
   do{
    system("cls");
   printf("  location d'une voiture  :\n======================\n");
    printf(" visualiser contrat..............1\n louer voiture...................2\n retourner la voiture............3\n modifier contrat................4\n supprimer contrat...............5\n retour..........................6\n");
   do{
    printf("\nEntre votr choix :");
    scanf("%d",&chox);
   }while(chox<1||chox>6);
   switch(chox){
    case 1:
afechContrat();
     break;
       case 2:
 louercontrat();
     break;
       case 3:
retournvoiture();
     break;
       case 4:
Modifiercontrat();
     break;
     case 5:
supprumcontra();
     break;
     case 6:
         rep='n';
     break;

   }

   }while(rep=='o'||rep=='O');
}




int reche2(int Idvoitur){

FILE *F;
F=fopen("cl.txt","r");
do{
fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d " ,&cl.idClient,&cl.nom,&cl.prenom,&cl.cin,&cl.adresse,&cl.telephone);
fflush(stdin);
if(cl.idClient==Idvoitur){
    fclose(F);
    return 1;
}
}
while(!feof(F));
fclose(F);
return -1;
}


void afechListClient(){

FILE *F;
F=fopen("cl.txt","r");
do{
 fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d " ,&cl.idClient,&cl.nom,&cl.prenom,&cl.cin,&cl.adresse,&cl.telephone);

    printf("les information sur le cleint\n\n");
    printf("idClient :%d\n",cl.idClient);
    printf("nom :%s\n",cl.nom);
    printf("prenom :%s\n",cl.prenom);
    printf("cin :%d\n",cl.cin);
    printf("adresse :%s\n",cl.adresse);
    printf("telephone :%d\n",cl.telephone);



}while(!feof(F));
fclose(F);
}




void Ajoterclient(){
FILE *F;
int Idvoitur;
F=fopen("cl.txt","a");
printf("\n Entre le Idclient :");
scanf("%d",&Idvoitur);

while(reche2(Idvoitur)==1){
    printf("\n ce client existe deja : ");
    printf("Entre le Idcleiint :");
    scanf("%d",&Idvoitur);
}
cl.idClient=Idvoitur;

printf("\n Entre nom client :");
gets(cl.nom);
fflush(stdin);
printf("\n Entre prenom de client :");
gets(cl.prenom);
fflush(stdin);
printf("\n Entre cin de client :");
scanf("%d",&cl.cin);
fflush(stdin);
printf("\n Entre addresse de client :");
gets(cl.adresse);
fflush(stdin);
printf("\n Entre telephone de client :");
scanf("%d",&cl.telephone);
fflush(stdin);
fprintf(F,"%d ;%s ;%s ;%d ;%s ;%d " ,cl.idClient,cl.nom,cl.prenom,cl.cin,cl.adresse,cl.telephone);
fclose(F);
}




void SupprimeClient(){
    char rep;
    int Idvoiture;
    printf("Entre Idclient a Supprimer :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche2(Idvoiture)==1){
    printf("\n vouler vous vraimment Supprimer o ? \n:");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){
        FILE *fich, *F;
        F=fopen("cl.txt","r");
        fich=fopen("clTemp.txt","a");
        do{
            fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d " ,&cl.idClient,&cl.nom,&cl.prenom,&cl.cin,&cl.adresse,&cl.telephone);
           if(Idvoiture!=cl.idClient){
            fprintf(fich,"%d ;%s ;%s ;%d ;%s ;%d " ,cl.idClient,cl.nom,cl.prenom,cl.cin,cl.adresse,cl.telephone);

           }
        }while(!feof(F));
        fclose(fich);
        fclose(F);
        remove("cl.txt");
        rename("clTemp.txt","cl.txt");
        printf("suppression Effecter avec succees");
    }
    }
}




void Modifierclient(){
    char rep='n';
     FILE *fich, *F;
    int Idvoiture,i;
    printf("Entre Idclient a Modifier :");
    scanf("%d",&Idvoiture);
    fflush(stdin);
    if(reche2(Idvoiture)==1){
    printf("\n vouler vous vraimment Modifier o\n? :");
    scanf("%c",&rep);
    fflush(stdin);
    if (rep=='o'||rep=='O'){

        F=fopen("cl.txt","r");
        fich=fopen("clTemp.txt","a");
        do{
            fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d " ,&cl.idClient,&cl.nom,&cl.prenom,&cl.cin,&cl.adresse,&cl.telephone);
           if(Idvoiture==cl.idClient){

printf("\n Entre noveu Idclient  :");
scanf("%d",&cl.idClient);
 fflush(stdin);
printf("\n Entre nom client :");
gets(cl.nom);
fflush(stdin);
printf("\n Entre prenom de client :");
gets(cl.prenom);
fflush(stdin);
printf("\n Entre cin de client :");
scanf("%d",&cl.cin);
fflush(stdin);
printf("\n Entre addresse de client :");
gets(cl.adresse);
fflush(stdin);
printf("\n Entre telephone de client :");
scanf("%d",&cl.telephone);
fflush(stdin);

           }
 fprintf(fich,"%d ;%s ;%s ;%d ;%s ;%d " ,cl.idClient,cl.nom,cl.prenom,cl.cin,cl.adresse,cl.telephone);

           }while(!feof(F));
           fclose(F);
           fclose(fich);
           remove("cl.txt");
        rename("clTemp.txt","cl.txt");

        printf("\n la modification a reussi ");
    }else{
        printf("la modification a ete annule \n");
    }
    }else{
        printf("\n Ce Idclient n'existe pas");
    }
}




void gestionClients()
{
   int chox;char rep;
   do{
    system("cls");
    printf("gestion des clients  :\n======================\n");
    printf(" listes des clients..............1\n Ajouter client..................2\n Modifier client.................3\n supprimer client................4\n retour..........................5\n:");
   do{
    printf("\nEntre votr choix :");
    scanf("%d",&chox);
   }while(chox<1||chox>5);
   switch(chox){
   case 1:
    afechListClient();
     break;
       case 2:
   Ajoterclient();
     break;
       case 3:
    Modifierclient();
     break;
       case 4:
    SupprimeClient();
     break;
       case 5:
           rep='n';
           break;
   }

   }while(rep=='o'||rep=='O');

}



int main()
{
    int chox,i=1;
   while(i!=2){
    system("cls");
    printf("  Menu principl  :\n======================\n");
    printf(" Location..............1\n gestoin voitures......2\n gestion client........3\n Quiter................4\n");
   do{
    printf("\nEntre votr choix :");
    scanf("%d",&chox);
   }while(chox<1||chox>4);
   switch(chox){
   case 1:
 LocationVoiture();
     break;
       case 2:
 gestionVoiture();
     break;
       case 3:
 gestionClients();
     break;
       case 4:
     i=0;
     break;

   }


   };



    return 0;
}

