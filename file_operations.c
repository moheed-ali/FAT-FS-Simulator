#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "oscafs.h"

//read file
FILE* open_file(const char *fname, const char *mode) {
	  FILE *f = fopen(fname, mode);
	  if (f == NULL) {
	    fprintf(stderr, "Error: Unable to open file '%s'.\n", fname);
	  }
	  return f;
}

//get file size
long get_file_size(const char *fname) {
	  // Open the file in read-only mode
	  FILE *f = fopen(fname, "r");
	  if (f == NULL) {
	    fprintf(stderr, "Error: Unable to open file '%s'.\n", fname);
	    return -1;
	  }

	  // Seek to the end of the file
	  fseek(f, 0, SEEK_END);

	  // Get the current position (i.e. the size of the file)
	  long size = ftell(f);

	  // Close the file
	  fclose(f);

	  return size;
}

//get req blocks
int get_req_blocks(int fsize){
	printf("\nSize of the File : %d bytes", fsize);
	printf("\nRequired Blocks : %d", fsize/BLOCK_SIZE);
	return fsize/BLOCK_SIZE;
	
}
