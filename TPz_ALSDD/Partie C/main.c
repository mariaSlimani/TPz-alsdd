  /*TP 2 ALSDD - GROUPE 11 - SLIMANI WASSILA MARIA ~ ABCHICHE SARAH - 2018/2019*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#define _WIN32_WINNT 0x0501
#include <windows.h>
  /*------------------- Les Déclarations -------------------*/
  typedef int bool ;
  typedef char * string255 ;
  typedef char * string2 ;
  #define True 1
  #define False 0

  /** Implémentation: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tcb Type_Tcb  ;
  typedef Type_Tcb * Typestr_Tcb ;
  typedef string2 Type1_Tcb  ;
  typedef bool Type2_Tcb  ;
  struct Tcb
    {
      Type1_Tcb Champ1 ;
      Type2_Tcb Champ2 ;
    };

  Type1_Tcb Struct1_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ1 ;
    }

  Type2_Tcb Struct2_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tcb ( Typestr_Tcb S, Type1_Tcb Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tcb ( Typestr_Tcb S, Type2_Tcb Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tcb Typeelem_ATcb   ;
  typedef struct Noeud_ATcb * Pointeur_ATcb ;

  struct Noeud_ATcb
    {
      Typeelem_ATcb  Val ;
      Pointeur_ATcb Fg ;
      Pointeur_ATcb Fd ;
      Pointeur_ATcb Pere ;
     } ;

  Typeelem_ATcb Info_ATcb( Pointeur_ATcb P )
    { return P->Val;   }

  Pointeur_ATcb Fg_ATcb( Pointeur_ATcb P)
    { return P->Fg ; }

  Pointeur_ATcb Fd_ATcb( Pointeur_ATcb P)
    { return P->Fd ; }

  Pointeur_ATcb Pere_ATcb( Pointeur_ATcb P)
    { return P->Pere ; }

  void Aff_info_ATcb ( Pointeur_ATcb P, Typeelem_ATcb Val)
    {
      Typeelem_ATcb _Temp ;
      _Temp = malloc(sizeof(Typestr_Tcb));
      _Temp->Champ1 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATcb( Pointeur_ATcb *P)
    {
      *P = (struct Noeud_ATcb *) malloc( sizeof( struct Noeud_ATcb))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tcb));
      (*P)->Val->Champ1 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATcb( Pointeur_ATcb P)
    { free( P ) ; }


  /** Implémentation **: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATcb Typeelem_PATcb ;
  typedef struct Maillon_PATcb * Pointeur_PATcb ;
  typedef   Pointeur_PATcb  Typepile_PATcb  ;

  struct Maillon_PATcb
    {
      Typeelem_PATcb  Val ;
      Pointeur_PATcb Suiv ;
    } ;

  void Creerpile_PATcb( Pointeur_PATcb *P )
    { *P = NULL ; }

  bool Pilevide_PATcb ( Pointeur_PATcb P )
    { return  (P == NULL ); }

  void Empiler_PATcb ( Pointeur_PATcb *P,  Typeelem_PATcb Val )
    {
      Pointeur_PATcb Q;

      Q = (struct Maillon_PATcb *) malloc( sizeof( struct Maillon_PATcb))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATcb ( Pointeur_PATcb *P,  Typeelem_PATcb *Val )
    {
      Pointeur_PATcb Sauv;

      if (! Pilevide_PATcb (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf (" Pile vide \n");
    }


  /** Implémentation **: TABLEAU DE ARBRES BINAIRES DE STRUCTURES**/

  /** Tableaux **/

  typedef Pointeur_ATcb Typeelem_V10000ATcb ;
  typedef Typeelem_V10000ATcb * Typevect_V10000ATcb ;

  Typeelem_V10000ATcb Element_V10000ATcb ( Typevect_V10000ATcb V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V10000ATcb ( Typevect_V10000ATcb V  , int I1 ,  Typeelem_V10000ATcb Val )
    {
      *(V + I1-1 ) = Val ;
    }


  /** Implémentation **: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V10000s ;
  typedef Typeelem_V10000s * Typevect_V10000s ;

  Typeelem_V10000s Element_V10000s ( Typevect_V10000s V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V10000s ( Typevect_V10000s V  , int I1 ,  Typeelem_V10000s Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }


  /** Implémentation **: TABLEAU DE CARACTERES**/

  /** Tableaux **/

  typedef string2 Typeelem_V26c ;
  typedef Typeelem_V26c * Typevect_V26c ;

  Typeelem_V26c Element_V26c ( Typevect_V26c V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V26c ( Typevect_V26c V  , int I1 ,  Typeelem_V26c Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }

  /** Variables du programme principal **/
  int N,I,J,K,L,M,V,Z,Y,Choix,Choix_mot,_Px2;
  Pointeur_ATcb R,A,Perer,Prec,Racine,T;
  Pointeur_PATcb P,Q;
  Typevect_V10000s Tabmots;
  string255 Mot,Motprec,Requete;
  Typestr_Tcb E;
  string2 C,Caracmot,Caracr,Carrequete,Carmot;
  bool Bool,Motjuste,Stop,Error,Limite;
  Pointeur_ATcb _Px1;
  string255 _Sx;
    char c;
    char word[40];

  /** Fonctions standards **/

  char *Caract ( string255 Ch , int I )
    {
      char *s = malloc(2);
      s[0] = Ch[I-1];
      s[1] = '\0';
      return  s;
    }

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);
      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;
      return (Chaine);
    }


  /** Prototypes des fonctions **/

  void getword (FILE* fichier,char word[30],char* c);
 void Genererarbre (Pointeur_ATcb *Racine ,int *M , int *L ,int *Choix_mot,FILE* fichier);
 int alphabetic (char c);
 int numword (FILE* fichier);
 void Parcours (Pointeur_ATcb *Racine);
  void Compabilitearbre (Pointeur_ATcb *Racine);
  bool  Verif (string255 *Mot , string255 *Requete) ;
  string255  Rest (string255 *Mot , int *I) ;
  string255  Reglerchaine (int *Re_mo , string255 *Chaine_rm , bool *Stop) ;
  void Init_min (Typevect_V26c *Minuscule);
  void Init_maj (Typevect_V26c *Majuscule);
  string255  Equiv (string255 *Requete) ;
  string255  Inverser (string255 *Requete) ;
  void Alea_saisie (int *Choix_mot);
  void fenetres_glissantes (Typevect_V10000s Tabmots, int nbrmot);
  void erreur ();
