#include <stdio.h>
#include <stdlib.h>

// function to compute and print the nth term of the sequence
void ComputeTerm(int n)
{
	// ak_3 stores the ak-3th term, ak_2 the ak-2th term, ak_1 the ak-1th 
	// term and ak the kth term
	int ak_3 = 1, ak_2 = 2, ak_1 = 3, ak;

	if(n == 1)
		ak = 1;
	else if(n == 2)
		ak = 2;
	else if(n == 3)
		ak = 3;
	else
	{
		for(int k=4; k<=n; k++)
		{
			ak = ak_2 + 2 * ak_3;

			// updating the values of ak_3, ak_2, ak_1
			ak_3 = ak_2;
			ak_2 = ak_1;
			ak_1 = ak;
		}
	}

	printf("The nth term of the sequence is %d.\n", ak);

	return;
}

int main()
{
	printf("Please enter n.\n");
    int n;
    scanf("%d", &n);

    if(n < 1)
    {
    	printf("Invalid Input: The value of n cannot be less than 1.\n");
    	return 0;
    }

    ComputeTerm(n);

    return 0;
}
