#include <stdio.h>
#include <stdlib.h>
#include "annexe.h"
int main(int argc, char *argv[]){
	int array[21]={1,5,1,4,5,5,8,7,9,4,2,5,4,7,9,6,5,4,1,4,8};
		
	if(check_moves_in_array(array,21)==-1){
		printf("test réussi\n");
	 }else{
		printf("test raté\n");
	}	
	int array2[21]={1,1,2,58,5,5,8,7,9,4,2,5,4,7,9,6,5,4,1,4,8};
	if(check_moves_in_array(array2,21)==3){
		printf("test réussi\n");
	}else{
		printf("test raté\n");
	}
	int array3[1]={20};
	if(check_moves_in_array(array3,1)==0){
		printf("test réussi\n");
	 }else{
		printf("test raté\n");
	}
	int array4[2]={1,0};
	if(check_moves_in_array(array4,2)==-1){
		printf("test réussi\n");
	 }else{
		printf("test raté\n");
	}
	int array5[3]={1,1,25};
	if(check_moves_in_array(array5,3)==2){
		printf("test réussi\n");
	 }else{
		printf("test raté\n");
	}
}
