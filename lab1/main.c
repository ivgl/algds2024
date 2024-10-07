#include "NumberOfRoutes.h"

int main()
{
	int N, K;
	printf("input N, K: ");
	scanf_s("%d %d", &N, &K);
	printf("%d", NumberOfRoutesAll(N, K));
	return 0;
}