#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"
#include "LQueue.cpp"
#include "AQueue.cpp"
#include "AQueue.h"

#define MAXQUEUE 10

void menu01(); 
void menu02();
void menu03(); 
int plan01();
int plan02();
int AIsNull(Aqueue *q);
int LIsNull(Lqueue *q); 

int main()
{
	//freopen("input.txt","r",stdin);
	int firstnum;
	menu01();
	scanf("%d",&firstnum);
	int judge;
	while(firstnum!=3)
	{
		if(firstnum==1)
		{
			if(plan01()==1) break;
		}
		else if(firstnum==2)
		{
			if(plan02()==1) break;
		}
		else if(firstnum==3)
		{
			break;
		}
		else
		{
			printf("������1~3������!\n"); 
		}
		menu01();
		scanf("%d",&firstnum);
	}
	
	
	return 0;
}

void menu01()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.ʹ����ʽ����                                *\n");
    	printf("*  2.ʹ��˳�����(���10��Ԫ��)                  *\n");
    	printf("*  3.�˳�                                        *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-3):");
}

void menu02()
{
	printf("\n\n*************************************************\n");
		printf("*  1.��ʼ��                                      *\n");
		printf("*  2.�ж϶����Ƿ�Ϊ��                            *\n");
		printf("*  3.��ȡ�����׸�Ԫ��                            *\n");
		printf("*  4.��ն���                                    *\n");
		printf("*  5.���ٶ���                                    *\n");
		printf("*  6.�����еĳ���                              *\n");
		printf("*  7.���                                        *\n");
		printf("*  8.����                                        *\n");
		printf("*  9.��������ӡ                                  *\n");
		printf("*  10.�˳�                                       *\n");
		printf("*  11.�Ż���һ��                                 *\n");
		printf("*************************************************\n\n");
		printf("������ָ����(1-11):");
	
}

void menu03()
{
	printf("\n\n*************************************************\n");
		printf("*  1.��ʼ��                                      *\n");
		printf("*  2.�ж϶����Ƿ�Ϊ��                            *\n");
		printf("*  3.�ж϶����Ƿ�����                            *\n");
		printf("*  4.��ȡ�����׸�Ԫ��                            *\n");
		printf("*  5.��ն���                                    *\n");
		printf("*  6.���ٶ���                                    *\n");
		printf("*  7.�����еĳ���                              *\n");
		printf("*  8.���                                        *\n");
		printf("*  9.����                                        *\n");
		printf("*  10.��������ӡ                                 *\n");
		printf("*  11.�˳�                                       *\n");
		printf("*  12.�Ż���һ��                                 *\n");
		printf("*************************************************\n\n");
		printf("������ָ����(1-12):");
	
}


