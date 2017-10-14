#ifndef linktable_h
#define linktable_h

#include <stdio.h>
#include <pthread.h>

#define SUCESS 0
#define FAILURE (-1)

typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOfNode;
}tLinkTable;

tLinkTable * CreateLinkTable();
int DeleteLinkTable(tLinkTable *pLinkTable);
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
int DeleteLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

#endif
