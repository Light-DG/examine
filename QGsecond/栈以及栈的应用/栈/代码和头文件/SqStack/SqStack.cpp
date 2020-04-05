#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes)
 {
 	s->size=sizes;
	s->elem=(int *)malloc(sizeof(int)*s->size);
	s->top=-1;
	return SUCCESS; 	
 }
 
Status isEmptyStack(SqStack *s)
 {
 	if(s->top==-1)
 	{
 		return SUCCESS;
	 }
	 return ERROR;
 }
 
 Status getTopStack(SqStack *s,ElemType *e)
 {
 	if(s==NULL||s->top==-1)
 	{
 		return ERROR;
	 }
	 (*e)=s->elem[s->top];
 	 return SUCCESS;
 }
 
 Status clearStack(SqStack *s)
 {
 	if(s==NULL)
 	{
 		return ERROR;
	 }
 	s->top=-1;
 	return SUCCESS;
 }
 
 Status destroyStack(SqStack *s)
 {
 	if(s==NULL)
 	{
 		return ERROR;
	 } 
 	free(s->elem);
	s->elem=NULL;
	s->size=0;
	s->top=-1;
	return SUCCESS; 
 }
 
 Status stackLength(SqStack *s,int *length)
 {
 	if(s==NULL)
 	{
 		return ERROR;
	 } 
	 (*length)=s->top+1; 
	 return SUCCESS;
 }
 
 Status pushStack(SqStack *s,ElemType data)
 {
 	if(s==NULL||s->top==s->size-1)
 	{
 		return ERROR;
	 }
	 s->elem[++s->top]=data;
	 return ERROR;
 }
 
 Status popStack(SqStack *s,ElemType *data)
 {
 	if(s==NULL||s->top==-1)
 	{
 		return ERROR;
	 }
 	(*data)=s->elem[s->top--]; 
 	return SUCCESS;
 }
 
