
#include "asgn3_support.h"

int main(void) {

  /* Make 10 calls to malloc */
   int a;
   int b;
   int c;
   int d[];
   int e[];
   int f[];
   int g[];
   int h[];
   int i[];
   int j[];
   int k[];
   int l[];
   int m[];

  if ((a = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((b = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((c = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((d = (int *)malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }


  if ((e = (int *)malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }

  /* Do it again because why not */
  if ((a = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((b = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((c = (int *)malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((d = (int *)malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }


  if ((e = (int *)malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }
 

  /* Make 10 calls to calloc */

  if ((d = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }


  if ((e = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }
 

  if ((f = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }


  if ((g = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }
 

  if ((h = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }


  if ((i = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }
 

  if ((j = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }


  if ((k = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }
 
  if ((l = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }


  if ((m = (int *)calloc(4, sizeof(int))) == NULL) {
    return 1; 
  }
 

  /* Make 10 calls to realloc */

  if ((d = (int *)realloc(d, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((e = (int *)realloc(e, sizeof(int) + 10)) == NULL) {
    return 1; 
  }
 

  if ((f = (int *)realloc(f, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((g = (int *)realloc(g, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 

  if ((h = (int *)realloc(h, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((i = (int *)realloc(i, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 

  if ((j = (int *)realloc(j, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((k = (int *)realloc(k, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 
  if ((l = (int *)realloc(l, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((m = (int *)realloc(m, sizeof(int) * 10)) == NULL) {
    return 1; 
  }

  /* Make 5 calls to free */

  free(a);
  free(b);
  free(c);
  free(d);
  free(e);

  /* Print total memory leakage */

  /* Print starting and ending addresses of the heap */
  printf("%p\n", global_base);
  printf("%p\n", sbrk(0));

  return 0;
}
