#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"
#include "calculate.cpp"


int main()
{
	
	printf("\n该程序仅支持 个位整数(最开始的每个数) 之间的计算。\n");
	printf("请在英文输入法下输入。\n");
	int opnum;
	char *mid;
	menu();
	scanf("%d",&opnum);
	while(opnum!=2)
	{
	   if(opnum==1)
	   {
	   	printf("每位运算符间两边有 两个 个位数。");
	   	printf("\n中文输入法下可能导致异常。\n\n");
	   	printf("请输入中缀表达式：");
	   	mid=(char *)malloc(sizeof(char)*1000);
		scanf("%s",mid);
	    int len=strlen(mid);
	   	final_caculate(mid,len);
	   	free(mid);
	   	menu();
	   }
	   else
	   {
	   		printf("请输入1~2的数字！\n");
		} 

		scanf("%d",&opnum);
    }
	
	return 0;
 } 
 
 void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.计算                                        *\n");
    	printf("*  2.退出                                        *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-2):");
}
 
 
