*****README TP4-PANCARTE Kenny******

Pour construire les différents programmes tapez "make" dans un terminal ouvert à l'endroit où sont les fichiers source.

Voici les differentes commandes en console permises grâce au Makefile:

 make : compile et crée tous les programmes
 make clean : supprime tous les fichiers temporaires
 make mrproper : execute clean et supprime les fichier .a, .o et les programmes crées.



Voici la liste des programmes crées et leur mode d'emploi:



colimacon : ./colimacon (unsigned int lignes) (unsigned int colonnes) 
	    Construit un tableau à deux dimensions en le remplissant en spirale puis ensuite l'affiche.



testColimacon : ./testColimacon 
		Teste la fonction colimacon sur des tableaux de dimension 10^i avec i€[0,5] en renvoyant le temps d'exécution pour chaque construction de tableau avec la commande clok().



exemplesColimacon : ./exemplesColimacon 
		    Teste les résultat de colimacon sur quelques exemples en les comparant à des résultats attendus.



palindrome : ./palindrome (char* chaîne_de_caractères)
	     Regarde si chaîne_de_caractères est un palindrome ou non.



exemplesPalindrome : ./exemplesPalindrome 
		     Teste les résultats de palindrome sur quelques exemples en les comparant à des résultats attendus.



annexe : ./annexe
	 Teste les résultats de check_moves_in_array sur quelques exemples en les comparant à des résultats attendus.



