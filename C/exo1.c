 #include <stdio.h> /* bibliothèque d'entrées-sorties standard */
#include <conio.h>
main() {
  
   
 	      printf ("Taille d'un entier:%d\n", sizeof(int));
          printf ("Taille d'un caractère:%d\n", sizeof(char));	
          printf ("Taille d'un entier Long:%d\n" , sizeof(long));	
          printf ("Taille d'un réel:%d\n", sizeof(float));	
          printf ("Taille d'un double:%d\n", sizeof(double));
          puts ("Pour sortir  tapez une touche...");
          getch() ; /* Attente d'une saisie clavier */
}


