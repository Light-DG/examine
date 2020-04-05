#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.cpp"
#include "SqStack.h"

void menu();
void myprint(SqStack *s);
int IsNull(SqStack *s);


int main()
{	
	SqStack *s;
	s=NULL;
	int opnum;
	menu();
	scanf("%d",&opnum);
	while(opnum!=10)
	{
	   if(opnum==1)
	   {
	   	if(s==NULL)  s=(SqStack *)malloc(sizeof(SqStack));
	   	else         free(s->elem); 
	   	int sizes;
	   	printf("请输入栈的大小："); 
		scanf("%d",&sizes); 
	   	initStack(s,sizes); 
	   	printf("初始化成功！");
	   	menu();
	   }
	   else if(opnum==2)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	if(SUCCESS==isEmptyStack(s))
	   	{
	   		printf("栈空！\n"); 
		}
		else
		{
			printf("栈非空！\n");
		}
	   	menu();
	   }
	   else if(opnum==4)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(SUCCESS==clearStack(s))
		{
			printf("清空成功！\n"); 
		}
		else printf("清空失败！\n");
	   	menu();
	   }
	   else if(opnum==3)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	int item;
		if(SUCCESS==getTopStack(s,&item))
		{
			printf("栈顶值为%d\n",item);
		}
		else printf("获取失败,栈为空！\n");
	   	menu();
	   }
	   else if(opnum==5)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(SUCCESS==destroyStack(s))
		{
			printf("销毁成功！\n");
			s=NULL;
		}
		else printf("销毁失败！\n"); 
	   	menu();
	   }
	   else if(opnum==6)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("栈长度为%d\n",s->top+1);
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	if(s->top==s->size-1)
	   	{
	   		printf("栈已满！,可选择弹出栈顶元素（指令8）或清空栈（指令4）\n\n"); 
	   		printf("请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
		printf("请输入要入栈的值：");
		int item;
		scanf("%d",&item); 
		if(SUCCESS==pushStack(s,item))
		{
			printf("入栈成功！\n");
		}
	   	menu();
	   }
	   else if(opnum==8)
	   {
	   	 if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(s->top==-1)
		{
			printf("栈空！无法弹出元素，可以使用入栈（指令7）\n\n");
			printf("请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
		 int item;
		 if(SUCCESS==popStack(s,&item))
		 {
		 	printf("出栈成功！弹出值为%d\n",item);
		 }
	   	 menu();
	   }
	   else if(opnum==9)
	   {
	   	 if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	 myprint(s);
	   	 menu();
	   }
	   else
	   {
	   		printf("请输入1~10的数字！\n");
		} 

		scanf("%d",&opnum);
    }
	
	return 0;
 } 
 

void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.初始化                                      *\n");
    	printf("*  2.判断栈是否为空                              *\n");
    	printf("*  3.获取栈顶元素                                *\n");
    	printf("*  4.清空栈                                      *\n");
    	printf("*  5.销毁栈                                      *\n");
    	printf("*  6.检测栈的长度                                *\n");
    	printf("*  7.入栈                                        *\n");
    	printf("*  8.出栈                                        *\n");
    	printf("*  9.打印栈                                      *\n");
    	printf("*  10.退出                                       *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-10):");
	
}

void myprint(SqStack *s)
{
	if(s->top==-1)
	{
		printf("栈空！");
		return; 
	}
	printf("栈如下：\n\n");
	for(int i=s->top;i>-1;i--)
	{
		if(i==s->top)
		{
			printf("top->");
		}
		else
		{
			printf("     ");
		}
		printf("%d\n",s->elem[i]);
	}
	printf("\n");
}

int IsNull(SqStack *s)
{
	if(s==NULL)
	{
		printf("栈已销毁或未被初始化，可使用指令1\n");
		printf("请重新输入指令："); 
		return 1;
	}
	return 0;
}

 
 
