#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int ha[N];

int main()
{
	fastio;

	cin >> n >> k;

	int res = 0;
	memset(ha, 0, sizeof ha);
	ha[0] = -1e8;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		if (ha[y] == 0) res++;
		ha[x]++;
	}

	cout << res << endl;
	return 0;
}