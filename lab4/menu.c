#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linktable.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int ShowAllCmd(tLinkTable *head)
int help();
int add();
int sub();
int mul();
int quit();

typedef struct DataNode
{
    tLinkNode * pNext;
    char* cmd;
    char* desc;
    int (*handler)();
}tDataNode;

tDataNode * FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode*)GetNextLinkNode(head, (tLinkNode*)pNode);
    }
    return NULL;
}
int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode = (tDataNode*)GetLinkHead(head);
    while(pNode !=NULL)
    {
        printf("%s--%s\n", pNode->cmd, pNode->desc);
        pNode=(tDataNode*)GetNextLinkNode(head, (tLinkNode*)pNode);
    }
    return 0;
}
static tDataNode menu[]=
{
    {(tLinkNode*)&menu[1], "version", "This is version 3.0", NULL},
    {(tLinkNode*)&menu[2], "help", "This is help cmd", help},
    {(tLinkNode*)&menu[3], "add", "This is add cmd", add},
    {(tLinkNode*)&menu[4], "sub", "This is sub cmd", sub},
    {(tLinkNode*)&menu[5], "sub", "This is mul cmd", mul},
    {(tLinkNode*)NULL, "quit", "This is quit cmd", quit}
};
int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    (*ppLinkTable)->pHead=(tLinkNode*)&menu[0];
    (*ppLinkTable)->pTail=(tLinkNode*)&menu[5];
    (*ppLinkTable)->SumOfNode=7;
}
tLinkTable *head = NULL;

int main()
{
    InitMenuData(&head);
    printf("Hello! Please enter 'help' to learn how to use.\n");
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("input a cmd: ");
        scanf("%s", cmd);
        tDataNode *p=FindCmd(head, cmd);
        printf("%d\n", head->SumOfNode);
        if(p == NULL)
        {
            printf("Wrong cmd!\n");
        }
        printf("%s--%s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}
int help()
{
    ShowAllCmd(head);
}
int add()
{
    int a, b, sum;
    printf("input 2 intergers: \n");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("%d + %d is %d\n", a, b, sum);
    return 0;
}
int sub()
{
    int a, b, sum;
    printf("input 2 intergers: \n");
    scanf("%d %d", &a, &b);
    sum = a - b;
    printf("%d - %d is %d\n", a, b, sum);
    return 0;
}
int mul()
{
    int a, b, sum;
    printf("input 2 intergers: \n");
    scanf("%d %d", &a, &b);
    sum = a * b;
    printf("%d * %d is %d\n", a, b, sum);
    return 0;
}
int quit()
{
    exit(0);
}
