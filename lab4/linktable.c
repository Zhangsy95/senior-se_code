#include <stdio.h>
#include "linktable.h"
#include <stdlib.h>
tLinkTable * CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
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

int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode)
{
    if(pLinkTable == NULL||pNode == NULL)
    {
        return -1;
       
    }
    pNode->pNext = NULL;

    if(pLinkTable->pHead == NULL)
	pLinkTable->pHead=pNode;
    
    else
    {
        pLinkTable->pTail->pNext = pNode;
	pLinkTable->pTail = pLinkTable->pTail->pNext;
    }
    pLinkTable->SumOfNode++;
    return 0;
}

int DelLinkNode(tLinkTable * pLinkTable, tLinkNode * pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
        return -1;
    tLinkNode * p=pLinkTable->pHead;
    if(pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead=pLinkTable->pHead->pNext;
	free(p);
	pLinkTable->SumOfNode--;
    }
    if(pLinkTable->SumOfNode == 0)
    {
	pLinkTable->pTail=NULL;
    }
    return 0;
    while(p != NULL)
    {
	if(p->pNext == pNode)
	{
	    tLinkNode * q=p->pNext;
	    p->pNext=p->pNext->pNext;
	    free(q);
	    pLinkTable->SumOfNode--;
	    if(pLinkTable->SumOfNode == 0)
		{
		    pLinkTable->pTail=NULL;
		}
	    return 0;
	}
	p=p->pNext;
    }
    return -1;
}

tLinkNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL || pLinkTable->pHead == NULL)
    {
        return NULL;
    }
    return pLinkTable->pHead;
}

tLinkNode * GetLinkTableTail(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL || pLinkTable->pTail == NULL)
    {
        return NULL;
    }
    return pLinkTable->pTail;
}


tLinkNode * GetNextLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    
    tLinkNode * p=pLinkTable->pHead;
    while(p !=NULL)
    {
	if(p == pNode)
	{
	    return p->pNext;
	}
	p=p->pNext;
    }
    return NULL;
}
