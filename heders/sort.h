#ifndef  SORT
#define  SORT

#include "input_output.h"

int Strcmp_left_to_right(line string_one, line string_two);
int Strcmp_right_to_left(line string_one, line string_two);
void Bobble_sort_text(line* array_of_lines, int number_of_lines, int (*Strcmp_)(line, line));

#endif