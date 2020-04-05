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
	   	printf("��ʼ���ɹ���");
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
	   		printf("ջ�գ�\n"); 
		}
		else
		{
			printf("ջ�ǿգ�\n");
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
			printf("��ճɹ���\n"); 
		}
		else printf("���ʧ�ܣ�\n");
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
			printf("ջ��ֵΪ%d\n",item);
		}
		else printf("��ȡʧ��,ջΪ�գ�\n");
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
			printf("���ٳɹ���\n");
			s=NULL;
		}
		else printf("����ʧ�ܣ�\n"); 
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
		printf("ջ����Ϊ%d\n",len);
	   	menu();
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(s))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("������Ҫ��ջ��ֵ��");
		int item;
		scanf("%d",&item); 
		if(SUCCESS==pushLStack(s,item))
		{
			printf("��ջ�ɹ���\n");
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
			printf("ջ�գ��޷�����Ԫ�أ�����ʹ����ջ��ָ��7��\n\n");
			printf("����������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
		 int item;
		 if(SUCCESS==popLStack(s,&item))
		 {
		 	printf("��ջ�ɹ�������ֵΪ%d\n",item);
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
	   		printf("������1~10�����֣�\n");
		} 

		scanf("%d",&opnum);
    }
	
	return 0;
}

void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.��ʼ��                                      *\n");
    	printf("*  2.�ж�ջ�Ƿ�Ϊ��                              *\n");
    	printf("*  3.��ȡջ��Ԫ��                                *\n");
    	printf("*  4.���ջ                                      *\n");
    	printf("*  5.����ջ                                      *\n");
    	printf("*  6.���ջ�ĳ���                                *\n");
    	printf("*  7.��ջ                                        *\n");
    	printf("*  8.��ջ                                        *\n");
    	printf("*  9.��ӡջ                                      *\n");
    	printf("*  10.�˳�                                       *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-10):");
	
}

\
void myprint(LinkStack *s)
{
	if(s->top==NULL)
	{
		printf("ջ�գ�");
		return; 
	}
	printf("ջ���£�\n\n");
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
		printf("ջ�����ٻ�δ����ʼ�������ȳ�ʼ����ָ��1��\n");
		printf("����������ָ�"); 
		return 1;
	}
	return 0;
}





