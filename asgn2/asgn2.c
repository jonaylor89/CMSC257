
////////////////////////////////////////////////////////////////////////////////
//
//  File          : asgn2.c
//  Description   : This is the main code file for the CMSC257 assignment 2.
//                  see class assignment for details on what needs to be added.
//
//  Author        : John Naylor
//  Created       : 02/11/18
//


// Include Files
#include <stdio.h>
#include <stdlib.h>

// Project Includes
#include "a2support.h"

// Defines
#define NUMBER_ENTRIES 20

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : This is the main function for the cmsc257-s16-assign2 program.
//
// Inputs       : none
// Outputs      : 0 if successful, -1 otherwise

int main( void ) {
	// Local variables
	float f_array[NUMBER_ENTRIES];
	int i, i_array[NUMBER_ENTRIES];

	// 1.) Read the integer values
	for (i = 0; i < NUMBER_ENTRIES; i++ ) {
	    scanf( "%f", &f_array[i] );
	}

	// 2.) Casting and modulus
  for (i = 0; i < NUMBER_ENTRIES; i++) {
		int temp = (int) f_array[i];
		i_array[i] = ((temp * temp) / temp) % 16;
	}

  // 3.) 
	float_display_array(f_array, NUMBER_ENTRIES);

  // 4.)
	integer_display_array(i_array, NUMBER_ENTRIES);

  // 5.)
	for (i = 0; i < NUMBER_ENTRIES; i++) {
		printf("%d", count_bits(i_array[i]));
	}

  // 6.)
	integer_quicksort(i_array, 0, NUMBER_ENTRIES);

  // 7.)
	integer_display_array(i_array, NUMBER_ENTRIES);

  // 8.)
	printf("%d", float_evens(f_array, NUMBER_ENTRIES));

  // 9.)
	printf("%d", integer_evens(i_array, NUMBER_ENTRIES));

  // 10.) 
  int *most_value = most_values(i_array, NUMBER_ENTRIES, i_array[NUMBER_ENTRIES-1]);
  for (i = 0; most_value[i] != -1; i++) {
    printf("%d", most_value[i]);
  }
  free(most_value);

  // 11.)
  unsigned short int theOne;
  char bin_str[sizeof(unsigned short int) + 1];
  char r_bin_str[sizeof(unsigned short int) + 1];
  for (i = 0; i < NUMBER_ENTRIES; i++) {
    theOne = (unsigned short int) i_array[i];

    binary_string(theOne, bin_str, sizeof(unsigned short int) + 1);
    reverse_bits(bin_str);
    
    printf("%s", bin_str);
    printf("%s", r_bin_str);

    // find decimal of r_bin_str

  }

	// Return successfully
	return 0;
}
















