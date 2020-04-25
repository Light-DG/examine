#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;

struct qnode
{
	BiTNode *bt;
	qnode *next;
 };

struct Stack{
	char data[N];
	int top;
	int size;
};

void Inital(Stack *s);
void push(Stack *s,char c);
char pop(Stack *s);
char * Conver(char *s);
int opGrade(char c);
Status InitBiTree(BiTree T);
Status DestroyBiTree(BiTree T);
Status CreateBiTree(BiTree T, char* definition);
Status PreOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));
Status InOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	
Status PostOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	
Status LevelOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	
int Value(BiTNode T);		
BiTree preCreat();
BiTree inCreat(char *s);
BiTree postCreat(char *s);
Status visit(TElemType e);
void addq(qnode **rear,BiTNode *p);
void levelordertraversal(BiTNode *boot);
BiTNode *deleteq(qnode *front,qnode **rear);
BiTree Build(char *s);
int Calculate(BiTNode *t);
int operate(char c,int l,int r);
void menu();
void menu02();
int IsNull(BiTNode *s);
void myCreat(char *s);
BiTNode *myCreate(char *s);

int index = 0; 

int main(){
	
	//freopen("input.txt","r",stdin);
	BiTNode *t;
	t=NULL;
	int opnum=0;
	menu();
	scanf("%d",&opnum);
	while(opnum!=9)
	{
		if(opnum==1)
		{
			t=(BiTNode *)malloc(sizeof(BiTNode));
			InitBiTree(t);
			printf("��ʼ���ɹ���");
		}
		else if(opnum==2)
	   {
	   	 if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
		  int key;
		  char *s;
		  s=(char *)malloc(sizeof(char)*100);
		  printf("���������ַ���(���磺����AB#DF##G##C#E#H##)\n");
		  printf("�����˳��\n"); 
		  scanf("%s",s);
		  index=0;
		  t=myCreate(s);
		  printf("�����ɹ���\n"); 
	   }
	   else if(opnum==3)
	   {
	     if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
		 PreOrderTraverse(t,visit);
	   }
	   else if(opnum==4)
	   {
	   	if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
	   	InOrderTraverse(t,visit);
	   }
	   else if(opnum==5)
	   {
	   	if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
	   	PostOrderTraverse(t,visit);
	   }
	   else if(opnum==6)
	   {
	   	if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
		 LevelOrderTraverse(t,visit);
	   }
	   else if(opnum==7)
	   {
	   	if(IsNull(t))
	   	 {
	   	 	scanf("%d",&opnum);
	   	 	continue;
			}
		 DestroyBiTree(t);
		 t=NULL;
	    }
	   else if(opnum==8)
	   {
		 char *s,*front;
		 s=(char *)malloc(sizeof(char)*N);
		 printf("��������ȷ����׺���ʽ��");
		 scanf("%s",s);
		 front = Conver(s);
		 printf("ǰ׺���ʽΪ��%s\n",front);
		 index=0;
		 BiTNode *temp = Build(front);
		 int ans = Calculate(temp);
		 printf("���Ϊ��%d\n",ans);
	   }
	   else
	   {
	   		printf("������1~9�����֣�\n");
		} 
		
		menu();
		scanf("%d",&opnum);
	}
	
	
	return 0; 
	
}

BiTNode *myCreate(char *s)
{
	if(index>=strlen(s))
	{
		return NULL;
	}
	int len = strlen(s);
	BiTNode *T;
	char c;
	c=s[index++];
	if(c=='#')
	{
	   T=NULL;
	}else{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=c;
		T->lchild=myCreate(s);
		T->rchild=myCreate(s);
	}
	return T;
}


int IsNull(BiTNode *s)
{
	if(s==NULL)
	{
		printf("ջ�����ٻ�δ����ʼ�������ȳ�ʼ����ָ��1��\n");
		printf("����������ָ�"); 
		return 1;
	}
	return 0;
}


void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.��ʼ��                                      *\n");
    	printf("*  2.������(����)                                *\n");
    	printf("*  3.�������                                    *\n");
    	printf("*  4.�������                                    *\n");
    	printf("*  5.�������                                    *\n");
    	printf("*  6.�������                                    *\n");
    	printf("*  7.������                                      *\n");
    	printf("*  8.��������                                    *\n");
    	printf("*  9.�˳�                                        *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-9):");
	
}

void menu02()
{
	printf("������/����/�����˳������,�� # ��ʾ�սڵ�"); 
	printf("\n\n*************************************************\n");
    	printf("*  1.���򴴽�                                    *\n");
    	printf("*  2.���򴴽�                                    *\n");
    	printf("*  3.���򴴽�                                    *\n");

    	printf("*************************************************\n\n");
    	printf("������ָ����(1-3):");
}


int Calculate(BiTNode *t)
{
	if(opGrade(t->data)==-1)
	{
		return t->data-'0';
	}
	int leftNum;
	int rightNum;
	if(opGrade(t->data)>0)
	{
		leftNum=Calculate(t->lchild);
		rightNum = Calculate(t->rchild);
	}
	return operate(t->data,leftNum,rightNum);
}

int operate(char c,int l,int r)
{
	if(c=='+')
	{
		return l+r;
	}else if(c=='-')
	{
		return l-r;
	}else if(c=='*')
	{
		return l*r;
	}else if(c=='/')
	{
		return l/r;
	}
 } 

BiTree Build(char *s)
{
	BiTNode *root;
	int len = strlen(s);
	root = (BiTree)malloc(sizeof(BiTNode));
	if(opGrade(s[index])==-1)
	{
		root->data=s[index++];
		root->lchild=NULL;
		root->rchild=NULL;
	}else if(opGrade(s[index])>0)
	{
		root->data=s[index++];
		root->lchild=Build(s);
		root->rchild=Build(s);		
	}
	return root;
}

