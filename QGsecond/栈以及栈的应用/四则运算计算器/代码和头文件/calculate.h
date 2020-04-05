#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

struct Node
{
	char c;
	Node *next;
};

struct numNode
{
	int data;
	numNode *next;
};

struct Stack{
	char *elem;
	int size;
	int top;
};

struct numStack{
	int *num;
	int size;
	int top;
};


int charToNum(char c);
char pop(Stack *s);
int push(Stack *s,char c);
int Npush(numStack *s,int data);
int Npop(numStack *s);
void initStack(Stack *s,int sizes);
int IsNum(char c);
int priority(char c);
int calculate(int num1,int num2,char c);
void menu();
void final_caculate(char *mid,int len);

#endif
