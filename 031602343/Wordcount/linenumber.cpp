#include "linenumber.h"
#include <string>
#include <iostream>

void linecount(string filename)//逐行读入
{
	int count2 = 0;
	string line;
	ifstream file(filename);//强制读取文件内容
	while (getline(file, line))
	{
		int l = line.length();
		for (int i = 0; i < l; i++)
		{
			if (line[i] != 13 && line[i] != 10 && line[i] != 32)
			{
				count2++;
				break;
			}//查找本行中是否有除了空格、换行、回车外的字符
		}
	}
	cout << "line:" << count2 << endl;
	file.clear();
	file.seekg(0);
}