#include "linenumber.h"
#include <string>
#include <iostream>

void linecount(string filename)//���ж���
{
	int count2 = 0;
	string line;
	ifstream file(filename);//ǿ�ƶ�ȡ�ļ�����
	while (getline(file, line))
	{
		int l = line.length();
		for (int i = 0; i < l; i++)
		{
			if (line[i] != 13 && line[i] != 10 && line[i] != 32)
			{
				count2++;
				break;
			}//���ұ������Ƿ��г��˿ո񡢻��С��س�����ַ�
		}
	}
	cout << "line:" << count2 << endl;
	file.clear();
	file.seekg(0);
}