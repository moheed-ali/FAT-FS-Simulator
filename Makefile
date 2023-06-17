.PHONY: all clean

TARGET=oscafs

all: ${TARGET}

oscafs: oscafs.o fat.o dentry.o data_block.o file_operations.o initial_file.o

oscafs.o: oscafs.c oscafs.h
fat.o: fat.c oscafs.h
dentry.o: dentry.c oscafs.h
data_block.o: data_block.o oscafs.h
initial_file.o: initial_file.o oscafs.h
file_operations.o: file_operations.o oscafs.h

clean:
	rm -f *~
	rm -f *.o
	rm -f ${TARGET}


	
