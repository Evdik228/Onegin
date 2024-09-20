
#include <cstdio>
#include <assert.h>
#include <stdlib.h>

#include "../heders/input_output.h"

// fstat
size_t Get_file_size(const char * SCAN_FILE_NAME) {
// TODO asserts, many assert

    assert(SCAN_FILE_NAME != NULL);

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

void SWAP (void * elem1, void * elem2) {

	line* string_one = (line*)elem1;
    line* string_two = (line*)elem2;

	line buf = {};

	buf.line_index = string_one->line_index;
	buf.line_size = string_one->line_size;

	string_one->line_index = string_two->line_index;
	string_one->line_size = string_two->line_size;

	string_two->line_index = buf.line_index;
	string_two->line_size = buf.line_size;

}

