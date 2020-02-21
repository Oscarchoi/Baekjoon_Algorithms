#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int digit;
	scanf("%d", &digit);

	long long int(*stairNumCount)[10] = (long long int(*)[10])malloc((digit + 1) * sizeof(long long int[10]));

	for (int j = 0; j < 10; j++)
	{
		stairNumCount[1][j] = 1;
	}
    //stairNumCount[1] = {1,1,1,1,1,1,1,1,1,1} 로 초기값 설정
	
	for (int i = 2; i <= digit; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) stairNumCount[i][j] = stairNumCount[i - 1][1];
			else if (j == 9) stairNumCount[i][j] = stairNumCount[i - 1][8];
			else stairNumCount[i][j] = (stairNumCount[i - 1][j - 1] + stairNumCount[i - 1][j + 1]) % 1000000000;
		}
	}

	long long int result = 0;
	for (int i = 1; i < 10; i++)
	{
		result += stairNumCount[digit][i];
	}


	printf("%lld", result%=1000000000);
	
	free(stairNumCount);


	return 0;
}