#include "charnumber.h"
#include <iostream>
#include <string>	

void charcount(string filename)
{

	int count1 = 0;

	ifstream infile;
	infile.open(filename.data());   //���ļ����������ļ��������� 
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

	char c;


	infile >> noskipws;//����ַ����루�����ո�ͻس���
	while (infile >> c)
	{

		if (c >= 0 && c <= 255)
		{
			count1++;
		}
	}

	infile.close();//�ر��ļ������� 
	cout << "characters: " << count1 << endl;
}