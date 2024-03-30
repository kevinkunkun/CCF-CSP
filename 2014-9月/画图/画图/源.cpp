#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;

int n;
bool st[N][N];

int main()
{
	cin >> n;
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				st[i][j] = true;
	}

	int res = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			res += st[i][j];

	cout << res << endl;
	return 0;
}