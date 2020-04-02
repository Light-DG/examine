#include "linkedList.h"
#include "linkedList.c"
#include <stdio.h> 
#include <stdlib.h>

void menu();
LNode *list1(LNode *head);
LNode *list2(LNode *head);
int IsNull(LNode *head); 

int main()
{
	menu();
	int opnum=0;
	scanf("%d",&opnum);
	LNode *head=NULL;
	
	while(opnum!=13)
	{
	   if(opnum==1)
	   {
	   	InitList(&head);
	   	menu();
	   }
	   else if(opnum==2)
	   {
	   	head=list1(head);
	   	menu();
	   }
	   else if(opnum==3)
	   {
	   	head=list2(head);
	   	menu();
	   }
	   else if(opnum==4)
	   {
	   	DestroyList(&head);
	   	printf("销毁完毕！\n");
	   	menu();
	   }
	   else if(opnum==5)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	int num=0;
	   	printf("要插在 第__个（0~最大值） 节点之后？请输入：");
		scanf("%d",&num);
		if(num<0)
		{
			printf("输入值为正数或0，请重新输入\n\n");
			continue; 
		}
		LNode *temp1;
		temp1=head;
		int i=0;
		for(i=0;temp1&&i<num;i++)
		{
			temp1=temp1->next;
		}
		if(temp1==NULL)
		{
			printf("找不到该节点，请重新输入\n\n");
			continue; 
		}
	   	LNode *temp;
	   	temp=(LNode *)malloc(sizeof(LNode));
	   	printf("请输入插入节点的值：");
	   	scanf("%d",&(temp->data));
	   	InsertList(temp1,temp);
	   	printf("插入完毕!\n");
	   	menu();
	   }
	   else if(opnum==6)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	int num=0;
	   	printf("要删除 第__个 节点？请输入：");
		scanf("%d",&num);
		if(num<=0)
		{
			printf("输入值为正数，请重新输入\n\n");
			continue; 
		}
		LNode *temp1;
		temp1=head;
		int i=0;
		for(i=0;temp1&&i<num-1;i++)
		{
			temp1=temp1->next;
		}
		if(temp1==NULL)
		{
			printf("找不到该节点，请重新输入\n\n");
			continue; 
		}
	   	int t;
	   	DeleteList(temp1,&t);
		printf("删除节点成功！该节点的值为%d\n",t); 
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	int e=0;
	   	printf("请输入你要查找的值：");
	   	scanf("%d",&e);
	   	SearchList(head,e);
	   	menu();
	   }
	   else if(opnum==9)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	ReverseList(&head);
	   	menu();
	   }
	   else if(opnum==8)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	 TraverseList(head,visit); 
	   	 menu();
	   }
	   else if(opnum==10)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	LNode *temp;
	   	temp=FindMidNode(&head);
	   	printf("中间结点的值为%d\n",temp->data);
	   	menu();
	   }
	   else if(opnum==11)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   	 IsLoopList(head);
	   	 menu();
	   }
	   else if(opnum==12)
	   {
	   		if(IsNull(head))
	   	{
	   		printf("该链表已销毁或未初始化，请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
	   		ReverseEvenList(&head);
	   		menu();
	   }
	   else
	   {
	   		printf("请输入1~13的数字！\n");
		} 
		
		scanf("%d",&opnum);
	
    }
	
	return 0;
}

void menu()
    {
    	printf("\n\n*************************************************\n");
    	printf("*  1.初始化                                      *\n");
    	printf("*  2.生成无环链表（1->2->3->4->5->6）            *\n");
    	printf("*  3.生成有环链表（1->2->3->4->5->6->3）         *\n");
    	printf("*  4.销毁链表                                    *\n");
    	printf("*  5.插入节点                                    *\n");
    	printf("*  6.删除节点                                    *\n");
    	printf("*  7.查找节点                                    *\n");
    	printf("*  8.遍历并打印链表                              *\n");
    	printf("*  9.反转链表                                    *\n");
    	printf("*  10.找到中间节点                               *\n");
    	printf("*  11..判断是否有环                              *\n"); 
    	printf("*  12..交换奇偶位置                              *\n");
    	printf("*  13..退出                                      *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-13):");
	}
	
LNode *list1(LNode *head)
{
	InitList(&head);
	LNode *temp;
	int a=6;
	int i=0;
	for(i=0;i<6;i++)
	{
		temp=(LNode *)malloc(sizeof(LNode));
		temp->data=a--;
		InsertList(head,temp);
	}
	printf("生成无环链表!\n\n");
	return head;
}

LNode *list2(LNode *head)
{
	InitList(&head);
	LNode *temp,*temp2,*rear;
	int a=6;
	int i=0;
	for(i=0;i<6;i++)
	{
		temp=(LNode *)malloc(sizeof(LNode));
		temp->data=a--;
		if(temp->data==6)
		{
			rear=temp;
		}
		if(temp->data==3)
		{
			temp2=temp;
		}
		InsertList(head,temp);
	}
	rear->next=temp2;
	printf("生成有环链表!\n\n");
	return head;
	
}

int IsNull(LNode *head)
{
	return head==NULL;
 } 


