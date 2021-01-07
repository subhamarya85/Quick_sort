#include<stdio.h>



int quick(int A[],int n,int beg,int end,int *pivot)
{
	int left,right,temporary;
	left=beg;
	right=end;
	*pivot=beg;
step1:
	while(A[*pivot]<A[right]&&*pivot!=right)
		--right;
	if(*pivot==right)
		return 0;
	if(A[*pivot]>A[right])
	{
		temporary=A[*pivot];
		A[*pivot]=A[right];
		A[right]=temporary;
		*pivot=right;
	}
	goto step2;
step2:
	while(A[left]<A[*pivot]&&left!=*pivot)
		++left;
	if(left==*pivot)
		return 0;
	if(A[left]>A[*pivot])
	{
		temporary=A[left];
		A[left]=A[*pivot];
		A[*pivot]=temporary;
		*pivot=left;
	}
	goto step1;
}
void quick_sort(int A[],int n)
{
	int beg,end,pivot,top=-1;
	int lower[n],upper[n];
	if(n>1)
	{
		++top;
		lower[top]=0;
		upper[top]=n-1;
	}
	while(top!=-1)
	{
		beg=lower[top];
		end=upper[top];
		--top;
		quick(A,n,beg,end,&pivot);
		if(beg<pivot-1)
		{
			++top;
			lower[top]=beg;
			upper[top]=pivot-1;
		}
		if(pivot+1<end)
		{
			++top;
			lower[top]=pivot+1;
			upper[top]=end;
		}

	}
}
int main()
{
	int n;
	printf("enter the number of elements in a array");
	scanf("%d",&n);
	int A[n];
	printf("enter the elements:");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&A[i]);
	}
	quick_sort(A,n);
	printf("sorted array =");
	for(int i=0;i<n;++i)
	{
		printf(" %d ",A[i]);
	}
}
