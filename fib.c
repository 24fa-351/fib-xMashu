#include <stdio.h>
#include <stdlib.h>

int iterative(int combinedNthValue)
{
   if (combinedNthValue == 0)
   {
      return 0;
   }
   else if (combinedNthValue == 1)
   {
      return 1;
   }
   int current = 1;
   int prev = 0;
   int next = 0;
   for (int i = 1; i < combinedNthValue; ++i)
   {
      next = prev + current;
      prev = current;
      current = next;
   }
   return current;
}

int recursion(int combinedNthValue)
{
   if (combinedNthValue == 0)
   {
      return 0;
   }
   else if (combinedNthValue == 1)
   {
      return 1;
   }
   else
   {
      return recursion(combinedNthValue - 1) + recursion(combinedNthValue - 2);
   }
}
// https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Iterative-Fibonacci.html
//  helped with understanding iterative fib again

int main(int argc, char *argv[])
{

   if (argc < 4)
   {
      printf("Too many arguments, only need int, r/i, and filename\n");
      exit(EXIT_FAILURE);
   }

   int commandLineInt = 0;
   sscanf(argv[1], "%d", &commandLineInt);
   // https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion/

   char fibOption = *argv[2];
   char *filename = argv[3];

   // scanf("%s", filename);
   FILE *file = fopen(filename, "r");
   // https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm

   int fileInteger;
   fscanf(file, "%d", &fileInteger);
   // https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
   fclose(file);

   int combinedNthValue = 0;
   combinedNthValue = commandLineInt + fileInteger - 1;
   // -1 cuz fib has to start at 0

   int result = 0;

   if (fibOption == 'i')
   {
      result = iterative(combinedNthValue);
   }
   else if (fibOption == 'r')
   {
      result = recursion(combinedNthValue);
   }

   printf("%d\n", result);
}