#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55;

int n, m;
char g[N][N];
bool st1[N][N], st2[N][N];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

bool check(int x, int y, int k)
{
	char c = g[x][y];
	if (c == 'S' || c == 'T' || c == '+') return true;
	if (c == '-' && k % 2 == 1) return true;
	if (c == '|' && k % 2 == 0) return true;
	if (c == '.' && k == 2) return true;
	return false;
}

void dfs1(int x, int y)
{
	st1[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
		if (st1[a][b]) continue;
		if (check(x, y, i)) dfs1(a, b);
	}
}

void dfs2(int x, int y)
{
	st2[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
		if (st2[a][b]) continue;
		if (check(a, b, i ^ 2)) dfs2(a, b);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> g[i];

	int tx, ty;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'S') dfs1(i, j);
			else if (g[i][j] == 'T')
			{
				tx = i, ty = j;
				dfs2(i, j);
			}

	if (!st1[tx][ty]) puts("I'm stuck!");
	else
	{
		int res = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
				if (st1[i][j] && !st2[i][j])
					res++;
		cout << res << endl;
	}

	return 0;
}