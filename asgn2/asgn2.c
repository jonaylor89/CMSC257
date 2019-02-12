////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s16-assign2.c
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

	// Read the integer values
	for (i = 0; i < NUMBER_ENTRIES; i++ ) {
	    scanf( "%f", &f_array[i] );
	}

	// Casting and modulus
	for (i = 0; i < NUMBER_ENTRIES; i++) {
		int temp = (int) f_array[i]
		i_array[i] = ((temp * temp) / temp) % 16;
	}

	float_display_array(f_array, NUMBER_ENTRIES);

	integer_display_array(i_array, NUMBER_ENTRIES);

	for (i = 0; i < NUMBER_ENTRIES; i++) {
		printf("%d", count_bits);
	}

	quicksort(i_array, NUMBER_ENTRIES, 0, NUMBER_ENTRIES - 1);

	integer_display_array(i_array, NUMBER_ENTRIES)

	printf("%d", float_evens(f_array, NUMBER_ENTRIES));

	printf("%d", integer_evens(i_array, NUMBER_ENTREIS));

	// Return successfully
	return 0;
}
















