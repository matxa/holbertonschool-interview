#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

/* MACROS */
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void push_zeros_to_end(int *arr, size_t n);
void push_zeros_to_start(int *arr, size_t n);

#endif /* SLIDE_LINE_H */
