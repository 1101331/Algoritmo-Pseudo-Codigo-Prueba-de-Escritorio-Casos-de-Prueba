#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int digits(int);

int main()
{
	int num, d, sum, temp, depth = 0;
	char* buff = malloc(10);
	fputs("Ponga un numero: ", stdout);
	buff = fgets(buff, 10, stdin);
	num = atoi(buff);
	
	do
	{
		sum = 0;
		temp = num;
		d = digits(num);
		for(int i = (int)(pow(10, d - 1)); i > 0; i = i/10)  
		{
			sum += num / i;
			num = num % i;
			if (i == 1)
				depth++;
		}
		num = sum;
		printf("%d\n", sum);
	}while (digits(num) > 1);
	printf("Depth: %d\n", depth);
	
	return 0;
}

int digits(int n)
{
	int i = 1;
	while ((n/10) > 0)
	{
		n = n / 10;
		i++;
	}
	
	return i;
}