#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AQueue.h"

void InitAQueue(AQueue *Q)
{
	Q->length=0;
	Q->front=0;
	Q->rear=-1;
}

void DestoryAQueue(AQueue *Q)
{
	if(Q==NULL)
	{
		return ;
	}
	Q->length=0;
	Q->front=0;
	Q->rear=-1;
	free(Q->data); 
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q==NULL)
	{
		return FALSE;
	}
	if(Q->length==MAXQUEUE)
	{
		return TRUE;
	}
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q==NULL)
	{
		return FALSE;
	}
	if(Q->length==0)
	{
		return TRUE;
	}
	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q==NULL)
	{
		return FALSE;
	}
	if(datatype[Q->front]=='i')
	{
		(*(int *)e)=*(int *)Q->data[Q->front];
		return TRUE;
	}
	else if(datatype[Q->front]=='d')
	{
		(*(double *)e)=*(double *)Q->data[Q->front];
		return TRUE;	
	}
	else if(datatype[Q->front]=='c')
	{
		(*(char *)e)=*(char *)Q->data[Q->front];
		return TRUE;	
	}
	else if(datatype[Q->front]=='s')
	{
		*(char **)e = (char *)Q->data[Q->front];
		return TRUE;	
	}
	return FALSE;
}

int LengthAQueue(AQueue *Q)
{
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)
{
	if(Q==NULL||Q->length==MAXQUEUE)
	{
		return FALSE;
	}
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->data[Q->rear]=data;
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)
{
	if(Q==NULL||Q->length==0)
	{
		return FALSE;
	}
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	if(Q==NULL)
	{
		return;
	}
	Q->length=0;
	Q->front=0;
	Q->rear=-1;
 } 
 
 Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(Q==NULL||Q->length==0)
	{
		return FALSE;
	}
	int p=Q->front;
	for(int i=0;i<Q->length;)
	{
		type = datatype[p];
		APrint(Q->data[p]);
		p=(p+1)%MAXQUEUE;
		i++;
	}
	return TRUE;
 } 
 
 void APrint(void *q)
{
	if(q==NULL)
	{
		return ;
	}
	if(type=='i')
	{
		printf("-->%d\n",*(int *)q);
	}
	else if(type=='d')
	{
		printf("-->%lf\n",*(double *)q);
	}
	else if(type=='c')
	{
		printf("-->%c\n",*(char *)q);
	}
	else if(type=='s')
	{
		printf("-->%s\n",(char *)q);
	}
	else
	{
		printf("无此数据类型!\n"); 
		return;
	}
}

 
