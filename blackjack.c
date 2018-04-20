#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


                        //***** Variables *****\\





struct carte {
    char couleur[16];
    char figure[16];
    char signe[16];
    int force;
};

struct Joueur {
    int Reserve_Argent;
    char Nom_Joueur[80];
    struct carte *Main;
    int Mise;
};



int Calcul_Point(struct carte Main[])
{
int Indice=0; // Déclaration de la variable Indice de type Entier
int Somme=0; // Déclaration de la variable Somme de type Entier


while (Main[Indice].force!=0) // Tant que la force de la carte numéro "Indice" de la main du joueur est différente de 0 faire
{
    Somme=Somme+Main[Indice].force; // On affecte Somme + Force de la carte à Somme
    Indice=Indice+1; // On affecte Indice +1 à Indice
}

return Somme;
}

void affiche_mains(struct carte mains[],char nom[])
{
    // Déclaration des variables

int Somme; // Déclaration de la variable Somme de type Entier
int indice=0; // Déclaration de la variable indice de type Entier
int points; // Déclaration de la variable points de type Entier


printf("Jeu de : %s \n",nom); // Afficher à l'écran "Jeu de 'nom'"
do
    {
    printf("Carte numero %d:\n",indice+1); // Afficher a l'écran "Carte numéro 'indice+1'
    if(nom=="Banque")// Si 'nom' est "Banque"
        {
            printf("+++");// Afficher a l'écran " +++ "
        }
    else // Sinon
        {
            printf("***"); // Afficher a l'écran " *** "
        }
    printf("[%d] le %s de %s %s (%d points)",indice,mains[indice].figure,mains[indice].signe,mains[indice].couleur,mains[indice].force);
    if(nom=="Banque") // Si 'nom' est "Banque"
        {
            printf("+++\n\n"); // Afficher a l'écran " +++ " et sauter deux lignes
        }
    else// Sinon
        {
            printf("***\n\n");// Afficher a l'écran " *** " et sauter deux lignes
        }
    indice=indice+1; // Incrementation de 'indice'
    }
while (mains[indice].force!=0); // Tant que la force de la carte 'indice' de la main est différente de 0
Somme=Calcul_Point(mains); // Affecter a 'Somme" la valeur de Calcul_Point(mains)
printf("La valeur de la main de %s est de: %d points\n\n\n\n\n",nom,Somme); // Afficher à l'écran " La valeur de la main de 'nom' est 'Somme'
};

void Creation_Jeu(struct carte Tab[])
{
    //Variables
int i = 0; // Déclaration de la variable i de type Entier *
char figure[][16]=
{
    "As",
    "Deux",
    "Trois",
    "Quatre",
    "Cinq",
    "Six",
    "Sept",
    "Huit",
    "Neuf",
    "Dix",
    "Valet",
    "Dame",
    "Roi"
};

char signe[][16] =
{
    "Coeur",
    "Trefle",
    "Carreau",
    "Pique"
};

char couleur[][16] =
{
    "Rouge",
    "Noir"
};
for (i=0; i<52; i=i+1) // Pour i=0,i<52 et i+1 faire
{
    strcpy(Tab[i].signe, signe[i%4]);
    strcpy(Tab[i].couleur, couleur[(i%4)%2]);
    strcpy(Tab[i].figure, figure[i%13]);

}
for (i=0; i<13; i=i+1) // Pour i=0,i<13 et i+1 faire
{
    if (i<10)
    {
        Tab[i].force=i+1;
        Tab[i+13].force=i+1;
        Tab[i+26].force=i+1;
        Tab[i+39].force=i+1;
    }
    else
    {
        Tab[i].force=10;
        Tab[i+13].force=10;
        Tab[i+26].force=10;
        Tab[i+39].force=10;
    }
}
}

void Init_Talon(struct carte Talon[])
{
struct carte Jeu[52]; // Déclaration d'un tableau de 52 cartes
int Compteur = 0; // Déclaration de la variable Compteur de type Entier
int Indice = 0; // Déclaration de la variable Indice de type Entier
int Indice_Talon = 0; // Déclaration de la variable Indice_Talon de type Entier


while (Compteur < 6) // Tant que 'Compteur' <6
    {
    Indice = 0;
    Creation_Jeu(Jeu); // Appel de la fonction ^Creation_Jeu^ prenant pour parametres le Jeu
    while (Indice < 52) // Tant que 'Indice'<52
        {
        Talon[Indice_Talon] = Jeu[Indice]; // Talon[Indice_Talon] prends la valeur de Jeu[Indice]
        Indice_Talon = Indice_Talon + 1; // 'Indice_Talon' s'incrémente
        Indice = Indice + 1; // 'Indice' s'incrémente
        }
    Compteur = Compteur + 1; // 'Compteur' s'incrémente
    }
}

