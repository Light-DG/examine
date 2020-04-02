#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	if((*L)!=NULL) DestroyList(L); 
	(*L) = (LNode *) malloc (sizeof(LNode));
	(*L)->next=NULL;
	printf("初始化成功！"); 
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	if(IsLoopList((*L))==SUCCESS)
	{
		(*L)=NULL;
		return;
	 } 
	LNode *t;
	while((*L)!=NULL)
	{
		
		t=(*L);
		(*L)=(*L)->next;
		free(t); 
	}
	t=(*L)=NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p!=NULL)
	{
		q->next=p->next;
		p->next=q;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p==NULL||p->next==NULL)
	{
		printf("删除节点失败！\n"); 
		return ERROR;
	}
	else
	{
		LNode *temp;
		temp=p->next;
		p->next=temp->next;
		(*e)=temp->data;
		free(temp);
		temp=NULL;
		printf("删除节点成功！\n");
		return SUCCESS;
	}
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL)
	{
		printf("链表未初始化或已销毁，请先初始化!\n");
		return; 
	}
	LNode *t;
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

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *t;
	t=L->next;
	int count=1;
	while(t)
	{
		if(t->data==e)
		{
			printf("找到该数据！\n");
			printf("位于该链表的第%d个位置。\n",count);
			return SUCCESS;
		}
		t=t->next;
		count++;
	}
	printf("未找到该数据！\n");
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if((*L)->next==NULL)
	{
		printf("该链表为空，反转失败！\n");
		return ERROR; 
	}
	LNode *mid,*front,*rear;
	mid=(*L)->next;
	front=rear=NULL;
	while(mid)
	{
		rear=mid->next;
		mid->next=front;
		front=mid;
		mid=rear;
	}
	(*L)->next=front;
	printf("链表反转成功！\n");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L==NULL||L->next==NULL)
	{
		printf("链表为空，没有环。\n");
		return ERROR; 
	}
	LNode *fast,*slow;
	fast=slow=L;
	while(1)
	{
		slow=slow->next;      
		if(fast)           
		{
			fast=fast->next;
			if(fast)  //fast指针可能只能走一步；
			{
				fast=fast->next;
			}
		}
		if(!fast||!slow) 
		{
			printf("不成环！\n");
			return ERROR; 
		}
		else if(slow==fast)
		{
			printf("成环！\n");
			return SUCCESS; 
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if((*L)->next==NULL)
	{
		printf("该链表为空，不能反转");
		return *L; 
	}
	if((*L)->next->next==NULL)
	{
		printf("该链表只有一个节点");
		return *L; 
	}
	LNode *front,*rear,*mid;
	rear=mid=front=*L;
	while(mid->next&&mid->next->next)
	{
		front=mid;
		mid=mid->next;
		rear=mid->next;
		
		front->next=rear;
		mid->next=rear->next;
		rear->next=mid;
	}
	printf("交换奇偶位置成功！\n");
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if((*L)->next==NULL)
	{
		printf("该链表没有节点！\n");
		return NULL; 
	}
	if((*L)->next->next==NULL)
	{
		printf("该链表只有一个节点。\n");
		return (*L)->next; 
	}
	LNode *slow,*fast;
	slow=fast=(*L);
	while(fast->next)
	{
		slow=slow->next;      
		if(fast->next)           
		{
			fast=fast->next;
			if(fast->next)       //fast指针可能只能走一步；
			{
				fast=fast->next;
			}
		}
	}
	return slow;
}

