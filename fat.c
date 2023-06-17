#include <stdio.h>
#include <stdlib.h>

#include "oscafs.h"

//declare fat
int fat[NUM_BLOCKS];

//get fat
int *get_fat(){
	return fat;
}

//initilize a fat
void init_fat(){
	for(int i=1 ; i<NUM_BLOCKS ; i++){
		fat[i] = FREE;
	}
}

//print fat table of a file
void print_fat_table(int start){
	while(start != -1){
		printf("Fat[ %d ] : %d\n", start, fat[start]);
		start = get_fat_value(start);
	}
}

//get fat value
int get_fat_value(int a){
	return fat[a];
}

//last block
int last_block(int i){
	return fat[i] == END;
}


//first free block 
int first_free_block(){
	for(int i=1 ; i<NUM_BLOCKS ; i++){
		if(fat[i] == FREE){
			fat[i] = END;
			return i;
		}
	}
}

//add next block
void add_next_block(int blocks, int i){
	while(blocks!=1){
		fat[i] = first_free_block();
		i = fat[i];
		blocks--;
	}
}

//delete fat
void delete_fat(int i){
	int next;
	while(i != -1){
		next = fat[i];
		fat[i] = FREE;
		i = next;
	} 
}




