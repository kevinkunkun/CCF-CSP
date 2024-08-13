#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int hash_a[N], hash_l[N];

int main()
{
	fastio;

	cin >> n >> m;

	memset(hash_a, 0, sizeof hash_a);
	memset(hash_l, 0, sizeof hash_l);

	while (n--)
	{
		int hash_w[N];
		memset(hash_w, 0, sizeof hash_w);

		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int t;
			cin >> t;
			hash_w[t]++, hash_a[t]++;
		}

		for (int i = 1; i <= m; i++)
			if (hash_w[i] != 0)
				hash_l[i]++;

		
	}

	for (int i = 1; i <= m; i++)
		cout << hash_l[i] << ' ' << hash_a[i] << endl;

	return 0;
}