void Melanger_Talon(struct carte Talon[])
{
struct carte Tampon; // Déclaration de la variable Tampon de type carte
int Index; // Déclaration de la variable Index de type Entie
int Indice; // Déclaration de la variable Indice de type Entier
long compteur;

Indice=0; // Indice prend la valeur 0
printf("                            ---- BLACKJACK ----\n\n\n\n");
srand(time(NULL));
compteur=time(&compteur);
while (Indice < compteur/100000)// Tant que indice inférieur à 10000 faire
    {
        Index=rand()%312; // Affecter un nombre aléatoire entre 1&52 à index
        Tampon=Talon[0]; // Affecter la case 0 du Talonleau à tampon
        Talon[0]=Talon[Index]; // Affecter la valeur index à la case 0 du Tableau
        Talon[Index]=Tampon; // Affecter tampon à la case index du Tableau
        Indice=Indice+1; // Affecter indice+1 à indice
    }
};

void init_mains(struct carte mains[])
{
int indice=0; // Déclaration de la variable indice de type Entier
while (indice < 21) // Tant que 'indice'<21 faire
    {
    strcpy( mains[indice].figure,"");
    strcpy( mains[indice].signe,"");
    strcpy( mains[indice].couleur,"");
    mains[indice].force=0; // la force de mains[indice] prendla valeur 0
    indice = indice+1; // 'indice' s'incrémente
    }
}

int Distribution(struct carte Main[], struct carte Main_Banque[], struct carte Talon[], int Top_Talon)
{
int Indice = 0; // Déclaration de la variable 'Indice' de type Entier
int Index = 0; // Déclaration de la variable 'Index' de type Entier


do
{
    Main[Indice] = Talon[Top_Talon]; //Affecte la valeur de la case du talon dans la case du Main_Joueur
    Top_Talon = Top_Talon + 1; //prend la valeur précédente de Indice_Talon et y rajoute 1
    Main_Banque[Indice] = Talon [Top_Talon]; //Affecte la valeur de la case du talon dans la case de Main_Banque
    Top_Talon = Top_Talon + 1; // 'Top_Talon' s'incrémente
    Indice = Indice + 1; //prend la valeur précédente de Indice et y rajoute 1
    Index = Index + 1; //prend la valeur précédente de Index et y rajoute 1
}while (Index < 2);

return Top_Talon;
}

int Joueur (struct carte Main_joueur[], struct carte Talon[],int Top_Talon,char Nom_joueur[] )
{
int Indice_Main; // Déclaration de la variable 'Indice_Main' de type Entier
int Reponse; // Déclaration de la variable 'Reponse' de type Entier
int Score=0; // Déclaration de la variable 'Score' de type Entier
int reponsePioche;

Indice_Main = 2; // 'Indice_Main' prend la valeur 2
Score=Calcul_Point(Main_joueur); // 'Score' prend la valeur de 'Calcul-Point(joueur.main)'
Reponse=1; // 'Reponse' prend la valeur 2
while (Reponse == 1 && Score < 21)//Tant que 'Reponse' differente de 0 faire
{
    do
    {
        printf("Voulez-vous une carte supplementaire ? Entrez 1 pour OUI ou 0 pour NON "); // Afficher a l'écran "Voulez-vous une carte supplementaire ? Entrez 1 ou 0:
        scanf("%d",&Reponse); // Demande a l'utilisateur sa reponse et l'affecte a 'Reponse'
    }while(Reponse!=0 && Reponse!=1);

    if (Reponse == 1) // Si 'Reponse'=1 et 'Score'<21 faire
        {
        printf("\n\n"); // Saute deux lignes
        Main_joueur[Indice_Main] = Talon[Top_Talon]; //'joueur.main[Indice.main]' prend la valeur de 'Talon[Top-Talon]'
        Indice_Main = Indice_Main+1; //'Indice-Main' s'incrémente
        Top_Talon = Top_Talon+1;//'Top-Talon' s'incrémente
        affiche_mains(Main_joueur,Nom_joueur);
        Score=Calcul_Point(Main_joueur); //'Score prend la valeur de 'Calcul_Point(joueur.main)'
        }

}
return Top_Talon;
}

