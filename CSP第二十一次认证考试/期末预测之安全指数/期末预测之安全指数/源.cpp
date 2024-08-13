#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int main()
{
	fastio;

	cin >> n;

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		res += a * b;
	}

	int ans = max(0, res);

	cout << ans << endl;

	return 0;
}