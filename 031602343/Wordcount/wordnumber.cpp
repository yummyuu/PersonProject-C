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
	regex WordPatternreg("^[a-z]{4}[a-z0-9]*");//我们要匹配的单词的正则式
	ifstream ifs(filename);//强制读取文件内容
	while (ifs >> s)
	{
		int l = s.length();//
		for (int i = 0; i < l; i++)
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] = s[i] + 32;
			}
		}//将大写转换成小写
		const std::sregex_token_iterator end;
		for (sregex_token_iterator wordIter(s.begin(), s.end(), WordPatternreg); wordIter != end; wordIter++)
		{//在一行文本中逐个找出单词
																															 //cout<<*wordIter<<endl;//每个单词
			find[*wordIter]++;//单词计数
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

	int count3 = ci.size();//统计数组里单词的个数
	cout << "word:" << count3 << endl;

	if (ci.size() < 10)
	{
		size = ci.size();
		cout << "单词不超过10个" << endl;
	}
	vector<pair<string, int>>::iterator vit;

	for (vit = ci.begin(); vit != ci.begin() + size; vit++)
	{
		cout << "<" << vit->first << ">:" << " " << vit->second << endl;
	}
}