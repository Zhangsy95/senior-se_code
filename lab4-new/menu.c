#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linktable.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int help();
int quit();

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;

int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    tDataNode *pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "all menu functions:";
    pNode->handler = help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode=(tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "menu program v3.0";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "quit from menu";
    pNode->handler = quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    return 0;
}

tLinkTable *head = NULL;

int ShowAllCmd(tLinkTable *head)
{
    printf("This is menu:\n");
    tDataNode *p = (tDataNode*)GetLinkTableHead(head);
    while(p != NULL)
    {
	printf("%s--%s\n",p->cmd,p->desc);
	p = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)p);
    }
    return 0;
}

tDataNode *FindCmd(tLinkTable *head,char *cmd)
{
    tDataNode *p = (tDataNode*)GetLinkTableHead(head);
    while(p != NULL)
    {
	if(strcmp(p->cmd,cmd) == 0)
	{
	    return p;
	}
	p = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)p);
    }
    return NULL;
}

int main()
{
    InitMenuData(&head);
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("Please input a cmd :");
	scanf("%s",cmd);
	tDataNode *p = FindCmd(head,cmd);
	if (p == NULL)
	{
	    printf("Wrong cmd!\n");
	    continue;
	}

	if(p->handler!=NULL)
	{
	    p->handler();
	}
    }
}

int help()
{
    ShowAllCmd(head);
    return 0;
}

int quit()
{
    exit(0);
}
