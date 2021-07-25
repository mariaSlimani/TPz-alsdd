
  {TP 2 ALSDD - GROUPE 11 - SLIMANI WASSILA MARIA ~ ABCHICHE SARAH - 2018/2019}
  {------------------- Les Déclarations -------------------}
   SOIENT
       N , I , J , K , L , M , V , Z , Y , Choix , Choix_mot , Choice : ENTIER ;
       R , A , Perer , Prec , Racine , T UN ARB DE ( CAR , BOOLEEN ) ;
       P , Q : PILE DE ARB DE ( CAR , BOOLEEN ) ;
       Tab : TABLEAU ( 10000 ) DE ARB DE ( CAR , BOOLEEN ) ;
      {ce programme est limité à 10000 arbres }
       Tabmots : TABLEAU ( 10000 ) DE CHAINE ;
      {ce programme est limité à 10000 mots }
       Mot , Motprec , Requete DES CHAINES ;
       E : ( CAR , BOOLEEN ) ;
       C , Caracmot , Caracr , Carrequete , Carmot : CAR ;
       Bool , Motjuste , Stop , Error , Limite : BOOLEEN ;
       Compabilitearbre , Genererarbre , Parcours , Intro , Alea_saisie , Init_min , Init_maj : ACTION ;
       Verif : FONCTION ( BOOLEEN ) ;
       Reglerchaine , Equiv , Inverser , Rest DES FONCTION ( CHAINE ) ;
      { ------------------- Le Programme Principal ------------------- }
      
   DEBUT
       APPEL Intro ;
       Choix := 0 ;
       Limite := VRAI ;
       TANTQUE ( Limite )
           ECRIRE ( 'Entrez le nombre d"arbre à generer: ' ) ;
           LIRE ( N ) ;
           SI N > 10000
               ECRIRE ( 'Erreur! Ce programme est limité à 10000 arbres!' ) ;
               Limite := VRAI ;
              
           SINON
               Limite := FAUX ;
              
           FINSI ;
          
       FINTANTQUE ;
       SI ( N = 0 )
           Choix := 3 ;
          
       SINON
           APPEL Alea_saisie ( Choix_mot ) ;
           ECRIRE ( ' Choisir la longueur maximale et le nombre des mots :' ) ;
           ECRIRE ( ' 1- Pour tous les arbres ' ) ;
           ECRIRE ( ' 2- Pour chaque arbre ' ) ;
           LIRE ( Choice ) ;
           SI ( Choice = 1 )
               ECRIRE ( 'Entrez la longueur maximale de mots: ' ) ;
               LIRE ( L ) ;
               Limite := VRAI ;
               TANTQUE ( Limite )
                   ECRIRE ( 'entrez le nombre de mots: ' ) ;
                   LIRE ( M ) ;
                   SI M > 10000
                       ECRIRE ( 'Erreur! Ce programme est limité à 10000 mots!' ) ;
                       Limite := VRAI ;
                      
                   SINON
                       Limite := FAUX ;
                      
                   FINSI ;
                  
               FINTANTQUE ;
              
           FINSI ;
          
       FINSI ;
       {---------------------generer N arbres-----------------------}
       POUR K := 1 , N , 1
           ECRIRE ( '' ) ;
           ECRIRE ( ' Arbre ' , K ) ;
           SI ( Choice = 2 )
               ECRIRE ( 'Entrez la longueur maximale de mots: ' ) ;
               LIRE ( L ) ;
               Limite := VRAI ;
               TANTQUE ( Limite )
                   ECRIRE ( 'entrez le nombre de mots: ' ) ;
                   LIRE ( M ) ;
                   SI M > 10000
                       ECRIRE ( 'Erreur! Ce programme est limité à 10000 mots!' ) ;
                       Limite := VRAI ;
                      
                   SINON
                       Limite := FAUX ;
                      
                   FINSI ;
                  
               FINTANTQUE ;
              
           FINSI ;
           Racine := NIL ;
           APPEL Genererarbre ( Racine , Tab , M , L , K , Choix_mot ) ;
           Choix := 0 ;
           TANTQUE ( Choix <> 3 )
               ECRIRE ( '' ) ;
               ECRIRE ( '              MENU         ' ) ;
               ECRIRE ( '1- Verifier la compabilité de l"arbre' ) ;
               ECRIRE ( '2- Lancer une requete' ) ;
               ECRIRE ( '3- Quitter le programme' ) ;
               LIRE ( Choix ) ;
               SI ( Choix = 1 )
              {------------ comptabilitéArbre ---------------------}
                   ECRIRE ( ' Vérification de la compabilité de l"Arbre ' , K ) ;
                   APPEL Compabilitearbre ( ELEMENT ( Tab [ K ] ) ) ;
                  
               SINON
                   SI ( Choix = 2 )
                  {----------------------- Requetes -----------------}
                       Motjuste := VRAI ;
                       R := ELEMENT ( Tab [ K ] ) ;
                       Z := 1 ;
                       Stop := FAUX ;
                       TANTQUE ( NON Stop )
                           ECRIRE ( 'Entrez votre requete ' ) ;
                           LIRE ( Requete ) ;
                           Requete := Reglerchaine ( 0 , Requete , Stop ) ;
                          
                       FINTANTQUE ;
                       Requete := Inverser ( Requete ) ;
                       Requete := Equiv ( Requete ) ;
                       C := CARACT ( Requete , 1 ) ;
                       TANTQUE ( ( FD ( R ) <> NIL ) ET ( C <> ( STRUCT ( INFO ( R ) , 1 ) ) ) )
                           R := FD ( R ) ;
                          
                       FINTANTQUE ;
                       SI C = STRUCT ( INFO ( R ) , 1 )
                           CREERPILE ( P ) ;
                           Mot := '' ;
                           TANTQUE ( ( R <> NIL ) OU ( NON PILEVIDE ( P ) ) )
                               TANTQUE R <> NIL
                                   EMPILER ( P , R ) ;
                                   Mot := Mot + STRUCT ( INFO ( R ) , 1 ) ;
                                   R := FG ( R ) ;
                                  
                               FINTANTQUE ;
                               DEPILER ( P , R ) ;
                               SI ( STRUCT ( INFO ( R ) , 2 ) )
                                   Motjuste := Verif ( Mot , Requete ) ;
                                   SI ( Motjuste )
                                       AFF_ELEMENT ( Tabmots [ Z ] , Mot ) ;
                                       Z := Z + 1 ;
                                      
                                   FINSI ;
                                  
                               FINSI ;
                               Motprec := '' ;
                               POUR V := 1 , ( LONGCHAINE ( Mot ) - 1 )
                                   Motprec := Motprec + CARACT ( Mot , V ) ;
                                  
                               FINPOUR ;
                               Mot := Motprec ;
                               R := FD ( R ) ;
                              
                           FINTANTQUE ;
                          
                       FINSI ;
                       SI ( Z >= 2 )
                           ECRIRE ( ' Les mots trouvés sont : ' ) ;
                           POUR Y := 1 , Z - 1 , 1
                               ECRIRE ( ELEMENT ( Tabmots [ Y ] ) ) ;
                              
                           FINPOUR ;
                          
                       SINON
                           ECRIRE ( 'Aucun mot trouvé!' ) ;
                          
                       FINSI ;
                      
                   SINON
                       SI ( Choix = 3 )
                           ECRIRE ( '~Fin Du programme~' )
                       SINON
                           ECRIRE ( 'erreur!' ) ;
                          
                       FINSI ;
                      
                   FINSI ;
                  
               FINSI ;
              
           FINTANTQUE ;
          
       FINPOUR ;
      {Les racines de tous les arbres générés sont enregistrées dans le Tab}
      
   FIN
  { ------------------- Les Modules ------------------- }
   ACTION Genererarbre ( Racine , Tab , M , L , K , Choix_mot )
   SOIENT
       R , Perer , Prec , Racine : ARB DE ( CAR , BOOLEEN ) ;
       I , J , M , L , K , Choix_mot : ENTIER ;
       E : ( CAR , BOOLEEN ) ;
       Mot : CHAINE ;
       Error : BOOLEEN ;
       Tab : TABLEAU ( 10000 ) DE ARB DE ( CAR , BOOLEEN ) ;
      
   DEBUT
       R := Racine ;
       Perer := NIL ;
       Prec := NIL ;
       POUR I := 1 , M , 1
           R := Racine ;
           Perer := NIL ;
           Prec := NIL ;
           SI ( Choix_mot = 1 )
               Stop := FAUX ;
               TANTQUE ( NON Stop )
                   ECRIRE ( 'Entrez le mot ' ) ;
                   LIRE ( Mot ) ;
                   Mot := Reglerchaine ( 1 , Mot , Stop ) ;
                   SI ( LONGCHAINE ( Mot ) > L )
                       Stop := FAUX ;
                       ECRIRE ( 'erreur! le mot dépasse la longueur!' ) ;
                      
                   SINON
                       ECRIRE ( Mot ) ;
                      
                   FINSI ;
                  
               FINTANTQUE ;
              
           SINON
          {aleatoire}
               Mot := ALEACHAINE ( ALEANOMBRE ( L ) + 1 ) ;
               Mot := Reglerchaine ( 1 , Mot , Stop ) ;
              
           FINSI ;
          {---------------------generer mot-----------------------}
           POUR J := 1 , LONGCHAINE ( Mot )
               SI ( R = NIL )
                   AFF_STRUCT ( E , 1 , CARACT ( Mot , J ) ) ;
                   AFF_STRUCT ( E , 2 , FAUX ) ;
                   CREERNOEUD ( R ) ;
                   AFF_INFO ( R , E ) ;
                   SI ( Prec <> NIL )
                       AFF_FG ( Prec , R ) ;
                      
                   FINSI ;
                   SI ( Racine = NIL )
                  {cas arbre vide }
                       Racine := R ;
                      
                   FINSI ;
                  
               SINON
              {--- avancer à droite jusqu'a trouver caract(mot,j) ou la position pour l'inserer }
                   TANTQUE ( ( CARACT ( Mot , J ) > STRUCT ( INFO ( R ) , 1 ) ) ET ( FD ( R ) <> NIL ) )
                       Perer := R ;
                       R := FD ( R ) ;
                      
                   FINTANTQUE ;
                   SI ( STRUCT ( INFO ( R ) , 1 ) <> CARACT ( Mot , J ) )
                       SI ( CARACT ( Mot , J ) > STRUCT ( INFO ( R ) , 1 ) )
                      { regler le cas ou l'on insere à la fin }
                           Perer := R ;
                           R := FD ( R ) ;
                          
                       FINSI ;
                       AFF_STRUCT ( E , 1 , CARACT ( Mot , J ) ) ;
                       AFF_STRUCT ( E , 2 , FAUX ) ;
                       CREERNOEUD ( T ) ;
                       AFF_INFO ( T , E ) ;
                       AFF_FD ( T , R ) ;
                       SI R = Racine
                      { cas ou l'on change la racine }
                           Racine := T ;
                          
                       SINON
                           SI Perer = Prec
                          { cas ou le fg( pereR) doit etre changé }
                               AFF_FG ( Perer , T ) ;
                              
                           SINON
                               AFF_FD ( Perer , T ) ;
                              
                           FINSI ;
                          
                       FINSI ;
                       R := T ;
                      
                   FINSI ;
                  
               FINSI ;
               Prec := R ;
               Perer := R ;
               R := FG ( R ) ;
              
           FINPOUR ;
           AFF_STRUCT ( E , 1 , CARACT ( Mot , LONGCHAINE ( Mot ) ) ) ;
           AFF_STRUCT ( E , 2 , VRAI ) ;
           AFF_INFO ( Perer , E ) ;
          
       FINPOUR ;
       AFF_ELEMENT ( Tab [ K ] , Racine ) ;
      
   FIN
   ACTION Parcours ( Racine )
   SOIT
       Racine UN ARB DE ( CAR , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( ' Arbre ' , K ) ;
       A := Racine ;
       CREERPILE ( Q ) ;
       TANTQUE ( ( A <> NIL ) OU NON PILEVIDE ( Q ) )
           TANTQUE ( A <> NIL )
               EMPILER ( Q , A ) ;
               A := FG ( A ) ;
              
           FINTANTQUE ;
           DEPILER ( Q , A ) ;
           ECRIRE ( STRUCT ( INFO ( A ) , 1 ) ) ;
           A := FD ( A ) ;
          
       FINTANTQUE ;
      
   FIN
  {----------------------------------------------------}
   ACTION Compabilitearbre ( Racine )
   SOIT
       Racine , R : ARB DE ( CAR , BOOLEEN ) ;
       B : PILE DE ARB DE ( CAR , BOOLEEN ) ;
       Mot , Motprec : CHAINES ;
       Nombremot : ENTIER ;
      
   DEBUT
       CREERPILE ( B ) ;
       R := Racine ;
       Bool := PILEVIDE ( B ) ;
       Mot := '' ;
       Nombremot := 0 ;
       TANTQUE ( ( NON Bool ) OU ( R <> NIL ) )
           TANTQUE ( R <> NIL )
               Mot := Mot + STRUCT ( INFO ( R ) , 1 ) ;
               EMPILER ( B , R ) ;
               R := FG ( R ) ;
              
           FINTANTQUE ;
           DEPILER ( B , R ) ;
           SI ( STRUCT ( INFO ( R ) , 2 ) )
               ECRIRE ( Mot ) ;
               Nombremot := Nombremot + 1 ;
              
           FINSI ;
           Motprec := '' ;
           POUR V := 1 , ( LONGCHAINE ( Mot ) - 1 )
               Motprec := Motprec + CARACT ( Mot , V ) ;
              
           FINPOUR ;
           Mot := Motprec ;
           R := FD ( R ) ;
           Bool := PILEVIDE ( B ) ;
          
       FINTANTQUE ;
       SI ( Nombremot > 0 )
           ECRIRE ( 'Comptabilite verifiée!' ) ;
           ECRIRE ( '' ) ;
           ECRIRE ( '' ) ;
          
       FINSI ;
      
   FIN
  {----------------------------------------------------}
   FONCTION Verif ( Mot , Requete ) : BOOLEEN
   SOIENT
       Requete , Mot : CHAINE ;
       Bool : BOOLEEN ;
       I , J DES ENTIER ;
       Carreq DES CAR ;
      
   DEBUT
       Bool := FAUX ;
       I := 1 ;
       J := 1 ;
       Carreq := CARACT ( Requete , J ) ;
       SI ( ( Carreq <> '?' ) ET ( Carreq <> '*' ) )
           SI ( I <= LONGCHAINE ( Mot ) )
               SI ( Carreq = CARACT ( Mot , I ) )
                   SI ( ( I = LONGCHAINE ( Mot ) ) ET ( J = LONGCHAINE ( Requete ) ) )
                       Verif := VRAI ;
                      
                   SINON
                       SI ( ( I <= LONGCHAINE ( Mot ) ) ET ( J < LONGCHAINE ( Requete ) ) )
                           I := I + 1 ;
                           J := J + 1 ;
                           Verif := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                          
                       SINON
                           Verif := FAUX ;
                          
                       FINSI ;
                      
                   FINSI ;
                  
               SINON
                   Verif := FAUX ;
                  
               FINSI ;
              
           SINON
               Verif := FAUX ;
              
           FINSI ;
          
       SINON
           SI ( Carreq = '?' )
               SI ( ( I = LONGCHAINE ( Mot ) ) ET ( J = LONGCHAINE ( Requete ) ) )
                   Verif := VRAI ;
                  
               SINON
                   SI ( ( I <= LONGCHAINE ( Mot ) ) ET ( J < LONGCHAINE ( Requete ) ) )
                       SI ( I < LONGCHAINE ( Mot ) )
                           I := I + 1 ;
                           J := J + 1 ;
                           Verif := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                          
                       SINON
                           SI ( ( ( J + 1 ) = LONGCHAINE ( Requete ) ) ET ( CARACT ( Requete , J + 1 ) = '*' ) )
                               Verif := VRAI ;
                              
                           SINON
                               Verif := FAUX ;
                              
                           FINSI ;
                          
                       FINSI ;
                      
                   SINON
                       Verif := FAUX ;
                      
                   FINSI ;
                  
               FINSI ;
              
           SINON
          {cas * }
               SI ( J = LONGCHAINE ( Requete ) )
                   Verif := VRAI ;
                  
               SINON
                   SI ( I > LONGCHAINE ( Mot ) )
                       Verif := FAUX ;
                      
                   SINON
                       SI ( CARACT ( Mot , I ) = CARACT ( Requete , J + 1 ) )
                           J := J + 1 ;
                           TANTQUE ( ( CARACT ( Mot , I ) = CARACT ( Requete , J ) ) ET ( I < LONGCHAINE ( Mot ) ) ET
                           ( NON Bool ) )
                               Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                               I := I + 1 ;
                              
                           FINTANTQUE ;
                           SI ( NON Bool )
                               SI ( CARACT ( Mot , I ) = CARACT ( Requete , J ) )
                                   Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                                  
                               SINON
                                   I := I + 1 ;
                                   TANTQUE ( I < LONGCHAINE ( Mot ) )
                                       Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                                       I := I + 1 ;
                                      
                                   FINTANTQUE ;
                                   SI ( I = LONGCHAINE ( Mot ) )
                                       Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                                      
                                   SINON
                                       Bool := FAUX ;
                                      
                                   FINSI ;
                                  
                               FINSI ;
                              
                           FINSI ;
                          
                       SINON
                           I := I + 1 ;
                           TANTQUE ( ( I < LONGCHAINE ( Mot ) ) ET ( NON Bool ) )
                               Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                               I := I + 1 ;
                              
                           FINTANTQUE ;
                           SI ( NON Bool )
                               SI ( I = LONGCHAINE ( Mot ) )
                                   Bool := Verif ( Rest ( Mot , I ) , Rest ( Requete , J ) ) ;
                                  
                               SINON
                                   Bool := FAUX ;
                                  
                               FINSI ;
                              
                           FINSI ;
                          
                       FINSI ;
                       Verif := Bool ;
                      
                   FINSI ;
                  
               FINSI ;
              
           FINSI ;
          
       FINSI ;
      
   FIN
  {----------------------------------------------------}
   FONCTION Rest ( Mot , I ) : CHAINE
   SOIENT
       Mot , Nov_mot : CHAINE ;
       I , J : ENTIER ;
      
   DEBUT
       Nov_mot := '' ;
       POUR J := I , LONGCHAINE ( Mot ) , 1
           Nov_mot := Nov_mot + CARACT ( Mot , J ) ;
          
       FINPOUR ;
       Rest := Nov_mot ;
      
   FIN
  {----------------------------------------------------}
   FONCTION Reglerchaine ( Re_mo , Chaine_rm , Stop ) : CHAINE
   SOIENT
       Re_mo , I , J : ENTIER ;
       Chaine_rm , Nv_chaine DES CHAINE ;
       Stop : BOOLEEN ;
       Minuscule , Majuscule DES VECTEUR ( 26 ) DE CAR ;
       Car_rm : CAR ;
      
   DEBUT
       APPEL Init_min ( Minuscule ) ;
       APPEL Init_maj ( Majuscule ) ;
       Nv_chaine := '' ;
       SI ( Re_mo = 1 )
           POUR I := 1 , LONGCHAINE ( Chaine_rm ) , 1
               Car_rm := CARACT ( Chaine_rm , I ) ;
               POUR J := 1 , 26 , 1
                   SI ( Car_rm = ELEMENT ( Majuscule [ J ] ) )
                       Nv_chaine := Nv_chaine + ELEMENT ( Minuscule [ J ] ) ;
                      
                   SINON
                       SI ( Car_rm = ELEMENT ( Minuscule [ J ] ) )
                           Nv_chaine := Nv_chaine + ELEMENT ( Minuscule [ J ] ) ;
                          
                       FINSI ;
                      
                   FINSI ;
                  
               FINPOUR ;
              
           FINPOUR ;
          
       SINON
      {re_mo = 0}
           ECRIRE ( Chaine_rm ) ;
           POUR I := 1 , LONGCHAINE ( Chaine_rm ) , 1
               Car_rm := CARACT ( Chaine_rm , I ) ;
               POUR J := 1 , 26 , 1
                   SI ( Car_rm = ELEMENT ( Majuscule [ J ] ) )
                       Nv_chaine := Nv_chaine + ELEMENT ( Minuscule [ J ] ) ;
                      
                   SINON
                       SI ( Car_rm = ELEMENT ( Minuscule [ J ] ) )
                           Nv_chaine := Nv_chaine + ELEMENT ( Minuscule [ J ] ) ;
                          
                       FINSI ;
                      
                   FINSI ;
                  
               FINPOUR ;
               SI ( Car_rm = '*' )
                   Nv_chaine := Nv_chaine + '*' ;
                  
               SINON
                   SI ( Car_rm = '?' )
                       Nv_chaine := Nv_chaine + '?' ;
                      
                   FINSI ;
                  
               FINSI ;
              
           FINPOUR ;
          
       FINSI ;
       SI ( ( CARACT ( Chaine_rm , 1 ) = '?' ) OU ( CARACT ( Chaine_rm , 1 ) = '*' ) )
           Reglerchaine := ' ' ;
           ECRIRE ( ' erreur! veuillez introduire une valeur valide!' ) ;
           Stop := FAUX ;
          
       SINON
           SI ( LONGCHAINE ( Chaine_rm ) <> LONGCHAINE ( Nv_chaine ) )
               Reglerchaine := ' ' ;
               ECRIRE ( ' erreur! veuillez introduire une valeur valide!' ) ;
               Stop := FAUX ;
              
           SINON
               Reglerchaine := Nv_chaine ;
               Stop := VRAI ;
              
           FINSI ;
          
       FINSI ;
      
   FIN
  {----------------------------------------------------}
   ACTION Init_min ( Minuscule )
   SOIT
       Minuscule : VECTEUR ( 26 ) DE CAR ;
      
   DEBUT
       AFF_ELEMENT ( Minuscule [ 1 ] , 'a' ) ;
       AFF_ELEMENT ( Minuscule [ 2 ] , 'b' ) ;
       AFF_ELEMENT ( Minuscule [ 3 ] , 'c' ) ;
       AFF_ELEMENT ( Minuscule [ 4 ] , 'd' ) ;
       AFF_ELEMENT ( Minuscule [ 5 ] , 'e' ) ;
       AFF_ELEMENT ( Minuscule [ 6 ] , 'f' ) ;
       AFF_ELEMENT ( Minuscule [ 7 ] , 'g' ) ;
       AFF_ELEMENT ( Minuscule [ 8 ] , 'h' ) ;
       AFF_ELEMENT ( Minuscule [ 9 ] , 'i' ) ;
       AFF_ELEMENT ( Minuscule [ 10 ] , 'j' ) ;
       AFF_ELEMENT ( Minuscule [ 11 ] , 'k' ) ;
       AFF_ELEMENT ( Minuscule [ 12 ] , 'l' ) ;
       AFF_ELEMENT ( Minuscule [ 13 ] , 'm' ) ;
       AFF_ELEMENT ( Minuscule [ 14 ] , 'n' ) ;
       AFF_ELEMENT ( Minuscule [ 15 ] , 'o' ) ;
       AFF_ELEMENT ( Minuscule [ 16 ] , 'p' ) ;
       AFF_ELEMENT ( Minuscule [ 17 ] , 'q' ) ;
       AFF_ELEMENT ( Minuscule [ 18 ] , 'r' ) ;
       AFF_ELEMENT ( Minuscule [ 19 ] , 's' ) ;
       AFF_ELEMENT ( Minuscule [ 20 ] , 't' ) ;
       AFF_ELEMENT ( Minuscule [ 21 ] , 'u' ) ;
       AFF_ELEMENT ( Minuscule [ 22 ] , 'v' ) ;
       AFF_ELEMENT ( Minuscule [ 23 ] , 'w' ) ;
       AFF_ELEMENT ( Minuscule [ 24 ] , 'x' ) ;
       AFF_ELEMENT ( Minuscule [ 25 ] , 'y' ) ;
       AFF_ELEMENT ( Minuscule [ 26 ] , 'z' ) ;
      
   FIN
  {----------------------------------------------------}
   ACTION Init_maj ( Majuscule )
   SOIT
       Majuscule : VECTEUR ( 26 ) DE CAR ;
      
   DEBUT
       AFF_ELEMENT ( Majuscule [ 1 ] , 'A' ) ;
       AFF_ELEMENT ( Majuscule [ 2 ] , 'B' ) ;
       AFF_ELEMENT ( Majuscule [ 3 ] , 'C' ) ;
       AFF_ELEMENT ( Majuscule [ 4 ] , 'D' ) ;
       AFF_ELEMENT ( Majuscule [ 5 ] , 'E' ) ;
       AFF_ELEMENT ( Majuscule [ 6 ] , 'F' ) ;
       AFF_ELEMENT ( Majuscule [ 7 ] , 'G' ) ;
       AFF_ELEMENT ( Majuscule [ 8 ] , 'H' ) ;
       AFF_ELEMENT ( Majuscule [ 9 ] , 'I' ) ;
       AFF_ELEMENT ( Majuscule [ 10 ] , 'J' ) ;
       AFF_ELEMENT ( Majuscule [ 11 ] , 'K' ) ;
       AFF_ELEMENT ( Majuscule [ 12 ] , 'L' ) ;
       AFF_ELEMENT ( Majuscule [ 13 ] , 'M' ) ;
       AFF_ELEMENT ( Majuscule [ 14 ] , 'N' ) ;
       AFF_ELEMENT ( Majuscule [ 15 ] , 'O' ) ;
       AFF_ELEMENT ( Majuscule [ 16 ] , 'P' ) ;
       AFF_ELEMENT ( Majuscule [ 17 ] , 'Q' ) ;
       AFF_ELEMENT ( Majuscule [ 18 ] , 'R' ) ;
       AFF_ELEMENT ( Majuscule [ 19 ] , 'S' ) ;
       AFF_ELEMENT ( Majuscule [ 20 ] , 'T' ) ;
       AFF_ELEMENT ( Majuscule [ 21 ] , 'U' ) ;
       AFF_ELEMENT ( Majuscule [ 22 ] , 'V' ) ;
       AFF_ELEMENT ( Majuscule [ 23 ] , 'W' ) ;
       AFF_ELEMENT ( Majuscule [ 24 ] , 'X' ) ;
       AFF_ELEMENT ( Majuscule [ 25 ] , 'Y' ) ;
       AFF_ELEMENT ( Majuscule [ 26 ] , 'Z' ) ;
      
   FIN
  {----------------------------------------------------}
   FONCTION Equiv ( Requete ) : CHAINE
   SOIENT
       Requete , Nv_requete DES CHAINE ;
       J : ENTIER ;
       Car_req : CAR ;
      
   DEBUT
       J := 1 ;
       Nv_requete := '' ;
       TANTQUE ( J <= LONGCHAINE ( Requete ) )
           Car_req := CARACT ( Requete , J ) ;
           SI ( Car_req <> '*' )
               Nv_requete := Nv_requete + Car_req ;
               J := J + 1 ;
              
           SINON
               Nv_requete := Nv_requete + Car_req ;
              {j := j+1;}
               TANTQUE ( ( CARACT ( Requete , J ) = '*' ) ET ( J < LONGCHAINE ( Requete ) ) )
                   J := J + 1 ;
                  
               FINTANTQUE ;
               SI ( CARACT ( Requete , J ) = '*' )
                   J := J + 1 ;
                  
               FINSI ;
              
           FINSI ;
          
       FINTANTQUE ;
       Equiv := Nv_requete ;
      
   FIN
  {----------------------------------------------------}
   FONCTION Inverser ( Requete ) : CHAINE
   SOIENT
       Modif : BOOLEEN ;
       Requete , Mot , Novmot : CHAINE ;
       I , J : ENTIER ;
      
   DEBUT
       Mot := Requete ;
       Modif := VRAI ;
       TANTQUE ( Modif )
           Modif := FAUX ;
           I := 1 ;
           TANTQUE ( I < ( LONGCHAINE ( Mot ) ) )
               SI ( ( ( CARACT ( Mot , I ) ) = '*' ) ET ( ( CARACT ( Mot , I + 1 ) ) = '?' ) )
                   Novmot := '' ;
                   POUR J := 1 , I - 1 , 1
                       Novmot := Novmot + CARACT ( Mot , J ) ;
                      
                   FINPOUR ;
                   Novmot := Novmot + '?' ;
                   Novmot := Novmot + '*' ;
                   Modif := VRAI ;
                   POUR J := I + 2 , LONGCHAINE ( Mot ) , 1
                       Novmot := Novmot + CARACT ( Mot , J ) ;
                      
                   FINPOUR ;
                  
               FINSI ;
               I := I + 1 ;
              
           FINTANTQUE ;
           SI ( Modif )
               Mot := Novmot ;
              
           FINSI ;
          
       FINTANTQUE ;
       Inverser := Mot ;
      
   FIN
  {----------------------------------------------------}
   ACTION Intro DEBUT
       ECRIRE ( '  ***************************************************************** ' ) ;
       ECRIRE ( '  *                                                                                    * ' ) ;
       ECRIRE ( '  *                         TP ALSDD 2                                      * ' ) ;
       ECRIRE ( '  *                                                                                    * ' ) ;
       ECRIRE ( '  *                 Requêtes sur un dictionnaire                     * ' ) ;
       ECRIRE ( '  *                                                                                   * ' ) ;
       ECRIRE ( '  *                 Réalisé Par:                                               * ' ) ;
       ECRIRE ( '  *     Slimani Wassila Maria    &&    Abchiche Sarah       * ' ) ;
       ECRIRE ( '  *                                                                                    * ' ) ;
       ECRIRE ( '  *                          2018-2019                                         * ' ) ;
       ECRIRE ( '  *                                                                                    * ' ) ;
       ECRIRE ( '  ***************************************************************** ' ) ;
      
   FIN
  {----------------------------------------------------}
   ACTION Alea_saisie ( Choix_mot )
   SOIENT
       Eror : BOOLEEN ;
       Choix_mot : ENTIER ;
      
   DEBUT
       Eror := VRAI ;
       TANTQUE ( Eror )
           ECRIRE ( '' ) ;
           ECRIRE ( 'Veuillez Choisir: ' ) ;
           ECRIRE ( '1- Saisie des mots' ) ;
           ECRIRE ( '2- Mots Aleatoires' ) ;
           ECRIRE ( '' ) ;
           LIRE ( Choix_mot ) ;
           SI ( ( Choix_mot <> 1 ) ET ( Choix_mot <> 2 ) )
               Eror := VRAI
           SINON
               Eror := FAUX ;
              
           FINSI ;
          
       FINTANTQUE ;
      
   FIN
  {----------------------------------------------------} 
