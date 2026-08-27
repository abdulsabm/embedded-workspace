/*
gcc .\10_missing_standerd_lybrary_links.c -o 10_missing_standerd_lybrary_links    
.\10_missing_standerd_lybrary_links.c: In function 'main':
.\10_missing_standerd_lybrary_links.c:5:39: error: implicit declaration of function 'sqrt' [-Wimplicit-function-declaration]
    5 |     printf("sque root of 4 is: %d\n", sqrt(4));
      |                                       ^~~~
.\10_missing_standerd_lybrary_links.c:2:1: note: include '<math.h>' or provide a declaration of 'sqrt'
    1 | #include<stdio.h>
  +++ |+#include <math.h>
    2 | 
.\10_missing_standerd_lybrary_links.c:5:39: warning: incompatible implicit declaration of built-in function 'sqrt' [-Wbuiltin-declaration-mismatch]
    5 |     printf("sque root of 4 is: %d\n", sqrt(4));
      |                                       ^~~~
.\10_missing_standerd_lybrary_links.c:5:39: note: include '<math.h>' or provide a declaration of 'sqrt'
*/

#include<stdio.h>
// #include<math.h>

void main(){
    int result = sqrt(4);
    printf("sque root of 4 is: %d\n", result);
}