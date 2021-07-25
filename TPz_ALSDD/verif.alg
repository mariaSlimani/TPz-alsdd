   {-------- module verif -----------}
   SOIENT
       N , I , J , L , M , V , Z , Y : ENTIER ;
       R , A , Perer , Prec , Racine , T UN ARB DE ( CAR , BOOLEEN ) ;
       P , Q : PILE DE ARB DE ( CAR , BOOLEEN ) ;
       Tab UN TABLEAU ( 50 ) DE ARB DE ( CAR , BOOLEEN ) ;
       Mot , Motprec , Requete DES CHAINES ;
       E : ( CAR , BOOLEEN ) ;
       C , Caracmot , Caracr , Carmot , Carrequete,etoile,intero : CAR ;
       Bool : BOOLEEN ;
       Motjuste : BOOLEEN ;
       Verif : FONCTION (BOOLEEN) ;
       ReglerChaine , Equiv , inverser, rest DES FONCTION (CHAINE) ;
       init_min , init_maj  DES ACTION ;
      
   DEBUT
        y :=1;
       tantque (y=1)

       etoile := '*' ;
       intero := '?' ;
       ecrire (' requete : ') ;
       LIRE ( Requete ) ;
       ecrire (requete) ;
       requete := inverser (requete ) ;
       requete := Equiv (requete) ;
       ecrire (requete) ;
       ecrire (' mot : ') ;
       LIRE ( Mot ) ;
       ecrire ( mot ) ;
       Motjuste := Verif (mot ,requete);
       ECRIRE ( motjuste ) ;
       LIRE (y);
       fintantque;
   FIN


    FONCTION Verif (mot , requete ) : BOOLEEN
    SOIENT
          requete, mot : CHAINE;
          bool : BOOLEEN;
          i,j DES ENTIER;
          CarReq DES CAR ;
    DEBUT
         bool := FAUX;
          i:= 1 ;
          j:=1;
          carReq := CARACT (requete , j );
          SI ((carReq <> '?') et (carReq <> '*'))
             SI (i <= LONGCHAINE (mot) )
                SI (carReq = CARACT ( mot, i) )
                   SI (( i = LONGCHAINE(mot) ) et ( j= LONGCHAINE(requete )))
                      Verif := VRAI;
                   SINON
                     SI ( ( i <= LONGCHAINE(mot) ) et ( j < LONGCHAINE(requete) ) )
                        i:= i + 1 ;
                        j:= j + 1 ;
                        Verif := Verif (Rest (mot, i) , Rest (requete,j) );
                     SINON
                          Verif := FAUX;
                     FINSI;
                   FINSI;
                SINON
                  Verif := FAUX;
                FINSI;
             SINON
                  Verif := FAUX;
             FINSI;
          SINON
               SI (carReq = '?' )
                  SI (( i = longchaine (mot) ) et ( j= longchaine (requete )))
                     Verif := VRAI;
                  SINON
                       SI ((i <= LONGCHAINE (mot)) et (j< LONGCHAINE (requete)))
                          SI (i < LONGCHAINE (mot))
                             i:= i + 1 ;
                             j:= j + 1 ;
                             Verif := Verif (Rest (mot, i) , Rest (requete,j) );
                          SINON
                               SI ( ( (j+1) = LONGCHAINE (requete) ) et (CARACT (requete, j+1 ) = '*' ))
                                  Verif := VRAI;
                               SINON
                                    Verif := FAUX;
                               FINSI;
                          FINSI;
                       SINON
                            Verif := FAUX;
                       FINSI;
                  FINSI;
               SINON {cas * }
                     SI (j = LONGCHAINE (requete))
                        Verif := VRAI;
                     SINON
                      SI (i >LONGCHAINE(mot))
                             Verif := FAUX;
                      SINON
                          SI (CARACT (mot, i ) = CARACT ( requete, j+1 ) )
                             j := j + 1 ;
                             TANTQUE ((CARACT (mot, i) = CARACT (requete, j) ) ET ( i < LONGCHAINE (mot))ET(non bool))
                                  bool := Verif (rest (mot, i ) , rest (requete, j ));
                                  i := i + 1 ;
                             FINTANTQUE;
                             si ( non bool )
                                si (CARACT (mot, i ) = CARACT ( requete, j ) )
                                   bool := Verif (rest (mot, i ) , rest (requete, j ));
                                sinon
                                     i := i+1;
                                     TANTQUE (i< LONGCHAINE (mot) )
                                             bool := Verif (rest (mot, i ) , rest (requete, j ));
                                             i := i+1;
                                     FINTANTQUE;
                                     SI (i= LONGCHAINE (mot) )
                                        bool := Verif (rest (mot, i ) , rest (requete, j ));
                                     SINON
                                          bool := FAUX;
                                     FINSI;
                                FINSI;
                             FINSI;
                          SINON
                               i := i+1;
                               TANTQUE ((i< LONGCHAINE (mot) ) ET (non bool) )
                                  bool := Verif (rest (mot, i ) , rest (requete, j ));
                                  i := i+1;
                               FINTANTQUE;
                               SI (non bool)
                                  SI (i= LONGCHAINE (mot) )
                                     bool := Verif (rest (mot, i ) , rest (requete, j ));
                                  SINON
                                    bool := FAUX;
                                  FINSI;
                               FINSI;
                          FINSI;
                          Verif :=  bool;
                      FINSI;
                     FINSI;
               FINSI;
          FINSI;
    FIN

    FONCTION rest (mot , i ) : CHAINE
    SOIENT
          mot , nov_mot : CHAINE;
          i,j : ENTIER;
    DEBUT
        nov_mot := '';
        POUR j:=i, LONGCHAINE(mot) ,1
            nov_mot := nov_mot + CARACT (mot , j);
        FINPOUR;
        rest := nov_mot;
    FIN

     FONCTION  ReglerChaine (re_mo , chaine_rm , stop) : chaine
          SOIENT
          re_mo,i,j : ENTIER ;
          chaine_rm, nv_chaine DES CHAINE ;
          stop : BOOLEEN ;
          minuscule, majuscule DES VECTEUR ( 26 ) DE CAR;
          car_rm : CAR ;
          DEBUT
          {--------------initialiser minuscule----------------}
          APPEL init_min (minuscule) ;

          {-------------- initialiser majuscule -------------}
          APPEL init_maj (majuscule) ;

          nv_chaine := '';
          si (re_mo = 1)
              pour i:=1 , longchaine (chaine_rm) , 1
                   car_rm := caract ( chaine_rm , i);

                   pour j:=1 , 26 ,1
                        si (car_rm = ELEMENT (majuscule [ j ]) )
                           nv_chaine := nv_chaine + ELEMENT (minuscule [j]);
                        sinon
                             si (car_rm = ELEMENT (minuscule [ j ]) )
                                nv_chaine := nv_chaine + ELEMENT (minuscule [j]);
                             finsi;
                        finsi;
                   finpour;
              finpour;

          sinon   {re_mo = 0}
               pour i:=1 , longchaine (chaine_rm) , 1
                   car_rm := caract ( chaine_rm , i);

                   pour j:=1 , 26 ,1
                        si (car_rm = ELEMENT (majuscule [ j ]) )
                           nv_chaine := nv_chaine + ELEMENT (minuscule [j]);
                        sinon
                             si (car_rm = ELEMENT (minuscule [ j ]) )
                                nv_chaine := nv_chaine + ELEMENT (minuscule [j]);
                             finsi;
                        finsi;
                   finpour;
                   si (car_rm = '*')
                      nv_chaine := nv_chaine + '*';
                   sinon
                        si (car_rm = '?')
                           nv_chaine := nv_chaine + '?';
                        finsi;
                   finsi;
              finpour;
          finsi;
         si (longchaine (chaine_rm) <> longchaine (nv_chaine) )
                 ReglerChaine := ' ';
                 ECRIRE (' erreur! veuillez introduire une valeur valide!' );
                 stop := FAUX;
         sinon
              ReglerChaine := nv_chaine;
              stop := VRAI;
         finsi;
         FIN


         ACTION init_min (minuscule)
                SOIT
                    minuscule : VECTEUR ( 26 ) DE CAR;
                DEBUT
                AFF_ELEMENT ( minuscule [ 1 ] , 'a' ) ;
                AFF_ELEMENT ( minuscule [ 2 ] , 'b' ) ;
                AFF_ELEMENT ( minuscule [ 3 ] , 'c' ) ;
                AFF_ELEMENT ( minuscule [ 4 ] , 'd' ) ;
                AFF_ELEMENT ( minuscule [ 5 ] , 'e' ) ;
                AFF_ELEMENT ( minuscule [ 6 ] , 'f' ) ;
                AFF_ELEMENT ( minuscule [ 7 ] , 'g' ) ;
                AFF_ELEMENT ( minuscule [ 8 ] , 'h' ) ;
                AFF_ELEMENT ( minuscule [ 9 ] , 'i' ) ;
                AFF_ELEMENT ( minuscule [ 10 ] , 'j' ) ;
                AFF_ELEMENT ( minuscule [ 11 ] , 'k' ) ;
                AFF_ELEMENT ( minuscule [ 12 ] , 'l' ) ;
                AFF_ELEMENT ( minuscule [ 13 ] , 'm' ) ;
                AFF_ELEMENT ( minuscule [ 14 ] , 'n' ) ;
                AFF_ELEMENT ( minuscule [ 15 ] , 'o' ) ;
                AFF_ELEMENT ( minuscule [ 16 ] , 'p' ) ;
                AFF_ELEMENT ( minuscule [ 17 ] , 'q' ) ;
                AFF_ELEMENT ( minuscule [ 18 ] , 'r' ) ;
                AFF_ELEMENT ( minuscule [ 19 ] , 's' ) ;
                AFF_ELEMENT ( minuscule [ 20 ] , 't' ) ;
                AFF_ELEMENT ( minuscule [ 21 ] , 'u' ) ;
                AFF_ELEMENT ( minuscule [ 22 ] , 'v' ) ;
                AFF_ELEMENT ( minuscule [ 23 ] , 'w' ) ;
                AFF_ELEMENT ( minuscule [ 24 ] , 'x' ) ;
                AFF_ELEMENT ( minuscule [ 25 ] , 'y' ) ;
                AFF_ELEMENT ( minuscule [ 26 ] , 'z' ) ;
                FIN


         ACTION init_maj (majuscule)
         SOIT
            majuscule : VECTEUR ( 26 ) DE CAR;
         DEBUT
          AFF_ELEMENT ( majuscule [ 1 ] , 'A' ) ;
          AFF_ELEMENT ( majuscule [ 2 ] , 'B' ) ;
          AFF_ELEMENT ( majuscule [ 3 ] , 'C' ) ;
          AFF_ELEMENT ( majuscule [ 4 ] , 'D' ) ;
          AFF_ELEMENT ( majuscule [ 5 ] , 'E' ) ;
          AFF_ELEMENT ( majuscule [ 6 ] , 'F' ) ;
          AFF_ELEMENT ( majuscule [ 7 ] , 'G' ) ;
          AFF_ELEMENT ( majuscule [ 8 ] , 'H' ) ;
          AFF_ELEMENT ( majuscule [ 9 ] , 'I' ) ;
          AFF_ELEMENT ( majuscule [ 10 ] , 'J' ) ;
          AFF_ELEMENT ( majuscule [ 11 ] , 'K' ) ;
          AFF_ELEMENT ( majuscule [ 12 ] , 'L' ) ;
          AFF_ELEMENT ( majuscule [ 13 ] , 'M' ) ;
          AFF_ELEMENT ( majuscule [ 14 ] , 'N' ) ;
          AFF_ELEMENT ( majuscule [ 15 ] , 'O' ) ;
          AFF_ELEMENT ( majuscule [ 16 ] , 'P' ) ;
          AFF_ELEMENT ( majuscule [ 17 ] , 'Q' ) ;
          AFF_ELEMENT ( majuscule [ 18 ] , 'R' ) ;
          AFF_ELEMENT ( majuscule [ 19 ] , 'S' ) ;
          AFF_ELEMENT ( majuscule [ 20 ] , 'T' ) ;
          AFF_ELEMENT ( majuscule [ 21 ] , 'U' ) ;
          AFF_ELEMENT ( majuscule [ 22 ] , 'V' ) ;
          AFF_ELEMENT ( majuscule [ 23 ] , 'W' ) ;
          AFF_ELEMENT ( majuscule [ 24 ] , 'X' ) ;
          AFF_ELEMENT ( majuscule [ 25 ] , 'Y' ) ;
          AFF_ELEMENT ( majuscule [ 26 ] , 'Z' ) ;
          FIN

 FONCTION Equiv ( requete ) : CHAINE
 SOIENT
      requete,nv_requete DES CHAINE;
      j : ENTIER;
      car_req : CAR;
 DEBUT
 j:=1;
 nv_requete := '';

 TANTQUE (j<= LONGCHAINE (requete) )
         car_req := CARACT (requete, j);
         SI (car_req <> '*' )
            nv_requete := nv_requete + car_req ;
            j:= j+1;
         SINON
              nv_requete := nv_requete + car_req ;
              {j := j+1;}

              TANTQUE ( (CARACT (requete, j) = '*' ) et ( j < LONGCHAINE (requete) ) )
                      j := j + 1;
              FINTANTQUE;
              SI (CARACT (requete, j) = '*' )
                 j := j + 1 ;
              FINSI;
         FINSI;
 FINTANTQUE;
 Equiv := nv_requete ;
 FIN

FONCTION inverser ( requete ) : CHAINE
soient
      modif :booleen;
      requete, mot,novmot:chaine;
      i,j:entier;
debut
     mot := requete;
     modif:=vrai;
     tantque (modif )
                modif:=faux;
                i:=1;
                tantque ( i<(longchaine(mot)))
                    si (((caract(mot,i))='*') et ((caract(mot,i+1))='?'))
                       novmot:='';
                       pour j:=1,i-1 , 1
                          novmot:=novmot+caract(mot,j);
                       finpour;
                       novmot:=novmot+'?';
                       novmot:=novmot+'*';
                       modif:=vrai;
                       pour j:=i+2,longchaine(mot) ,1
                          novmot:=novmot+caract(mot,j);
                       finpour;
                    finsi;
                    i:=i+1;
                fintantque;
                si (modif)
                   mot := novmot ;
                finsi;
     fintantque;
     inverser := mot ;
fin

