#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 15;

int n, m;
int w[N][M];

int main()
{
	fastio;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> w[i][j];

	for (int i = 1; i <= n; i++)//ö��ÿһ���ֿ�
	{
		int id = 0;
		for (int j = 1; j <= n; j++)//����ö��ÿһ���ֿ�
		{
			bool is_bigger = true;
			for (int k = 1; k <= m; k++)//ö��ÿһά
				if (w[j][k] <= w[i][k])
				{
					is_bigger = false;
					break;
				}

			if (is_bigger)
			{
				id = j;
				break;
			}
		}

		cout << id << endl;
	}

	return 0;
}