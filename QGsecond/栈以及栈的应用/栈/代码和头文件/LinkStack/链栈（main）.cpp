#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.cpp"
#include "LinkStack.h"


void menu();
int IsNull(LinkStack *s);
void myprint(LinkStack *s);

int main()
{
	
	LinkStack *s;
	s=NULL;
	int opnum;
	menu();
	scanf("%d",&opnum);
	while(opnum!=10)
	{
	   if(opnum==1)
	   {
	   	if(s==NULL)  s=(LinkStack *)malloc(sizeof(LinkStack));
	   	else         clearLStack(s); 
	   	initLStack(s); 
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
	   	if(s->top==NULL)
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
		if(SUCCESS==clearLStack(s))
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
		if(SUCCESS==getTopLStack(s,&item))
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
		if(SUCCESS==destroyLStack(s))
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
		int len=0;
		LStackLength(s,&len);
		printf("栈长度为%d\n",len);
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("请输入要入栈的值：");
		int item;
		scanf("%d",&item); 
		if(SUCCESS==pushLStack(s,item))
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
		if(s->top==NULL)
		{
			printf("栈空！无法弹出元素，可以使用入栈（指令7）\n\n");
			printf("请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
		 int item;
		 if(SUCCESS==popLStack(s,&item))
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

\
void myprint(LinkStack *s)
{
	if(s->top==NULL)
	{
		printf("栈空！");
		return; 
	}
	printf("栈如下：\n\n");
	StackNode *temp;
	temp=s->top;
	printf("top->");
	int count=0;
	while(temp!=NULL)
	{
		if(count>0) printf("     ");
		printf("%d\n",temp->data);
		temp=temp->next;
		count++;
	}
	printf("\n");
}

int IsNull(LinkStack *s)
{
	if(s==NULL)
	{
		printf("栈已销毁或未被初始化，请先初始化（指令1）\n");
		printf("请重新输入指令："); 
		return 1;
	}
	return 0;
}





