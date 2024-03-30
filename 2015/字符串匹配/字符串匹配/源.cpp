#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

string get(string str)
{
	string res;
	for (auto c : str)
		res += tolower(c);
	return res;
}
int main()
{
	string S;
	cin >> S;
	int n,type;
	cin >>type>>n;
	while (n--)
	{
		string str;
		cin >> str;
		if (type && str.find(S) != -1) cout << str << endl;
		else if (!type && get(str).find(get(S)) != -1) cout << str << endl;
	}

	return 0;
}
