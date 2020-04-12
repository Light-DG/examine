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
			printf("请输入1~3的数字!\n"); 
		}
		menu01();
		scanf("%d",&firstnum);
	}
	
	
	return 0;
}

void menu01()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.使用链式队列                                *\n");
    	printf("*  2.使用顺序队列(最多10个元素)                  *\n");
    	printf("*  3.退出                                        *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-3):");
}

void menu02()
{
	printf("\n\n*************************************************\n");
		printf("*  1.初始化                                      *\n");
		printf("*  2.判断队列是否为空                            *\n");
		printf("*  3.获取队列首个元素                            *\n");
		printf("*  4.清空队列                                    *\n");
		printf("*  5.销毁队列                                    *\n");
		printf("*  6.检测队列的长度                              *\n");
		printf("*  7.入队                                        *\n");
		printf("*  8.出队                                        *\n");
		printf("*  9.遍历并打印                                  *\n");
		printf("*  10.退出                                       *\n");
		printf("*  11.放回上一级                                 *\n");
		printf("*************************************************\n\n");
		printf("请输入指令编号(1-11):");
	
}

void menu03()
{
	printf("\n\n*************************************************\n");
		printf("*  1.初始化                                      *\n");
		printf("*  2.判断队列是否为空                            *\n");
		printf("*  3.判断队列是否已满                            *\n");
		printf("*  4.获取队列首个元素                            *\n");
		printf("*  5.清空队列                                    *\n");
		printf("*  6.销毁队列                                    *\n");
		printf("*  7.检测队列的长度                              *\n");
		printf("*  8.入队                                        *\n");
		printf("*  9.出队                                        *\n");
		printf("*  10.遍历并打印                                 *\n");
		printf("*  11.退出                                       *\n");
		printf("*  12.放回上一级                                 *\n");
		printf("*************************************************\n\n");
		printf("请输入指令编号(1-12):");
	
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
	   	printf("初始化成功！");
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
	   		printf("队列空！\n"); 
		}
		else
		{
			printf("队列非空！\n");
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
			printf("已空\n");
			menu02();
			scanf("%d",&opnum);
	   		continue;
		}
		ClearLQueue(q);
		printf("清空成功！\n"); 
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
			printf("队列为空！,可使用入队指令(指令7)\n"); 
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
					printf("队首为%d\n",temp);
				}
			}
			else if(type=='d')
			{
				double temp;
				if(TRUE==GetHeadLQueue(q,&temp))
				{
					printf("队首为%f\n",temp);
				}
			}
			else if(type=='c')
			{
				char temp;
				if(TRUE==GetHeadLQueue(q,&temp))
				{
					printf("队首为%c\n",temp);
				}
			}
			else if(type=='s')
			{
				char **temp;
				temp=(char **)malloc(sizeof(char *));
				if(TRUE==GetHeadLQueue(q,temp))
				{
					printf("队首为%s\n",*temp);
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
		printf("销毁成功！\n");
	   	menu02();
	   }
	   else if(opnum==6)
	   {
	   	if(LIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("队列长度为%d\n",LengthLQueue(q));
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
			printf("请输入要对应数据类型的 标号，选择如下：\n");
			printf("1,整形int  2,浮点型double  3,字符char  4,字符串String\n请输入：");
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
				printf("请输入要输入的值：");
				scanf("%d",i);
				type='i';
				EnLQueue(q,i); 
				break;
			}
			else if(num==2)
			{
				d = (double *)malloc(sizeof(double));
				printf("请输入要输入的值：");
				scanf("%lf",d);
				type='d';
				EnLQueue(q,d); 
				break;
			}
			else if(num==3)
			{
				c = (char *)malloc(sizeof(char)*200);
				printf("请输入要输入的字符：");
				scanf("%s",c);
				type = 'c';
				EnLQueue(q,c);
				if(strlen(c)>1)
				{
					printf("\n***请注意，此处应为字符输入，已将所输入字符串的首字符存入。***\n");
				}
				break;
			}
			else if(num==4)
			{
				printf("字符串最长为200。\n");
				s = (char *)malloc(sizeof(char)*200);
				printf("请输入要输入的字符串：");
				scanf("%s",s);
				type='s';
				EnLQueue(q,s); 
				break;
			}
			else
			{
				printf("请输入1~4的数子。\n请重新输入：");
				scanf("%d",&num); 
			}	
			}
			
			printf("入队成功！\n");
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
			printf("队列空！无法出队，可以使用入队（指令7）\n\n");
			menu02();
			printf("请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
		 if(TRUE==DeLQueue(q))
		 {
		 	printf("出队成功！");
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
			printf("队列为空！\n"); 
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
	   		printf("请输入1~11的数字！\n");
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
	   	printf("初始化成功！");
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
	   		printf("队列空！\n"); 
		}
		else
		{
			printf("队列非空！\n");
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
	   	 	printf("队列已满！\n");
		 }
		 else
		 {
		 	printf("队列未满！\n");	
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
		printf("清空成功！\n"); 
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
			printf("队列为空！,可使用入队指令(指令7)\n"); 
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
					printf("队首为%d\n",temp);
				}
			}
			else if(type=='d')
			{
				double temp;
				if(TRUE==GetHeadAQueue(q,&temp))
				{
					printf("队首为%f\n",temp);
				}
			}
			else if(type=='c')
			{
				char temp;
				if(TRUE==GetHeadAQueue(q,&temp))
				{
					printf("队首为%c\n",temp);
				}
			}
			else if(type=='s')
			{
				char **temp;
				temp=(char **)malloc(sizeof(char *));
				if(TRUE==GetHeadAQueue(q,temp))
				{
					printf("队首为%s\n",*temp);
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
		printf("销毁成功！\n");
	   	menu03();
	   }
	   else if(opnum==7)
	   {
	   	if(AIsNull(q))
	   	{
	   		scanf("%d",&opnum);
	   		continue;
		}
		printf("队列长度为%d\n",LengthAQueue(q));
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
				printf("队列已满。\n请重新输入指令");
				menu03();
				scanf("%d",&opnum);
				continue;
			 } 
			int num;
			printf("请输入要对应数据类型的 标号，选择如下：\n");
			printf("1,整形int  2,浮点型double  3,字符char  4,字符串String\n请输入：");
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
					printf("请输入要输入的值：");
					scanf("%d",i);
					datatype[(q->rear+1)%MAXQUEUE]='i';
					EnAQueue(q,i); 
					break;
				}
				else if(num==2)
				{
					d = (double *)malloc(sizeof(double));
					printf("请输入要输入的值：");
					scanf("%lf",d);
					datatype[(q->rear+1)%MAXQUEUE]='d';
					EnAQueue(q,d); 
					break;
				}
				else if(num==3)
				{
					c = (char *)malloc(sizeof(char)*200);
					printf("请输入要输入的字符：");
					scanf("%s",c);
					datatype[(q->rear+1)%MAXQUEUE]='c';
					EnAQueue(q,c);
					if(strlen(c)>1)
					{
						printf("\n***请注意，此处应为字符输入，已将所输入字符串的首字符存入。***\n");
					}
					break;
				}
				else if(num==4)
				{
					printf("字符串最长为200。\n");
					s = (char *)malloc(sizeof(char)*200);
					printf("请输入要输入的字符串：");
					scanf("%s",s);
					datatype[(q->rear+1)%MAXQUEUE]='s';
					EnAQueue(q,s);
					break;
				}
				else
				{
					printf("请输入1~4的数字。\n请重新输入：");
					scanf("%d",&num);
				}
			}
			
			printf("入队成功！\n");
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
			printf("队列空！无法出队，可以使用入队（指令7）\n\n");
			menu03();
			printf("请重新输入指令：");
			scanf("%d",&opnum);
			continue; 
		}
		 
		 if(TRUE==DeAQueue(q))
		 {
		 	printf("出队成功！");
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
			printf("队列为空！\n"); 
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
	   		printf("请输入1~12的数字！\n");
		} 

		scanf("%d",&opnum);
    
	
	}	
}

int AIsNull(Aqueue *q)
{
	if(q==NULL)
	{
		printf("队列已销毁或未被初始化，请先初始化（指令1）\n");
		printf("请重新输入指令："); 
		return 1;
	}
	return 0;
}

int LIsNull(Lqueue *q)
{
	if(q==NULL)
	{
		printf("队列已销毁或未被初始化，请先初始化（指令1）\n");
		printf("请重新输入指令："); 
		return 1;
	}
	return 0;
}





