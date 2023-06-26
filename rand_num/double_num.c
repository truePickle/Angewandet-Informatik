#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
   FILE *in = stdin;

   if(argc > 2)
   {
      fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   if(argc == 2)
   {
      in = fopen(argv[1], "r");
      if(!in)
      {
         perror(argv[0]);
         exit(EXIT_FAILURE);
      }
   }

   int value;

   while(!feof(in))
   {
      fscanf(in, "%d", &value);
      value = value *2;
      printf("%d\n", value);

   } 


   if(in!=stdin)
   {
      fclose(in);
   }
   exit(EXIT_SUCCESS);
}