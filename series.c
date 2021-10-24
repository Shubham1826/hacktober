//Fibonacci series

#include<stdio.h>

int main()
{
	int n,i;
	int n1=0,n2=1; //initializing 1st two terms
	int n3 = n1 + n2; //initializing 3rd term(i.e,sum of the previous 2 terms)

	printf("Enter the number : "); //taking input from user
	scanf("%d",&n);

	printf("Fibonacci series : %d %d ", n1, n2); //printing 1st two terms

    //for printing 3rd to n terms
	for (int i = 3; i <= n; ++i)
	{
		printf("%d ",n3);
		n1 = n2;
		n2 = n3;
		n3 = n1+n2;
	}
	
	return 0;
	
}