#ifndef A2SUPPORT_INCLUDED
#define A2SUPPORT_INCLUDED

//////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.h
//  Description   : This is the header file for the functions for assignment
//                  1 of the CMSC257 course.  Students are required to define
//                  the following functions and implement them in another
//                  file, a1support.c.
//
//  Author        : John Naylor
//  Created       : 02/12/19

// Functions to define

void float_display_array(int*, int);
void integer_display_array(int*, int);
int float_evens(float*, int);
int integer_evens(int*, int);
int count_bits(int);
void integer_quicksort(int*, int, int);
void most_values(int*, int, int);
unsigned short reverse_bits(unsigned short);
void binary_string(unsigned short, char*, int);

#endif

