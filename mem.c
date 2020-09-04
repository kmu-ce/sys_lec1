/* File: mem.c
 * ------------
 * Demonstrates strange behaviours when memory/stack is mishandled
 */
 #include <stdio.h>
 #include <stdbool.h>

 static int read_int()
 {
     while(true){
         int num;
         printf("Enter an integer: ");
         if(scanf("%d", &num) == 1) return num;
         scanf("%*[^\n]"); // clean garbage
     }
 }

 // This function is buggy -- given an argument larger than 5
 // it will overrun the array. What happens when you overrun
 // and array in C?
 static int sum_ints(int count)
 {
     int nums[5], sum = 0;

     for(int i = 0; i < count; i++) nums[i] = i + 1;
     for(int i = 0; i < count; i++) sum += nums[i];
     return sum;
 }

 int main(int argc, char *argv[])
 {
     while (true){
         int num = read_int();
         if(num == 0) break;
         printf("Sum of numbers 1 to %d = %d\n", num, sum_ints(num));
     }
     return 0;
 }
