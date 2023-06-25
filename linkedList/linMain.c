#include <stdio.h>
#include <stdlib.h>
#include "linList.h"

int main(int argc, char *argv[])
{
    FILE *in = stdin;

    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        in = fopen(argv[1], "r");
        if (!in)
        {
            perror(argv[1]);
            exit(EXIT_FAILURE);
        }
    }

    linList_p anchor = NULL;
    char input[255];
     while(fgets(input, sizeof(input), in))
    {
//       printf("Gelesen\n");
       linListInsertLast(&anchor, linListAllocCell(input));
//       printf("Eingefuegt\n");
    }
    printf("removing dupes\n");
    linListRemoveDuplikate(&anchor);
    printf("printing list:\n");
    linListPrint(anchor);

    if (in != stdin)
    {
        fclose(in);
    }

    exit(EXIT_SUCCESS);
}
