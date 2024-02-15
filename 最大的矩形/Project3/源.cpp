#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int h[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = i;
		while (l > 0 && h[l] >= h[i])
		{
			l--;
		}
		while (r <= n && h[r] >= h[i])
		{
			r++;
		}
		res = max(res, h[i] * (r - l - 1));
	}
	cout << res << endl;
	return 0;
}
