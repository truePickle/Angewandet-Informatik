#include "labLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int checkLab(FILE *Lab, int *maxWid, int *maxLeng){
    bool hasEnd = false;
    bool hasStart = false;
    int maxLength = 0;
    int maxWidth = 0;
    int tempWidth = 0;
    
    char currChar;

    while((currChar = fgetc(Lab)) != EOF){
        
        if(currChar == '\n'){
            if(maxWidth < tempWidth){
                maxWidth = tempWidth;
            }
            maxLength++;
            tempWidth = 0;
        }
        else{
            tempWidth++;

            if(currChar == 'X')
            {  
                if(hasEnd){
                    return 0;
                }
                hasEnd = true;
            }
            else if (currChar == 'S')
            {
                if(hasStart){
                    return 0;
                }
                hasStart = true;
            }
        }
    }

    *maxWid = maxWidth;
    *maxLeng = maxLength; 
    return 1;
    
}