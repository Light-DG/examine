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
	   	printf("Ҫ���� ��__�� �ڵ�֮ǰ�������룺");
		scanf("%d",&num);
		if(num==0)
		{
			printf("������ͷ���ǰ���룬����������\n\n");
			continue;
		}
		if(num<0)
		{
			printf("����ֵΪ����������������\n\n");
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
			printf("�Ҳ����ýڵ㣬����������\n\n");
			continue; 
		}
		DuLNode *temp2;
		temp2=(DuLNode *)malloc(sizeof(DuLNode));
		printf("���������ڵ��ֵ��");
		scanf("%d",&(temp2->data));
		Status ret=InsertBeforeList_DuL(temp1, temp2);
		if(ret==SUCCESS) printf("����ɹ���\n");
	   	menu();
	   }
	   else if(opnum==3)
	   {
	   	DestroyList_DuL(&head);
	   	printf("������ϣ�\n");
	   	menu();
	   }
	   else if(opnum==5)
	   {
	   	int num=0;
	   	printf("Ҫ���� ��__����0~���ֵ�� �ڵ�֮�������룺");
		scanf("%d",&num);
		if(num<0)
		{
			printf("����ֵΪ������0������������\n\n");
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
			printf("�Ҳ����ýڵ㣬����������\n\n");
			continue; 
		}
		DuLNode *temp2;
		temp2=(DuLNode *)malloc(sizeof(DuLNode));
		printf("���������ڵ��ֵ��");
		scanf("%d",&(temp2->data));
		InsertAfterList_DuL(temp1, temp2);
		printf("����ɹ���\n");
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
	   	printf("Ҫɾ�� ��__����1~���ֵ�� �ڵ㣿�����룺");
		scanf("%d",&num);
		if(num<0)
		{
			printf("����ֵΪ����������������\n\n");
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
			printf("�Ҳ����ýڵ㣬����������\n\n");
			continue; 
		}
		int e; 
	   	DeleteList_DuL(temp1, &e); 
	   	printf("ɾ���ڵ�ɹ����ýڵ��ֵΪ%d\n",e);
	   	menu();
	   }
	   else
	   {
	   		printf("������1~8�����֣�\n");
		} 
		
		scanf("%d",&opnum);
	
    }
	
	return 0;	
}

void menu()
    {
    	printf("\n\n*************************************************\n");
    	printf("*  1.��ʼ��                                      *\n");
    	printf("*  2.��������1<->2<->3<->4<->5<->6��           *\n");
    	printf("*  3.��������                                    *\n");
    	printf("*  4.����ڵ㣨ǰ�壩                            *\n");
    	printf("*  5.����ڵ㣨��壩                            *\n");
    	printf("*  6.��������ӡ����                              *\n");
    	printf("*  7.ɾ���ڵ�                                    *\n");
    	printf("*  8.�˳�                                        *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-8):");
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




