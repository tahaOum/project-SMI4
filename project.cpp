#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

                      /*********************************************************************************
					  *                               												   *
					  *              Projet by : taha oumoussa (Groupe TP: G3b)                  *
		    	      *                               											   	   *
					  *	                                                                               *
					  *********************************************************************************/


//*********************************************************** Prototypes
//Menu principal
  int MenuPrincipal();
  int Location();
  int GestionVoiture();
  int GestionClient();
  char Quiter();
//Gestion voiture
  int  rech(int idV);
  void ListVoiture();
  void AjouterVoiture();
  void ModifierVoiture();
  void SupprimerVoiture();

//location d'une voiture
  int  rechContrat(int num);
  void visualiserContrat();
  void LouerVoiture();
  void RetournerVoiture();
  void ModifierContrat();
  void SupprimerContrat();
//Gestion des clients
  int  rechClient(int num);
  void ListClient();
  void AjouterClient();
  void ModifierClient();
  void SupprimerClient();
  int retour();




//*************************************************************** Struct
typedef struct date
{
int J;
int M;
int A;
}date;

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

typedef struct contratLocation
{
int
 numContrat;
int idVoiture;
int idClient;
date debut;
date fin;
int cout;
}contrat;

typedef struct Client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}client;

//declaration de type struct
voiture V;
contrat Co;
client Cl;



//*********************************************************************** main
main()
{
int a,b,c,d,n;
char q;
menu:
system("cls");
a=MenuPrincipal();
switch(a)
 {
  case 1:
   VC:
   system("cls");
   b=Location();
   switch(b)
     {
       case 1:
       	system("cls");
       	visualiserContrat();
       	n=retour();
       	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    LouerVoiture();
	    n=retour();
	    if(n)
       	 goto VC;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	//RetournerVoiture();
	   	n=retour();
	   	if(n)
       	 goto VC;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	ModifierContrat();
       	n=retour();
       	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	   	SupprimerContrat();
	   	n=retour();
	   	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 6:
	   	system("cls");
	   	goto menu;
	    break;
	  }
   break;

  case 2:
   GV:
   system("cls");
   c=GestionVoiture();
   switch(c)
        {
       case 1:
       	system("cls");
       	ListVoiture();
       	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    AjouterVoiture();
	    n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	ModifierVoiture();
	   	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	SupprimerVoiture();
       	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	    goto menu;
	    break;
	  }
   break;

  case 3:
   GC:
   system("cls");
   d=GestionClient();
   switch(d)
        {
       case 1:
       	system("cls");
       	ListClient();
       	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    AjouterClient();
	    n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	ModifierClient();
	   	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	SupprimerClient();
       	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	   	goto menu;
	    break;
	  }
   break;

  case 4:
   Q:
   q=Quiter();
   if(q=='O' || q=='o')
      system("exit");
   else if(q=='N' || q=='n')
     {
  	  system("cls");
	  goto menu;
	  }
   else
     {
      system("cls");
 	  printf("\n\n\n\t\t Vous devez saisir O pour Oui ou N pour Non !!\n\n");
      goto Q;
	  }

    break;

  default :
  system("cls");
  	 printf("\n\n\t\t Svp saisir un nombre entre 1 et 4 !!\n\n");
  	 goto menu;
 }
}
//***************************************************************** fonction