BiTNode *deleteq(qnode *front,qnode **rear)
 {
 	qnode *temp;
 	BiTNode *ret;
 	temp=front->next;
 	front->next=temp->next;
 	if(front->next==NULL) (*rear)=front;
 	ret=temp->bt;
 	free(temp);
 	return ret;
 }

void addq(qnode **rear,BiTNode *p)
 {
 	qnode *temp;
 	temp=(qnode *)malloc(sizeof(qnode));
 	temp->bt=p;
 	temp->next=NULL;
 	(*rear)->next=temp;
 	(*rear)=(*rear)->next;
 }

Status InitBiTree(BiTree T)
{
	T->data='#';
	T->lchild=NULL;
	T->rchild=NULL;
	return SUCCESS;
}

Status CreateBiTree(BiTree T, char* definition)
{
	char *s;
	if(strcmp(definition,"Pre")==0)
	{
		T=preCreat();
	}else if(strcmp(definition,"In")==0){
		T=inCreat(s);
	}else if(strcmp(definition,"Post")){
		T=postCreat(s);
	}
}


BiTree preCreat()
{
	BiTNode *T;
	char c;
	scanf("%c\n",&c);
	if(c=='#')
	{
	   T=NULL;
	}else{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=c;
		T->lchild=preCreat();
		T->rchild=preCreat();
	}
	return T;
}

BiTree inCreat(char *s)
{
	if(index>=strlen(s))
	{
		return NULL;
	}
	int len = strlen(s);
	BiTNode *T;
	char c;
	c=s[index++];
	if(c=='#')
	{
	   T=NULL;
	}else{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->lchild=myCreate(s);
		T->data=c;
		T->rchild=myCreate(s);
	}
	return T;
	
}

BiTree postCreat(char *s)
{
	if(index>=strlen(s))
	{
		return NULL;
	}
	int len = strlen(s);
	BiTNode *T;
	char c;
	c=s[index++];
	if(c=='#')
	{
	   T=NULL;
	}else{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->lchild=myCreate(s);
		T->rchild=myCreate(s);
		T->data=c;
	}
	return T;
	

}


Status visit(TElemType e)
{
	printf("%c ",e);
}

Status PreOrderTraverse(BiTNode *T, Status (*visit)(TElemType e)){
	if(T==NULL)
	{
		return SUCCESS;
	}else{
		visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
	return SUCCESS;
}

Status InOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
	if(T==NULL)
	{
		return SUCCESS;
	}else{
		InOrderTraverse(T->lchild,visit);
		visit(T->data);
		InOrderTraverse(T->rchild,visit);
	}
	return SUCCESS;
}

Status PostOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
	if(T==NULL)
	{
		return SUCCESS;
	}else{
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T->data);
	}
	return SUCCESS;
}

Status DestroyBiTree(BiTree T)
{
	if(T==NULL)
	{
		return ERROR;
	}
	else
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		return SUCCESS;
	}
}

Status LevelOrderTraverse(BiTNode *boot, Status (*visit)(TElemType e))
{
	BiTNode *t=boot;
 	if(!boot) return ERROR;
 	qnode *front,*rear;
 	front=(qnode *)malloc(sizeof(qnode));
    front->next=NULL;	
 	rear=front;
 	
 	addq(&rear,t);
 	while(front->next!=NULL)
 	{
 		t=deleteq(front,&rear);
 		visit(t->data);
 		if(t->lchild!=NULL)  addq(&rear,t->lchild);
 		if(t->rchild!=NULL) addq(&rear,t->rchild);
	 }
 	printf("\n");
	
}

void Inital(Stack *s)
 {
 	s->size=N;
 	s->top=-1;
 }
 
 void push(Stack *s,char c)
 {
 	if(s->top==N)
 	{
 		printf("����!\n");
 		return;
	 }
 	s->data[++s->top] = c;
 }
 
 char pop(Stack *s)
 {
 	if(s->top==-1)
 	{
 		printf("�ѿգ�\n");
 		return '#';
	 }
 	return s->data[s->top--];
 }
 
 char * Conver(char *s)
 {
 	Stack *ret,*op;
	ret= (Stack *)malloc(sizeof(Stack));
	op=(Stack *)malloc(sizeof(Stack));
	Inital(op);
	Inital(ret);  
 	int len = strlen(s);
 	int count = 0;
 	for(int i=len-1;i>=0;i--)
 	{
 		if(opGrade(s[i])==-1)
		 {
		 	push(ret,s[i]);
		 }
 		else if(op->top==-1||s[i]==')')
 		{
 			push(op,s[i]);
 			if(s[i]==')') count++;
		 }
		 else if(s[i]=='('){
		 	count++;
		 	while(op->data[op->top]!=')')
		 	{
		 		char c = pop(op);
		 		push(ret,c);
			 }
			 pop(op);
		 }else if(opGrade(s[i])>=opGrade(op->data[op->top]))
		 {
		 	push(op,s[i]);
		 }
	 }
	   while(op->top>=0)
	   {
		char c = pop(op);
		if(c!='('&&c!=')')
		{
			push(ret,c);
		}
	   }
	 char *ans;
	 ans = (char *)malloc(sizeof(char)*N);
	 int i;
	 for(i=0;i<len-count;i++)
	 {
	 	ans[i]=pop(ret);
	 }
	 ans[i]='\0';
	 return ans;
 }
 
 int opGrade(char c)
 {
 	if(c=='+'||c=='-'){
 		return 1;
	 }
	 else if(c=='*'||c=='/'){
	 	return 2;
	 }
	 else if(c>='0'&&c<='9')
	 {
	 	return -1;
	 }else{
	 	return -2;
	 }
 }

