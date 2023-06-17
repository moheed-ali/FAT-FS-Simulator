#include <stdio.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 512
#define FREE NUM_BLOCKS 
#define ALLOCATED 1
#define END -1
#define NUM_DENTRY 5
#define STR_LEN  256


typedef struct  {
    char data[1024];
} data_block;


//initilize block
void init_block();

//clear entry
void clear_block(int i);
//return block at i
data_block *get_data_block(int i);

//check block
int check_block(int i);


//write block
void write_block(int index, char *name);


//print single block
void print_block(int i);

//read block
char* read_block(int index);

typedef struct  {
    char name[STR_LEN];
    int block_address;
} str_t;

//initilize dentry
void init_dentry();

//clear entry
void clear_dentry(int i);

//return dentry at i
str_t *get_dentry(int i);

//check dentry
int check_dentry(int i);


//write dentry
void write_dentry(int index, int block, char *name);

//write first free dentry
int write_first_free_dentry(int block, char *name);

//print single dentry
void print_dentry(int i);

//print dentry
void display_dentry();

//get dentry block number
int get_dentry_block(char *name);

//get dentry index
int get_dentry_index(char *name);

// FAT
//get fat
int *get_fat();

//delete fat 
void delete_fat(int i);


//initilize a fat
void init_fat();

//get fat value
int get_fat_value(int a);

//print fat table of a file
void print_fat_table(int start);

//last block
int last_block(int i);


//first free block 
int first_free_block();

//add next block
void add_next_block(int blocks, int i);



//File_Operations

//read file
FILE* open_file(const char *fname, const char *mode);

//get file size
long get_file_size(const char *fname);

//get req blocks
int get_req_blocks(int fsize);

//init_file

// Initializes the file with the block table, directory entry, and section organized in blocks
void init_file(const char* file_name);

// Writes the block table to the file
void write_block_table(const char* file_name) ;

//Read Fat Table 
void read_block_table(const char* file_name) ;


// Writes the directory entry to the file
void write_dir_entry(const char* file_name, const str_t* dentry) ;

// Reads the directory entry from the file
void read_dir_entry(const char* file_name, str_t* dentry) ;



