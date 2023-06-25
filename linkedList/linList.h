#ifndef LINLIST_H
#define LINLIST_H

typedef struct linList
{
    char *payload;
    struct linList *next;
}linListCell, *linList_p;

linList_p linListAllocCell(char* payload);
void linListFreeCell(linList_p junk);
void linListFree(linList_p junk);
linList_p linListInsertFirst(linList_p *anchor, linList_p newCell);
linList_p linListExtractFirst( linList_p *anchor);
linList_p linListInsertLast(linList_p *anchor, linList_p newCel);
linList_p linListExtractLast(linList_p *anchor);
linList_p linListFind(linList_p anchor, char* payload);
linList_p linListExtract(linList_p *anchor, linList_p cell);
linList_p linListRemoveDuplikate(linList_p *anchor);
void linListPrint(linList_p anchor);

#endif
