#include "recLang.h"

int main(int argc, char *argv[])
{

  /**********************/
  /* Mode Apprentissage */
  /**********************/

	if(argc > 2){
		int nbLang = (argc-1)/2;
		data lettres[MAXLANG] = {{0}, {0.0}};

    /** ETAPE 1 : Récolter les stats depuis les fichiers de référence **/
		recolteStats(lettres, nbLang, argv);
    /** ETAPE 2 : Ecrire les stats dans le fichier stats.txt **/
		ecritureStats(lettres, nbLang, argv);
	}

  /***********************/
  /* Mode Reconnaissance */
  /***********************/

	else{
		int nbLang = 1;
		data lettres[MAXLANG] = {{0}, {0.0}};
		stats texte[MAXLANG] = {{0.0}, {0}};

    /** ETAPE 1 : Récolter les stats du fichier inconnu **/
		recolteStats(lettres, nbLang, argv);
    /** ETAPE 2 : Transférer les fréquences du fichier stats.txt dans un tableau **/
		lectureStats(texte, &nbLang);
    /** ETAPE 3 : Conclure en comparant la somme des différences entre fréquences pour chaque char **/
		printf("\nLe fichier proposé est écrit en %s\n", recon(lettres, texte, nbLang));
	}
	
	return EXIT_SUCCESS;
}