
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#include "../heders/input_output.h"
#include "../heders/sort.h"
#include "../heders/utilits.h"


const char* SCAN_FILE_NAME = "text.txt"; 
const char* OUTPUT_FILE_NAME = "sort_text.txt"; 


int main(const int argc, char const *argv[]) {

    //Creating and filling an array

    int number_of_symbols = Get_file_size(SCAN_FILE_NAME); //TODO: Parsing open file error: yes

    FILE * file     = fopen(SCAN_FILE_NAME, "rt"); 
    if (file == NULL) {
         return 0;
    }

    FILE * output_f = fopen(OUTPUT_FILE_NAME,"w");     
    if (output_f == NULL) {
        return 0;
    }

    char * text = (char *)calloc(number_of_symbols, sizeof(char));  //TODO: make new function

    if (number_of_symbols == fread(text, sizeof(char), number_of_symbols, file)) {
        printf("writing data to the array was successful!\n");

    } else {
        printf("error in reading data from the file!\n");

    }
    int number_of_lines = First_n_lines(text, number_of_symbols); 
    line * array_of_lines = (line *)calloc(number_of_lines + 1, sizeof(line)); // in 64b_os one pointer like double - 8bite
    printf("n_lines: %i\n", number_of_lines);
    printf("n_symb: %i\n", number_of_symbols);
    
    line firs_line = {0, text};
    *(array_of_lines) = firs_line;

    number_of_lines = Fill_array_pointer(array_of_lines, number_of_lines, number_of_symbols);

    Output_data(output_f, array_of_lines, number_of_lines, number_of_symbols, text); 


    free(text);     //clean memory 
    free(array_of_lines);
    fclose(file);
    return 0;
}
