#include <stdio.h>
#include "linktable.h"
#include <stdilb.h>
tLinkTable * CreateLinkTable()
{
    tLinkTable *pTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    pTable->pHead = NULL;
    pTable->pTail = NULL;
    pTable->SumOfNode = 0;

    return pTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    free(pLinkTable);
    return 0;
}

int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if(pLinkTable == NULL)
    {
        printf("The table is empty!\n");
        exit(0);
    }
    
    else if(pNode == NULL)
    {
        printf("The node is empty!\n");
        return 0;
    }

    else if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode = 1;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
	pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode++;
    }
    return 0;
}

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        Printf("The table is empty!\n");
        exit(0);
    }
    return pLinkTable->Head;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if(pLinkTable == NULL)
    {
        printf("The table is empty!\n");
        exit(0);
    }
    
    if(pNode == NULL)
    {
        printf("The node is empty!\n");
    }
    return pNode->pNext;
}
