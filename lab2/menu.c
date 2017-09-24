#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void plus();
void minus();
void mul();
void Div();
void max();
void min();
void hello();
void quit();

int main()
{
    char cmd[128];
    while(1)
    {
        printf("Please enter your command:\n");
	scanf("%s", cmd);
	if(strcmp(cmd,"plus") == 0)
	{
	    plus();
	}
	else if(strcmp(cmd,"minus") == 0)
	{
	    minus();
	}
	else if(strcmp(cmd,"mul") == 0)
	{
	    mul();
	}
	else if(strcmp(cmd,"Div") == 0)
	{
	    Div();
	}
	else if(strcmp(cmd,"max") == 0)
	{
	    max();
	}
	else if(strcmp(cmd,"min") == 0)
	{
	    min();
	}
	else if(strcmp(cmd,"hello") == 0)
	{
	    hello();
	}
	else if(strcmp(cmd,"quit") == 0)
	{
	    quit();
	}
	else 
	{
	    printf("It's a wrong command!\n");
	}
    }
}
void plus()
{
    int a,b,plus;
    printf("Please enter 2 intergers:\n");
    scanf("%d%d", &a,&b);
    plus = a + b;
    printf("%d plus %d is %d\n", a,b,plus);
};

void minus()
{
    int a,b,minus;
    printf("Please enter 2 intergers:\n");
    scanf("%d%d", &a,&b);
    minus = a - b;
    printf("%d minus %d is %d\n", a,b,minus);
};

void mul()
{
    int a,b,mul;
    printf("Please enter 2 intergers:\n");
    scanf("%d%d", &a,&b);
    mul = a * b;
    printf("%d mul %d is %d\n", a,b,mul);
};

void Div()
{
    float a,b;
    double Div;
    printf("Please enter 2 numbers:\n");
    scanf("%f%f", &a,&b);
    Div = a / b;
    printf("%f div %f is %f\n", a,b,Div);
};

void max()
{
    int a,b,max;
    printf("Please enter 2 intergers:\n");
    scanf("%d%d", &a,&b);
    if(a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    printf("Max of %d and %d is %d\n", a,b,max);
   
};

void min()
{
    int a,b,min;
    printf("Please enter 2 intergers:\n");
    scanf("%d%d", &a,&b);
    if(a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    printf("Min of %d and %d is %d\n", a,b,min); 
};

void hello()
{
    char name[255];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
};

void quit()
{
    exit(0);
};
