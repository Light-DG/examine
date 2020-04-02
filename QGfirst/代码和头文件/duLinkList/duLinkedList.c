#include "../head/duLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	(*L)=(DuLNode *)malloc(sizeof(DuLNode));
	(*L)->prior=NULL;
	(*L)->next=NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {

	DuLNode *t;
	while((*L)!=NULL)
	{
		
		t=(*L);
		(*L)=(*L)->next;
		free(t); 
	}
	t=(*L)=NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL)
	{
		printf("第一个节点为空！\n");
		return ERROR;
	}
	if(p->next==NULL&&p->prior==NULL)
	{
		printf("不能在头结点前插入！可以使用指令5.\n");
		return ERROR;
	}
	q->prior=p->prior;
	q->next=p;
	p->prior->next=q;
	p->prior=q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None 
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) { 
	if(p==NULL)
	{
		printf("传入的第一个节点为空！\n");
		return ERROR;
	}
	q->prior=p;
	q->next=p->next;
	if(p->next)
	{
		p->next->prior=q;	
	}
	p->next=q; 
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL||p->next==NULL)
	{
		printf("没有可删除的节点！\n");
		return ERROR;
	}
	DuLNode *temp1,*temp2;
	if(p->next->next==NULL)
	{ 
		temp1=p->next;
		p->next=NULL;
		(*e)=temp1->data;
		free(temp1);
		printf("删除成功！\n");
		return SUCCESS; 
	}
	temp1=p->next;
	temp2=p->next->next;
	p->next=temp2;
	temp2->prior=p;
	(*e)=temp1->data;
	free(temp1);
	printf("删除成功！\n");
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL)
	{
		printf("链表未初始化或已销毁，请先初始化!\n");
		return; 
	}
	DuLNode *t;
	t=L->next;
	while(t)
	{
		visit(t->data);
		if(t->next) printf("->");
		t=t->next;
	}
	printf("\n\n");
}

void visit(int item)
{
	printf("%d",item);
}
