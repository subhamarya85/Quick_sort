#include<stdio.h>

void quick_sort(int A[],int);
int quick(int A[],int,int,int,int*);



int main()
{
	int A[]={44,33,11,55,77,90,40,60,22,88};
	quick_sort(A,10);
	for(int i=0;i<=11;++i)
	printf(" %d ",A[i]);

}
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
		return ;
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
		return ;
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
	int lower[10],upper[10];
	if(n>1)
	{
		++top;
		lower[top]=beg;
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
