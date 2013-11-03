#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

int main(int argc, char *argv[]){

	printf("Test de validation du bon fonctionnement de palindrome sur quelques exemples\n");
	
	
	printf("test sur ''\n ");
	if(palindrome("")==1){
		printf("Réussi\n");
	}else{
		printf("Raté\n");
		
	}


	printf("test sur '5'\n ");
	if(palindrome("5")==1){
		printf("Réussi\n");
	}else{
		printf("Raté\n");
		
	}

	printf("test sur 'palindrome'\n ");
	if(palindrome("palindrome")==1){
		printf("Raté\n");
	}else{
		printf("Réussi\n");
		
	}

	printf("test sur 'palindromemordnilap'\n ");
	if(palindrome("palindromemordnilap")==1){
		printf("Réussi\n");
	}else{
		printf("Raté\n");
		
	}
	

			
	return 1;
}
