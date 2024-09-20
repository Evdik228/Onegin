#include <stdio.h>
#include <ctype.h>
#include <assert.h> 

#include "../heders/input_output.h"
#include "../heders/utilits.h"

int Is_letter_LR (char * string_ , int index_letter) {

    assert(string_ != 0);

    while (!isalpha(*(string_ + index_letter))) {
        index_letter++;
    } 
    return index_letter;
}


int Is_letter_RL (char * string_ , int index_letter) {

    assert(string_ != 0);

    while (!isalpha(*(string_ + index_letter))  && index_letter > 1) {
        index_letter--;
    } 
    return index_letter;
}


int Strcmp_left_to_right(void* string_1, void* string_2) { 

    assert(string_1 != 0);
    assert(string_2 != 0);

    line* string_one = (line*)string_1;
    line* string_two = (line*)string_2;

    size_t elem_str_one = 1;
    size_t elem_str_two = 1;

    while (*(string_one->line_index + elem_str_one) != '\n' && *(string_two->line_index + elem_str_two) != '\n') {

        elem_str_one = Is_letter_LR(string_one->line_index, elem_str_one);
        elem_str_two = Is_letter_LR(string_two->line_index, elem_str_two);

        if (tolower(*(string_one->line_index + elem_str_one)) != tolower(*(string_two->line_index + elem_str_two))) {

            return   tolower(*(string_one->line_index + elem_str_one)) 
                   - tolower(*(string_two->line_index + elem_str_two)) > 0 
                   ? +1 
                   : -1;
        }
        elem_str_one++;
        elem_str_two++;
    }
    return 0; 
}

int Strcmp_right_to_left(void * string_1, void * string_2) {   

    assert(string_1 != 0);
    assert(string_2 != 0);
    
    line* string_one = (line*)string_1;
    line* string_two = (line*)string_2;

    size_t elem_str_one = string_one->line_size - 1;
    size_t elem_str_two = string_two->line_size - 1;

    while (elem_str_one != 1 && elem_str_two != 1) {

        elem_str_one = Is_letter_RL(string_one->line_index, elem_str_one);
        elem_str_two = Is_letter_RL(string_two->line_index, elem_str_two);

        if (tolower(*(string_one->line_index + elem_str_one)) != tolower(*(string_two->line_index + elem_str_two))) {

            return   tolower(*(string_one->line_index + elem_str_one)) 
                   - tolower(*(string_two->line_index + elem_str_two)) > 0 
                   ? +1 
                   : -1;
        }
        elem_str_one--;
        elem_str_two--;
    }
    return 0;                   
}

/*
void Bobble_sort_text(line* array_of_lines, int number_of_lines, int (*Strcmp_)(line, line)) {
    // TODO assert
    //printf("Number of lines in bobble: %d\n", number_of_lines);

    for(int iteration_num = 0; iteration_num < number_of_lines - 1; iteration_num++) {

        for(int line_num = 0; line_num < number_of_lines - iteration_num - 1; line_num++) {
        
            if (Strcmp_(*(array_of_lines + line_num), *(array_of_lines + line_num + 1)) == 1) {
                SWAP((array_of_lines + line_num),   (array_of_lines + line_num + 1), sizeof(line));
                
            }
        }
    }
}
*/

void New_bobble_sort(void * array_of_lines, size_t number_of_lines, int (*Strcmp_)(void*, void*), size_t size_pointer) {

    for(int iteration_num = 0; iteration_num < number_of_lines - 1; iteration_num++) {

        for(int line_num = 0; line_num < number_of_lines - iteration_num - 1; line_num++) {
            
            if (Strcmp_(((char *)array_of_lines + line_num * size_pointer),
                        ((char *)array_of_lines + (line_num + 1) * size_pointer)) == 1) { 

                SWAP(((char *)array_of_lines + line_num * size_pointer),
                     ((char *)array_of_lines + (line_num + 1) * size_pointer));
                
            }
        }
    }
}
