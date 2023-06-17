#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "oscafs.h"


// Initializes the file with the block table, directory entry, and section organized in blocks
void init_file(const char* file_name) {
  FILE* file = fopen(file_name, "wb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
   

  fclose(file);
}

// Writes the block table to the file
void write_block_table(const char* file_name) {
  FILE* file = fopen(file_name, "r+b");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  fwrite(get_fat(), sizeof(int), NUM_BLOCKS, file);
  fclose(file);
  
}

//Read Fat Table 
void read_block_table(const char* file_name) {
  FILE* file = fopen(file_name, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  fread(get_fat(), sizeof(int), NUM_BLOCKS, file);
  fclose(file);
}



// Writes the directory entry to the file
void write_dir_entry(const char* file_name, const str_t* dentry) {
  FILE* file = fopen(file_name, "r+b");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  fseek(file, NUM_BLOCKS * sizeof(int), SEEK_SET); // seek to the location of the directory entry
  
  fwrite(dentry, sizeof(str_t), 1, file);
  fclose(file);
}

// Reads the directory entry from the file
void read_dir_entry(const char* file_name, str_t* dentry) {
  FILE* file = fopen(file_name, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }

  fseek(file, NUM_BLOCKS * sizeof(int), SEEK_SET); // seek to the location of the directory entry
  
  fread(dentry, sizeof(str_t), 1, file);
  printf("\nRead Starting Block of file : %d", dentry->block_address);
	printf("\nRead Name of the file : %s", dentry->name);
	printf("\n");
  fclose(file);
}















