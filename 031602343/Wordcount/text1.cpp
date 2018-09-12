#include "pch.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include "charnumber.h"
#include "charnumber.cpp"
#include "linenumber.h"
#include "linenumber.cpp"
#include "wordnumber.h"
#include "wordnumber.cpp"
using  namespace std;


int main(int argc, const char* argv[])
{
	int countword(string filename);
	int i;
	for (i = 1; i < argc; i++)
	{
		string filename = argv[i];
		charcount(filename);
		linecount(filename);
		
		frequency(filename);//统计最多的10个单词及其词频
		
		
	}
	return 0;
}