#include <stdio.h>
/* Na ordem de chamada o print vai ser:
   f1=2     f2=2      f3=3      main=3  */

void f1 ( int v) {
 v = v + 1;
 printf (" f1 = %d\n " , v ); // v=1  1 + 1 = 2
}
void f2 ( int *v) {
 *v = *v + 1;
 printf (" f2 = %d\n " , *v ); // v=1  1 + 1 = 2
}
int f3 ( int v) {
 v = v + 1;
 printf (" f3 = %d\n " , v ); //v=2  2 + 1 = 3
 return v;
}
int main (void) {
 int v = 1;
 f1 ( v );
 f2 (&v );
 v = f3 ( v ); // v = 2 + 1 = 3
 printf (" main = %d \n" , v ); // 3
 return 0;
}