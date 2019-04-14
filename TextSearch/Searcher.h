#pragma once
#include<string>
using namespace std;
class Searcher
{
public:
	Searcher();
	~Searcher();
	string FindLines(string filename,string reg);
	string FindFiles(string MainDir, string regu);
	string FindAllFiles(string path, string regu);
	string FindInOneFile(string filename, string regu);
};

