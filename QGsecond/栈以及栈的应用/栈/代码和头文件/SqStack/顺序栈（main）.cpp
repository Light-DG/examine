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
	   	printf("������ջ�Ĵ�С��"); 
		scanf("%d",&sizes); 
	   	initStack(s,sizes); 
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
	   	if(SUCCESS==isEmptyStack(s))
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
		if(SUCCESS==clearStack(s))
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
		if(SUCCESS==getTopStack(s,&item))
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
		if(SUCCESS==destroyStack(s))
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
		printf("ջ����Ϊ%d\n",s->top+1);
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
	   		printf("ջ������,��ѡ�񵯳�ջ��Ԫ�أ�ָ��8�������ջ��ָ��4��\n\n"); 
	   		printf("����������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
		printf("������Ҫ��ջ��ֵ��");
		int item;
		scanf("%d",&item); 
		if(SUCCESS==pushStack(s,item))
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
		if(s->top==-1)
		{
			printf("ջ�գ��޷�����Ԫ�أ�����ʹ����ջ��ָ��7��\n\n");
			printf("����������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
		 int item;
		 if(SUCCESS==popStack(s,&item))
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

void myprint(SqStack *s)
{
	if(s->top==-1)
	{
		printf("ջ�գ�");
		return; 
	}
	printf("ջ���£�\n\n");
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
		printf("ջ�����ٻ�δ����ʼ������ʹ��ָ��1\n");
		printf("����������ָ�"); 
		return 1;
	}
	return 0;
}

 
 
