#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)
{
	StackNode *node;
	node=NULL;
	s->top=node;
	s->count=0;
}

Status isEmptyLStack(LinkStack *s)
{
	if(s->count==0)
	{
		return SUCCESS;
	}
	return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->top==NULL)
	{
		return ERROR;
	}
	(*e)=s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
	if(s==NULL)
	{
		return ERROR;
	}
	StackNode *temp;
	temp=s->top;
	while(s->top!=NULL)
	{
		s->top=s->top->next;
		free(temp);
		temp=s->top;
	}
	return SUCCESS;
}


//销毁后，在主程序里将s=NULL; 
Status destroyLStack(LinkStack *s)
{
	if(s==NULL)
	{
		return ERROR;
	}
	StackNode *temp;
	temp=s->top;
	while(s->top!=NULL)
	{
		s->top=s->top->next;
		free(temp);
		temp=s->top;
	}
	return SUCCESS;
	
}

Status LStackLength(LinkStack *s,int *length)
{
	if(s==NULL)
	{
		return ERROR;
	}
	StackNode *temp;
	temp=s->top;
	int len=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		len++;
	}
	(*length)=len;
	return SUCCESS;
	
	
}


Status pushLStack(LinkStack *s,ElemType data)
{
	if(s==NULL)
	{
		return ERROR;
	}
	StackNode *temp;
	temp=(StackNode *)malloc(sizeof(StackNode));
	temp->data=data;
	temp->next=s->top;
	s->top=temp;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{
	if(s==NULL)
	{
		return ERROR;
	}
	StackNode *temp;
	temp=s->top;
	s->top=s->top->next;
	(*data)=temp->data;
	free(temp);
	return SUCCESS;
}

