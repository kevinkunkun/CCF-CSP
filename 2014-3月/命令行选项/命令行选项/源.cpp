#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 30;
int n;
bool o1[N], o2[N];
string ans[N];

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (str[i + 1] == ':' && i + 1 < str.size())
		{
			o2[str[i] - 'a'] = true;
			i++;
		}
		else o1[str[i] - 'a'] = true;

	cin >> n;
	getchar();
	for (int C = 1; C <= n; C++)
	{
		printf("Case %d:", C);
		getline(cin, str);
		stringstream ssin(str);
		vector<string> ops;
		while (ssin >> str) ops.push_back(str);
		for (int i = 0; i < 26; i++) ans[i].clear();
		for (int i = 1; i < ops.size(); i++)
		{
			if (ops[i][0] != '-' || ops[i][1] < 'a' || ops[i].size() != 2) break;
			int k = ops[i][1] - 'a';
			if (o1[k]) ans[k] = '*';
			else if (o2[k] && i + 1 < ops.size()) ans[k] = ops[i + 1], i++;
			else break;
		}
		for (int i = 0; i < 26; i++)
			if (ans[i].size())
			{
				cout << " -" << char(i + 'a');
				if (o2[i]) cout << ' ' << ans[i];
			}
		cout << endl;
	}
	return 0;
}