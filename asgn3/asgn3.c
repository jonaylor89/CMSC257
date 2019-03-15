
#include "asgn3_support.h"

int main(int argc, char **argv) {

  /* Make 10 calls to malloc */
   int a;
   int b;
   int c;
   int[] d;
   int[] e;

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


  /* Make 10 calls to realloc */

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
