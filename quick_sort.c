#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int pos(int* arr,int piv,int i,int t)
{	
	while(1)
	{
		while(arr[i]<piv)
			i++;
		
		while(arr[t]>piv)
			t--;
		
		if(i==t)
			return i;
		
		int c=arr[i];
		arr[i]=arr[t];
		arr[t]=c;
		
		if(arr[t]==arr[i])	
			t--;

	}
}
void quick(int *arr,int i,int j)
{
	if(i==j)
		return;
	
	int size=j-i+1;
	int p=i+rand()%size;
	p=pos(arr,arr[p],i,j);
	
	if(p>i)
		quick(arr,i,p-1);
	if(p<j)
		quick(arr,p+1,j);
}
int main()
{
	int n,*arr,i;
	printf("Enter the array size:\n");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter the aray:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	quick(arr,0,n-1);
	printf("\n\nThe sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}




