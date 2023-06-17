#include <stdio.h>
#include <string.h>

#include "oscafs.h"


//declare block
data_block d_block[NUM_BLOCKS];

//initilize block
void init_block(){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		clear_block(i);	
	}
}

//clear entry
void clear_block(int i){
	d_block[i].data[0]= '\0';
}

//return block at i
data_block *get_data_block(int i){
	return &d_block[i]; 
}

//check block
int check_block(int i){
	return d_block[i].data[0] == '\0';
}


//write block
void write_block(int index, char *name){
	strncpy(d_block[index].data, name, BLOCK_SIZE);
	d_block[index].data[BLOCK_SIZE-1] = '\0';
	printf("\n Lenght is : %d", BLOCK_SIZE);
	printf("\n data is : %s", d_block[index].data);
}

//read block
char* read_block(int index){
	return d_block[index].data;
}

//print single block
void print_block(int i){
	printf("\nData : %s\n", d_block[i].data);
}