int plan01()
{
	menu02();
	int opnum;
	scanf("%d",&opnum);
	Lqueue *q;
	q=NULL; 
	while(opnum!=11)
	{
		if(opnum==1)
	   {
	   	if(q==NULL)  q=(Lqueue *)malloc(sizeof(Lqueue));
	   	else         ClearLQueue(q); 
	   	InitLQueue(q); 
	   	printf("��ʼ���ɹ���");
	   	menu02();
	   }
	   else if(opnum==2)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	if(q->length==0)
	   	{
	   		printf("���пգ�\n"); 
		}
		else
		{
			printf("���зǿգ�\n");
		}
	   	menu02();
	   }
	   else if(opnum==4)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("�ѿ�\n");
			menu02();
			scanf("%d",&opnum);
	   		continue;
		}
		ClearLQueue(q);
		printf("��ճɹ���\n"); 
	   	menu02();
	   }
	   else if(opnum==3)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("����Ϊ�գ�,��ʹ�����ָ��(ָ��7)\n"); 
			menu02();
			scanf("%d",&opnum);
			continue;
		}
		type = q->front->next->type;
			if(type=='i')
			{
				int temp;
				if(TRUE==GetHeadLQueue(q,&temp))
				{
					printf("����Ϊ%d\n",temp);
				}
			}
			else if(type=='d')
			{
				double temp;
				if(TRUE==GetHeadLQueue(q,&temp))
				{
					printf("����Ϊ%f\n",temp);
				}
			}
			else if(type=='c')
			{
				char temp;
				if(TRUE==GetHeadLQueue(q,&temp))
				{
					printf("����Ϊ%c\n",temp);
				}
			}
			else if(type=='s')
			{
				char **temp;
				temp=(char **)malloc(sizeof(char *));
				if(TRUE==GetHeadLQueue(q,temp))
				{
					printf("����Ϊ%s\n",*temp);
				}
			}
	   	menu02();
	   }
	   else if(opnum==5)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		DestoryLQueue(q);
		q=NULL;
		printf("���ٳɹ���\n");
	   	menu02();
	   }
	   else if(opnum==6)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("���г���Ϊ%d\n",LengthLQueue(q));
	   	menu02();
	   }
	   else if(opnum==7)
	   {
	   		if(LIsNull(q))
		   	{
		   		scanf("%d",&opnum);
		   		continue;
			}
			int num;
			printf("������Ҫ��Ӧ�������͵� ��ţ�ѡ�����£�\n");
			printf("1,����int  2,������double  3,�ַ�char  4,�ַ���String\n�����룺");
			scanf("%d",&num);
			int *i;
			double *d;
			char *c;
			char *s;
			while(1)
			{
			if(num==1)
			{
				i = (int *)malloc(sizeof(int));
				printf("������Ҫ�����ֵ��");
				scanf("%d",i);
				type='i';
				EnLQueue(q,i); 
				break;
			}
			else if(num==2)
			{
				d = (double *)malloc(sizeof(double));
				printf("������Ҫ�����ֵ��");
				scanf("%lf",d);
				type='d';
				EnLQueue(q,d); 
				break;
			}
			else if(num==3)
			{
				c = (char *)malloc(sizeof(char)*200);
				printf("������Ҫ������ַ���");
				scanf("%s",c);
				type = 'c';
				EnLQueue(q,c);
				if(strlen(c)>1)
				{
					printf("\n***��ע�⣬�˴�ӦΪ�ַ����룬�ѽ��������ַ��������ַ����롣***\n");
				}
				break;
			}
			else if(num==4)
			{
				printf("�ַ����Ϊ200��\n");
				s = (char *)malloc(sizeof(char)*200);
				printf("������Ҫ������ַ�����");
				scanf("%s",s);
				type='s';
				EnLQueue(q,s); 
				break;
			}
			else
			{
				printf("������1~4�����ӡ�\n���������룺");
				scanf("%d",&num); 
			}	
			}
			
			printf("��ӳɹ���\n");
			menu02();
		} 
	   else if(opnum==8)
	   {
	   	 if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("���пգ��޷����ӣ�����ʹ����ӣ�ָ��7��\n\n");
			menu02();
			printf("����������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
		 if(TRUE==DeLQueue(q))
		 {
		 	printf("���ӳɹ���");
		 }
	   	 menu02();
		
	   }
	   else if(opnum==9)
	   {
	   	 if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("����Ϊ�գ�\n"); 
		}
		else
		{
			TraverseLQueue(q,LPrint);
		}
		menu02();
	   }
	   else if(opnum==10)
		{
			DestoryLQueue(q);
			q=NULL;
			return 1;
		}
	   else
	   {
	   		printf("������1~11�����֣�\n");
		} 

		scanf("%d",&opnum);
    
	}
}