//fontions menu principal
int retour()
{
 int n;
 printf("\n\n ----------------- Voulez-vous retourner au Menu Principal ou Menu Precedent ? -----------------");
 printf("\n\n                0:Menu principal                                  1:Menu precedent ");
 printf("\n\n                                      votre choix :  ");
 scanf("%d",&n);
 return n;
}
char Quiter()
{
 char q;
 printf("\n\n\n\t\t    Voulez-vous vraiment Quiter O/N ? ");
 printf("\n\n\n\t\t  O:oui                               N:Non  ");
 printf("\n\n\n\t\t            Votre choix : ");
 scanf("%c",&q);
 scanf("%c",&q);
 return q;
}
int MenuPrincipal()
{
    int choix;

	printf("\n                       \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                       \xb3 Menu Principal  \xb3");
	printf("\n                       \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("taha oumoussa\n\n");

    printf("\n          \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n          \xba                                              \xba");
    printf("\n          \xba    Location..............................1   \xba");
    printf("\n          \xba    Gestion voitures......................2   \xba");
    printf("\n          \xba    Gestion clients.......................3   \xba");
    printf("\n          \xba    Quitter...............................4   \xba");
    printf("\n          \xba                                              \xba");
    printf("\n          \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                          Votre choix  :  ");

    scanf("%d",&choix);

    return choix;
}

int Location()
{
    int choix;

	printf("\n                     \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                     \xb3 Location d'une voiture  \xb3");
	printf("\n                     \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n           \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n           \xba                                              \xba");
    printf("\n           \xba    Visualiser contrat...................1    \xba");
    printf("\n           \xba    Louer voiture........................2    \xba");
    printf("\n           \xba    Retourner voiture....................3    \xba");
    printf("\n           \xba    Modifier contrat.....................4    \xba");
    printf("\n           \xba    Supprimer contrat....................5    \xba");
    printf("\n           \xba    Retour...............................6    \xba");
    printf("\n           \xba                                              \xba");
    printf("\n           \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                         Votre choix  :  ");

    scanf("%d",&choix);

    return choix;
}

int GestionVoiture()
{
    int choix;

	printf("\n                     \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                     \xb3 Gestion des voitures \xb3");
	printf("\n                     \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n          \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n          \xba                                              \xba");
    printf("\n          \xba    Liste des voitures....................1   \xba");
    printf("\n          \xba    Ajouter voiture.......................2   \xba");
    printf("\n          \xba    Modifier voiture......................3   \xba");
    printf("\n          \xba    Supprimer voiture.....................4   \xba");
    printf("\n          \xba    Retour................................5   \xba");
    printf("\n          \xba                                              \xba");
    printf("\n          \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                         Votre choix  :  ");

    scanf("%d",&choix);

    return choix;
}

int GestionClient()
{
    int choix;

	printf("\n                       \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                       \xb3 Gestion des clients \xb3");
	printf("\n                       \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n          \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n          \xba                                              \xba");
    printf("\n          \xba    Liste des client......................1   \xba");
    printf("\n          \xba    Ajouter client........................2   \xba");
    printf("\n          \xba    Modifier client.......................3   \xba");
    printf("\n          \xba    Supprimer client......................4   \xba");
    printf("\n          \xba    Retour................................5   \xba");
    printf("\n          \xba                                              \xba");
    printf("\n          \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                         Votre choix  :  ");

    scanf("%d",&choix);

    return choix;
}

//fontions Gestion des voitures
int  rech(int IdV)
 {
  FILE *F;
  F=fopen("GVoiture.txt","r");
  do{
  	 fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d ;%d ;%s \n",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
  	 fflush(stdin);
  	 if(V.idVoiture==IdV)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));
 	fclose(F);
  	     return 0;
 }

