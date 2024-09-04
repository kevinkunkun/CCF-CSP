#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 110, M = 10, S = 1 << M;

int n, m, k;//酒店、检查点、食材数
int need[N][M];//need[i][j]表示第i个酒店是否需要第j类食材
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;//邻接表数据结构
int d[N][M];//预处理数组，的d[i][j]表示从第i个酒店（作为j食材的检查点）走完所有需要食材j的酒店所需要的距离最大值
int f[S], state[N];//状态转移数组f[S]与酒店所需食材的二进制压缩记忆存储数组state[N]

//邻接表存储函数
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

//深搜函数
PII dfs(int u, int fa, int v)
{
	PII res(0, -1);//res中，x表示此路径的长度，y表示到达距离树根距离最大一个点的距离长度
	if (need[u][v]) res.y = 0;//如果这个点需要食材v，说明汽车要开向此点，初始化res.y为0，表示此时在根节点，距离为0
	for (int i = h[u]; ~i; i = ne[i])//遍历邻接表
	{
		int j = e[i];//取子节点为j
		if (j == fa) continue;//如果子节点为父节点，则进行下一次遍历
		auto t = dfs(j, u, v);//递归处理每一个子节点
		if (t.y != -1)//如果此点需要食材v，则更新res的x与y的值
		{
			res.x += t.x + w[i] * 2;//res.x为路径长度的两倍
			res.y = max(res.y, t.y + w[i]);//res.y为树根到最远点的路径长度
		}
	}
	return res;//返回路径最大值
}

//二分检查函数
bool check(int mid)
{
	memset(state, 0, sizeof state);//初始化state数组为0
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			if (d[i][j] <= mid)//如果此路径在二分出的结果中
				state[i] |= 1 << j;//将此结果保存至state数组中

	memset(f, 0x3f, sizeof f);//初始出f数组为无穷大
	f[0] = 0;//设置递归基，表示0000000000，即所有酒店都不需要食材时检查点个数为0
	for (int i = 0; i < 1 << k; i++)
		for (int j = 1; j <= n; j++)
			f[i | state[j]] = min(f[i | state[j]], f[i] + 1);//状态转移

	return f[(1 << k) - 1] <= m;//返回是否在m个以内的bool值
}

int main()
{
	fastio;

	cin >> n >> m >> k;

	//录入食材需要情况
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			cin >> need[i][j];

	//录入树
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}

	//状态压缩dp
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
		{
			auto t = dfs(i, -1, j);
			if (t.y != -1) d[i][j] = t.x - t.y;
		}

	//二分
	int l = 0, r = 2e8;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r << endl;

	return 0;
}