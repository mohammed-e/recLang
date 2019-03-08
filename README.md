# recLang
Auteur :<br />
Mohammed EL KHAIRA<br />
2016<br />
<br />

Ce programme de reconnaissance de langue vous permet d'identifier la langue dans laquelle est écrit le texte de votre choix.<br /><br />
Liste des langues reconnues par défaut:<br />
∞	allemand<br />
∞	anglais<br />
∞	arabe<br />
∞	catalan<br />
∞	chinois<br />
∞	chinois classique<br />
∞	coréen<br />
∞	espagnol<br />
∞	français<br />
∞	italien<br />
∞	japonais<br />
∞	néerlandais<br />
∞	ourdou<br />
∞	portugais<br />
∞	russe<br />
∞	ukrainien<br />
<br />
Si vous souhaitez pouvoir reconnaître des langues supplémentaires, il suffit de suivre l'étape 8.<br /><br />
<br />

Mode d'emploi<br />
<br />
1.	Placez le répertoire racine (ici recLang) sur votre Bureau<br />

2.	Ouvrez le répertoire puis le répertoire test<br />

3.	Créez un fichier texte et nommez-le inconnu.txt (si un fichier avec le même nom existe déjà, contentez-vous d'effacer son contenu)<br />

4.	Remplissez ce fichier avec le texte dont vous aimeriez connaître la langue<br />

5.	Ouvrez maintenant un terminal et entrez la ligne de commande suivante : cd ~/Bureau/recLang/src<br />

6.	Pour compiler et préparer le programme entrez la ligne de commande suivante : make ; make clean ; make stats<br />

7.	Enfin, pour afficher dans le terminal la langue de votre fichier inconnu.txt, entrez la ligne de commande suivante : make recon<br />

8.	Langues supplémentaires :<br />

∞	Ouvrez le répertoire recLang puis le répertoire data<br />

∞	Créez un fichier texte et nommez-le nouvelle_langue.txt (remplacez nouvelle_langue par la langue choisie)<br />

∞	Remplissez ce fichier avec une dizaine de lignes de texte écrites dans la nouvelle langue que vous avez choisie<br />

∞	Ouvrez ensuite le répertoire src puis le fichier Makefile<br />

∞	Remplacer la ligne 5 (FREQ=…) par la ligne suivante : <br />
FREQ=../data/allemand.txt allemand ../data/anglais.txt anglais ../data/arabe.txt arabe ../data/chinois.txt chinois ../data/coréen.txt coréen ../data/espagnol.txt espagnol ../data/francais.txt français ../data/italien.txt italien ../data/japonais.txt japonais ../data/néerlandais.txt néerlandais ../data/portugais.txt portugais ../data/russe.txt russe ../data/catalan.txt catalan ../data/chinoisClassique.txt chinois_classique ../data/ourdou.txt ourdou ../data/ukrainien.txt ukrainien ../data/nouvelle_langue.txt nouvelle_langue<br />
<br />
Le reconnaisseur de langue peut maintenant reconnaître la nouvelle langue que vous avez choisie. Vous pouvez reprendre les étapes 2 à 7.<br /><br />
<br />

Notes sur la fiabilité des résultats :<br />
<br />
La fiabilité de réponse du reconnaisseur de langues dépend de la taille  de votre texte inconnu.<br />
En effet, plus votre texte dont la langue est inconnue est long, plus le reconnaisseur de langues est fiable.<br />
Voici une échelle (approximative) de fiabilité :<br />
∞	+ 10 lignes :  100 %<br />
∞	5-10 lignes : 99 %<br />
∞	3-5 lignes : 95 %<br />
∞	- 3 lignes : le résultat n'est pas fiable !<br />
<br />
De la même manière, lorsque vous ajoutez une nouvelle langue dans le répertoire data, veuillez remplir votre nouveau fichier texte avec au moins 10 lignes (plus il y en aura et mieux ce sera !).
