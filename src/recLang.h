#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLANG 100
#define MAXLENGTH 50



/* Structure stockant le nombre d'apparition, dans un texte, de chaque caractère ASCII + le nombre de caractères total 
Utilisée pour la récolte de données en vue de faire des stats */

typedef struct data{
	int nbApparition[256];
	double nbTotal;
}data;


/* Structure stockant la fréquence, dans un texte, de chaque caractères ASCII + la langue de ce texte 
Utilisée pour la lecture/écriture d'un fichier de stats */
typedef struct stats{
	double freq[256];
	char lang[MAXLENGTH];
}stats;




void openCheck(FILE *fichier){
	if(fichier == NULL)
	{
		printf("Il y a un problème dans l'ouverture du fichier !\n");
		exit(EXIT_FAILURE);
	}
}



void recolteStats(data *lettres, int nbLang, char **argv){
	FILE *fichiers = NULL; 
	int i = 0, j = 1;
	unsigned char c = 0; 

	for(i = 0; i < nbLang; i++)
	{
		fichiers = fopen(argv[j],"r");
		openCheck(fichiers);
		j = j + 2;
		while ((unsigned char)(c = fgetc(fichiers)))
		{
			if( (!(c >= 0 && c <= 64)) && (!(c >= 91 && c <= 96)) && (!(c >= 123 && c <= 127)) && (c != 255) )
			{
				lettres[i].nbApparition[c] = lettres[i].nbApparition[c] + 1;
				lettres[i].nbTotal = lettres[i].nbTotal + 1;
			}
			if(feof(fichiers))
				break;
		}
		fclose(fichiers);
	}
}



void ecritureStats(data *lettres, int nbLang, char **argv){
	FILE *freq = NULL;
	int i = 0, j = 0, k = 2;

	freq = fopen("stats.txt", "w");
	fprintf(freq, "%d\n", nbLang);
	for(i = 0; i < nbLang; i++)
	{
		fprintf(freq, "\n%s\n", argv[k]);
		k = k+2;
		for(j = 0; j < 256; j++)
			fprintf(freq, "%lf\n", (lettres[i].nbApparition[j]/lettres[i].nbTotal)*100);
	}
	fclose(freq);
}



void lectureStats(stats *texte, int *nbLang){
	FILE *fichiers = NULL;
	int i = 0, j = 0;
	char chaine[MAXLENGTH] = "";

	fichiers = fopen("stats.txt","r");
	openCheck(fichiers);

	fscanf(fichiers, "%d", nbLang);

	while (fgets(chaine, MAXLENGTH, fichiers) != NULL)
	{
		if(*chaine != '\n'){
			if((*chaine >= 'A' && *chaine <= 'Z') || (*chaine >= 'a' && *chaine <= 'z')){
				strcpy(texte[i].lang, chaine);
				i++;
			}
			else{
				if(j == 256) j = 0;
				texte[i-1].freq[j] = strtod(chaine, NULL);
				j++;
			}
		}
	}
}


/* Renvoie l'indice de la plus petite valeur du tableau passé en paramètre */
int indiceMin(double *tab, int taille){
	int i = 0, indice = 0;
	double min = tab[0]; 

	for(i = 0; i < taille; i++){
		if(tab[i] < min){
			min = tab[i];
			indice = i;
		}
	}
	return indice;
}


/* La langue choisie est celle minimisant les différences de fréquences d'apparition des caractères */
char* recon(data *lettres, stats *texte, int nbLang){
	double sommeDiff[MAXLANG] = {0.0};
	int i = 0, j = 0, indiceLang = 0;

	for(i = 0; i < nbLang; i++)
	{
		for(j = 0; j < 256; j++)
			sommeDiff[i] = sommeDiff[i] + fabs((lettres[0].nbApparition[j]/lettres[0].nbTotal)*100 - texte[i].freq[j]);
	}
	indiceLang = indiceMin(sommeDiff, nbLang);

	return texte[indiceLang].lang;
}