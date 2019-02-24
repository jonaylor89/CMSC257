
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

  // printf("[DEBUG] start\n");

	// 1.) Read the integer values
	for (i = 0; i < NUMBER_ENTRIES; i++ ) {
	    scanf( "%f", &f_array[i] );
	}

  // printf("[DEBUG] Checkpoint 1\n");

	// 2.) Casting and modulus
  for (i = 0; i < NUMBER_ENTRIES; i++) {
		int temp = (int) f_array[i];
		i_array[i] = ((temp * temp) / temp) % 16;
	}

  // printf("[DEBUG] Checkpoint 2\n");

  // 3.) 
  printf("Float Display:\n");
	float_display_array(f_array, NUMBER_ENTRIES);

  // printf("[DEBUG] Checkpoint 3\n");

  // 4.)
  printf("Integer Display:\n");
	integer_display_array(i_array, NUMBER_ENTRIES);

  // printf("[DEBUG] Checkpoint 4\n");

  // 5.)
	for (i = 0; i < NUMBER_ENTRIES; i++) {
		printf("The integer array value %d has %d bits\n", i_array[i], count_bits(i_array[i]));
	}

  // printf("[DEBUG] Checkpoint 5\n");

  // 6.)
	integer_quicksort(i_array, 0, NUMBER_ENTRIES);

  // printf("[DEBUG] Checkpoint 6\n");

  // 7.)
  printf("The sorted integers are:\n");
	integer_display_array(i_array, NUMBER_ENTRIES);

  // printf("[DEBUG] Checkpoint 7\n");

  // 8.)
	printf("The number of even floats is: %d\n", float_evens(f_array, NUMBER_ENTRIES));

  // printf("[DEBUG] Checkpoint 8\n");

  // 9.)
	printf("The number of even ints is: %d\n", integer_evens(i_array, NUMBER_ENTRIES));

  // printf("[DEBUG] Checkpoint 9\n");

  // 10.) 
  most_values(i_array, NUMBER_ENTRIES, i_array[NUMBER_ENTRIES-1]);

  // printf("[DEBUG] Checkpoint 10\n");

  // 11.)
  unsigned short int theOne;

  // Decalre strings
  char r_theOne[(sizeof(unsigned short int) * 8) + 1];
  char bin_str[(sizeof(unsigned short int) * 8) + 1];

  for (i = 0; i < NUMBER_ENTRIES; i++) {
    theOne = (unsigned short int) i_array[i];
    
    // Set all of the arrays to zero
    memset(r_theOne, '0', (sizeof(unsigned short int) * 8) + 1);
    memset(bin_str, '0', (sizeof(unsigned short int) * 8) + 1);

    binary_string(theOne, bin_str, sizeof(unsigned short int) * 8 + 1);
    binary_string(reverse_bits(theOne), r_theOne, sizeof(unsigned short int) * 8 + 1);

    /* 
    int j;
    for (j = 0; j < sizeof(unsigned short int) * 8 + 1; j++) {
      printf("[DEBUG] %c\n", bin_str[j]);
    }

    for (j = 0; j < sizeof(unsigned short int) * 8 + 1; j++) {
      printf("[DEBUG] %c - reverse\n", r_theOne[j]);
    }

    */

    printf("The unsigned short value 0x%x\n", theOne);
    printf("\tORIG : %s\n", bin_str);
    printf("\tREVR : %s\n", r_theOne);

    // TODO find decimal of r_bin_str
    unsigned char *p = r_theOne;
    unsigned int   r = 0;

    while (p && *p ) {
      r <<= 1;
      r += (unsigned int)((*p++) & 0x01);
    }

    printf("\tVAL : %d\n", (int) r);

  }

  // printf("[DEBUG] Checkpoint 11\n");

	// Return successfully
	return 0;
}
















