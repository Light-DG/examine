#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h" 

void InitLQueue(LQueue *Q)
{
	if(Q==NULL)
	{
		return;
	}
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->next=NULL;
	Q->front=Q->rear=temp;
	Q->length=0;
}

//main里置空 
 void DestoryLQueue(LQueue *Q)
 {
 	if(Q==NULL)
 	{
 		return;
	 }
 	Node *p1,*p2;
 	p1=Q->front->next;
 	while(p1)
 	{
 		p2=p1;
 		p1=p1->next;
 		free(p2);
	 }
	 free(Q->front);
	 Q->front=Q->rear=NULL;
 }
 
 Status IsEmptyLQueue(const LQueue *Q)
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
 
 Status GetHeadLQueue(LQueue *Q, void *e)
 {
 	if(Q==NULL||Q->front->next==NULL)
 	{
 		return FALSE;
	 }
 	Node *temp;
	temp=Q->front->next; 
 	if(Q==NULL)
	{
		return FALSE;
	}
	if(temp->type=='i')
	{
		(*(int *)e)=*(int *)temp->data;
		return TRUE;
	}
	else if(temp->type=='d')
	{
		(*(double *)e)=*(double *)temp->data;
		return TRUE;	
	}
	else if(temp->type=='c')
	{
		(*(char *)e)=*(char *)temp->data;
		return TRUE;	
	}
	else if(temp->type=='s')
	{
		*(char **)e = (char *)temp->data;
		return TRUE;	
	}
	return FALSE;
 }
 
 int LengthLQueue(LQueue *Q)
 {
 	if(Q==NULL)
 	{
 		return -1;
	 }
 	return Q->length;
 }
 
 //main函数里设置type 
 Status EnLQueue(LQueue *Q, void *data)
 {
 	if(Q==NULL)
 	{
 		return FALSE;
	 }
	 Node *temp;
	 temp=(Node *)malloc(sizeof(Node));
	 temp->data=data;
	 temp->type=type;
	 temp->next=NULL;
	 Q->rear->next=temp;
	 Q->rear=temp;
	 Q->length++;
	 return TRUE; 
 }
 
 Status DeLQueue(LQueue *Q)
 {
 	if(Q==NULL||Q->front->next==NULL)
 	{
 		return FALSE;
	 }
 	Node *temp;
 	temp=Q->front->next;
 	Q->front->next=temp->next;
 	free(temp);
 	Q->length--;
 	return TRUE;
 }
 
 //main函数里不置空 
 void ClearLQueue(LQueue *Q)
 { 
 	if(Q==NULL)
 	{
 		printf("清空失败！\n");
 		return;
	 }
 	Node *p1,*p2;
 	p1=Q->front->next;
 	while(p1)
 	{
 		p2=p1;
 		p1=p1->next;
 		free(p2);
	 }
	 Q->length=0;
	 Q->front->next=NULL;
 }
 
 Status TraverseLQueue(const LQueue *Q, void (*LPrint)(void *q))
 {
 	if(Q==NULL)
 	{
 		return FALSE;
	 }
 	Node *p;
 	p=Q->front->next;
	while(p)
	{
		type = p->type;
		LPrint(p->data);
		p=p->next;
	 } 
	 return TRUE;
 }
 
 void LPrint(void *q)
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

