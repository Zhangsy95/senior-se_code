#include<stdlib.h>
#include<stdio.h>
#include  "linktable.h"

tLinkTable *CreateLinkTable()
{
    tLinkTable *pTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    pTable->pHead = NULL;
    pTable->pTail = NULL;
    pTable->SumOFNode = 0;
    return pTable;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL)
    {
	printf("The table is empty!\n");
        exit(0);
    }
    else if (pNode == NULL)
    {
        printf("The node is empty!\n");
        return 0;
    }
    else if (pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOFNode = 1;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOFNode++;
    }
    return 0;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    free(pLinkTable);
    return 0;
}

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if (pLinkTable == NULL)
    {
        printf("The table is empty!\n");
        exit(0);
    }
    return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if (pLinkTable == NULL)
    {
        printf("Error,The table is empty!\n");
        exit(0);
    }
    else if (pNode == NULL)
    {
        printf("Error,The node is empty!\n");
        exit(0);
    }
    return pNode->pNext;
} 
