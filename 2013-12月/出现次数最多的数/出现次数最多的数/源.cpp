#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;
int n;
int s[N];

int main()
{
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		s[x]++;
	}
	int res = 0;
	for (int i = 1; i < N; i++)
		if (s[i] > s[res])
			res = i;

	cout << res << endl;
	return 0;
}