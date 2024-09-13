
#include <cstdio>
#include <stdlib.h>


size_t Get_file_size(const char * SCAN_FILE_NAME) {
// TODO asserts, many assert
    FILE * file = fopen(SCAN_FILE_NAME, "rb");
    int file_size = 0;                         //what int64_t?
              
    if (file == NULL) {  
		file_size = -1;
	} else {

		fseek(file, 0, SEEK_END);    //open file in binary mode, go to last element and get number of last bite
		file_size = ftello(file);     
		fclose(file);
	}
	return file_size;    
}

/*
void SWAP (void * elem1, void * elem2, size_t size) {
    void * buffer =  calloc(1 , size);
    buffer = elem1;

}
*/
