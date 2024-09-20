#ifndef  SORT
#define  SORT

#include "input_output.h"

int Strcmp_left_to_right(void* string_one, void* string_two);
int Strcmp_right_to_left(void* string_one, void* string_two);
void Bobble_sort_text(line* array_of_lines, int number_of_lines, int (*Strcmp_)(line, line));
void New_bobble_sort(void * array_of_lines, size_t number_of_lines, int (*Strcmp_)(void*, void*), size_t size_pointer);

#endif