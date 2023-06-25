#include "linList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linList_p linListAllocCell(char* payload){
    linList_p cell;
    cell = malloc(sizeof(linListCell));
    cell->payload = strdup(payload);
    cell->next = NULL;
    return cell;
}

void linListFreeCell(linList_p junk){
    free(junk->payload);
    free(junk);
}

void linListFree(linList_p junk){
    linList_p currCell = junk;

    while (currCell->next != NULL)
    {
        linList_p nextCell = currCell->next;
        linListFreeCell(currCell);
        currCell = nextCell;
    }
    linListFreeCell(currCell);

}

linList_p linListInsertFirst(linList_p *anchor, linList_p newCell){
    newCell->next = *anchor;
    *anchor = newCell;
    return *anchor;
}

linList_p linListExtractFirst( linList_p *anchor){
    if(anchor){
    
        linList_p firstCell = *anchor;
        *anchor = firstCell->next;
        return firstCell;
    }
    else{
        return NULL;
    }
}

linList_p linListInsertLast(linList_p *anchor, linList_p newCel){
    //kann auch 2 Listen verketten
    linList_p curr = *anchor; 
    if(curr == NULL){
        *anchor = newCel;
        return *anchor;
    }
    
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next=newCel;
    return *anchor;
}

linList_p linListExtractLast(linList_p *anchor){
    linList_p curr = *anchor; 
    linList_p last = NULL;
    while(curr->next != NULL){
        last = curr;
        curr = curr->next;
    }
    last->next=NULL;
    return curr;
}

linList_p linListFind(linList_p anchor, char* payload){
    linList_p curr =anchor->next;       
    while(strcmp(curr->payload, payload) !=0){
            if(curr->next != NULL){
            curr = curr->next;
            }
            else{return NULL;}
    }
    return curr;
}

linList_p linListExtract(linList_p *anchor, linList_p cell){
    linList_p curr = *anchor; 
    linList_p last = NULL;
    while(curr->next != cell){
        if(curr->next == NULL){
            return NULL;
        }
        last = curr;
        curr = curr->next;
    }
    last = curr;
    curr = curr->next;
    last->next = curr->next;
    
    return curr;
}


linList_p linListRemoveDuplikate(linList_p *anchor){
    linList_p curr = *anchor;

    do{
        printf("current = %s\n", curr->payload);
        linList_p found = linListFind(curr, curr->payload);
        if(found != NULL){
            printf("dupe = %s\n", found->payload);
            linListFreeCell(linListExtract(anchor, found));
            printf("removed dupe\n");
        }
        curr = curr->next;
        
    } while (curr->next != NULL);
    
    return *anchor;

}

void linListPrint(linList_p anchor){
    linList_p curr = anchor;

    while(curr->next != NULL){
        printf("%s", curr->payload);
        curr = curr->next;
    }
    printf("%s", curr->payload);
    return;
}   
