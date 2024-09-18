#ifndef  INPUT_OUTPUT
#define  INPUT_OUTPUT

#include<stdlib.h>
#include <cstdio>

struct line
{
    size_t line_size;
    char* line_index;
};

void Output_data(FILE * output_f, line* array_of_lines, int number_of_lines, int number_of_symbols, char* text);
int First_n_lines(char* text, int number_of_symbols);
void Output_original(char* text, int number_of_symbols, FILE * output_f);
int Fill_array_pointer(line* array_of_lines, int number_of_lines, int number_of_symbols);
void Output_text_file(line* array_of_lines, int number_of_lines, int number_of_symbols, FILE * output_f);


#endif