int Banque(struct carte Main_Banque[],struct carte Talon[],int Top_Talon,struct Joueur joueur )
{
int Score_Joueur;
int Somme; // Déclaration de la variable 'Somme' de type Entier
int Indice_Main; // Déclaration de la variable 'Indice-Main' de type Entier

Score_Joueur=Calcul_Point(joueur.Main);
Indice_Main=2; // Indice_Main prends la valeur 2 ( Après la distribution )
Somme=Calcul_Point(Main_Banque); //'Somme' prend la valeur de 'Calcul_Point(Main-Banque)'
if (Score_Joueur <= 21)// Permet de MAJ le Top-Talon automatiquement
{
    printf("La BANQUE joue\n\n"); // Affiche a l'écran "La banque joue"
    while(Somme<17) // Tant que la main de la banque a une valeur inférieure a 17
    {
        Main_Banque[Indice_Main]=Talon[Top_Talon]; // La banque pioche une carte
        Indice_Main=Indice_Main+1;// La main augmente alors d'une carte
        Top_Talon=Top_Talon+1;// Le top du talon augmente de 1
        Somme=Calcul_Point(Main_Banque); // Recalcule le score de la banque
        printf("Somme BANQUE: %d\n",Somme); // Affiche le socre de la banque
        affiche_mains(Main_Banque,"BANQUE"); // Reaffiche la main de la banque
    }
}
return Top_Talon;
}

int Partie(struct Joueur joueur, struct carte Main_Banque[], struct carte Talon[], int Top_Talon)
{
    Top_Talon=Joueur(joueur.Main,Talon,Top_Talon,joueur.Nom_Joueur);
    Top_Talon=Banque(Main_Banque,Talon,Top_Talon,joueur);
    return Top_Talon;
}

void Affiche_Solde(struct Joueur p_j)
{
    printf("Le Solde de votre compte est de: %d \n\n\n\n", p_j.Reserve_Argent); // Affiche le porte-monnaie du Joueur
}

int Gagnant_Partie(struct Joueur p_joueur, struct carte Main_Banque[])
{

int Score_Joueur; // Déclaration d'une variable Score_Joueur de type Entier
int Score_Banque; // Déclaration d'une variable Socre_Banque de type Entier
int Result = 0; // Déclaration d'une variable Result de type Entier


Score_Joueur=Calcul_Point(p_joueur.Main); // Affecter à Score_Joueur la valeur de Calcul_Point(Main_Joueur)
Score_Banque=Calcul_Point(Main_Banque); // Affecter à Score_Banque la valeur de Calcul_Point(Main_Banque)
printf("Score : Joueur:%d - Banque:%d \n",Score_Joueur,Score_Banque);
if (Score_Joueur <= Score_Banque && Score_Banque <= 21) // Si le score du joueur est supérieur a celui de la banque et que le score du joueur est inférieur a 23 , faire
{
    printf(" \n*******************************");
    printf("\n*                             *\n* La banque gagne, retentes ta chance    *\n*                             *\n");
    printf("*******************************\n\n");
}
else if (Score_Joueur > 21)
{
    printf(" \n*****************************************************");
    printf("\n*                                                   *\n* Vous avez depasse 21, la banque gagne, dommage    *\n*                                                   *\n");
    printf("*****************************************************\n\n");
}
else if (Score_Joueur==Score_Banque && Score_Joueur < 21 ) // Sinon si le score du joueur est égal au score de la banque faire
{

    printf(" \n*******************************");
    printf("\n*                             *\n* Egalite, La banque gagne, retentes ta chance    *\n*                             *\n");
    printf("*******************************\n\n");
}

else if (Score_Joueur <= 21 && Score_Joueur > Score_Banque ) // Sinon faire
{
    printf(" \n*******************************");
    printf("\n*                             *\n* Le joueur gagne , bien joue *\n*                             *\n");
    printf("*******************************\n\n");
    Result = 1;
}
else if ( Score_Joueur <= 21 && Score_Banque > 21)
{
    printf(" \n*******************************");
    printf("\n*                             *\n* Le joueur gagne , bien joue *\n*                             *\n");
    printf("*******************************\n\n");
    Result=1;
}
return Result;
}


