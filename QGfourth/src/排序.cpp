#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void menu03(); 
void insertsort(int arry[],int n);
void myprint(int num[],int n);
void merge(int arry[],int left,int middle,int right);
void mergesort(int arry[],int left,int right);
void quickSort(int num[],int left,int right);
void countsort(int arry[],int n,int max);
void arryClear(int arry[],int n);
void radixsort(int arry[],int maxterm,int n);
int getmaxterm(int max);
void arryClear(int arry[],int n);
void menu04();
 
int main()
{
	printf("***注意，请在使用该程序前用'数据生成文件'生成相应的数据文件***\n"); 
	printf("***注意，请在使用该程序前用'数据生成文件'生成相应的数据文件***\n");
	printf("***注意，请在使用该程序前用'数据生成文件'生成相应的数据文件***\n");
	int opnum;
	menu03();
	scanf("%d",&opnum); 
	
	int total=0;
	if(opnum==1)
	{
		total=10000;
	}
	else if(opnum==2)
	{
		total=50000;
	}
	else if(opnum==3)
	{
		total=200000;
	}
	else if(opnum==4)
	{
		total=10000000;
	} 
	freopen("data.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
	if(opnum==4)
	{
		int num2[100];

		clock_t start=clock();
		for(int i=0;i<100000;i++)
		{
			for(int j=0;j<100;j++)
			{
				scanf("%d",&num2[j]);
			}
			quickSort(num2,0,99); 
		}
		clock_t end=clock(); 
		printf("快排(递归)：%dms\n",end-start);
		
		clock_t start2=clock();
		for(int i=0;i<100000;i++)
		{
			for(int j=0;j<100;j++)
			{
				scanf("%d",&num2[j]);
			}
			
			insertsort(num2,100); 
		}
		clock_t end2=clock();
		printf("插入排序：%dms\n",end2-start2);
		
		clock_t start3=clock();
		for(int i=0;i<100000;i++)
		{
			for(int j=0;j<100;j++)
			{
				scanf("%d",&num2[j]);
			}
			
			mergesort(num2,0,99); 
		}
		clock_t end3=clock();
		printf("归并排序：%dms\n",end3-start3);
		
		clock_t start4=clock();
		for(int i=0;i<100000;i++)
		{
			int max=-9999999;
			for(int j=0;j<100;j++)
			{
				scanf("%d",&num2[j]);
				if(num2[j]>max) max=num2[j];
			}
			countsort(num2,100,max); 
		}
		clock_t end4=clock();
		printf("计数排序：%dms\n",end4-start4);
		
		clock_t start5=clock();
		for(int i=0;i<100000;i++)
		{
			int max=-9999999;
			for(int j=0;j<100;j++)
			{
				scanf("%d",&num2[j]);
				if(num2[j]>max) max=num2[j];
			}
			int maxterm = getmaxterm(max);
			radixsort(num2,maxterm,100); 
		}
		clock_t end5=clock();
		printf("基数计数排序：%dms\n",end5-start5);
		
	}
	else
	{
		
		int num[total];
		int max=-99999999;
		for(int i=0;i<total-1;i++)
	    {
		  scanf("%d\n",&num[i]);
		  if(num[i]>max){
		  	max=num[i]; 
		  }
		  if(max>2000)
		  {
		  	printf("%d:%d\n",i,max);
		  }
	    }
	    fclose(stdin);
	    menu04(); 
	    int choose=0;
	    freopen("CON","r",stdin);
	    scanf("%d",&choose);
			if(choose==1)
			{
				clock_t start3=clock();
				quickSort(num,0,total-1);
				clock_t end3=clock();
				printf("快排(递归)： %dms\n",end3-start3);
			}
			else if(choose==2)
			{
				clock_t start1=clock();
				insertsort(num,total);
				clock_t end1=clock();
				printf("插入排序：%dms\n",end1-start1);
			}
			else if(choose==3)
			{
				clock_t start2=clock();
				mergesort(num,0,total-1);
				clock_t end2=clock();
				printf("归并排序：%dms\n",end2-start2);
			}
			else if(choose==4)
			{
				clock_t start4=clock();
				countsort(num,total,max);
				clock_t end4=clock();
				printf("计数排序： %dms\n",end4-start4);
			}
			else if(choose==5)
			{
				clock_t start5=clock();
				int maxterm=getmaxterm(max);
				radixsort(num,maxterm,total);
				clock_t end5=clock();
				printf("基数计数排序： %dms\n",end5-start5);
			}
		
	}
	freopen("CON","r",stdin);
	system("pause");

	return 0;
}

void menu03()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.测试数据为10000(0~2000)                    *\n");
    	printf("*  2.测试数据为50000(0~2000)                    *\n");
    	printf("*  3.测试数据为200000(0~2000)                   *\n");
    	printf("*  4.测试数据为100*100k                         *\n");
    	printf("*************************************************\n\n");
    	printf("请输入编号(1-4):");
}

