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
		int temp = (int) f_array[i]
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
	quicksort(i_array, NUMBER_ENTRIES, 0, NUMBER_ENTRIES - 1);

  // 7.)
	integer_display_array(i_array, NUMBER_ENTRIES)

  // 8.)
	printf("%d", float_evens(f_array, NUMBER_ENTRIES));

  // 9.)
	printf("%d", integer_evens(i_array, NUMBER_ENTRIES));

  // 10.) 
  printf("%d", most_values(i_array, NUMBER_ENTRIES, i_array[NUMBER_ENTRIES-1]));

  // 11.)
  char* bin_str;
  char* r_bin_str;
  for (i = 0; i < NUMBER_ENTRIES; i++) {
    bin_str = binary_string(i_array[i]);
    r_bin_str = reverse_bits(binary_string(i_array[i])

    i_array[i] = (unsigned int) i_array[i];
    
    printf("%s", bin_str);
    printf("%s", r_bin_str);

    // find decimal of r_bin_str

  }

	// Return successfully
	return 0;
}
















