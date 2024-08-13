#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n;
int g[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);

	for (int i = 2; i <= n * 2; i++)
		if (i % 2 == 0)
		{
			for (int j = i - 1; j; j--)
				if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
					printf("%d ", g[j][i - j]);
		}
		else
		{
			for (int j = 1; j < i; j++)
				if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
					printf("%d ", g[j][i - j]);
		}
}