void retablir_color ();
void posCurse(FILE* fichier,int lig);
void retablir_color2 ();
void Ecran(int Mode);
void window();
void gotoxy(int x, int y);
void SetColorAndBackground(int ForgC, int BackC);
int choisirparametre(char tab[][500],int nbchoix, int decalmenu_x, int decalmenu_y,int bc, int fc);
void date_daujourdhui (int *year, int *month, int *day, char *wday[20]);
void quitter ();
void entrer ();
void set_screen(int background);
void ligneV (int coord_x, int coord_y, int max_y); //affiche une ligne verticale selon les coordonnes
void ligneH (int coord_x, int coord_y,int max_x,int timer);//affiche une ligne horizontal selon les coordonnes
 void resblink ();

  /* ------------------- Les Modules ------------------- */
 void Genererarbre (Pointeur_ATcb *Racine ,int *M , int *L ,int *Choix_mot,FILE* fichier)
    {
      /** Variables locales **/
      Pointeur_ATcb R,Perer,Prec;
      int I,J,_Px1,_Px2;
      Typestr_Tcb E;
      string255 Mot;
      bool Error;

      /** Corps du module **/
     E = malloc(sizeof(Typestr_Tcb));
     E->Champ1 = malloc(2 * sizeof(string2));
     Mot = malloc(255 * sizeof(string255));
     R  =  *Racine ;
     Perer  =  NULL ;
     Prec  =  NULL ;
     for( I  =  1 ;I <=  *M   ; ++I)
        {
            R  = *Racine ;
            Perer  = NULL ;
            Prec  = NULL ;
       if( ( *Choix_mot == 0 ))
        {
         Stop  =  False ;
         int p=10;
         while( ( Stop == False))
            {
                system ("cls");
                system("COLOR 0e");
                set_screen(0);
                gotoxy(5,p);p++;
                printf ( "Entrez le mot %d: ",I ) ;
                scanf ( " %[^\n]", Mot ) ;
                _Px1 =  1 ;
                strcpy (Mot, Reglerchaine ( &_Px1, & Mot , & Stop )) ;
                if( ( Longchaine(Mot) > *L ))
                {
                    Stop  =  False ;
                }
                    if (Stop == False)
                    {
                        gotoxy(40,p);printf("Erreur!  ");
                    if( ( Longchaine(Mot) > *L ))
                    {
                        system("COLOR 46");
                       printf ( "Le mot depasse la longueur! \n" ) ;
                    }
                    else
                    {
                            system("COLOR 46");
                        printf ( "Veuillez introduire une valeur valide! \n" ) ;
                    }
                        Sleep(600);
                    }
                    else
                    {
                        Stop = True;
                    }
                };
         }
      /*aleatoire*/
       else if (*Choix_mot == 1)
         {
         strcpy (Mot,   Aleachaine(Aleanombre(*L ) + 1 )) ;
         _Px2 =  1 ;
         strcpy (Mot,Reglerchaine ( &_Px2, & Mot , & Stop )) ;
        }
        else // = 2
        {
            //saisie par dico

            strcpy(word,"\0");
            getword(fichier,word,&c);
            _Px2 =  1 ;
            strcpy(Mot,word);
            strcpy (Mot,Reglerchaine ( &_Px2, & Mot , & Stop )) ;
        }
      /*---------------------generer mot-----------------------*/
       for( J  =  1 ;J <=  Longchaine(Mot) ; ++J){
         if( ( R == NULL ))
            {
           Aff_struct1_Tcb(E , Caract(Mot , J ) ) ;
           Aff_struct2_Tcb(E , False ) ;
           Creernoeud_ATcb(&R ) ;
           Aff_info_ATcb(R , E ) ;
           if( ( Prec != NULL ))
           {
             Aff_fg_ATcb(Prec , R ) ;
           } ;
          /*cas arbre vide */
           if( ( *Racine == NULL ))
           {
             *Racine  =  R ;
           } ;
           }
        /*--- avancer a droite jusqu'a trouver caract(mot,j) ou la position pour l'inserer */
         else
           {
           while( ( (strcmp( Caract(Mot , J ), Struct1_Tcb(Info_ATcb(R )  )) > 0  ) && ( Fd_ATcb(R ) != NULL ) ))
            {
             Perer  =  R ;
             R  =  Fd_ATcb(R ) ;
            } ;
           if( (strcmp( Struct1_Tcb(Info_ATcb(R )  ), Caract(Mot , J )) != 0  ))
           {
            /* regler le cas ou l'on insere à la fin */
             if( (strcmp( Caract(Mot , J ), Struct1_Tcb(Info_ATcb(R )  )) > 0  ))
             {
               Perer  =  R ;
               R  =  Fd_ATcb(R ) ;
             } ;
             Aff_struct1_Tcb(E  , Caract(Mot , J ) ) ;
             Aff_struct2_Tcb(E  , False ) ;
             Creernoeud_ATcb(&T ) ;
             Aff_info_ATcb(T , E ) ;
             Aff_fd_ATcb(T , R ) ;
            /* cas ou l'on change la racine */
             if( R == *Racine)
                {
               *Racine  =  T ;
               }
             else
               {
              /* cas ou le fg( pereR) doit etre changé */
               if( Perer == Prec) {
                 Aff_fg_ATcb(Perer , T ) ;
                 }
               else
                 {
                 Aff_fd_ATcb(Perer , T ) ;
               } ;
             } ;
             R  =  T ;
           } ;
         } ;
         Prec  =  R ;
         Perer  =  R ;
         R  =  Fg_ATcb(R ) ;
       } ;
       Aff_struct1_Tcb(E  , Caract(Mot , Longchaine(Mot ) ) ) ;
       Aff_struct2_Tcb(E  , True ) ;
       Aff_info_ATcb(Perer , E ) ;
     } ;
    }


int alphabetic (char c)
//renvoi vrai si le caractère c est alphabetique
{
    char s[1];
    int alpha;
    alpha=0;
    sprintf(s,"%c",c);
    if (c=='A')
    {
        alpha=1;
    }
    else if (c=='B')
    {
        alpha=1;
    }
    else if (c=='C')
        {
        alpha=1;
    }
    else if (c=='D')
    {
        alpha=1;
    }
    else if (c=='E')
    {
        alpha=1;
    }
    else if (c=='F')
    {
        alpha=1;
    }
    else if (c=='G')
    {
        alpha=1;
    }
    else if (c=='H')
    {
        alpha=1;
    }
    else if (c=='I')
    {
        alpha=1;
    }
    else if (c=='J')
    {
        alpha=1;
    }
    else if (c=='K')
    {
        alpha=1;
    }
    else if (c=='L')
    {
        alpha=1;
    }
    else if (c=='M')
    {
        alpha=1;
    }
    else if (c=='N')
    {
        alpha=1;
    }
    else if (c=='O')
    {
        alpha=1;
    }
    else if (c=='P')
    {
        alpha=1;
    }
    else if (c=='Q')
    {
        alpha=1;
    }
    else if (c=='R')
    {
        alpha=1;
    }
    else if (c=='S')
    {
        alpha=1;
    }
    else if (c=='T')
    {
        alpha=1;
    }
    else if (c=='U')
    {
        alpha=1;
    }
    else if (c=='V')
    {
        alpha=1;
    }
    else if (c=='W')
    {
        alpha=1;
    }
    else if (c=='X')
    {
        alpha=1;
    }
    else if (c=='Y')
    {
        alpha=1;
    }
    else if (c=='Z')
    {
        alpha=1;
    }
    else if (c=='a')
    {
        alpha=1;
    }
    else if (c=='b')
    {
        alpha=1;
    }
    else if (c=='c')
        {
        alpha=1;
    }
    else if (c=='d')
    {
        alpha=1;
    }
    else if (c=='e')
    {
        alpha=1;
    }
    else if (c=='f')
    {
        alpha=1;
    }
    else if (c=='g')
    {
        alpha=1;
    }
    else if (c=='h')
    {
        alpha=1;
    }
    else if (c=='i')
    {
        alpha=1;
    }
    else if (c=='j')
    {
        alpha=1;
    }
    else if (c=='k')
    {
        alpha=1;
    }
    else if (c=='l')
    {
        alpha=1;
    }
    else if (c=='m')
    {
        alpha=1;
    }
    else if (c=='n')
    {
        alpha=1;
    }
    else if (c=='o')
    {
        alpha=1;
    }
    else if (c=='p')
    {
        alpha=1;
    }
    else if (c=='q')
    {
        alpha=1;
    }
    else if (c=='r')
    {
        alpha=1;
    }
    else if (c=='s')
    {
        alpha=1;
    }
    else if (c=='t')
    {
        alpha=1;
    }
    else if (c=='u')
    {
        alpha=1;
    }
    else if (c=='v')
    {
        alpha=1;
    }
    else if (c=='w')
    {
        alpha=1;
    }
    else if (c=='x')
    {
        alpha=1;
    }
    else if (c=='y')
    {
        alpha=1;
    }
    else if (c=='z')
    {
        alpha=1;
    }
    else
    {
        alpha=0;
    }
    return alpha;
}

