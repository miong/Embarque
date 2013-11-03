#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

int main(int argc, char *argv[])
{
	if(argc<2){
                        printf("Vous n'avez pas entre de chaîne de caractères\n");
                        return 0;

        }

	
	if(palindrome(argv[1])){
		printf("C'est un palindrome\n");
		return 1;	
	}

	printf("Ce n'est pas un palindrome\n");
	return 0;
}
