#ifndef linktable_h
#define linktable_h

#include <stdio.h>
#include <pthread.h>

#define SUCESS 0
#define FAILURE -1

typedef struct LinkNode
{
    struct LinkNode * pNext;
}tLinkNode;

typedef struct LinkTable
{
    tLinkNode *pHead;
    tLinkNode *pTail;
    int SumOfNode;
}tLinkTable;

tLinkTable * CreateLinkTable();
int DeleteLinkTable(tLinkTable *pLinkTable);
int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);
int DelLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);
tLinkNode * GetLinkTableHead(tLinkTable * pLinkTable);
tLinkNode * GetLinkTableTail(tLinkTable * pLinkTable);
tLinkNode * GetNextLinkNode(tLinkTable * pLinkTable, tLinkNode * pNode);

#endif
