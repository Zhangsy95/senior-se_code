#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"

void Quit(int argc, char *argv[]);
void Version(int argc, char *argv[]);


void Quit(int argc, char *argv[])
{
    exit(0);
}

void Version(int argc, char *argv[])
{
    printf("version v7.0\n");
}


int main(int argc,char* argv[])
{
    MenuConfig("version","This is menu program v7.0 ",NULL);
    MenuConfig("quit","Quit from menu",Quit);

    ExecuteMenu();
}
