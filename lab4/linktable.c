#include <stdio.h>
#include "linktable.h"
#include <stdlib.h>
tLinkTable * CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkLinkTable == NULL)
        return NULL;
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;

    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{   
    if(pLinkTable == NULL)
	return FAILURE;
    while(pLinkTable->pHead != NULL)
    {
        tLinkNode* pNode = pLinkTable->pHead;
	pLinkTable->pHead = pLinkTable->pHead->pNext;
	free(pNode);
	pLinkTable->SumOfNode--;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    free(pLinkTable);
    free(pLinkTable);
    return  SUCESS;       
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
