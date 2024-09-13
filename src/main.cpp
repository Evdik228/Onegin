
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#include "../heders/input_output.h"
#include "../heders/sort.h"
#include "../heders/utilits.h"

// TODO: do not commit binaries(a.out)
// TODO: "main.cpp" seriously????   


// TODO: why define and not a function???


const char* SCAN_FILE_NAME = "text.txt"; 
const char* OUTPUT_FILE_NAME = "sort_text.txt"; 


// TODO: maybe it is better for function parameter to be FILE * argument, 
//       I think it will be more usable
//       it is strange that you are opening and closing file just to know its size
//       so i think FILE * is better


//main 

int main(const int argc, char const *argv[]) {
    // TODO разбить на файлы
    // TODO мейн должен быть в начале
    //Creating and filling an array

    int number_of_symbols = Get_file_size(SCAN_FILE_NAME); //TODO: Parsing open file error: yes

    FILE * file = fopen(SCAN_FILE_NAME, "rt");   
    FILE * output_f = fopen(OUTPUT_FILE_NAME,"w");     

    char * text = (char *)calloc(number_of_symbols, sizeof(char)); 

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

    fprintf(output_f, "\n\n----------------------------------------------------- Sort L --> R ---------------------------------------------------\n\n");
    Bobble_sort_text(array_of_lines, number_of_lines, Strcmp_left_to_right);
    Output_text_file(array_of_lines, number_of_lines, number_of_symbols, output_f);
    printf("\nSort L --> R\n");

    fprintf(output_f, "\n\n-----------------------------------------------------Sort R --> l -----------------------------------------------------\n\n");
    Bobble_sort_text(array_of_lines, number_of_lines, Strcmp_right_to_left);
    Output_text_file(array_of_lines, number_of_lines, number_of_symbols, output_f);
    printf("Sort R --> L\n");

    fprintf(output_f, "\n\n----------------------------------------------------- OUR TEXT --------------------------------------------------\n\n");
    Output_original(text, number_of_symbols, output_f);
    printf("OUR TEXT\n");


    free(text);     //clean memory 
    free(array_of_lines);
    fclose(file);
    return 0;
}
