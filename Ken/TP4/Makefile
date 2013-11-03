all: colimacon testColimacon exemplesColimacon palindrome exemplesPalindrome annexe


colimacon: main.c colimacon.a
	gcc -o colimacon main.c colimacon.a

testColimacon: testPhase.c test.a
	gcc -o testColimacon testPhase.c test.a -lm

exemplesColimacon: testAvecExemples.c colimacon.a
	gcc -o exemplesColimacon testAvecExemples.c colimacon.a 

palindrome: mainPalindrome.c palindrome.a
	gcc -o palindrome mainPalindrome.c palindrome.a 
	
exemplesPalindrome: exemplesPalindrome.c palindrome.a
	gcc -o exemplesPalindrome exemplesPalindrome.c palindrome.a

annexe: exemplesAnnexe.c annexe.a
	gcc -o annexe exemplesAnnexe.c annexe.a

annexe.a: annexe.o annexe.h
	ar -q annexe.a annexe.o

colimacon.a : colimacon.o colimacon.h 
	ar -q colimacon.a colimacon.o

colimacon.o:colimacon.c
	gcc -c colimacon.c

test.a : colimacon.o test.o colimacon.h test.h
	ar -q test.a colimacon.o test.o


palindrome.a: palindrome.o palindrome.h
	ar -q palindrome.a palindrome.o
 
clean:
	
	rm -rf *~


mrproper: clean
	rm -rf *.a *.o
	rm -rf colimacon
	rm -rf testColimacon
	rm -rf exemplesColimacon
	rm -rf palindrome
	rm -rf exemplesPalindrome
	rm -rf annexe
