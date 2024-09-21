#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m, p, q;
int a[N];

int main()
{
	fastio;

	cin >> n >> m >> p >> q;

	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[k];
			k++;
		}

	k = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout << a[k] << ' ';
			k++;
		}
		cout << endl;
	}

	return 0;
}
