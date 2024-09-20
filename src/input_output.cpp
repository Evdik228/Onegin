
#include <stdio.h>
#include <assert.h>

#include "../heders/input_output.h"
#include "../heders/sort.h"


int First_n_lines(char* text, int number_of_symbols){
    int n_lines = 0;
    for (size_t elem = 0; elem < number_of_symbols; elem++) {
        if(*(text + elem) == '\n' && *(text + elem + 1) != '\n') {
            n_lines++;
        }
    }
    return n_lines;
}

void Output_original(char* text, int number_of_symbols, FILE * output_f) {

    assert( text != NULL ); 

    fwrite(text, sizeof(char), number_of_symbols, output_f);
}


int Fill_array_pointer(line* array_of_lines, int number_of_lines, int number_of_symbols) {
    int n_lines = 0;
    assert( array_of_lines != NULL );

    for (size_t elem = 1; elem < (size_t)number_of_symbols; elem++) {     

        if (*(array_of_lines->line_index + elem)     == '\n' &&
            *(array_of_lines->line_index + elem + 1) != '\n') {

            line i_line = {0 , array_of_lines->line_index};
            *(array_of_lines + n_lines + 1) = i_line;
            (array_of_lines + n_lines + 1)->line_index = array_of_lines->line_index + elem; 
            (array_of_lines + n_lines)->line_size = size_t((array_of_lines + n_lines + 1)->line_index) 
                                                  - size_t((array_of_lines + n_lines)    ->line_index);
            n_lines++;
        }
    }
    return n_lines;
}


void Output_text_file(line* array_of_lines, int number_of_lines, int number_of_symbols, FILE * output_f) {
    
    int elem_counter = 0;
    assert( array_of_lines != NULL );

    for (size_t line = 0; line < number_of_lines; line++) { 
        int elem = 1;             

        while ( *((array_of_lines + line)->line_index + elem) != '\n' && elem_counter < number_of_symbols) { 

            fputc(*((array_of_lines + line)->line_index + elem), output_f); // NOTE: let it be, it is first iteration as i remember, 
            elem++;
            elem_counter++;
        }

       fputc(*((array_of_lines + line)->line_index + elem), output_f);

        elem_counter++;
        elem = 1;

    }
}   
void Output_data(FILE * output_f, line* array_of_lines, int number_of_lines, int number_of_symbols, char* text) { 
    assert( text != NULL );
    assert( array_of_lines != NULL );

    fprintf(output_f, "\n\n----------------------------------------------------- Sort L --> R ---------------------------------------------------\n\n");
    New_bobble_sort(array_of_lines, number_of_lines, Strcmp_left_to_right, sizeof(line));
    Output_text_file(array_of_lines, number_of_lines, number_of_symbols, output_f);
    printf("\nSort L --> R\n");

    fprintf(output_f, "\n\n-----------------------------------------------------Sort R --> l -----------------------------------------------------\n\n");
    New_bobble_sort(array_of_lines, number_of_lines, Strcmp_right_to_left, sizeof(line));
    Output_text_file(array_of_lines, number_of_lines, number_of_symbols, output_f);
    printf("Sort R --> L\n");

    fprintf(output_f, "\n\n----------------------------------------------------- OUR TEXT --------------------------------------------------\n\n");
    Output_original(text, number_of_symbols, output_f);
    printf("OUR TEXT\n");
    }