void getword (FILE* fichier,char word[30],char* c)
//recupere le prochain mot d'un fichier texte
//le premier caractère est danc c
//le mot sera sauvegardé dans word
{

    char character[30];

    strcpy(word,"\0");

        while (alphabetic(*c)==1 && *c!=EOF)
        {


            strcpy(character,"\0");
            sprintf(character,"%c",*c);
            strcat(word,character);
            *c=fgetc(fichier);
        }

        while (alphabetic(*c)==0 && *c!=EOF)
        {
            *c=fgetc(fichier);

        }

}
int numword (FILE* fichier)
//recupere le nombre de mots dans un fichier
{
    int i=0;

    char c;
    c=getc(fichier);
    if (alphabetic(c)==0)
    {
        i=-1;
    }

    while (c!=EOF)
    {


        while (alphabetic(c)==1 && c!=EOF)
        {

            c=fgetc(fichier);
        }

        i++;

        while (alphabetic(c)==0 && c!=EOF)
        {
            c=fgetc(fichier);

        }
    }
    return i;
}
  void Parcours (Pointeur_ATcb *Racine)
    {
      /** Corps du module **/
     printf ( "     Parcours de L'Arbre ");
     A  =  *Racine ;
     Creerpile_PATcb(&Q ) ;
     while( ( ( A != NULL ) || ! Pilevide_PATcb(Q ) )) {
       while( ( A != NULL )) {
         Empiler_PATcb(&Q , A ) ;
         A  =  Fg_ATcb(A ) ;
       } ;
       Depiler_PATcb(&Q , &A ) ;
       printf ( " %s \n", Struct1_Tcb(Info_ATcb(A)) ) ;
       A  =  Fd_ATcb(A ) ;
     } ;
    }
  /*----------------------------------------------------*/
  void Compabilitearbre (Pointeur_ATcb *Racine)
    {
      /** Variables locales **/
      Pointeur_ATcb R;
      Pointeur_PATcb B;
      string255 Mot;
      string255 Motprec;
      int Nombremot,i;
      string255 _Sx;
      char r;
      /** Corps du module **/

        system("COLOR 84");
      set_screen(8);

      i=0;
     Mot = malloc(255 * sizeof(string255));
     Motprec = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     Creerpile_PATcb(&B ) ;
     R  =  *Racine ;
     Bool  =  Pilevide_PATcb(B ) ;
     strcpy (Mot, "") ;
     Nombremot  =  0 ;
     system("COLOR 84");
      set_screen(8);
      printf("\n\n");
     while( ( ( ! Bool ) || ( R != NULL ) )) {
       while( ( R != NULL )) {
         strcpy (_Sx, Mot);
         strcpy (Mot,  strcat(_Sx, Struct1_Tcb(Info_ATcb(R )  ))) ;
         Empiler_PATcb(&B , R ) ;
         R  =  Fg_ATcb(R ) ;

       } ;
       Depiler_PATcb(&B , &R ) ;
       if( ( Struct2_Tcb(Info_ATcb(R )  ) ))
        {
         printf ( "    %s \n", Mot ) ;
         Nombremot  =  Nombremot + 1 ;
         i = i+1;
            if (i>20)
            {
                printf("             Appuyez sur 'Enter' pour afficher la suite des mots");
                scanf("%c",&r);
                i=0;
                system("cls");
                system("COLOR 84");
                set_screen(8);
                printf ( "\n Verification de la compabilite de l'Arbre ");
                printf("\n\n");
            }
       } ;
       strcpy (Motprec,   "") ;
       for( V  =  1 ;V <=  ( Longchaine(Mot ) - 1 ) ; ++V){
         strcpy (_Sx, Motprec);
         strcpy (Motprec,  strcat(_Sx, Caract(Mot , V ))) ;
       } ;
       strcpy (Mot,   Motprec) ;
       R  =  Fd_ATcb(R ) ;
       Bool  =  Pilevide_PATcb(B ) ;
     } ;
     if( ( Nombremot > 0 ))
     {
       printf ( " Comptabilite verifiee! \n" ) ;
     } ;
    }
  /*----------------------------------------------------*/
  bool  Verif (string255 *Mot , string255 *Requete)
    {
      /** Variables locales **/
      bool  Verif2 ,Bool;
      int I,J;
      string2 Carreq;
      string255 _Px1;
      string255 _Px2;
      string255 _Px3;
      string255 _Px4;
      string255 _Px5;
      string255 _Px6;
      string255 _Px7;
      string255 _Px8;
      string255 _Px9;
      string255 _Px10;
      string255 _Px11;
      string255 _Px12;
      string255 _Px13;
      string255 _Px14;
      string255 _Px15;
      string255 _Px16;

      /** Corps du module **/
     Carreq = malloc(2 * sizeof(string2));
     _Px1 = malloc(255 * sizeof(string255));
     _Px2 = malloc(255 * sizeof(string255));
     _Px3 = malloc(255 * sizeof(string255));
     _Px4 = malloc(255 * sizeof(string255));
     _Px5 = malloc(255 * sizeof(string255));
     _Px6 = malloc(255 * sizeof(string255));
     _Px7 = malloc(255 * sizeof(string255));
     _Px8 = malloc(255 * sizeof(string255));
     _Px9 = malloc(255 * sizeof(string255));
     _Px10 = malloc(255 * sizeof(string255));
     _Px11 = malloc(255 * sizeof(string255));
     _Px12 = malloc(255 * sizeof(string255));
     _Px13 = malloc(255 * sizeof(string255));
     _Px14 = malloc(255 * sizeof(string255));
     _Px15 = malloc(255 * sizeof(string255));
     _Px16 = malloc(255 * sizeof(string255));
     Bool  =  False ;
     I  =  1 ;
     J  =  1 ;
     strcpy (Carreq,   Caract(*Requete , J )) ;
     if( ( (strcmp( Carreq, "?") != 0  ) && (strcmp( Carreq, "*") != 0  ) )) {
       if( ( I <= Longchaine(*Mot ) )) {
         if( (strcmp( Carreq, Caract(*Mot , I )) == 0  )) {
           if( ( ( I == Longchaine(*Mot ) ) && ( J == Longchaine(*Requete ) ) )) {
             Verif2  =  True ;
             }
           else
             {
             if( ( ( I <= Longchaine(*Mot ) ) && ( J < Longchaine(*Requete ) ) )) {
               I  =  I + 1 ;
               J  =  J + 1 ;
               strcpy(_Px1,  Rest ( & *Mot , & I ) );
               strcpy(_Px2,  Rest ( & *Requete , & J ) );
               Verif2  =  Verif ( &_Px1, &_Px2) ;
               }
             else
               {
               Verif2  =  False ;
             } ;
           } ;
           }
         else
           {
           Verif2  =  False ;
         } ;
         }
       else
         {
         Verif2  =  False ;
       } ;
       }
     else
       {
       if( (strcmp( Carreq, "?") == 0  )) {
         if( ( ( I == Longchaine(*Mot ) ) && ( J == Longchaine(*Requete ) ) )) {
           Verif2  =  True ;
           }
         else
           {
           if( ( ( I <= Longchaine(*Mot ) ) && ( J < Longchaine(*Requete ) ) )) {
             if( ( I < Longchaine(*Mot ) )) {
               I  =  I + 1 ;
               J  =  J + 1 ;
               strcpy(_Px3,  Rest ( & *Mot , & I ) );
               strcpy(_Px4,  Rest ( & *Requete , & J ) );
               Verif2 = Verif ( &_Px3, &_Px4) ;
               }
             else
               {
               if( ( ( ( J + 1 ) == Longchaine(*Requete ) ) && (strcmp( Caract(*Requete , J + 1 ), "*") == 0  ) )) {
                 Verif2  =  True ;
                 }
               else
                 {
                 Verif2  =  False ;
               } ;
             } ;
             }
           else
             {
             Verif2  =  False ;
           } ;
         } ;
         }
      /*cas / */
       else
         {
         if( ( J == Longchaine(*Requete ) )) {
           Verif2  =  True ;
           }
         else
           {
           if( ( I > Longchaine(*Mot ) )) {
             Verif2  =  False ;
             }
           else
             {
             if( (strcmp( Caract(*Mot , I ), Caract(*Requete , J + 1 )) == 0  )) {
               J  =  J + 1 ;
               while( ( (strcmp( Caract(*Mot , I ), Caract(*Requete , J )) == 0  ) && ( I < Longchaine(*Mot ) ) && ( ! Bool ) )) {
                 strcpy(_Px5,  Rest ( & *Mot , & I ) );
                 strcpy(_Px6,  Rest ( & *Requete , & J ) );
                 Bool  =  Verif ( &_Px5, &_Px6) ;
                 I  =  I + 1 ;

               } ;
               if( ( ! Bool )) {
                 if( (strcmp( Caract(*Mot , I ), Caract(*Requete , J )) == 0  )) {
                   strcpy(_Px7,  Rest ( & *Mot , & I ) );
                   strcpy(_Px8,  Rest ( & *Requete , & J ) );
                   Bool  =  Verif ( &_Px7, &_Px8) ;
                   }
                 else
                   {
                   I  =  I + 1 ;
                   while( ( I < Longchaine(*Mot ) )) {
                     strcpy(_Px9,  Rest ( & *Mot , & I ) );
                     strcpy(_Px10,  Rest ( & *Requete , & J ) );
                     Bool  =  Verif ( &_Px9, &_Px10) ;
                     I  =  I + 1 ;

                   } ;
                   if( ( I == Longchaine(*Mot ) )) {
                     strcpy(_Px11,  Rest ( & *Mot , & I ) );
                     strcpy(_Px12,  Rest ( & *Requete , & J ) );
                     Bool  =  Verif ( &_Px11, &_Px12) ;
                     }
                   else
                     {
                     Bool  =  False ;

                   } ;

                 } ;

               } ;
               }
             else
               {
               I  =  I + 1 ;
               while( ( ( I < Longchaine(*Mot ) ) && ( ! Bool ) )) {
                 strcpy(_Px13,  Rest ( & *Mot , & I ) );
                 strcpy(_Px14,  Rest ( & *Requete , & J ) );
                 Bool  =  Verif ( &_Px13, &_Px14) ;
                 I  =  I + 1 ;

               } ;
               if( ( ! Bool )) {
                 if( ( I == Longchaine(*Mot ) )) {
                   strcpy(_Px15,  Rest ( & *Mot , & I ) );
                   strcpy(_Px16,  Rest ( & *Requete , & J ) );
                   Bool  =  Verif ( &_Px15, &_Px16) ;
                   }
                 else
                   {
                   Bool  =  False ;
                 } ;
               } ;
             } ;
             Verif2  =  Bool ;
           } ;
         } ;
       } ;
     } ;
     return Verif2 ;
    }
  /*----------------------------------------------------*/
  string255  Rest (string255 *Mot , int *I)
    {
      /** Variables locales **/
      string255  Rest2 ;
      string255 Nov_mot;
      int J;
      string255 _Sx;

      /** Corps du module **/
     Nov_mot = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     Rest2 = malloc(255 * sizeof(string255));
     strcpy (Nov_mot,   "") ;
     for( J  =  *I ;J <=  Longchaine(*Mot )   ; ++J){
       strcpy (_Sx, Nov_mot);
       strcpy (Nov_mot,  strcat(_Sx, Caract(*Mot , J ))) ;

     } ;
     strcpy (Rest2,   Nov_mot) ;

     return Rest2 ;
    }
  /*----------------------------------------------------*/
  string255  Reglerchaine (int *Re_mo , string255 *Chaine_rm , bool *Stop)
    {
      /** Variables locales **/
      string255  Reglerchaine2 ;
      int I;
      int J;
      string255 Nv_chaine;
      Typevect_V26c Minuscule;
      Typevect_V26c Majuscule;
      string2 Car_rm;
      string255 _Sx;

      /** Corps du module **/
     Nv_chaine = malloc(255 * sizeof(string255));
     Minuscule = malloc(26 * 2  * sizeof(string2));
     int _Izw2;for (_Izw2=0; _Izw2<26; ++_Izw2)
       Minuscule[_Izw2]= malloc(2 * sizeof(string2));
     Majuscule = malloc(26 * 2  * sizeof(string2));
     int _Izw3;for (_Izw3=0; _Izw3<26; ++_Izw3)
       Majuscule[_Izw3]= malloc(2 * sizeof(string2));
     Car_rm = malloc(2 * sizeof(string2));
     _Sx = malloc(255 * sizeof(string255));
     Reglerchaine2 = malloc(255 * sizeof(string255));
     Init_min ( & Minuscule ) ;
     Init_maj ( & Majuscule ) ;
     strcpy (Nv_chaine,   "") ;
     if( ( *Re_mo == 1 )) //{c'est un mot}
        {
       for( I  =  1 ;I <=  Longchaine(*Chaine_rm )   ; ++I){
         strcpy (Car_rm,   Caract(*Chaine_rm , I )) ;
         for( J  =  1 ;J <=  26   ; ++J){
           if( (strcmp( Car_rm, Element_V26c(Majuscule , J   )) == 0  )) {
             strcpy (_Sx, Nv_chaine);
             strcpy (Nv_chaine,  strcat(_Sx, Element_V26c(Minuscule , J   ))) ;
             }
           else
             {
             if( (strcmp( Car_rm, Element_V26c(Minuscule , J   )) == 0  )) {
               strcpy (_Sx, Nv_chaine);
               strcpy (Nv_chaine,  strcat(_Sx, Element_V26c(Minuscule , J   ))) ;

             } ;

           } ;

         } ;

       } ;
       }
    /*re_mo = 0*/
     else
       {
       for( I  =  1 ;I <=  Longchaine(*Chaine_rm )   ; ++I){
         strcpy (Car_rm,   Caract(*Chaine_rm , I )) ;
         for( J  =  1 ;J <=  26   ; ++J){
           if( (strcmp( Car_rm, Element_V26c(Majuscule , J   )) == 0  )) {
             strcpy (_Sx, Nv_chaine);
             strcpy (Nv_chaine,  strcat(_Sx, Element_V26c(Minuscule , J   ))) ;
             }
           else
             {
             if( (strcmp( Car_rm, Element_V26c(Minuscule , J   )) == 0  )) {
               strcpy (_Sx, Nv_chaine);
               strcpy (Nv_chaine,  strcat(_Sx, Element_V26c(Minuscule , J   ))) ;

             } ;

           } ;

         } ;
         if( (strcmp( Car_rm, "*") == 0  )) {
           strcpy (_Sx, Nv_chaine);
           strcpy (Nv_chaine,  strcat(_Sx, "*")) ;
           }
         else
           {
           if( (strcmp( Car_rm, "?") == 0  )) {
             strcpy (_Sx, Nv_chaine);
             strcpy (Nv_chaine,  strcat(_Sx, "?")) ;

           } ;

         } ;

       } ;

     } ;
     if( ( (strcmp( Caract(*Chaine_rm , 1 ), "?") == 0  ) || (strcmp( Caract(*Chaine_rm , 1 ), "*") == 0  ) ))
        {
       strcpy (Reglerchaine2,   " ") ;
       *Stop  =  False ;
       }
     else
       {
       if( ( Longchaine(*Chaine_rm ) != Longchaine(Nv_chaine ) ))
        {
       *Stop  =  False ;
         }
       else
         {
         strcpy (Reglerchaine2,   Nv_chaine) ;
         *Stop  =  True ;

       } ;

     } ;

     return Reglerchaine2 ;
    }
  /*----------------------------------------------------*/
  void Init_min (Typevect_V26c *Minuscule)
    {

      /** Corps du module **/
     Aff_element_V26c(*Minuscule , 1   , "a" ) ;
     Aff_element_V26c(*Minuscule , 2   , "b" ) ;
     Aff_element_V26c(*Minuscule , 3   , "c" ) ;
     Aff_element_V26c(*Minuscule , 4   , "d" ) ;
     Aff_element_V26c(*Minuscule , 5   , "e" ) ;
     Aff_element_V26c(*Minuscule , 6   , "f" ) ;
     Aff_element_V26c(*Minuscule , 7   , "g" ) ;
     Aff_element_V26c(*Minuscule , 8   , "h" ) ;
     Aff_element_V26c(*Minuscule , 9   , "i" ) ;
     Aff_element_V26c(*Minuscule , 10   , "j" ) ;
     Aff_element_V26c(*Minuscule , 11   , "k" ) ;
     Aff_element_V26c(*Minuscule , 12   , "l" ) ;
     Aff_element_V26c(*Minuscule , 13   , "m" ) ;
     Aff_element_V26c(*Minuscule , 14   , "n" ) ;
     Aff_element_V26c(*Minuscule , 15   , "o" ) ;
     Aff_element_V26c(*Minuscule , 16   , "p" ) ;
     Aff_element_V26c(*Minuscule , 17   , "q" ) ;
     Aff_element_V26c(*Minuscule , 18   , "r" ) ;
     Aff_element_V26c(*Minuscule , 19   , "s" ) ;
     Aff_element_V26c(*Minuscule , 20   , "t" ) ;
     Aff_element_V26c(*Minuscule , 21   , "u" ) ;
     Aff_element_V26c(*Minuscule , 22   , "v" ) ;
     Aff_element_V26c(*Minuscule , 23   , "w" ) ;
     Aff_element_V26c(*Minuscule , 24   , "x" ) ;
     Aff_element_V26c(*Minuscule , 25   , "y" ) ;
     Aff_element_V26c(*Minuscule , 26   , "z" ) ;

    }
  /*----------------------------------------------------*/
  void Init_maj (Typevect_V26c *Majuscule)
    {

      /** Corps du module **/
     Aff_element_V26c(*Majuscule , 1   , "A" ) ;
     Aff_element_V26c(*Majuscule , 2   , "B" ) ;
     Aff_element_V26c(*Majuscule , 3   , "C" ) ;
     Aff_element_V26c(*Majuscule , 4   , "D" ) ;
     Aff_element_V26c(*Majuscule , 5   , "E" ) ;
     Aff_element_V26c(*Majuscule , 6   , "F" ) ;
     Aff_element_V26c(*Majuscule , 7   , "G" ) ;
     Aff_element_V26c(*Majuscule , 8   , "H" ) ;
     Aff_element_V26c(*Majuscule , 9   , "I" ) ;
     Aff_element_V26c(*Majuscule , 10   , "J" ) ;
     Aff_element_V26c(*Majuscule , 11   , "K" ) ;
     Aff_element_V26c(*Majuscule , 12   , "L" ) ;
     Aff_element_V26c(*Majuscule , 13   , "M" ) ;
     Aff_element_V26c(*Majuscule , 14   , "N" ) ;
     Aff_element_V26c(*Majuscule , 15   , "O" ) ;
     Aff_element_V26c(*Majuscule , 16   , "P" ) ;
     Aff_element_V26c(*Majuscule , 17   , "Q" ) ;
     Aff_element_V26c(*Majuscule , 18   , "R" ) ;
     Aff_element_V26c(*Majuscule , 19   , "S" ) ;
     Aff_element_V26c(*Majuscule , 20   , "T" ) ;
     Aff_element_V26c(*Majuscule , 21   , "U" ) ;
     Aff_element_V26c(*Majuscule , 22   , "V" ) ;
     Aff_element_V26c(*Majuscule , 23   , "W" ) ;
     Aff_element_V26c(*Majuscule , 24   , "X" ) ;
     Aff_element_V26c(*Majuscule , 25   , "Y" ) ;
     Aff_element_V26c(*Majuscule , 26   , "Z" ) ;

    }
  /*----------------------------------------------------*/
  string255  Equiv (string255 *Requete)
    {
      /** Variables locales **/
      string255  Equiv2 ;
      string255 Nv_requete;
      int J;
      string2 Car_req;
      string255 _Sx;

      /** Corps du module **/
     Nv_requete = malloc(255 * sizeof(string255));
     Car_req = malloc(2 * sizeof(string2));
     _Sx = malloc(255 * sizeof(string255));
     Equiv2 = malloc(255 * sizeof(string255));
     J  =  1 ;
     strcpy (Nv_requete,   "") ;
     while( ( J <= Longchaine(*Requete ) )) {
       strcpy (Car_req,   Caract(*Requete , J )) ;
       if( (strcmp( Car_req, "*") != 0  )) {
         strcpy (_Sx, Nv_requete);
         strcpy (Nv_requete,  strcat(_Sx, Car_req)) ;
         J  =  J + 1 ;
         }
       else
         {
         strcpy (_Sx, Nv_requete);
         strcpy (Nv_requete,  strcat(_Sx, Car_req)) ;
        /*j := j+1;*/
         while( ( (strcmp( Caract(*Requete , J ), "*") == 0  ) && ( J < Longchaine(*Requete ) ) )) {
           J  =  J + 1 ;

         } ;
         if( (strcmp( Caract(*Requete , J ), "*") == 0  )) {
           J  =  J + 1 ;

         } ;

       } ;

     } ;
     strcpy (Equiv2,   Nv_requete) ;

     return Equiv2 ;
    }
  /*----------------------------------------------------*/
  string255  Inverser (string255 *Requete)
    {
      /** Variables locales **/
      string255  Inverser2 ;
      bool Modif;
      string255 Mot;
      string255 Novmot;
      int I;
      int J;
      string255 _Sx;

      /** Corps du module **/
     Mot = malloc(255 * sizeof(string255));
     Novmot = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     Inverser2 = malloc(255 * sizeof(string255));
     strcpy (Mot,   *Requete) ;
     Modif  =  True ;
     while( ( Modif )) {
       Modif  =  False ;
       I  =  1 ;
       while( ( I < ( Longchaine(Mot ) ) )) {
         if( ( (strcmp( ( Caract(Mot , I ) ), "*") == 0  ) && (strcmp( ( Caract(Mot , I + 1 ) ), "?") == 0  ) )) {
           strcpy (Novmot,   "") ;
           for( J  =  1 ;J <=  I - 1   ; ++J){
             strcpy (_Sx, Novmot);
             strcpy (Novmot,  strcat(_Sx, Caract(Mot , J ))) ;
           } ;
           strcpy (_Sx, Novmot);
           strcpy (Novmot,  strcat(_Sx, "?")) ;
           strcpy (_Sx, Novmot);
           strcpy (Novmot,  strcat(_Sx, "*")) ;
           Modif  =  True ;
           for( J  =  I + 2 ;J <=  Longchaine(Mot )   ; ++J){
             strcpy (_Sx, Novmot);
             strcpy (Novmot,  strcat(_Sx, Caract(Mot , J ))) ;
           } ;
         } ;
         I  =  I + 1 ;
       } ;
       if( ( Modif )) {
         strcpy (Mot,   Novmot) ;
       } ;
     } ;
     strcpy (Inverser2,   Mot) ;
     return Inverser2 ;
    }

  /*----------------------------------------------------*/
  void Alea_saisie (int *Choix_mot)
    {
      /** Variables locales **/
        char tabchoix [10] [500];
      /** Corps du module **/
        system("COLOR 73");
        gotoxy(15,10); printf("Veuillez Choisir:");
        strcpy(tabchoix[0],"Saisie des mots");
        strcpy(tabchoix[1],"Mots Aleatoires");
        strcpy(tabchoix[2],"A partir du dictionnaire");
        *Choix_mot= choisirparametre(tabchoix,3,18,12,3,7);
        system("cls");
        system("COLOR fc");
    }

    void fenetres_glissantes (Typevect_V10000s Tabmots, int nbrmot)
    {

        char tabchoix [10][500];
        int choix_gliss;
        bool retour = False;
        int i=0;
        int j;
        int cpt;
        int c;
        while(retour==False)
        {
        system("cls");
        system("COLOR f4");
        cpt=0;
        c=1;
        gotoxy(10,29);
        printf ( " Les mots trouves sont : " ) ;
        if (i<0)
           {
               i=0;
           }
        if (nbrmot>5)
        {
        if (i==0) //5 premiers
        {
           j=i;
           while ((i<5) && (i<nbrmot))
           {
               gotoxy(11,29+c);
               printf("    %s ",Tabmots[i]);
               c++;
               i++;
           }

           menu();
           strcpy(tabchoix[0],"Retour vers le menu");
           strcpy(tabchoix[1],"Debut");
           strcpy(tabchoix[2],"Suivant");
           strcpy(tabchoix[3],"Fin");
           choix_gliss= choisirparametre(tabchoix,4,40,20,1,15);
           switch (choix_gliss)
           {
            case 0:
                retour = True;
                system("cls");
                break;
            case 1:
                i=0;
                break;
            case 2:
                retour = False;
                break;
            case 3:
                i= nbrmot-5;
                break;
           }
        }
        else if (i>=(nbrmot-5)) //6derniers
        {
           j=i;
           while (i<nbrmot)
           {
               gotoxy(11,29+c);
               printf("    %s ",Tabmots[i]);
               c++;
               i++;
           }
           menu();
           strcpy(tabchoix[0],"Retour vers le menu");
           strcpy(tabchoix[1],"Debut");
           strcpy(tabchoix[2],"Precedent");
           strcpy(tabchoix[3],"Fin");
           choix_gliss= choisirparametre(tabchoix,4,40,15,1,15);

           switch (choix_gliss)
           {
            case 0:
                retour = True;
                system("cls");
                break;
            case 1:
                i=0;
                break;
            case 2:
                i=j-5;
                break;
            case 3:
                i= nbrmot-5;
                break;
           }
        }
        else
        {
           menu();
           j=i;
           while (cpt<=5)
           {
               gotoxy(11,29+c);
               printf("    %s ",Tabmots[i]);
               c++;
               i++;
               cpt++;
           }
            strcpy(tabchoix[0],"Retour vers le menu");
           strcpy(tabchoix[1],"Debut");
           strcpy(tabchoix[2],"Precedent");
           strcpy(tabchoix[3],"Suivant");
           strcpy(tabchoix[4],"Fin");
           choix_gliss= choisirparametre(tabchoix,5,40,15,1,15);
           switch (choix_gliss)
           {
            case 0:
                retour = True;
                system("cls");
                break;
            case 1:
                i=0;
                break;
            case 2:
                i=j-5;
                break;
            case 3:
                retour = False;
                break;
            case 4:
                i= nbrmot-5;
                break;
           }
        }
        }
        else //nbrmot<=5
        {
          while (i<nbrmot)
           {
               gotoxy(11,29+c);
               printf("    %s ",Tabmots[i]);
               c++;
               i++;
           }

           menu();
           strcpy(tabchoix[0],"Retour vers le menu");
           choix_gliss= choisirparametre(tabchoix,1,40,20,1,15);
           switch (choix_gliss)
           {
            case 0:
                retour = True;
                system("cls");
                break;
           }
        }
        }
    }


    void erreur ()
{
    //en cas d'errur
    system("cls");
    system("COLOR 46");
    int e=20;
    int f=10;
    gotoxy (e,f);
    printf("   . \n",167);gotoxy (e,f+1);
    printf("  %c %c\n",47,92);gotoxy (e,f+2);
    printf(" %c %c %c\n",47,33,92);gotoxy (e,f+3);
    printf(" %c%c%c%c%c\n",196,196,196,196,196);gotoxy (e-1,f+4);
};
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void retablir_color ()
{
    system("cls");
    system("COLOR 0c");
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void retablir_color2 ()
{
    system("cls");
    system("COLOR 05");
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void posCurse(FILE* fichier,int lig)
//position le curseur sur le debut de la ligne (lig)
//On repositionne le curseur en début du fichier
//On recupère les lignes du fichier précédentes la ligne lig
{
    rewind(fichier);
    char chaine[10000] = "";
    for (int i=1;i<lig;i++)
    {

        fgets(chaine, 10000, fichier);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Ecran(int Mode) // parametre Mode : 1=plein ecran et 2=mode fenetre
{
    typedef BOOL WINAPI (*SetConsoleDisplayModeT)(HANDLE,DWORD,DWORD*);
    SetConsoleDisplayModeT SetConsoleDisplayMode;

   HINSTANCE hLib=LoadLibrary("KERNEL32.DLL");
   SetConsoleDisplayMode=(SetConsoleDisplayModeT)
      GetProcAddress(hLib,"SetConsoleDisplayMode");

   HANDLE h=CreateFile("CONOUT$",GENERIC_WRITE|GENERIC_READ,FILE_SHARE_READ |
      FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,0);

   DWORD oldmode;
   SetConsoleDisplayMode(h,Mode,&oldmode);
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y)
{
    //positionne le curseur sur un point (x,y)
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void SetColorAndBackground(int ForgC, int BackC)
{
    //change la couleur de la for/back ground
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int choisirparametre(char tab[][500],int nbchoix, int decalmenu_x, int decalmenu_y,int bc, int fc)
{
    //choisir un parametre a partir d'un menu
    int i,y=0,keyp=1,br=0;
    char ch=' ';
    i = 0;
    y = 0;
    decalmenu_y--;
    for(i=0;i<=nbchoix-1;i++)
        {
        if(i==y)
            {
                gotoxy(decalmenu_x,i+1+decalmenu_y);
                SetColorAndBackground(fc,bc);
                printf("%s\n",tab[i],ch);
                SetColorAndBackground(bc,fc);
            }
        else
            {
                gotoxy(decalmenu_x,i+1+decalmenu_y);
                printf("%s\n",tab[i],ch);
            }
        }

    gotoxy(decalmenu_x,y+1+decalmenu_y);
    char c;
    int bol;
    while(1)
        {
            if(br) break;
            if(keyp) c=getch();
            keyp=1;
            switch(c)
            {
                case 80: //l'utilisateur clique sue la fleche vers le bas
                    if (y==nbchoix-1) y=0; //retour vers la 1ere option
                    else y++; //incrementer la ligne (aller vers l'option/ligne suivante)
                    gotoxy(1,y+1+decalmenu_y);
                    for(i=0;i<=nbchoix-1;i++)
                    {
                        if(i==y)
                            {
                                gotoxy(decalmenu_x,i+1+decalmenu_y);
                                SetColorAndBackground(fc,bc);
                                printf("%s\n",tab[i],ch);
                                SetColorAndBackground(bc,fc);
                            }
                        else
                            {
                                gotoxy(decalmenu_x,i+1+decalmenu_y);
                                printf("%s\n",tab[i],ch);
                            }
                    }
                    gotoxy(decalmenu_x+1,y+1+decalmenu_y);
                    break;
                case 72: //l'utilisateur clique sue la fleche vers le haut
                        if (y==0) y=nbchoix-1; //aller vers la derniere option(ligne) du menu
                        else y--; //decrementer la ligne (aller vers l'option/ligne precedente)
                        gotoxy(1,y+1+decalmenu_y);
                        for(i=0;i<=nbchoix-1;i++)
                            {
                                if(i==y)
                                {
                                    gotoxy(decalmenu_x,i+1+decalmenu_y);
                                    SetColorAndBackground(fc,bc);
                                    printf("%s\n",tab[i],ch);
                                    SetColorAndBackground(bc,fc);
                                }
                                else
                                {
                                    gotoxy(decalmenu_x,i+1+decalmenu_y);
                                    printf("%s\n",tab[i],ch);
                                }
                            }
                            gotoxy(decalmenu_x,y+1+decalmenu_y);
                            break;

                        case 13: //l'utilisateur clique sue 'Entrer'
                            return y; //valider le choix de l'option
                            br=0;
                            break;
                }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void window()
{
    SetConsoleTitle("Tp ALSDD 2 : Dictionnaire ");
    int ecran;
    system("COLOR 71");
    system("mode con cols=45 lines=6");
    char tabchoix[10][500];
    printf("Veuillez Selectioner le mode de la fenetre :");
    strcpy(tabchoix[0],"Mode plein ecran ");
    strcpy(tabchoix[1],"Mode fenetre");
    ecran= choisirparametre(tabchoix,2,10,3,1,7);
    printf("%d", ecran);
    if (ecran==0)
    {
        system("cls");
        Ecran(1);
    }
    else if (ecran==1)
    {
        system("cls");
        Ecran(2);
        system("mode con cols=130 lines=40");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void date_daujourdhui (int *year, int *month, int *day, char *wday[20]) //pour recuperer la date de la journee X
{
    time_t result = time(NULL);
    struct tm date;
    date = *localtime(&result);
    *year = 1900 + (date.tm_year); //l'annee
    *month= (date.tm_mon) +1; //le mois
    *day= (date.tm_mday); //le jour
    int weekd;
    weekd=date.tm_wday;
    switch(weekd)
    {
        case 0:
            strcpy(wday,"Dimanche");
            break;
        case 1:
            strcpy(wday,"Lundi");
            break;
         case 2:
            strcpy(wday,"Mardi");
            break;
        case 3:
            strcpy(wday,"Mercredi");
            break;
        case 4:
            strcpy(wday,"Jeudi");
            break;
        case 5:
            strcpy(wday,"Vendredi");
            break;
        case 6:
            strcpy(wday,"Samedi");
            break;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////
void entrer ()
{
//CETTE FONCTION AFFICHE L'ECRAN D'ACCEUIL DU PROGRAMME
int i=2;
//bienvenue
SetColorAndBackground(4,0);
gotoxy(40,i);i++;
 printf(" ____  __  ____  __ _  _  _  ____  __ _  _  _  ____ ");gotoxy(40,i);i++;Sleep(100);
 printf("(  _ \\(  )(  __)(  ( \\/ )( \\(  __)(  ( \\/ )( \\(  __)");gotoxy(40,i);i++;Sleep(90);
 printf(" ) _ ( )(  ) _) /    /\\ \\/ / ) _) /    /) \\/ ( ) _) ");gotoxy(40,i);i++;Sleep(85);
 printf("(____/(__)(____)\\_)__) \\__/ (____)\\_)__)\\____/(____)");gotoxy(40,i);i++;Sleep(80);
 ////////////////////
//Requetes sur un dicionnaire
i++;
gotoxy(20,i);i++;
SetColorAndBackground(15,0);

printf("              .---.                    .-.                                               ");gotoxy(20,i);i++;Sleep(100);
printf("              : .; :                  .' `.                                              ");gotoxy(20,i);i++;Sleep(100);
printf("              :   .' .--.  .---..-..-.`. .' .--.  .--.    .--. .-..-..--.                ");gotoxy(20,i);i++;Sleep(100);
printf("              : :.`.' '_.'' .; :: :; : : : ' '_.'`._-.'  `._-.': :; :: ..'               ");gotoxy(20,i);i++;Sleep(100);
printf("              :_;:_;`.__.'`._. ;`.__.' :_; `.__.'`.__.'  `.__.'`.__.':_;                 ");gotoxy(20,i);i++;Sleep(100);
printf("                             : :                                                         ");gotoxy(20,i);i++;i++;Sleep(100);
printf("                             :_:                                                         ");gotoxy(15,i);i++;Sleep(100);
printf("                             .-. _        .-.  _                           _             ");gotoxy(15,i);i++;Sleep(100);
printf("                             : ::_;      .' `.:_;                         :_;            ");gotoxy(15,i);i++;Sleep(100);
printf("            .-..-.,-.,-.   .-' :.-. .--. `. .'.-. .--. ,-.,-.,-.,-. .--.  .-..--.  .--.  ");gotoxy(15,i);i++;Sleep(100);
printf("            : :; :: ,. :  ' .; :: :'  ..' : : : :' .; :: ,. :: ,. :' .; ; : :: ..'' '_.' ");gotoxy(15,i);i++;Sleep(100);
printf("            `.__.':_;:_;  `.__.':_;`.__.' :_; :_;`.__.':_;:_;:_;:_;`.__,_;:_;:_;  `.__.' ");gotoxy(15,i);i++;Sleep(100);



//////////////////
i= 30;
int ligne_cadre =i;
int c_cadre=4;
int c_ecrit=15;
SetColorAndBackground(c_cadre,0);
ligneH(0,ligne_cadre,130,30);
gotoxy(20,ligne_cadre);printf("%c", 203);
ligneV(20,ligne_cadre+1,ligne_cadre+7);
int j=10;
i+=3;
gotoxy(j-8,i);
SetColorAndBackground(c_ecrit,0);
printf("TP ALSDD 2");
j+=14;
i-=2;
gotoxy(j,i);
printf("\033[4mRealise par :\033[0m ");i+=2; j+=5;gotoxy(j+5,i);
printf("Slimani Wassila Maria");i++;gotoxy(j+5,i);
printf("Abchiche Sarah");i++;gotoxy(j-5,i+1);
printf("Groupe 11");
SetColorAndBackground(c_cadre,0);
ligneV(j+30,ligne_cadre+1,ligne_cadre+7);
gotoxy(j+30,ligne_cadre);printf("%c", 203);
int x=j+36;
int y= ligne_cadre+2;
//Logo ESI
    SetColorAndBackground(15,0);
    gotoxy(x,y);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x,y+1);
    printf("%c%c",219,219);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x,y+3);
    printf("%c%c",219,219);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x+6,y);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x+6,y+1);
    printf("%c%c",219,219);
    gotoxy(x+6,y+2);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x+9,y+3);
    printf("%c%c",219,219);
    gotoxy(x+6,y+4);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(x+12,y);
    SetColorAndBackground(1,0);printf("%c%c",219,219);
    SetColorAndBackground(15,0);
    gotoxy(x+12,y+1);
    printf("%c%c",219,219);
    gotoxy(x+12,y+2);
    printf("%c%c",219,219);
    gotoxy(x+12,y+3);
    printf("%c%c",219,219);
    gotoxy(x+12,y+4);
    printf("%c%c",219,219);
    ////
    gotoxy(x+20,y+1);
    printf("ECOLE NATIONALE");
    gotoxy(x+20,y+2);
    printf("SUPERIEURE");
    gotoxy(x+20,y+3);
    printf("D'INFORMATIQUE");
    gotoxy(x+40,y+2);
    printf(" 2018/2019");
//////
SetColorAndBackground(c_cadre,0);
ligne_cadre+=7;
ligneH(0,ligne_cadre,20,30);
gotoxy(20,ligne_cadre); printf("%c", 202);
ligneH(21,ligne_cadre,j+30,30);
gotoxy(j+30,ligne_cadre); printf("%c", 202);
ligneH(j+31,ligne_cadre,130,30);

SetColorAndBackground(15,0);
system("PAUSE");
//system("COLOR 0f");
}
void ligneV (int coord_x, int coord_y, int max_y) //affiche une ligne verticale selon les coordonnes
{
    for ( int k=coord_y; k<max_y;k++ )
{
    gotoxy(coord_x,k);
     printf("%c", 186); Sleep(20);
 }
}
/////////////////////////////////////////
void ligneH (int coord_x, int coord_y,int max_x,int timer)//affiche une ligne horizontal selon les coordonnes
{
 for ( int j=coord_x; j<max_x;j++ )
{
    gotoxy(j,coord_y);
    printf("%c", 205);
    Sleep(timer);
}
}
////////////////////////////////////////////////////////////////////////////////////////////
void menu ()
{
    int clr_bo=4, clr_in=1;
    int x=20, y=2;

gotoxy(x,y);y++;

 SetColorAndBackground(clr_bo,15);

gotoxy(x,y);y++;printf(" .----------------.  .----------------.  .-----------------. .----------------. ");
gotoxy(x,y);y++;printf("| .--------------. || .--------------. || .--------------. || .--------------. |");
gotoxy(x,y);y++;printf("| | ");SetColorAndBackground(clr_in,15);printf("____    ____ ");SetColorAndBackground(clr_bo,15);printf("| || |  ");SetColorAndBackground(clr_in,15);printf("_________   ");SetColorAndBackground(clr_bo,15);printf("| || | ");SetColorAndBackground(clr_in,15);printf("____  _____  ");SetColorAndBackground(clr_bo,15);printf("| || | ");SetColorAndBackground(clr_in,15);printf("_____  _____");SetColorAndBackground(clr_bo,15);printf(" | |");
gotoxy(x,y);y++;printf("| |");SetColorAndBackground(clr_in,15);printf("|_   \\  /   _|");SetColorAndBackground(clr_bo,15);printf("| || | ");SetColorAndBackground(clr_in,15);printf("|_   ___  |");SetColorAndBackground(clr_bo,15);printf("  | || |");SetColorAndBackground(clr_in,15);printf("|_   \\|_   _|");SetColorAndBackground(clr_bo,15);printf(" | || |");SetColorAndBackground(clr_in,15);printf("|_   _||_   _|");SetColorAndBackground(clr_bo,15);printf("| |");
gotoxy(x,y);y++;printf("| |  ");SetColorAndBackground(clr_in,15);printf("|   \\/   |  ");SetColorAndBackground(clr_bo,15);printf("| || |   ");SetColorAndBackground(clr_in,15);printf("| |_  \\_|");SetColorAndBackground(clr_bo,15);printf("  | || |  ");SetColorAndBackground(clr_in,15);printf("|   \\ | |  ");SetColorAndBackground(clr_bo,15);printf(" | || | ");SetColorAndBackground(clr_in,15);printf(" | |    | |  ");SetColorAndBackground(clr_bo,15);printf("| |");
gotoxy(x,y);y++;printf("| |  ");SetColorAndBackground(clr_in,15);printf("| |\\  /| |  ");SetColorAndBackground(clr_bo,15);printf("| || |   ");SetColorAndBackground(clr_in,15);printf("|  _|  _ ");SetColorAndBackground(clr_bo,15);printf("  | || |  ");SetColorAndBackground(clr_in,15);printf("| |\\ \\| |  ");SetColorAndBackground(clr_bo,15);printf(" | || | ");SetColorAndBackground(clr_in,15);printf(" | '    ' |  ");SetColorAndBackground(clr_bo,15);printf("| |");
gotoxy(x,y);y++;printf("| | ");SetColorAndBackground(clr_in,15);printf("_| |_\\/_| |_ ");SetColorAndBackground(clr_bo,15);printf("| || |  ");SetColorAndBackground(clr_in,15);printf("_| |___/ |");SetColorAndBackground(clr_bo,15);printf("  | || | ");SetColorAndBackground(clr_in,15);printf("_| |_\\   |_  ");SetColorAndBackground(clr_bo,15);printf("| || |  ");SetColorAndBackground(clr_in,15);printf(" \\ `--' /   ");SetColorAndBackground(clr_bo,15);printf("| |");
gotoxy(x,y);y++;printf("| |");SetColorAndBackground(clr_in,15);printf("|_____||_____|");SetColorAndBackground(clr_bo,15);printf("| || | ");SetColorAndBackground(clr_in,15);printf("|_________|");SetColorAndBackground(clr_bo,15);printf("  | || |");SetColorAndBackground(clr_in,15);printf("|_____|\\____| ");SetColorAndBackground(clr_bo,15);printf("| || |  ");SetColorAndBackground(clr_in,15);printf("  `.__.'    ");SetColorAndBackground(clr_bo,15);printf("| |");
gotoxy(x,y);y++;printf("| |              | || |              | || |              | || |              | |");
gotoxy(x,y);y++;printf("| '--------------' || '--------------' || '--------------' || '--------------' |");
gotoxy(x,y);y++;printf(" '----------------'  '----------------'  '----------------'  '----------------' ");


}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void quitter ()
{
    //affiche la fin du programme
//MERCI
    system("cls");
    system("COLOR 3F");
    int i= 10;
    gotoxy(20,i); i++;
    printf("         *****   **    **                                             ");  Sleep(100);gotoxy(20,i); i++;
    printf("  ******  ***** *****                                       *     ");  Sleep(100);gotoxy(20,i); i++;
    printf(" **   *  *  ***** *****                                    ***    ");  Sleep(100);gotoxy(20,i); i++;
    printf("*    *  *   * **  * **                                      *     ");  Sleep(100);gotoxy(20,i); i++;
    printf("    *  *    *     *               ***  ****                       ");  Sleep(100);gotoxy(20,i); i++;
    printf("   ** **    *     *        ***     **** **** *    ****    ***     ");  Sleep(100);gotoxy(20,i); i++;
    printf("   ** **    *     *       * ***     **   ****    * ***  *  ***    ");  Sleep(100);gotoxy(20,i); i++;
    printf("   ** **    *     *      *   ***    **          *   ****    **    ");  Sleep(100);gotoxy(20,i); i++;
    printf("   ** **    *     *     **    ***   **         **           **    ");  Sleep(100);gotoxy(20,i); i++;
    printf("   ** **    *     **    ********    **         **           **    ");  Sleep(100);gotoxy(20,i); i++;
    printf("   *  **    *     **    *******     **         **           **    ");  Sleep(100);gotoxy(20,i); i++;
    printf("      *     *      **   **          **         **           **    ");  Sleep(100);gotoxy(20,i); i++;
    printf("  ****      *      **   ****    *   ***        ***     *    **    ");  Sleep(100);gotoxy(20,i); i++;
    printf(" *  *****           **   *******     ***        *******     *** * ");  Sleep(100);gotoxy(20,i); i++;
    printf("*     **                  *****                  *****       ***  ");  Sleep(100);gotoxy(20,i); i++;
    printf("*                                                                 ");  Sleep(100);gotoxy(20,i); i++;
    printf(" **  \n\n\n");
    system("PAUSE");
//ESI
    system("cls");
    system("COLOR 0F");
    i=10;
    gotoxy(20,i);i++;
    SetColorAndBackground(15,0);printf("******************************");SetColorAndBackground(4,0);printf("                  **********      **");SetColorAndBackground(2,0);printf("        **************\n");  Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("*******************************");SetColorAndBackground(4,0);printf("             ****************** ***");SetColorAndBackground(2,0);printf("        ***************\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("   ***************************");SetColorAndBackground(4,0);printf("           *******       ***********");SetColorAndBackground(2,0);printf("           *******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("     *****                 *****");SetColorAndBackground(4,0);printf("         *****              *******");SetColorAndBackground(2,0);printf("            *****\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("     *****                   ****");SetColorAndBackground(4,0);printf("        ****                 ******");SetColorAndBackground(2,0);printf("           *****\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******                    ***");SetColorAndBackground(4,0);printf("       *****                  *****");SetColorAndBackground(2,0);printf("          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******          ***        **");SetColorAndBackground(4,0);printf("       ******                   ***");SetColorAndBackground(2,0);printf("          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******          ***");SetColorAndBackground(4,0);printf("                  *******                  **");SetColorAndBackground(2,0);printf("          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******         ****");SetColorAndBackground(4,0);printf("                  ***********");SetColorAndBackground(2,0);printf("                          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******        *****");SetColorAndBackground(4,0);printf("                    ***************");SetColorAndBackground(2,0);printf("                    ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    *******************");SetColorAndBackground(4,0);printf("                      *****************");SetColorAndBackground(2,0);printf("                ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    *******************");SetColorAndBackground(4,0);printf("                         ******************");SetColorAndBackground(2,0);printf("            ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******        *****");SetColorAndBackground(4,0);printf("                               **************");SetColorAndBackground(2,0);printf("          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******         ****");SetColorAndBackground(4,0);printf("                                     *********");SetColorAndBackground(2,0);printf("         ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******          ***");SetColorAndBackground(4,0);printf("                ****                    *******");SetColorAndBackground(2,0);printf("        ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******          ***         ***");SetColorAndBackground(4,0);printf("    ****                     ******");SetColorAndBackground(2,0);printf("        ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******                     ****");SetColorAndBackground(4,0);printf("     ****                     *****");SetColorAndBackground(2,0);printf("        ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******                    ****");SetColorAndBackground(4,0);printf("      ******                   *****");SetColorAndBackground(2,0);printf("        ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    *****                  ******");SetColorAndBackground(4,0);printf("       ******                 *****");SetColorAndBackground(2,0);printf("          *****\n");  Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("    ******                *******");SetColorAndBackground(4,0);printf("        *********            ******");SetColorAndBackground(2,0);printf("          ******\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("** *****************************");SetColorAndBackground(4,0);printf("         **** *********************");SetColorAndBackground(2,0);printf("       **************\n"); Sleep(100);gotoxy(20,i); i++;
    SetColorAndBackground(15,0);printf("********************************");SetColorAndBackground(4,0);printf("         ***    ****************");SetColorAndBackground(2,0);printf("          ***************"); Sleep(100);gotoxy(20,i); i++;

    for (int h=0;h<20;h++){printf("\n\n\n");Sleep(100);}
}
void set_screen(int background)
{
    //logo ESI
int w,c;
if (background==15){w=1;}
else {w=15;}
if ((background==1)||(background==15)) {c=0;}
else {c=1;}
int i=99;int y =30;
gotoxy(0,50);
SetColorAndBackground(w,background);
ligneH(0,35,100,0);
gotoxy(20,36);
int year,month,day;
char wday[20];
date_daujourdhui (&year, &month, &day, wday);
printf("~~Le %s %d/%d/%d ~~", wday, day,month,year);
gotoxy(20,37);
printf("Slimani Wassila && Abchiche Sarah");

gotoxy(i,y);
SetColorAndBackground(w,background);printf("   ('-.     .-')    ");y++;gotoxy(i,y);
printf(" _(  OO)   ( OO ).            ");y++;gotoxy(i,y);
printf("(");SetColorAndBackground(c,background);printf(",------. ");SetColorAndBackground(w,background);printf("(_)");SetColorAndBackground(c,background);printf("---");SetColorAndBackground(w,background);printf("\\_)   ");
SetColorAndBackground(c,background);printf(",-");SetColorAndBackground(w,background);printf(".-')  ");y++;gotoxy(i,y);
SetColorAndBackground(c,background);printf(" |  .---' /    _ |    |  |");SetColorAndBackground(w,background);printf("OO) ");y++;gotoxy(i,y);
SetColorAndBackground(c,background);printf(" |  |     \\  :`");SetColorAndBackground(w,background);printf(" `.    ");
SetColorAndBackground(c,background);printf("|  |");SetColorAndBackground(w,background);printf("  \\ ");y++;gotoxy(i,y);
printf("(");SetColorAndBackground(c,background);printf("|  '--.   '..`''.");SetColorAndBackground(w,background);
printf(")   ");SetColorAndBackground(c,background);printf("|  |");SetColorAndBackground(w,background);printf("(_/ ");y++;gotoxy(i,y);
SetColorAndBackground(c,background);printf(" |  .--'  .-._)   \\  ");SetColorAndBackground(w,background);printf(",");
SetColorAndBackground(c,background);printf("|  |");SetColorAndBackground(w,background);printf("_.' ");y++;gotoxy(i,y);
SetColorAndBackground(c,background);printf(" |  `---. \\       / ");SetColorAndBackground(w,background);printf("(_");
SetColorAndBackground(c,background);printf("|  |    ");y++;gotoxy(i,y);
printf(" `------'  `-----'    `--'    ");y++;

gotoxy(1,1);

}
 void resblink ()
  {
        for (int i=0; i<5;i++)
        {
            SetColorAndBackground(12,15);
            SetColorAndBackground(12,15); gotoxy(10,5);printf("****** Aucun mot trouve!******");
            Sleep(100);
            SetColorAndBackground(2,15); gotoxy(10,5);printf("****** Aucun mot trouve!******");
            Sleep(100);
        }
  }
  int main(int argc, char *argv[])
    {
     Tabmots = malloc(100000 * 255  * sizeof(string255));
     int _Izw3;for (_Izw3=0; _Izw3<100000; ++_Izw3)
       Tabmots[_Izw3]= malloc(255 * sizeof(string255));
     Mot = malloc(255 * sizeof(string255));
     Motprec = malloc(255 * sizeof(string255));
     Requete = malloc(255 * sizeof(string255));
     E = malloc(sizeof(Typestr_Tcb));
     E->Champ1 = malloc(2 * sizeof(string2));
     C = malloc(2 * sizeof(string2));
     Caracmot = malloc(2 * sizeof(string2));
     Caracr = malloc(2 * sizeof(string2));
     Carrequete = malloc(2 * sizeof(string2));
     Carmot = malloc(2 * sizeof(string2));
     _Sx = malloc(255 * sizeof(string255));
     const max_length = 40;
     window(); //pour selectioner le mode de la fenetre
     system("cls");
    retablir_color ();
    entrer(); //afficher l'ecran d'accueil
    system("cls");
    set_screen(0);
     Choix  = 0 ;
     FILE* fichier=NULL;
        fichier=fopen("Quantum Computers.txt","r");
        if (fichier == NULL)
        {
         printf("Impossible d'ouvrir le fichier !");
        }
       Alea_saisie ( & Choix_mot ) ;
       if ((Choix_mot == 0) || (Choix_mot == 1))
        {
            system("COLOR 74");
            set_screen(7);
            gotoxy(20,20);
            printf ( "Entrez la longueur maximale de mots:" ) ;
            scanf ( " %d", &L ) ;
            Limite = True;
            while (Limite ==True)
            {
                system("COLOR 74");
                set_screen(7);
                gotoxy(40,24);
                printf("                                                     ");
                gotoxy(20,22);
                printf ( "Entrez le nombre de mots:   " ) ;
                scanf ( "  %d", &M ) ;
           if ((M > 100000) || (M==0))
            {
                system("COLOR 46");
                gotoxy(40,24);
                printf ( "Erreur! Ce programme est limite a 100000 mots! " ) ;
                gotoxy(20,22);
                printf("                                              ");
                Limite  =  True ;
                Sleep(100);
             }
           else
             {
             Limite  =  False ;
             } ;
            }
            }
            else
            {
                L = max_length;
                rewind(fichier);
                M =numword(fichier);
                rewind(fichier);
            };

    /*---------------------generer arbre-----------------------*/
       Racine  =  NULL ;
       rewind(fichier);
        c=getc(fichier);
        while (alphabetic(c)==0 && c!=EOF)
        {
            c=fgetc(fichier);
        }
        Genererarbre ( & Racine , & M , & L , & Choix_mot,fichier) ;
       Choix  =  0 ;
       char tabchoix [10] [500];
       while ( Choix != 2 )
        {
            system("cls");
            system("COLOR f4");
            set_screen(15);
            menu();
            strcpy(tabchoix [0],"Verifier la compabilite de l'arbre");
            strcpy(tabchoix [1],"Lancer une requete");
            strcpy(tabchoix [2],"Quitter le programme");
            Choix = choisirparametre(tabchoix,3,30,15,4,15);
        /*------------ comptabiliteArbre ---------------------*/
         if( ( Choix == 0 ))
         {
            system("cls");
            set_screen(15);
           SetColorAndBackground(0,15);
           gotoxy(10,40);
           printf ( " Verification de la compabilite de l'Arbre \n");
           Compabilitearbre ( & Racine) ;
            system("PAUSE");
           }
         else
           {
          /*----------------------- Requetes -----------------*/
           if( ( Choix == 1 )) {
             Motjuste  =  True ;
             R  =  Racine;
             Z  =  1 ;
             Stop  =  False ;
             while( ( ! Stop ))
                {
                 system("cls");
                 system("COLOR f0");
                set_screen(15);
                SetColorAndBackground(0,15);
                gotoxy(10,40);
               printf ( " Entrez votre requete " ) ;
               scanf ( " %[^\n]", Requete ) ;
               _Px2 =  0 ;
               strcpy (Requete, Reglerchaine ( &_Px2, & Requete , & Stop )) ;
               if (Stop==False)
               {
                   system("COLOR 46");
                   printf("Cette requete n'est pas prise en charge ! Entrez une nouvelle valeur"),
                   Sleep(800);
               }

             } ;
             strcpy (Requete,   Inverser ( & Requete )) ;
             strcpy (Requete,   Equiv ( & Requete )) ;
             strcpy (C,   Caract(Requete , 1 )) ;
             while( ( ( Fd_ATcb(R ) != NULL ) && (strcmp( C, ( Struct1_Tcb(Info_ATcb(R )  ) )) != 0  ) )) {
               R  =  Fd_ATcb(R ) ;
             } ;
             if(strcmp( C, Struct1_Tcb(Info_ATcb(R )  )) == 0 ) {
               Creerpile_PATcb(&P ) ;
               strcpy (Mot,   "") ;
               while( ( ( R != NULL ) || ( ! Pilevide_PATcb(P ) ) )) {
                 while( R != NULL) {
                   Empiler_PATcb(&P , R ) ;
                   strcpy (_Sx, Mot);
                   strcpy (Mot,  strcat(_Sx, Struct1_Tcb(Info_ATcb(R )  ))) ;
                   R  =  Fg_ATcb(R ) ;
                 } ;
                 Depiler_PATcb(&P , &R ) ;
                 if( ( Struct2_Tcb(Info_ATcb(R )  ) ))
                    {
                   Motjuste  =  Verif ( & Mot , & Requete ) ;
                   if( ( Motjuste )) {
                     Aff_element_V10000s(Tabmots , Z   , Mot ) ;
                     Z  =  Z + 1 ;
                   } ;
                 } ;
                 strcpy (Motprec,   "") ;
                 for( V  =  1 ;V <=  ( Longchaine(Mot ) - 1 ) ; ++V){
                   strcpy (_Sx, Motprec);
                   strcpy (Motprec,  strcat(_Sx, Caract(Mot , V ))) ;
                 } ;
                 strcpy (Mot,   Motprec) ;
                 R  =  Fd_ATcb(R ) ;
               } ;

             } ;
             if ( Z >= 2 )
                {
                    fenetres_glissantes(Tabmots,Z-1);
               }
             else
               {
                resblink ();

                system("PAUSE");
             } ;
             }
           else
             {
             if( ( Choix == 2 ))
                {
               quitter ();
                }
           } ;
         } ;
       } ;
       return 0;
     }

