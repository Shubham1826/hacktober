#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,a[10],n,x,f=0,mid,beg,end;
	printf("Enter the no in the array you want");
	scanf("%d",&n);
	printf("Enter the elements in the array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the element you want to search in the array");
	scanf("%d",&x);
	beg=0;
	end=n-1;
	while(a[end]>=a[beg])
	{
		mid=(beg+end)/2;
		if(a[mid]==x)
		{
		printf("%d is present at %d position the array",x,mid+1);
		f=f+1;
		break;
	    }
	    else if(x<a[mid])
	    {
	    	end=mid-1;
	    	continue;
		}
		else if(x>a[mid])
		{
			beg=mid+1;
			continue;
		}
	
	}
	if(f==0)
	printf("Not present");
}
