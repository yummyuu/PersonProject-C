#include "charnumber.h"
#include <iostream>
#include <string>	

void charcount(string filename)
{

	int count1 = 0;

	ifstream infile;
	infile.open(filename.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	char c;


	infile >> noskipws;//逐个字符读入（包括空格和回车）
	while (infile >> c)
	{

		if (c >= 0 && c <= 255)
		{
			count1++;
		}
	}

	infile.close();//关闭文件输入流 
	cout << "characters: " << count1 << endl;
}