#include "wordnumber.h"
#include <vector>
#include <string>
#include <map>
#include <regex>

bool findword(pair<string, int> elem1, pair<string, int> elem2)
{
	return elem1.second > elem2.second;
}
void frequency(string  filename)
{
	string s;
	map<string, int> find;
	regex WordPatternreg("^[a-z]{4}[a-z0-9]*");//����Ҫƥ��ĵ��ʵ�����ʽ
	ifstream ifs(filename);//ǿ�ƶ�ȡ�ļ�����
	while (ifs >> s)
	{
		int l = s.length();//
		for (int i = 0; i < l; i++)
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] = s[i] + 32;
			}
		}//����дת����Сд
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(s.begin(), s.end(), WordPatternreg); wordIter != end; wordIter++)
		{//��һ���ı�������ҳ�����
																															 //cout<<*wordIter<<endl;//ÿ������
			find[*wordIter]++;//���ʼ���
		}
	}
	ifs.clear();
	ifs.seekg(0);

	vector<pair<string, int>> ci;
	for (map<string, int>::iterator iter = find.begin(); iter != find.end(); iter++)
	{
		ci.push_back(pair<string, int>(iter->first, iter->second));
	}
	sort(ci.begin(), ci.end(), findword);
	int size = 10;

	int count3 = ci.size();//ͳ�������ﵥ�ʵĸ���
	cout << "word:" << count3 << endl;

	if (ci.size() < 10)
	{
		size = ci.size();
		cout << "���ʲ�����10��" << endl;
	}
	vector<pair<string, int>>::iterator vit;

	for (vit = ci.begin(); vit != ci.begin() + size; vit++)
	{
		cout << "<" << vit->first << ">:" << " " << vit->second << endl;
	}
}