int plan02()
{
	menu03();
	int opnum;
	scanf("%d",&opnum);
	Aqueue *q;
	q=NULL; 
	while(opnum!=12)
	{
		if(opnum==1)
	   {
	   	if(q==NULL)  q=(Aqueue *)malloc(sizeof(Aqueue));
	   	else         ClearAQueue(q); 
	   	InitAQueue(q); 
	   	printf("��ʼ���ɹ���");
	   	menu03();
	   }
	   else if(opnum==2)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
	   	if(q->length==0)
	   	{
	   		printf("���пգ�\n"); 
		}
		else
		{
			printf("���зǿգ�\n");
		}
	   	menu03();
	   }
	   else if(opnum==3)
	   {
	   		if(AIsNull(q))
		   	{
		   		scanf("%d",&opnum);
		   		continue;
			}
	   	 if(TRUE==IsFullAQueue(q))
	   	 {
	   	 	printf("����������\n");
		 }
		 else
		 {
		 	printf("����δ����\n");	
		 }
		 menu03();
	   }
	   else if(opnum==5)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		ClearAQueue(q);
		printf("��ճɹ���\n"); 
	   	menu03();
	   }
	   else if(opnum==4)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("����Ϊ�գ�,��ʹ�����ָ��(ָ��7)\n"); 
			menu03();
			scanf("%d",&opnum);
			continue;
		}
		type = datatype[q->front];
			if(type=='i')
			{
				int temp;
				if(TRUE==GetHeadAQueue(q,&temp))
				{
					printf("����Ϊ%d\n",temp);
				}
			}
			else if(type=='d')
			{
				double temp;
				if(TRUE==GetHeadAQueue(q,&temp))
				{
					printf("����Ϊ%f\n",temp);
				}
			}
			else if(type=='c')
			{
				char temp;
				if(TRUE==GetHeadAQueue(q,&temp))
				{
					printf("����Ϊ%c\n",temp);
				}
			}
			else if(type=='s')
			{
				char **temp;
				temp=(char **)malloc(sizeof(char *));
				if(TRUE==GetHeadAQueue(q,temp))
				{
					printf("����Ϊ%s\n",*temp);
				}
			}
	   	menu03();
	   }
	   else if(opnum==6)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		DestoryAQueue(q);
		q=NULL;
		printf("���ٳɹ���\n");
	   	menu03();
	   }
	   else if(opnum==7)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("���г���Ϊ%d\n",LengthAQueue(q));
	   	menu03();
	   }
	   else if(opnum==8)
	   {
	   		if(AIsNull(q))
		   	{
		   		scanf("%d",&opnum);
		   		continue;
			}
			if(q->length==MAXQUEUE)
			{
				printf("����������\n����������ָ��");
				menu03();
				scanf("%d",&opnum);
				continue;
			 } 
			int num;
			printf("������Ҫ��Ӧ�������͵� ��ţ�ѡ�����£�\n");
			printf("1,����int  2,������double  3,�ַ�char  4,�ַ���String\n�����룺");
			scanf("%d",&num);
			int *i;
			double *d;
			char *s;
			char *c;
			while(1)
			{
				if(num==1)
				{
					i = (int *)malloc(sizeof(int));
					printf("������Ҫ�����ֵ��");
					scanf("%d",i);
					datatype[(q->rear+1)%MAXQUEUE]='i';
					EnAQueue(q,i); 
					break;
				}
				else if(num==2)
				{
					d = (double *)malloc(sizeof(double));
					printf("������Ҫ�����ֵ��");
					scanf("%lf",d);
					datatype[(q->rear+1)%MAXQUEUE]='d';
					EnAQueue(q,d); 
					break;
				}
				else if(num==3)
				{
					c = (char *)malloc(sizeof(char)*200);
					printf("������Ҫ������ַ���");
					scanf("%s",c);
					datatype[(q->rear+1)%MAXQUEUE]='c';
					EnAQueue(q,c);
					if(strlen(c)>1)
					{
						printf("\n***��ע�⣬�˴�ӦΪ�ַ����룬�ѽ��������ַ��������ַ����롣***\n");
					}
					break;
				}
				else if(num==4)
				{
					printf("�ַ����Ϊ200��\n");
					s = (char *)malloc(sizeof(char)*200);
					printf("������Ҫ������ַ�����");
					scanf("%s",s);
					datatype[(q->rear+1)%MAXQUEUE]='s';
					EnAQueue(q,s);
					break;
				}
				else
				{
					printf("������1~4�����֡�\n���������룺");
					scanf("%d",&num);
				}
			}
			
			printf("��ӳɹ���\n");
			menu03();
		} 
	   else if(opnum==9)
	   {
	   	 if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("���пգ��޷����ӣ�����ʹ����ӣ�ָ��7��\n\n");
			menu03();
			printf("����������ָ�");
			scanf("%d",&opnum);
			continue; 
		}
		 
		 if(TRUE==DeAQueue(q))
		 {
		 	printf("���ӳɹ���");
		 }
	   	 menu03();
	   }
	   else if(opnum==10)
	   {
	   	 if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		if(q->length==0)
		{
			printf("����Ϊ�գ�\n"); 
		}
		TraverseAQueue(q,APrint);
		menu03();
	   }
	   else if(opnum==11)
		{
			DestoryAQueue(q);
			q=NULL;
			return 1;
		}
	   else
	   {
	   		printf("������1~12�����֣�\n");
		} 

		scanf("%d",&opnum);
    
	
	}	
}

int AIsNull(Aqueue *q)
{
	if(q==NULL)
	{
		printf("���������ٻ�δ����ʼ�������ȳ�ʼ����ָ��1��\n");
		printf("����������ָ�"); 
		return 1;
	}
	return 0;
}

int LIsNull(Lqueue *q)
{
	if(q==NULL)
	{
		printf("���������ٻ�δ����ʼ�������ȳ�ʼ����ָ��1��\n");
		printf("����������ָ�"); 
		return 1;
	}
	return 0;
}





