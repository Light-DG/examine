#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void menu();

int main()
{
	menu(); 
	int opnum;
	int total;
	scanf("%d",&opnum); 
	while(1)
	{
		if(opnum==1)
		{
			total=10000;
			break;
		}
		else if(opnum==2)
		{
			total=50000;
			break;
		}
		else if(opnum==3)
		{
			total=200000;
			break;
		}
		else if(opnum==4)
		{
			total=10000000;
			break;
		 } 
		else{
			printf("请输入1~4的数据"); 
		} 
	 } 
	printf("生成文件data.txt\n再按任意键结束\n"); 
    freopen("data.txt","w",stdout);
	int num;
	srand((unsigned int)time(0));
		if(total==10000000)
		{
			for(int i=0;i<total;i++)
			{
				num=rand()%2000;
			    printf("%d ",num);
			}
		}
		else
		{
			for(int i=0;i<total;i++)
			{
			  num=rand()%2001;
			  printf("%d ",num);
			}
			
		}  
   return 0;
}

void menu()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.产生10000个数据(0~2000)                    *\n");
    	printf("*  2.产生50000个数据(0~2000)                    *\n");
    	printf("*  3.产生200000个数据(0~2000)                   *\n");
    	printf("*  4.产生100*100k的数据                         *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-4):");
}