void ListVoiture()
 {
  FILE *F;
  F=fopen("GVoiture.txt","r");
  printf(" \n\n               --------------- La liste des voitures --------------- \n\n");
  printf("IdVoiture\t marque\t\t NomVoiture\t\t couleur\t Nbplaces\t prixJour\t Enlocation \n");
  do{
  	 fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d ;%d ;%s \n",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
  	 printf("%d\t\t %s\t\t %s\t\t %s\t\t %d\t\t %d\t\t %s \n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
	}while(fgetc(F)!=EOF);
	fclose(F);
 }

void AjouterVoiture()
 {

 FILE *F;
 int Id;
 F=fopen("GVoiture.txt","a");
 printf("\n  > Entrer le id de nouveau voiture : ");
 scanf("%d",&Id);
 fflush(stdin);
 while(rech(Id)==1)
   {
 	printf("\n  Ce Id exist deja !!");
 	printf("\n > Entrer le id de nouveau voiture :  ");
 	scanf("%d",&Id);
   }
   V.idVoiture=Id;
   printf("\n  > Entrer la marque de Voiture :  ");
   gets(V.marque);
   fflush(stdin);
   printf("\n  > Entrer nom de Voiture :  ");
   gets(V.nomVoiture);
   fflush(stdin);
   printf("\n  > Entrer la couleur de Voiture :  ");
   gets(V.couleur);
   fflush(stdin);
   printf("\n  > Entrer le nombre de places dans Voiture :  ");
   scanf("%d",&V.nbplaces);
   fflush(stdin);
   printf("\n  > Entrer le prix de jour (Dh):  ");
   scanf("%d",&V.prixJour);
   fflush(stdin);
   printf("\n  > Entrer En location:  ");
   gets(V.EnLocation);
   fflush(stdin);
   fprintf(F,"%d ;%s ;%s ;%s ;%d ;%d ;%s \n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
   fclose(F);
 }

void ModifierVoiture()
 {
 char rep;
 int Id;
 printf("\n\n\t\t   Entrer le id voiture a modifier : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rech(Id)==1)
   {
   	printf("\n\n\t\t     Voulez-vous vraiment Modifier O/N ? ");
    printf("\n\n\t\t   O:oui                               N:Non  ");
    printf("\n\n\t\t             Votre choix : ");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o' )
   	  {
   	  FILE *F,*Fich;
	  F=fopen("GVoiture.txt","r");
	  Fich=fopen("TempGVoiture.txt","a");
	  do{
	  	fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d ;%d ;%s \n",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
	  	if(Id==V.idVoiture)
	  	  {
	  	  V.idVoiture=Id;
	  	  printf("\n > Entrer le id de nouveau voiture :  ");
 	      scanf("%d",&V.idVoiture);
 	      fflush(stdin);
          printf("\n  > Entrer le nouveau marque de Voiture :  ");
          gets(V.marque);
          fflush(stdin);
          printf("\n  > Entrer le nouveau nom de Voiture :  ");
          gets(V.nomVoiture);
          fflush(stdin);
          printf("\n  > Entrer le nouveau couleur de Voiture :  ");
          gets(V.couleur);
          fflush(stdin);
          printf("\n  > Entrer le nouveau nombre de places dans Voiture :  ");
          scanf("%d",&V.nbplaces);
          fflush(stdin);
          printf("\n  > Entrer le nouveau prix de jour (Dh):  ");
          scanf("%d",&V.prixJour);
          fflush(stdin);
          printf("\n  > Entrer le nouveau En location:  ");
          scanf("%d",&V.EnLocation);
          fflush(stdin);
          }
		  fprintf(Fich,"%d ;%s ;%s ;%s ;%d ;%d ;%s \n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
	    }while(!feof(F));

	     fclose(Fich);
	     fclose(F);
	     remove("GVoiture.txt");
	     rename("TempGVoiture.txt","GVoiture.txt");
	     printf("\n\nla modification a Reusi!!");
     }
  }
  else
   {
   system("cls");
   printf("\n\n -------------------- Ce id de voiture n'existe Pas !! -------------------- \n");
   ModifierVoiture();
   }
 }

void SupprimerVoiture()
 {
 char rep;
 int Id;
 printf("\n\n\t\t   Entrer le id voiture a supprimer : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rech(Id)==1)
   {
   	printf("\n\n\t\t     Voulez-vous vraiment Supprimer O/N ? ");
    printf("\n\n\t\t   O:oui                               N:Non  ");
    printf("\n\n\t\t             Votre choix : ");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o' )
   	 {
   	  FILE *F,*Fich;
	  F=fopen("GVoiture.txt","r");
	  Fich=fopen("TempGVoiture.txt","a");
	  do{
	  	fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d ;%d ;%s \n",&V.idVoiture,&V.marque,&V.nomVoiture,&V.couleur,&V.nbplaces,&V.prixJour,&V.EnLocation);
	  	if(Id!=V.idVoiture)
	  	  {
	  	  	fprintf(Fich,"%d ;%s ;%s ;%s ;%s ;%d ;%d ;%s \n",V.idVoiture,V.marque,V.nomVoiture,V.couleur,V.nbplaces,V.prixJour,V.EnLocation);
		  }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("GVoiture.txt");
	   rename("TempGVoiture.txt","GVoiture.txt");
	   printf("\n\nSuppression Effectuee avec succees!!");
	 }
   }

 else
  {
  system("cls");
  printf("\n\n -------------------- Ce id de voiture n'existe Pas !! --------------------");
  SupprimerVoiture();
  }
}
//fontions Location d'une voiture
int  rechContrat(int num)
 {
  FILE *F;
  F=fopen("LVoiture.txt","r");
  do{
  	 fscanf(F,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",&Co.numContrat,&Co.idVoiture,&Co.idClient,&Co.debut.J,&Co.debut.M,&Co.debut.A,&Co.fin.J,&Co.fin.M,&Co.fin.A,&Co.cout);
  	 fflush(stdin);
  	 if(Co.numContrat==num)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));
    fclose(F);
  	     return 0;
 }

void visualiserContrat()
 {
  int num;
  printf("Entrer le numero de contrat a Rechercher \n");
  scanf("%d",&num);
  FILE *F;
  F=fopen("LVoiture.txt","r");
  do{
  	 fscanf(F,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",&Co.numContrat,&Co.idVoiture,&Co.idClient,&Co.debut.J,&Co.debut.M,&Co.debut.A,&Co.fin.J,&Co.fin.M,&Co.fin.A,&Co.cout);
  	 if(num==Co.numContrat)
  	  {
  	    printf("----------- Information de contrat a Rechercher : -----------\n\n");
  	    printf("le numero de contrat: %d ",Co.numContrat);
  	    printf("\nle id de voiture : %d ",Co.idVoiture);
  	    printf("\nle id de client : %d ",Co.idClient);
  	    printf("\nla date debut : %d/%d/%d ",Co.debut.J,Co.debut.M,Co.debut);
  	    printf("\nla date fin : %d/%d/%d ",Co.fin.J,Co.fin.M,Co.fin.A);
  	    printf("\nle cout : %d ",Co.cout);
	  }
	 else
      {
	    printf("\n\n -------------------- Ce numero de contrat n'existe Pas !! --------------------\n\n");
	    visualiserContrat();
	  }

    }while(!feof(F));
     fclose(F);
 }

void LouerVoiture()
 {

 FILE *F;
 F=fopen("LVoiture.txt","a");

   printf("\nEntrer le numero de Contrat :");
   scanf("%d",&Co.numContrat);
   fflush(stdin);
   printf("\nEntrer le id de voiture :");
   scanf("%d",&Co.idVoiture);
   fflush(stdin);
   printf("\nEntrer le id de client :");
   scanf("%d",&Co.idClient);
   fflush(stdin);
   printf("\nEntrer la date debut (jj/mm/AAAA) :");
   scanf("%d",&Co.debut.J);printf("/");
   scanf("%d",&Co.debut.M);printf("/");
   scanf("%d",&Co.debut.A);
   fflush(stdin);
   printf("\nEntrer la date de fin (jj/mm/AAAA) :");
   scanf("%d",&Co.fin.J);printf("/");
   scanf("%d",&Co.fin.M);printf("/");
   scanf("%d",&Co.fin.A);
   fflush(stdin);
   printf("\nEntrer le cout :");
   scanf("%d",&Co.cout);
   fflush(stdin);
   fprintf(F,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",Co.numContrat,Co.idVoiture,Co.idClient,Co.debut.J,Co.debut.M,Co.debut.A,Co.fin.J,Co.fin.M,Co.fin.A,Co.cout);
   fclose(F);
 }

void ModifierContrat()
 {
 char rep;
 int num;
 printf("\n\n\t\t     entrer le numero de contrat a Modifier : ");
 printf("\n\n\t\t     Voulez-vous vraiment Modifier O/N ? ");
 printf("\n\n\t\t   O:oui                               N:Non  ");
 printf("\n\n\t\t             Votre choix : ");
 scanf("%d",&num);
 fflush(stdin);
 if(rech(num)==1)
   {
   	printf("\nVoulez vous vraiment Modifier O/N ?");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o')
   	 {
   	  FILE *F,*Fich;
	  F=fopen("LVoiture.txt","r");
	  Fich=fopen("TempLVoiture.txt","a");
	  do{
	  	fscanf(F,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",&Co.numContrat,&Co.idVoiture,&Co.idClient,&Co.debut.J,&Co.debut.M,&Co.debut.A,&Co.fin.J,&Co.fin.M,&Co.fin.A,&Co.cout);
	  	if(num==Co.numContrat)
	  	  {
	  	    printf("\nEntrer le nouveau numero de Contrat :");
            scanf("%d",&Co.numContrat);
            fflush(stdin);
            printf("\nEntrer le nouveau id de voiture :");
            scanf("%d",&Co.idVoiture);
            fflush(stdin);
            printf("\nEntrer le nouveau id de client :");
            scanf("%d",&Co.idClient);
            fflush(stdin);
            printf("\nEntrer le nouveau date debut (jj/mm/AAAA) :");
            scanf("%d",&Co.debut.J);printf("/");
            scanf("%d",&Co.debut.M);printf("/");
            scanf("%d",&Co.debut.A);
            fflush(stdin);
            printf("\nEntrer le nouveau date de fin (jj/mm/AAAA) :");
            scanf("%d",&Co.fin.J);printf("/");
            scanf("%d",&Co.fin.M);printf("/");
            scanf("%d",&Co.fin.A);
            fflush(stdin);
            printf("\nEntrer le nouveau cout :");
            scanf("%d",&Co.cout);
            fflush(stdin);
		  }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("LVoiture.txt");
	   rename("TempLVoiture.txt","LVoiture.txt");
	   printf("\nModification a Reusi!!");
	 }
   }

 else
   {
   system("cls");
   printf("\n\n -------------------- Ce id de voiture n'existe Pas !! --------------------");
   ModifierContrat();
   }
}

void SupprimerContrat()
 {
 char rep;
 int num;
 printf("\n\n\t\t Entrer le numero de contrat a supprimer : ");
 scanf("%d",&num);
 fflush(stdin);
 if(rech(num)==1)
   {
   	printf("\n\n\t\t     Voulez-vous vraiment Supprimer O/N ? ");
    printf("\n\n\t\t   O:oui                               N:Non  ");
    printf("\n\n\t\t             Votre choix : ");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o')
   	 {
   	  FILE *F,*Fich;
	  F=fopen("LVoiture.txt","r");
	  Fich=fopen("TempLVoiture.txt","a");
	  do{
	  	fscanf(F,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",&Co.numContrat,&Co.idVoiture,&Co.idClient,&Co.debut.J,&Co.debut.M,&Co.debut.A,&Co.fin.J,&Co.fin.M,&Co.fin.A,&Co.cout);
	  	if(num!=Co.numContrat)
	  	  {
	  	  	fprintf(Fich,"%f ;%d ;%d ;%d ;%d ;%d ;%d ;%d ;%d ,%d \n",Co.numContrat,Co.idVoiture,Co.idClient,Co.debut.J,Co.debut.M,Co.debut.A,Co.fin.J,Co.fin.M,Co.fin.A,Co.cout);
		  }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("LVoiture.txt");
	   rename("TempLVoiture.txt","LVoiture.txt");
	   printf("\nSuppression Effectuee avec succees!!");
	  }

      else if(rep=='N' || rep=='n')
       system("exit");
   }

 else
  {
  system("cls");
  printf("\n\n -------------------- Ce id de voiture n'existe Pas !! --------------------");
  SupprimerContrat();
  }
}

//fontions Gestion des clients
int  rechClient(int num)
 {
  FILE *F;
  F=fopen("GClient.txt","r");
  do{
  	 fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",&Cl.idClient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
  	 fflush(stdin);
  	 if(Cl.idClient==num)
  	   {
  	     fclose(F);
  	     return 1;
		 }

    }while(!feof(F));

  	     fclose(F);
  	     return 0;
 }

void ListClient()
 {
  FILE *F;
  F=fopen("GClient.txt","r");
  printf(" \n\n               --------------- La liste des clients : ---------------  \n\n");
  printf("IdClient\t Nom\t\t Prenom\t\t CIN\t\t Adresse\t Telephone \n");
  do{
  	 fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",&Cl.idClient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
  	 printf(" %d\t\t %s\t %s\t\t %d\t\t %s\t\t %d \n",Cl.idClient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
    }while(fgetc(F)!=EOF);
 	fclose(F);
 }

void AjouterClient()
 {

 FILE *F;
 int Id;
 F=fopen("GClient.txt","a");
 printf("\n  > Entrer le id de nouveau client : ");
 scanf("%d",&Id);
 fflush(stdin);
 while(rechClient(Id)==1)
   {
 	printf("\n  Ce Id exist deja");
 	printf("\n  > Entrer le id de nouveau voiture :  ");
 	scanf("%d",&Id);
   }
   Cl.idClient=Id;
   printf("\n  > Entrer le nom de client :  ");
   gets(Cl.nom);
   fflush(stdin);
   printf("\n  > Entrer prenom de client :  ");
   gets(Cl.prenom);
   fflush(stdin);
   printf("\n  > Entrer le cin :");
   scanf("%d",&Cl.cin);
   fflush(stdin);
   printf("\n  > Entrer l'adresse de client :  ");
   gets(Cl.adresse);
   fflush(stdin);
   printf("\n  > Entrer le telephone de client :  ");
   scanf("%d",&Cl.telephone);
   fflush(stdin);
   fprintf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",Cl.idClient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
   fclose(F);
 }

void ModifierClient()
 {
 char rep;
 int Id;
 printf("entrer le id client a Modifier : ");

 scanf("%d",&Id);
 fflush(stdin);
 if(rechClient(Id)==1)
   {
   	printf("\n\n\t\t     Voulez-vous vraiment Modifier O/N ? ");
    printf("\n\n\t\t   O:oui                               N:Non  ");
    printf("\n\n\t\t             Votre choix : ");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o')
   	 {
   	  FILE *F,*Fich;
	  F=fopen("GClient.txt","r");
	  Fich=fopen("TempGClient.txt","a");
	  do{
	  	fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",&Cl.idClient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
	  	if(Id==Cl.idClient)
	  	  {
	  	  	Cl.idClient=Id;
	  	   	printf("\n  > Entrer le nom de client :  ");
            gets(Cl.nom);
            fflush(stdin);
            printf("\n  > Entrer prenom de client :  ");
            gets(Cl.prenom);
            fflush(stdin);
            printf("\n  > Entrer le cin :");
		    scanf("%d",&Cl.cin);
            fflush(stdin);
            printf("\n  > Entrer l'adresse de client :  ");
            gets(Cl.adresse);
            fflush(stdin);
            printf("\n  > Entrer le telephone de client :  ");
            scanf("%d",&Cl.telephone);
            fflush(stdin);
       	  }
		 fprintf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",Cl.idClient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("GClient.txt");
	   rename("TempGClient.txt","GClient.txt");
	   printf("\nModification a Reusi!!");
	 }
  }

  else
  {
   system("cls");
   printf("\n\n -------------------- Ce id de voiture n'existe Pas !! -------------------- \n");
   ModifierClient();
  }

}

void SupprimerClient()
 {
 char rep;
 int Id;
 printf("\n\n\t\t  entrer le id client a supprimer : ");
 scanf("%d",&Id);
 fflush(stdin);
 if(rechClient(Id)==1)
   {
   	printf("\n\n\t\t     Voulez-vous vraiment Supprimer O/N ? ");
    printf("\n\n\t\t   O:oui                               N:Non  ");
    printf("\n\n\t\t             Votre choix : ");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o')
   	 {
   	  FILE *F,*Fich;
	  F=fopen("GClient.txt","r");
	  Fich=fopen("TempGClient.txt","a");
	  do{
	  	fscanf(F,"%d ;%s ;%s ;%d ;%s ;%d \n",&Cl.idClient,&Cl.nom,&Cl.prenom,&Cl.cin,&Cl.adresse,&Cl.telephone);
	  	if(Id!=Cl.idClient)
	  	  {
	  	   	fprintf(Fich,"%d ;%s ;%s ;%d ;%s ;%d \n",Cl.idClient,Cl.nom,Cl.prenom,Cl.cin,Cl.adresse,Cl.telephone);
		  }
	   }while(!feof(F));
	   fclose(Fich);
	   fclose(F);
	   remove("GClient.txt");
	   rename("TempGClient.txt","GClient.txt");
	   printf("\nSuppression Effectuee avec succees!!");
	 }

   }

 else
  {
  system("cls");
  printf("\n\n -------------------- Ce id de voiture n'existe Pas !! -------------------- ");
  SupprimerClient();
  }
}


