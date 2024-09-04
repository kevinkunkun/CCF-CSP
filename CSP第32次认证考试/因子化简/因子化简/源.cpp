#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 100010;

int q, k;
LL n;
bool st[N];
int ha[N];

void primes(LL n)
{
	for (int i = 2; i <= N; i++)
	{
		if (n < 2) return;
		if (st[i]) continue;
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				ha[i]++;
			}
		}
		for (int j = i * 2; j <= N; j += i) st[j] = true;
	}
}

int main()
{
	fastio;

	cin >> q;

	while (q--)
	{
		cin >> n >> k;

		memset(ha, 0, sizeof ha);

		primes(n);

		LL res = 1;
		for (int i = 0; i < N; i++)
		{
			if (ha[i] >= k)
				res *= pow(i, ha[i]);
		}

		cout << res << endl;
	}

	return 0;
}