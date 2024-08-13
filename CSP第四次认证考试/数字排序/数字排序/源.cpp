#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n;
int cnt[N];

//��ĿҪ��Ҫ���������ͬʱ��ǰ��������֣�����������ʱҪͨ����Ԫ�ṹ���������
struct Data
{
	int v, c;
	bool operator <(const Data& t)const
	{
		if (c != t.c) return c < t.c;
		else return v > t.v;
	}
}q[N];

int main()
{
	fastio;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	n = 0;
	for (int i = 0; i < N; i++)
		if (cnt[i])
			q[n++] = { i,cnt[i] };

	sort(q, q + n);

	for (int i = n-1; i >= 0; i--)
		cout << q[i].v << ' ' << q[i].c << endl;

	return 0;
}