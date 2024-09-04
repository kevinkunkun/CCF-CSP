#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)
#define first x
#define second y 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e8 + 10;

int n;
PII q[N];

struct Score
{
	int y, r;
	bool operator <(const Score& W)const
	{
		if (r != W.r) return r < W.r;
		else return y < W.y;
	}
}s[N];

int main()
{
	fastio;

	cin >> n;

	for (int i = 0; i < n; i++) cin >> q[i].x >> q[i].y;

	for (int i = 0; i < n; i++)
	{
		int y = q[i].x, res = 0;
		for (int j = 0; j < n; j++)
			if (q[j].x >= y && q[j].y == 1 || q[j].x < y && q[j].y == 0)
				res++;
		s[i] = { y,res };
	}

	sort(s, s + n);

	cout << s[n - 1].y << endl;

	return 0;
}