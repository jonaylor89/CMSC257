
#include "asgn3_support.h"

int main(int argc, char **argv) {

  /* Make 10 calls to malloc */
   int a;
   int b;
   int c;
   int[] d;
   int[] e;
   int[] f;
   int[] g;
   int[] h;
   int[] i;
   int[] j;
   int[] k;
   int[] l;
   int[] m;

  if ((a = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((b = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((c = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((d = malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }


  if ((e = malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }

  /* Do it again because why not */
  if ((a = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((b = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((c = malloc(sizeof(int))) == NULL) {
    return 1; 
  }

  if ((d = malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }


  if ((e = malloc(sizeof(int) * 4)) == NULL) {
    return 1; 
  }
 

  /* Make 10 calls to calloc */

  if ((d = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }


  if ((e = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }
 

  if ((f = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }


  if ((g = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }
 

  if ((h = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }


  if ((i = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }
 

  if ((j = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }


  if ((k = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }
 
  if ((l = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }


  if ((m = calloc(sizeof(int), 4)) == NULL) {
    return 1; 
  }
 

  /* Make 10 calls to realloc */

  if ((d = realloc(d, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((e = realloc(e, sizeof(int) + 10)) == NULL) {
    return 1; 
  }
 

  if ((f = realloc(f, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((g = realloc(g, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 

  if ((h = realloc(h, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((i = realloc(i, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 

  if ((j = realloc(j, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((k = realloc(k, sizeof(int) * 10)) == NULL) {
    return 1; 
  }
 
  if ((l = realloc(l, sizeof(int) * 10)) == NULL) {
    return 1; 
  }


  if ((m = realloc(m, sizeof(int) * 10)) == NULL) {
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
