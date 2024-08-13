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
vector<string> s1, s2;//ʹ��vector��Ϊ�洢�ַ�������������

int main()
{
	fastio;

	cin >> n >> m;

	//¼���һ���ַ���
	while (n--)
	{
		string str;
		cin >> str;

		//�����ַ����������д�Сд���õ��ַ���ȫ��ת��ΪСд�ַ���
		for (auto& c : str)
			c = tolower(c);
		s1.push_back(str);//���õ����ַ�������vector������
	}

	//¼��ڶ����ַ���
	while (m--)
	{
		string str;
		cin >> str;

		//�����ַ����������д�Сд���õ��ַ���ȫ��ת��ΪСд�ַ���
		for (auto& c : str)
			c = tolower(c);
		s2.push_back(str);//���õ����ַ�������vector������
	}

	//ʹ��set�������������ַ�������֮��Ľ����벢��
	set<string> str1(s1.begin(), s1.end());//¼���һ���ַ������飬ȥ��
	set<string> str2(s2.begin(), s2.end());//¼��ڶ����ַ������飬ȥ��
	set<string> strs1,strs2;//���������µ��ַ������飬���ڴ洢�����ַ�������֮��Ľ����벢��

	//ͨ��set���������Ͻ����ķ���
	for (auto& str : str1) 
		if (str2.find(str) != str2.end()) 
			strs1.insert(str);

	//ͨ��set�е�union��������������ϲ����ķ���
	set_union(str1.begin(), str1.end(),
		str2.begin(), str2.end(),
		inserter(strs2, strs2.begin()));

	cout << strs1.size() << endl;//��������Ĵ�С
	cout << strs2.size() << endl;//��������Ĵ�С

	return 0;
}