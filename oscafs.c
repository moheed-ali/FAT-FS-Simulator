#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "oscafs.h"


int main(){
	printf("Welcome to Fat File System\n");
	init_dentry();
	init_fat();
	init_block();
	int choice;
	
	start:
	printf("Menu:\n");
    	printf("1. Create a file\n");
    	printf("2. List files\n");
    	printf("3. Delete a file\n");
    	printf("4. Display Fat table of a file\n");
    	printf("5. Copy File From Host PC TO FAT File System\n");
    	printf("6. Copy File From FAT File System to Host PC\n");
    	printf("7. Quit\n");
    	printf("Enter your choice: ");
    	choice = getchar();  // Read in the user's choice
    	
    	switch(choice) {
        	case '1':
        		 printf("Create a File\n");
        		 
        		 char file_name[100]; // array to store file name
		  	 printf("Enter a file name from host system: ");
		  	 scanf("%s", file_name); // get file name from user
		  	 
		  	 write_first_free_dentry(first_free_block(), file_name);
		  	 
		  	 int size; // Enter size in bytes
		  	 printf("Enter the size of File %s : ", file_name);
		  	 scanf("%d", &size); // get file name from user
		  	 int block_req = get_req_blocks(size);
		  	 
		  	 printf("\nStarting Block is : %d\n", get_dentry_block(file_name));
			 if(block_req > 0){
			 	add_next_block(block_req, get_dentry_block(file_name));
			 }
			 	
		  	 
		  	 printf("File created Successfully\n\n");
        		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start;
            		
        	case '2':
            		printf("List Files\n");
            		 
            		 display_dentry();
            		 printf("File Listed Successfully\n\n");
        		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start;
        	case '3':
            		 printf("Delete a File\n");
            		 
            		 display_dentry();
            		 
            		 char del_name[100]; 
            		 printf("Enter name of the file : ");
            		 scanf("%s", del_name); 
            		 
            		 if(get_dentry_index(del_name) != -1){
            		 	delete_fat(get_dentry_block(del_name));
            		 	clear_dentry(get_dentry_index(del_name));	
            		 	printf("File Deleted Successfully\n\n");
            		 }
            		 else {
            		 	printf("File Not Found\n\n");
            		 }
            		 
        		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start;
        	case '4':
            		printf("Display Fat Table of File\n");
            		char l_name[100]; 
            		 printf("Enter name of the file : ");
            		 scanf("%s", l_name);
            		 printf("Value : %d ", get_dentry_index(l_name));
            		 if(get_dentry_index(l_name) != -1){
            		 	print_fat_table(get_dentry_block(l_name));
            		 	printf("Fat Displayed Successfully\n\n");
            		 }
            		 else {
            		 	printf("File Not Found\n\n");
            		 }
            		 
            		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start; 
            		break;
            	case '5':
            		printf("Copy File From Host PC TO FAT File System\n");
            		char h_name[100]; 
            		 printf("Enter name of the file From Host PC : ");
            		 scanf("%s", l_name);
            		 
            		FILE *fh;
		    	char buffer[1024];
    			size_t bytesRead;

			fh = fopen(l_name, "r+");
		    	if (fh == NULL) {
				printf("Error opening file\n");
				break;
		    	}
		    	else{
		    		write_first_free_dentry(first_free_block(), l_name);
            		 	int Blocks_req = get_req_blocks((int) get_file_size(l_name));
            		 	printf("\nStarting Block is : %d\n", get_dentry_block(l_name));
			 	if(Blocks_req > 0){
				 	add_next_block(Blocks_req , get_dentry_block(l_name));
				 }
			 	printf("Value : %d, %d\n", Blocks_req , get_dentry_block(l_name)); 
			 	
			 	
			 	int x = get_dentry_block(l_name); 
			 	while ((bytesRead = fread(buffer, 1, sizeof(buffer), fh)) > 0) {
				 	printf("Data read: %s", buffer);
				 	write_block(x, buffer);
				 	x = get_fat_value(x);
				 	printf("----------------------------Read Sucessful-------------------\n");
				 	if(x == -1){
				 		break;
				 	}
				 	
				 }
				 
		    		 
			}    
	
			    	/*write_first_free_dentry(first_free_block(), l_name);
            		 	int blocks_req = get_req_blocks((int) get_file_size(l_name));
            		 	printf("\nStarting Block is : %d\n", get_dentry_block(l_name));
			 	if(block_req > 0){
				 	add_next_block(blocks_req, get_dentry_block(l_name));
				 }
			 	printf("Value : %d, %d\n", blocks_req, get_dentry_block(l_name));
		    		
		    		if(blocks_req > 0){
				 	add_next_block(blocks_req, get_dentry_block(l_name));
				 	int x = get_dentry_block(l_name); 
					for(int i=1 ; i<=blocks_req ; i++){
						// Read first 1024 bytes of data
					    	fread(buffer, 1, 1026, fh);
					    	printf("Data read: %s\n", buffer);

					    	// Create offset of 1024 bytes
					    	fseek(fh, 1026, SEEK_CUR-2);
						
						write_block(x, buffer);    	
					    	
						
						x = get_fat_value(x);
						printf("----------------------------Read Sucessful-------------------\n");
					}
				 }
		    		else{	
		    			fread(buffer, 1, 1026, fh);
		    		}	write_block(get_dentry_block(l_name), buffer);
		    		
		    		
		    	
		    	}*/
		    	fclose(fh);
		    	
            		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start; 
            		break;	
            	case '6':
            		 printf("Copy File From FAT File System to Host PC\n");
            		 display_dentry();
            		 
            		 char g_name[100]; 
            		 printf("Enter name of the file from FAT: ");
            		 scanf("%s", g_name); 
            		 
            		 if(get_dentry_index(g_name) != -1){
		    		char k_name[100]; 
		    		 printf("Enter name of the file From Host PC : ");
		    		 scanf("%s", k_name);
		    		 FILE *fk;
		    		char buffer[1024];
            		 	fk = fopen(k_name, "w+");
			    	if (fk == NULL) {
					printf("Error opening file\n");
					break;
			    	}
			    	else{
			    		
			    		int x = get_dentry_block(g_name);
			    		printf("Value : %d, %d\n", x, get_dentry_block(g_name));
			    		while (x != -1){
			    			strncpy(buffer, read_block(x), BLOCK_SIZE);
						buffer[BLOCK_SIZE-1] = '\0';
						//fwrite(buffer, 1, sizeof(buffer), fk);
						fputs(buffer, fk);
						fseek(fk, 0, SEEK_END);
			    			/*strcpy(buffer, read_block(x)); 
							// Read first 1024 bytes of data
						    	fwrite(buffer, 1, 1026, fk);
						    	printf("Data Write: %s\n", buffer);
						    	// Create offset of 1024 bytes
						    	fseek(fk, 1026, SEEK_CUR-2);    	*/	
						    	printf("Data read: %s", buffer);				
							x = get_fat_value(x);
							printf("----------------------------Write Sucessful-------------------\n");
			    		} 
			    		
			    		printf("File Copied Successfully\n\n");
			    	}
			    	fclose(fk);	
            		 	
            		 	
            		 }
            		 else {
            		 	printf("File Not Found\n\n");
            		 }
            		
            		
		    	
            		 printf("Press Enter Twice to exit\n");
   			 getchar();getchar();getchar();
   			 system("clear");
        		 goto start; 
            		break;	
            		
            	case '7':
            		printf("Quit\n");

   			 system("clear");
        		 //goto start; 
            		break;		
            		
        	default:
            		 printf("Invalid choice.\n");
   			 system("clear");
        		 goto start;
            		
    	}	
    	
	
	/*
	
	write_first_free_dentry(first_free_block(), "text.txt");
	write_first_free_dentry(first_free_block(), "Thefie");
	display_dentry();
	int size = 5090;
	int block_req = get_req_blocks((int) get_file_size("text.txt")); 
	//printf("Size of the file is : %d\n", size);
	//printf("Number of Blocks Req : %d\n", block_req);
	printf("\nStarting Block is : %d\n", get_dentry_block("text.txt"));
	add_next_block(block_req, get_dentry_block("text.txt"));
	print_fat_table(get_dentry_block("text.txt"));	
	print_fat_table(get_dentry_block("Thefie"));	
	
	FILE *fp;
    	char buffer[1026];
	
	fp = fopen("text.txt", "rb");
    	if (fp == NULL) {
        	printf("Error opening file\n");
        	return 1;
    	}
	
	
	int x = get_dentry_block("text.txt"); 
	for(int i=1 ; i<=block_req ; i++){
		// Read first 1024 bytes of data
	    	fread(buffer, 1, 1026, fp);
	    	printf("Data read: %s\n", buffer);

	    	// Create offset of 1024 bytes
	    	fseek(fp, 1026, SEEK_CUR-2);
		
		write_block(x, buffer);    	
	    	
		
		x = get_fat_value(x);
		printf("----------------------------Right Sucessful-------------------\n");
	}
	
	
	print_block(1);

    	fclose(fp);*/
	


	return 0;
}

