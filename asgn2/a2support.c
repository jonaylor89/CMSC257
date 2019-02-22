
//////////////////////////////////////////////////////////////////////////////
//
//  File          : a2support.c
//  Description   : This is the file for the functions for assignment
//                  2 of the CMSC257 course.  Students are required to define
//                  the following functions and implement them in another
//                  file, a1support.c.
//
//  Author        : John Naylor
//  Created       : 02/12/19

// Functions to define

#include "a2support.h"

void float_display_array(float* arr, int size) {
	// Print contents
	for (int i = 0; i < size; i++) {
		printf("%f\n", arr[i]);
	}
}

void integer_display_array(int* arr, int size) {
	// Print contents
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

}

int float_evens(float* arr, int size) {

  int counter = 0;

  int i;
  for (i = 0; i < size; i++) {
    if ((int) arr[i] % 2 == 0) {
      counter++; 
    }
  }

	return counter;
}

int integer_evens(int* arr, int size) {

  int counter = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      counter++; 
    }
  }

	return counter;
}

int counter_bits(int num) {

  int count = 0;

  while (num) {
    count += num & 1;
    num >>= 1;
  }

	return count;
}

int partition(int* arr, int left, int right) {
  int pivot = arr[right];
  int index = left - 1;
  int temp;

  int i;
  for (i = left; i < right - 1; i++) {
    if (arr[i] < pivot) {
      index++;
      temp = arr[index];
      arr[index] = arr[i];
      arr[i] = temp;
    }
  }

  temp = arr[index + 1];
  arr[index + 1] = arr[right];
  arr[right] = temp;

  return index + 1;
}


void integer_quicksort(int* arr, int left, int right) {

  int index;

  if (left < right) {
    index = partition(arr, left, right);

    integer_quicksort(arr, left, index-1);
    integer_quicksort(arr, index+1, right);
  }
}

int *most_values(int* arr, int size, int highest) {

  int frequency[highest];

  int i;
  for (i = 0; i < size; i++) {
    frequency[arr[i]]++;
  }

  int most_freq = 0;
  for (i = 0; i < highest; i++) {
    if (most_freq < frequency[i]) {
      most_freq = frequency[i];
    }
  }

  int ret_count = 0;
  for (i = 0; i < highest; i++) {
    if (most_freq == frequency[i]) {
      ret_count++;
    }
  }

  int counter[ret_count+1];

  int position = 0;
  for (i = 0; i < highest; i++) {
    if (most_freq == frequency[i]) {
      counter[position] = i;
      position++;
    }
  }

  counter[position] = -1;

  return counter;
}

unsigned short int reverse_bits(unsigned short int num) {

  unsigned short int count = sizeof(unsigned short int) * 8 - 1;
  unsigned short int backwards = num;

  num >>= 1;
  while (num) {

    backwards <<= 1;
    backwards |= num & 1;
    num >>= 1;
    count--;

  }

  backwards <<= count;

	return backwards;
}

void binary_string(unsigned short binary, char* arr, int size) {

  int count = 0;

  while (binary) {
    arr[count] |= binary & 1;
    binary >>= 1;
    count++;
  }

  arr[count] = '\0';

}


