#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

void final_caculate(char *mid,int len)
 {
 	for(int i=0;i<len;i++)
 	{
 		if(mid[i]=='/'&&mid[i+1]=='0')
 		{
 			printf("\n不能除0！\n");
 			return;
		 }
	 }
 	
 	char *rear;
    rear=(char *)malloc(sizeof(char)*len);
    
	Stack *s1;
	s1=(Stack *)malloc(sizeof(Stack));
	initStack(s1,len); 
	
	numStack *s2;
	s2=(numStack *)malloc(sizeof(numStack));
	s2->top=-1;
	s2->size=len;
	s2->num=(int *)malloc(sizeof(int)*len);
    
    int k=0;
    int count=0;
    for(int i=0;i<len;i++)
    {
    	//数字直接输出 
    	if(IsNum(mid[i]))
    	{
			rear[k++]=mid[i];
			continue;
		}
		
		//左括号直接入栈 
		if(mid[i]=='(')
		{
			push(s1,mid[i]); 
			count++;
			continue;
		}
		if(mid[i]==')')
		{
			while(s1->top>=0&&s1->elem[s1->top]!='(')
			{
				rear[k++]=pop(s1);
			}
			pop(s1);
			count++;
			continue;
		}
		
		//加减乘除 
		if(priority(mid[i]))
		{
			while(s1->top>=0&&priority(mid[i])<=priority(s1->elem[s1->top]))
			{
				rear[k++]=pop(s1);
			}
			push(s1,mid[i]);
			continue;
		}
	}
	while(s1->top>=0)
	{
		rear[k++]=pop(s1);
	}
	len-=count;
    printf("后缀表达式为：");
    for(int i=0;i<len;i++)
    {
    	printf("%c ",rear[i]);
	}
	printf("\n");
    
	//用后缀表达式计算
	int num1=0,num2=0;
	int judge=1;
	for(int i=0;i<len;i++)
    {
    	if(i==0&&mid[i]=='-')
    	{
    		Npush(s2,0);
		}
    	if(IsNum(rear[i]))
    	{
			Npush(s2,rear[i]-'0');
			continue;
		}
		if(priority(rear[i]))
		{
			if(s2->top<1)
			{
				judge=0;
				break;
			}
			num1=Npop(s2);
			num2=Npop(s2);
			Npush(s2,calculate(num1,num2,rear[i]));
			continue;
		}
	}
	if(s2->top==0&&judge)
	{
		printf("计算结果：%d\n",s2->num[s2->top]);
	}
	else
	{
		printf("请输入正确的表达式。"); 
	 } 
 }


int push(Stack *s,char c)
 {
 	if(s==NULL||s->top==s->size-1)
 	{
 		return -1;
	 }
	 s->elem[++s->top]=c;
	 return 1;
 }
 
 char pop(Stack *s)
 {
 	if(s==NULL||s->top==-1)
 	{
 		return -1;
	 }
 	return s->elem[s->top--];
 }
 
int charToNum(char c)
{
	if(c>='0'&&c<='9')
	{
		return c-'0';
	}
	return -1;
}

void initStack(Stack *s,int sizes)
 {
 	s->size=sizes;
	s->elem=(char *)malloc(sizeof(char)*s->size);
	s->top=-1;
 }
 
 void myprint(Stack *s)
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
		printf("%c\n",s->elem[i]);
	}
	printf("\n");
}

int Npush(numStack *s,int data)
 {
 	if(s==NULL||s->top==s->size-1)
 	{
 		return -1;
	 }
	 s->num[++s->top]=data;
	 return 1;
 }
 
 int Npop(numStack *s)
 {
 	if(s==NULL||s->top==-1)
 	{
 		return -1;
	 }
 	return s->num[s->top--];
 }
 
 int IsNum(char c)
 {
 	if(c>='0'&&c<='9')
 	{
 		return 1;
	 }
	return 0;
 }
 
 int priority(char c)
 {
 	if(c=='+'||c=='-')
 	{
 		return 1;
	 }
	if(c=='*'||c=='/')
	{
		return 2;
	}
	return 0;
 }
 
 int calculate(int num1,int num2,char c)
 {
 	if(c=='+')
 	{
 		return num1+num2;
	 }
	if(c=='-')
	{
		return num2-num1;
	}
	if(c=='*')
	{
		return num2*num1;
	}
	if(c=='/')
	{
		return num2/num1;
	}
 	
 }

