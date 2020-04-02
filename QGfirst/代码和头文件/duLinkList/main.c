#include "duLinkedList.c"
#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


void menu();
DuLNode *list1(DuLNode *head);

int main()
{
	menu();
	int opnum=0;
	scanf("%d",&opnum);
	DuLNode *head;
	head=(DuLNode *)malloc(sizeof(DuLNode));
	head->prior=head->next=NULL;
	while(opnum!=8)
	{
	   if(opnum==1)
	   {
	   	InitList_DuL(&head);
	   	menu();
	   }
	   else if(opnum==2)
	   {
	   	InitList_DuL(&head);
	   	head=list1(head);
	   	menu();
	   }
	   else if(opnum==4)
	   {
	   	int num=0;
	   	printf("要插在 第__个 节点之前？请输入：");
		scanf("%d",&num);
		if(num==0)
		{
			printf("不能在头结点前插入，请重新输入\n\n");
			continue;
		}
		if(num<0)
		{
			printf("输入值为正数，请重新输入\n\n");
			continue; 
		}
		DuLNode *temp1;
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
		DuLNode *temp2;
		temp2=(DuLNode *)malloc(sizeof(DuLNode));
		printf("请输入插入节点的值：");
		scanf("%d",&(temp2->data));
		Status ret=InsertBeforeList_DuL(temp1, temp2);
		if(ret==SUCCESS) printf("插入成功！\n");
	   	menu();
	   }
	   else if(opnum==3)
	   {
	   	DestroyList_DuL(&head);
	   	printf("销毁完毕！\n");
	   	menu();
	   }
	   else if(opnum==5)
	   {
	   	int num=0;
	   	printf("要插在 第__个（0~最大值） 节点之后？请输入：");
		scanf("%d",&num);
		if(num<0)
		{
			printf("输入值为正数或0，请重新输入\n\n");
			continue; 
		}
		DuLNode *temp1;
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
		DuLNode *temp2;
		temp2=(DuLNode *)malloc(sizeof(DuLNode));
		printf("请输入插入节点的值：");
		scanf("%d",&(temp2->data));
		InsertAfterList_DuL(temp1, temp2);
		printf("插入成功！\n");
	   	menu();
	   }
	   else if(opnum==6)
	   {
	   	TraverseList_DuL(head, visit);
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	int num=0;
	   	printf("要删除 第__个（1~最大值） 节点？请输入：");
		scanf("%d",&num);
		if(num<0)
		{
			printf("输入值为正数，请重新输入\n\n");
			continue; 
		}
		DuLNode *temp1;
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
		int e; 
	   	DeleteList_DuL(temp1, &e); 
	   	printf("删除节点成功！该节点的值为%d\n",e);
	   	menu();
	   }
	   else
	   {
	   		printf("请输入1~8的数字！\n");
		} 
		
		scanf("%d",&opnum);
	
    }
	
	return 0;	
}

void menu()
    {
    	printf("\n\n*************************************************\n");
    	printf("*  1.初始化                                      *\n");
    	printf("*  2.生成链表（1<->2<->3<->4<->5<->6）           *\n");
    	printf("*  3.销毁链表                                    *\n");
    	printf("*  4.插入节点（前插）                            *\n");
    	printf("*  5.插入节点（后插）                            *\n");
    	printf("*  6.遍历并打印链表                              *\n");
    	printf("*  7.删除节点                                    *\n");
    	printf("*  8.退出                                        *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-8):");
	}
	
DuLNode *list1(DuLNode *head)
{
	DuLNode *temp;
	int i=0;
	int a=6;
	for(i=0;i<6;i++)
	{
		temp=(DuLNode *)malloc(sizeof(DuLNode));
		temp->data=a--;
		InsertAfterList_DuL(head,temp);
	}
	return head;
	
}




