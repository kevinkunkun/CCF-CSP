#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1010, MOD = 1e9 + 7;

int n;
int C[N][N];

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
		if (!j)
		{
			C[i][j] = 1;
		}
		else
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}

	int res = 0;
	for (int k = 2; k <= n - 2; k++)
	{
		res = (res + (LL)C[n - 1][k] * (k - 1) * (n - k - 1)) % MOD;
	}
	cout << res << endl;
	return 0;
}