int main ()
{
    //Variables

int Reponse; // Déclaration d'une variable Reponse de type Entier
int Top_Talon;// Déclaration d'une variable Top-Talon de type Entier
struct carte Talon[312]; // Déclaration du tableau comprenant les 6 jeux
struct Joueur Joueur_A; // Déclaration d'un Joueur A de type Joueur
int Resultat; // Déclaration d'une variable Resultat de type Entier
int Reserve; // Déclaration d'une variable Reserve de type Entier
int indice; // Déclaration d'une variable indice de type Entier
struct carte Main_Banque[21]; // Déclaration de la Main_Banque

Joueur_A.Main=(struct carte *)malloc(21*sizeof(struct carte));  // Allocation
printf("Quel est votre pseudo? \n"); // Demande de son pseudo a l'utilisateur
scanf("%[^\n]",Joueur_A.Nom_Joueur); //
printf("Bienvenue %s \n\n ",Joueur_A.Nom_Joueur);
Init_Talon(Talon);
Top_Talon = 0;
Melanger_Talon(Talon);
Reponse = 1;

do
{
    printf("*** Combien souhaitez vous ajouter a votre solde ? *** \n");
    scanf("%d",&Joueur_A.Reserve_Argent);

    if (Joueur_A.Reserve_Argent <= 0)
    {
        printf("*** Vous devez entrer une valeur superieure a 0 $ *** \n\n\n");
    }
}
while (Joueur_A.Reserve_Argent <= 0);

printf("*** Vous avez ajoute %d $ \n ***",Joueur_A.Reserve_Argent);



while (Reponse == 1  )
    {

do
    {
        printf("*** Combien souhaitez vous miser ? ***\n",Joueur_A.Reserve_Argent);
        printf("*** Votre reserve etant actuellement a %d $ *** \n",Joueur_A.Reserve_Argent);
        scanf("%d",&Joueur_A.Mise);
        if (Joueur_A.Mise <= 0)
            {
            printf("*** Vous ne pouvez pas jouer avec 0$ ou moins de mise ***\n");
            printf("*** Combien souhaitez-vous miser ? ***\n");
            scanf("%d",&Joueur_A.Mise);
            }
        else (Joueur_A.Mise > Joueur_A.Reserve_Argent);
            {
            while (Joueur_A.Mise > Joueur_A.Reserve_Argent)
                {
                    printf("*** Vous ne pouvez pas miser plus que votre solde ***\n");
                    printf("*** Combien souhaitez-vous miser ? ***\n");
                    scanf("%d",&Joueur_A.Mise);
                }
            }
    }
while (Joueur_A.Mise == 0);
        indice = 0;
        while (indice<200)
        {
            printf("\n\n");
            indice=indice+1;
        }

        init_mains(Joueur_A.Main);
        init_mains(Main_Banque);
        Reserve = Joueur_A.Reserve_Argent;
        Top_Talon=Distribution(Joueur_A.Main, Main_Banque, Talon, Top_Talon);
        affiche_mains(Main_Banque,"Banque");
        affiche_mains(Joueur_A.Main, Joueur_A.Nom_Joueur);
        Top_Talon=Partie(Joueur_A,Main_Banque, Talon, Top_Talon);
        Resultat=Gagnant_Partie(Joueur_A, Main_Banque);
        if(Resultat==1)
                Joueur_A.Reserve_Argent = Joueur_A.Mise + Reserve;
        else if(Resultat==0)
                Joueur_A.Reserve_Argent = Reserve - Joueur_A.Mise;
                Affiche_Solde(Joueur_A);
    if (Joueur_A.Reserve_Argent <=0)
    {
        printf("***Merci de quitter la table***\n\n\n\n\n");
        Reponse = 0;
    }
    else
    {
        do
        {
            printf("Voulez-vous rejouer une partie ? Entrez 1 pour oui, 0 pour non : ");
            scanf("%d",&Reponse);
        }while(Reponse!=0 && Reponse!=1);
    }
}
    printf("**** Merci d'avoir joue ****\n\n\n");

return 0;
}



/* MAJ 1.0 le 09/06/16  / Fonctions de mise et de solde , bye quand plus de solde , visibilité du code source
                        */


