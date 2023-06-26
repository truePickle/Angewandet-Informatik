#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXITEMS 10000

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
   
   char value;
   char *arr[MAXITEMS];
   int index = 0;

   while(!feof(in))
   {
      if(index > MAXITEMS)
      {
         fprintf(stderr, "Input cannot be more than 10000 strings\n");
         exit(EXIT_FAILURE);
      }

      fscanf(in, "%s\n", value);
      printf("asining");
      arr[index] = malloc(sizeof(value));
      printf("assigned memory");
      strcpy(arr[index], value);
      printf("copied string");
      index++;

      
   }
   for(int i = index-1; i >=0; i--)
   {
      printf("%s", arr[i]);
   }

   if(in!=stdin)
   {
      fclose(in);
   }
   exit(EXIT_SUCCESS);
}