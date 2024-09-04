#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
int n, a, b;

int main()
{
	fastio;

	cin >> n >> a >> b;

	LL res = 0;
	while (n--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = max(x1, 0), x2 = min(x2, a), y1 = max(y1, 0), y2 = min(b, y2);
		if (x2 >= x1 && y2 >= y1)
			res += (x2 - x1) * (y2 - y1);
	}
	cout << res << endl;

	return 0;
}