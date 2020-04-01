#include<stdio.h>
#include<stdlib.h>
void merge(int*,int,int,int);
void mergesort(int*,int,int);
int main()
{
	int i,arr[100],n;
	printf("Enter size of an array:\n");
	scanf("%d",&n);
	printf("Enter an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);	
	}
	mergesort(arr,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",*(arr+i));	
	}
	printf("\n");
	
}
void mergesort(int* arr,int i,int t)
{	
	if(i>=t)
		return;
	int m=(i+t)/2;
	mergesort(arr,i,m);
	mergesort(arr,m+1,t);
	merge(arr,i,m,t);
}
void merge(int* arr,int i,int m,int t)
{
	int n1=m-i+1,n2=t-m,p,q;
	int *L=(int*)malloc(n1*sizeof(int)),*R=(int*)malloc(n2*sizeof(int));
	for(p=0;p<n1;p++)
		L[p]=arr[i+p];
	for(q=0;q<n2;q++)
		R[q]=arr[m+1+q];
	p=q=0;
	int k=i;
	while(p<n1&&q<n2)
	{
		if(L[p]>R[q])
		{
			arr[k]=R[q];
			q++;		
		}
		else
		{
			arr[k]=L[p];
			p++;
		}
		k++;
	}
	while(p<n1)
	{
		arr[k]=L[p];
		k++;
		p++;	
	}
	while(q<n2)
	{
		arr[k]=R[q];
		k++;
		q++;	
	}	
}

