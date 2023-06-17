#include <stdio.h>
#include <string.h>

#include "oscafs.h"


//declare dentry
str_t dentry[NUM_DENTRY];

//initilize dentry
void init_dentry(){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		clear_dentry(i);	
	}
}

//clear entry
void clear_dentry(int i){
	dentry[i].name[0]= '\0';
	dentry[i].block_address = 0;
	
}

//return dentry at i
str_t *get_dentry(int i){
	return &dentry[i]; 
}

//check dentry
int check_dentry(int i){
	return dentry[i].block_address == 0;
}


//write dentry
void write_dentry(int index, int block, char *name){
	strcpy(dentry[index].name, name);
	dentry[index].block_address = block;	
}



//write first free dentry
int write_first_free_dentry(int block, char *name){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		if(check_dentry(i)){
			write_dentry(i, block, name);
		 	return i;
		 	break;
		}
	} 
}

//print single dentry
void print_dentry(int i){
	printf("[%d] The Name of the File is : %s\n", i, dentry[i].name);
	printf("[%d] The First Block of the File is : %d\n", i, dentry[i].block_address);	
}

//get dentry block number
int get_dentry_block(char *name){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		if(strcmp(dentry[i].name, name) == 0){
			return dentry[i].block_address; 
		}
	}
}

//get dentry block number
int get_dentry_index(char *name){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		if(strcmp(dentry[i].name, name) == 0){
			return i; 
			break;
		}
	}
	return -1;
}

//print dentry
void display_dentry(){
	for(int i=0 ; i<NUM_DENTRY ; i++){
		if(!check_dentry(i)){
			print_dentry(i);
		}		
	}
}


