#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"
#include "calculate.cpp"


int main()
{
	
	printf("\n�ó����֧�� ��λ����(�ʼ��ÿ����) ֮��ļ��㡣\n");
	printf("����Ӣ�����뷨�����롣\n");
	int opnum;
	char *mid;
	menu();
	scanf("%d",&opnum);
	while(opnum!=2)
	{
	   if(opnum==1)
	   {
	   	printf("ÿλ������������� ���� ��λ����");
	   	printf("\n�������뷨�¿��ܵ����쳣��\n\n");
	   	printf("��������׺���ʽ��");
	   	mid=(char *)malloc(sizeof(char)*1000);
		scanf("%s",mid);
	    int len=strlen(mid);
	   	final_caculate(mid,len);
	   	free(mid);
	   	menu();
	   }
	   else
	   {
	   		printf("������1~2�����֣�\n");
		} 

		scanf("%d",&opnum);
    }
	
	return 0;
 } 
 
 void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.����                                        *\n");
    	printf("*  2.�˳�                                        *\n");
    	printf("*************************************************\n\n");
    	printf("������ָ����(1-2):");
}
 
 
