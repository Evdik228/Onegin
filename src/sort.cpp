#include <stdio.h>
#include <ctype.h>


#include "../heders/input_output.h"
#include "../heders/utilits.h"

#define SWAP(type, a, b) type tmp = a; a = b; b = tmp;   

int Is_letter_LR (char * string_ , int index_letter) {
    while (!isalpha(*(string_ + index_letter))) {
        index_letter++;
    } 
    return index_letter;
}


int Is_letter_RL (char * string_ , int index_letter) {
    while (!isalpha(*(string_ + index_letter))  && index_letter > 1) {
        index_letter--;
    } 
    return index_letter;
}


int Strcmp_left_to_right(line string_one, line string_two) { 
    size_t elem_str_one = 1;
    size_t elem_str_two = 1;

    while (*(string_one.line_index + elem_str_one) != '\n' && *(string_two.line_index + elem_str_two) != '\n') {

        elem_str_one = Is_letter_LR(string_one.line_index, elem_str_one);
        elem_str_two = Is_letter_LR(string_two.line_index, elem_str_two);

        if (tolower(*(string_one.line_index + elem_str_one)) != tolower(*(string_two.line_index + elem_str_two))) {

            return tolower(*(string_one.line_index + elem_str_one)) 
                   - tolower(*(string_two.line_index + elem_str_two)) > 0 
                   ? 1 
                   : -1;
        }
        elem_str_one++;
        elem_str_two++;
    }
    return 0; 
}

int Strcmp_right_to_left(line string_one, line string_two) {   

    size_t elem_str_one = string_one.line_size - 1;
    size_t elem_str_two = string_two.line_size - 1;

    while (elem_str_one != 1 && elem_str_two != 1) {

        elem_str_one = Is_letter_RL(string_one.line_index, elem_str_one);
        elem_str_two = Is_letter_RL(string_two.line_index, elem_str_two);

        if (tolower(*(string_one.line_index + elem_str_one)) != tolower(*(string_two.line_index + elem_str_two))) {

            return tolower(*(string_one.line_index + elem_str_one)) 
                   - tolower(*(string_two.line_index + elem_str_two)) > 0 
                   ? 1 
                   : -1;
        }
        elem_str_one--;
        elem_str_two--;
    }
    return 0;                   
}


void Bobble_sort_text(line* array_of_lines, int number_of_lines, int (*Strcmp_)(line, line)) {
    // TODO assert
    //printf("Number of lines in bobble: %d\n", number_of_lines);

    for(int iteration_num = 0; iteration_num < number_of_lines - 1; iteration_num++) {

        for(int line_num = 0; line_num < number_of_lines - 1; line_num++) {
        
            if (Strcmp_(*(array_of_lines + line_num), *(array_of_lines + line_num + 1)) == 1) {
                SWAP( line, *(array_of_lines + line_num), *(array_of_lines + line_num + 1));
                
            }
        }
    }
}


/*
void Quick_sort(char** array_of_lines, int first_index, int number_of_lines) {
    if (first_index >= number_of_lines) {
        return;
    }
    char * main_elem = *(array_of_lines + first_index);
    int left_border = first_index; 
    int right_border = number_of_lines; 

    while (left_border <= right_border){
        while(Strcmp_left_to_right(*(array_of_lines + left_border), main_elem) == -1) {
            left_border++;
        }
        while(Strcmp_left_to_right(*(array_of_lines + right_border), main_elem) == 1) {
            right_border--;
        }

        if (left_border <= right_border){
            SWAP(char*, array_of_lines[left_border], array_of_lines[right_border]);
            left_border++;
            right_border--;
        }
    }
    Quick_sort(array_of_lines, first_index, right_border);
    Quick_sort(array_of_lines, left_border, number_of_lines);

}


void My_quick_sort(char** array_of_lines, int first_index, int number_of_lines) {
    if (first_index >= number_of_lines) {
        return;
    }
    int wall = first_index;
    char * main_element = *(array_of_lines + number_of_lines);
    int current_index = first_index;

    while (current_index < number_of_lines - 1  && wall < number_of_lines - 1) {
        if (Strcmp_left_to_right(array_of_lines[current_index], main_element) == -1) {
            SWAP(char *, array_of_lines[wall], array_of_lines[current_index]);
            wall++; 
            current_index++;

        } else {
            current_index++;
        }
    }
    if (wall < number_of_lines){
        SWAP(char *, array_of_lines[wall], array_of_lines[number_of_lines]);
        wall++; 

        My_quick_sort(array_of_lines, first_index, wall);      //тут что то происходит аааааааааааа
        My_quick_sort(array_of_lines, wall, number_of_lines);
    } 
}
*/
