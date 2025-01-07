#include <stdio.h>

struct salary
{
char name[20];
char department[10];
struct navi
{
int basic_pay;
int da;
int hra;
int city_allowance;
} allowance;
};

int main()
{
	int i=  5;
    printf("%d %d %d %d", ++i, i, i++, ++i);
}
