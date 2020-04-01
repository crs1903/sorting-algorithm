#include<stdio.h>
#include<stdlib.h>
void insert(int*,int,int);
int main()
{
	int *arr,n;
	printf("Enter the number of elements in array:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=1;i<n;i++)
		insert(arr,i,n);
	for(int i=0;i<n;i++)
		printf("%d ",*(arr+i));
	printf("\n");
}
void insert(int *arr,int i,int n)
{
	int c=arr[i];
	while(i > 0 && c < arr[i-1])
	{
		arr[i]=arr[i-1];
		i--;
	}
	arr[i]=c;
}