void insertsort(int arry[],int n)
{
	int ret[n];
	ret[0]=arry[0];
	int temp;
	for(int i=1;i<n;i++)
	{
		temp=arry[i];
		int j;
		for(j=i;j>0&&ret[j-1]>=temp;j--)
		{
			ret[j]=ret[j-1];
		}
		ret[j]=temp;
			
	}
	memcpy(arry,ret,sizeof(int)*n);
}

void myprint(int num[],int n)
 {
 	for(int i=0;i<n;i++)
	{
	 printf("%d ",num[i]);
	}
	printf("\n");
  } 
  
  void merge(int arry[],int left,int middle,int right)
 {
 
 	int temp[right-left+1];
 	for(int i=left;i<=right;i++)
 	{
 		
 		temp[i-left]=arry[i];
	 }
	int i=left;
	int j=middle+1;
	for(int k=left;k<=right;k++)
	{
		if(i>middle&&j<=right)
		{
			arry[k]=temp[j-left];
			j++;
		}
		else if(j>right&&i<=middle)
		{
			arry[k]=temp[i-left];
			i++;
	
		}
		else if(temp[i-left]<temp[j-left]&&i<=middle)
		{
			arry[k]=temp[i-left];
			i++;
		}
		else if(temp[i-left]>=temp[j-left]&&j<=right)
		{
			arry[k]=temp[j-left];
			j++;
		}
	 } 
 }
 
 void mergesort(int arry[],int left,int right)
 {
 	if(left>=right)
 	{
 		return;
	 }
 	int middle=(right+left)/2;
 	mergesort(arry,left,middle);
 	mergesort(arry,middle+1,right);
 	merge(arry,left,middle,right);
 }
 
 void quickSort(int num[],int left,int right)
 {
 	if(left>=right)
 	{
 		return;
	 }
 	int pivot=num[left];
 	int left1=left;
 	int right1=right;
 	while(left<right)
 	{
 		while(left<right&&num[right]>=pivot)
 		{
 			right--;
		 }
		 if(left<right)
		 {
		 	num[left]=num[right];
		 }
		 while(left<right&&num[left]<=pivot)
		 {
		 	left++;
		 }
		 if(left<right)
		 {
		 	num[right]=num[left];
		 }
		 if(left<=right)
		 {
		 	num[left]=pivot;
		 }
	 }
	quickSort(num,left1,left-1);
	quickSort(num,right+1,right1);
		
 }

void countsort(int arry[],int n,int max)
 {
 	int ret[n]; 
	int count[max+1];
	int k=0;
	for(int i=0;i<max+1;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		count[arry[i]]++;
	}
	for(int i=0;i<max+1;i++)
	{
		if(count[i])
		{
			for(int j=0;j<count[i];j++)
			{
				ret[k++]=i;	
			}
		}
	}
	memcpy(arry,ret,sizeof(int)*n);
 }

void radixsort(int arry[],int maxterm,int n)
 {
 	int count[10];
 	int term=1;
 	int ret[n];
 	for(int i=1;i<=maxterm;i++)
 	{
 		arryClear(count,10);
 		int k=0;
 		for(int j=0;j<n;j++)
 		{
 			count[arry[j]/term%10]++;	
		 }
 		
 		for(int k=1;k<10;k++)                  //数组累加，统计小于等于下标的个数，得到结果数组里的顺序 
 		{
 			count[k]=count[k]+count[k-1];
		 }                               
		 for(int t=n-1;t>=0;t--)              //倒序保持稳定性 
		 {
		 	ret[--count[arry[t]/term%10]]=arry[t];
		 }
 		//myprint(ret,n);
 		
 		term*=10;
	 }
 	
 }
 
 int getmaxterm(int max)
 {
 	int maxterm=0;
 	while(max>0)
	{
		max/=10;
		maxterm++;
	}
	return maxterm;
 }
 
 void arryClear(int arry[],int n)
  {
  	for(int i=0;i<n;i++)
  	{
  		arry[i]=0;
	  }
  }
  
  void menu04()
{
	printf("\n\n*************************************************\n");
    	printf("*  1.快排                                       *\n"); 
    	printf("*  2.插入排序                                   *\n");
    	printf("*  3.归并排序                                   *\n");
    	printf("*  4.计数排序                                   *\n");
    	printf("*  5.基数计数排序                               *\n");
    	printf("*  6.退出                                       *\n");
    	printf("*************************************************\n\n");
    	printf("请输入指令编号(1-5):");
}
  
