#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>

using namespace std;

const int N = 1010;

int n, m;
vector<string> s1, s2;//使用vector作为存储字符串的数组容器

int main()
{
	fastio;

	cin >> n >> m;

	//录入第一个字符串
	while (n--)
	{
		string str;
		cin >> str;

		//遍历字符串，将所有大小写混用的字符串全部转化为小写字符串
		for (auto& c : str)
			c = tolower(c);
		s1.push_back(str);//将得到的字符串存入vector数组中
	}

	//录入第二个字符串
	while (m--)
	{
		string str;
		cin >> str;

		//遍历字符串，将所有大小写混用的字符串全部转化为小写字符串
		for (auto& c : str)
			c = tolower(c);
		s2.push_back(str);//将得到的字符串存入vector数组中
	}

	//使用set容器来求两个字符串数组之间的交集与并集
	set<string> str1(s1.begin(), s1.end());//录入第一个字符串数组，去重
	set<string> str2(s2.begin(), s2.end());//录入第二个字符串数组，去重
	set<string> strs1,strs2;//定义两个新的字符串数组，用于存储两个字符串数组之间的交集与并集

	//通过set求两个集合交集的方法
	for (auto& str : str1) 
		if (str2.find(str) != str2.end()) 
			strs1.insert(str);

	//通过set中的union函数求解两个集合并集的方法
	set_union(str1.begin(), str1.end(),
		str2.begin(), str2.end(),
		inserter(strs2, strs2.begin()));

	cout << strs1.size() << endl;//输出交集的大小
	cout << strs2.size() << endl;//输出并集的大小

	return 0;
}