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

int n, m, k;//�Ƶꡢ���㡢ʳ����
int need[N][M];//need[i][j]��ʾ��i���Ƶ��Ƿ���Ҫ��j��ʳ��
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;//�ڽӱ����ݽṹ
int d[N][M];//Ԥ�������飬��d[i][j]��ʾ�ӵ�i���Ƶ꣨��Ϊjʳ�ĵļ��㣩����������Ҫʳ��j�ľƵ�����Ҫ�ľ������ֵ
int f[S], state[N];//״̬ת������f[S]��Ƶ�����ʳ�ĵĶ�����ѹ������洢����state[N]

//�ڽӱ�洢����
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

//���Ѻ���
PII dfs(int u, int fa, int v)
{
	PII res(0, -1);//res�У�x��ʾ��·���ĳ��ȣ�y��ʾ������������������һ����ľ��볤��
	if (need[u][v]) res.y = 0;//����������Ҫʳ��v��˵������Ҫ����˵㣬��ʼ��res.yΪ0����ʾ��ʱ�ڸ��ڵ㣬����Ϊ0
	for (int i = h[u]; ~i; i = ne[i])//�����ڽӱ�
	{
		int j = e[i];//ȡ�ӽڵ�Ϊj
		if (j == fa) continue;//����ӽڵ�Ϊ���ڵ㣬�������һ�α���
		auto t = dfs(j, u, v);//�ݹ鴦��ÿһ���ӽڵ�
		if (t.y != -1)//����˵���Ҫʳ��v�������res��x��y��ֵ
		{
			res.x += t.x + w[i] * 2;//res.xΪ·�����ȵ�����
			res.y = max(res.y, t.y + w[i]);//res.yΪ��������Զ���·������
		}
	}
	return res;//����·�����ֵ
}

//���ּ�麯��
bool check(int mid)
{
	memset(state, 0, sizeof state);//��ʼ��state����Ϊ0
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			if (d[i][j] <= mid)//�����·���ڶ��ֳ��Ľ����
				state[i] |= 1 << j;//���˽��������state������

	memset(f, 0x3f, sizeof f);//��ʼ��f����Ϊ�����
	f[0] = 0;//���õݹ������ʾ0000000000�������оƵ궼����Ҫʳ��ʱ�������Ϊ0
	for (int i = 0; i < 1 << k; i++)
		for (int j = 1; j <= n; j++)
			f[i | state[j]] = min(f[i | state[j]], f[i] + 1);//״̬ת��

	return f[(1 << k) - 1] <= m;//�����Ƿ���m�����ڵ�boolֵ
}

int main()
{
	fastio;

	cin >> n >> m >> k;

	//¼��ʳ����Ҫ���
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			cin >> need[i][j];

	//¼����
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}

	//״̬ѹ��dp
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
		{
			auto t = dfs(i, -1, j);
			if (t.y != -1) d[i][j] = t.x - t.y;
		}

	//����
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