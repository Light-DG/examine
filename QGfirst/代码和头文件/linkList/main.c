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
	   	printf("������ϣ�\n");
	   	menu();
	   }
	   else if(opnum==5)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
	   	int num=0;
	   	printf("Ҫ���� ��__����0~���ֵ�� �ڵ�֮�������룺");
		scanf("%d",&num);
		if(num<0)
		{
			printf("����ֵΪ������0������������\n\n");
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
			printf("�Ҳ����ýڵ㣬����������\n\n");
			continue; 
		}
	   	LNode *temp;
	   	temp=(LNode *)malloc(sizeof(LNode));
	   	printf("���������ڵ��ֵ��");
	   	scanf("%d",&(temp->data));
	   	InsertList(temp1,temp);
	   	printf("�������!\n");
	   	menu();
	   }
	   else if(opnum==6)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
	   	int num=0;
	   	printf("Ҫɾ�� ��__�� �ڵ㣿�����룺");
		scanf("%d",&num);
		if(num<=0)
		{
			printf("����ֵΪ����������������\n\n");
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
			printf("�Ҳ����ýڵ㣬����������\n\n");
			continue; 
		}
	   	int t;
	   	DeleteList(temp1,&t);
		printf("ɾ���ڵ�ɹ����ýڵ��ֵΪ%d\n",t); 
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
	   	int e=0;
	   	printf("��������Ҫ���ҵ�ֵ��");
	   	scanf("%d",&e);
	   	SearchList(head,e);
	   	menu();
	   }
	   else if(opnum==9)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
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
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
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
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
	   	LNode *temp;
	   	temp=FindMidNode(&head);
	   	printf("�м����ֵΪ%d\n",temp->data);
	   	menu();
	   }
	   else if(opnum==11)
	   {
	   	if(IsNull(head))
	   	{
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
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
	   		printf("�����������ٻ�δ��ʼ��������������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
	   		ReverseEvenList(&head);
	   		menu();
	   }
	   else
	   {
	   		printf("������1~13�����֣�\n");
		} 
		
		scanf("%d",&opnum);
	
    }
	
	return 0;
}

void menu()
    {
    	printf("\n\n*************************************************\n");
    	printf("*  1.��ʼ��                                      *\n");
    	printf("*  2.�����޻�����1->2->3->4->5->6��            *\n");
    	printf("*  3.�����л�����1->2->3->4->5->6->3��         *\n");
    	printf("*  4.��������                                    *\n");
    	printf("*  5.����ڵ�                                    *\n");
    	printf("*  6.ɾ���ڵ�                                    *\n");
    	printf("*  7.���ҽڵ�                                    *\n");
    	printf("*  8.��������ӡ����                              *\n");
    	printf("*  9.��ת����                                    *\n");
    	printf("*  10.�ҵ��м�ڵ�                               *\n");
    	printf("*  11..�ж��Ƿ��л�                              *\n"); 
    	printf("*  12..������żλ��                              *\n");
    	printf("*  13..�˳�                                      *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-13):");
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
	printf("�����޻�����!\n\n");
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
	printf("�����л�����!\n\n");
	return head;
	
}

int IsNull(LNode *head)
{
	return head==NULL;
 } 


