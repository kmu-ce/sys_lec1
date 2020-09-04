/* File: num.c
 *-------------
 * Demonstrates some suprising properties of computer arithmetic.
 */

 #include <stdbool.h>
 #include <stdio.h>

 static int read_int()
 {
     while(true){
         int num;
         printf("Enter an integer: ");
         if(scanf("%d", &num) == 1) return num;
         scanf("%*[^\n]"); // clean garbage
     }
 }

 // Shouldn't x^2 be positive for all values of x? It is in the real world
 // but is the computer real?
 int main(int argc, char *argv[])
 {
     while(true){
         int num = read_int();
         if(num == 0) break;
         int squared = num * num;
         printf("%d^2 = %d\n", num, squared);
     }
     return 0;
 }