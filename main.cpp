
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define SWAP(type, a, b) type tmp = a; a = b; b = tmp;

const char* SCAN_FILE_NAME = "text.txt"; 
const char* OUTPUT_FILE_NAME = "sort_text.txt"; 




size_t Get_file_size(const char * SCAN_FILE_NAME) {

    FILE * file = fopen(SCAN_FILE_NAME, "rb");
    int file_size = 0;                         //what int64_t?
              
    if(file == NULL) {  

		file_size = -1;

	} else {

		fseek(file, 0, SEEK_END);    //open file in binary mode, go to last element and get number of last bite
		file_size = ftello(file);     
		fclose(file);

	}
	return file_size;    
}


void Filling_array_pointer(char** index_line, int number_of_lines, int number_of_symbols) {

     for (int line = 0; line < number_of_lines - 1; line++){
        
        for (size_t elem = 1; elem < (size_t)number_of_symbols; elem++) {

            if (*(index_line[line] + elem) == '\n') {

                *(index_line + line + 1) = index_line[line] + elem; 
                break;
            }

        }
    }

}


void Output_text_file(char** index_line, int number_of_lines, int number_of_symbols, const char* OUTPUT_FILE_NAME) {
    
    FILE * output_f = fopen(OUTPUT_FILE_NAME,"w");
    int elem_counter = 0;

    for (size_t line = 0; line < number_of_lines; line++) { 

        int elem = 1;

        while ( *(index_line[line] + elem) != '\n' ) { //TODO: хз как по другому

            fputc(*(index_line[line] + elem), output_f);
            elem++;
            elem_counter++;
        }

        fputc(*(index_line[line] + elem), output_f);
        elem++;
        elem_counter++;
        elem = 1;
    }
    printf("The text has been successfully written to the file!\n");
}


int String_comparison(char * string_one, char * string_two) {
    size_t elem = 1;

    while (*(string_one + elem) != '\n') {

        if (tolower(*(string_one + elem)) != tolower(*(string_two + elem))){

            return 1 ? tolower(*(string_one + elem)) - tolower(*(string_two + elem)) > 0 : -1;
        }
        elem++;
    }

    return 0; 
}


void Bobble_sort_text(char** index_line, int number_of_lines) {
    
    for(int iteration_num = 0; iteration_num < number_of_lines - 1; iteration_num++) {

        for(int line_num = 0; line_num < number_of_lines - 1; line_num++) {
        
            if (String_comparison(*(index_line + line_num), *(index_line + line_num + 1)) == 1) {
                SWAP(char*, *(index_line + line_num), *(index_line + line_num + 1));
                
            }
        }
    }

}


//main 

int main(int argc, char const *argv[])
{

    //Creating and filling an array

    int number_of_lines = 14;  //TODO:realloc

    int number_of_symbols = Get_file_size(SCAN_FILE_NAME); //TODO: Parsing open file error 

    FILE * file = fopen(SCAN_FILE_NAME, "rt");         //TODO: Parsing open file error 

    char* text = (char *)calloc(number_of_symbols, sizeof(char));

    char** index_line = (char **)calloc(number_of_lines + 1, sizeof(double)); // in 64b_os one pointer like double - 8bite

    if (number_of_symbols == fread(text, sizeof(char), number_of_symbols, file)) {
        printf("writing data to the array was successful!\n");
    } else {
        printf("error in reading data from the file!\n");
    }

    *index_line = text;

    Filling_array_pointer(index_line, number_of_lines, number_of_symbols);

    Bobble_sort_text(index_line, number_of_lines);

    Output_text_file(index_line, number_of_lines, number_of_symbols, OUTPUT_FILE_NAME);

    free(text);     //clean memory 
    fclose(file);
    return 0;
}
