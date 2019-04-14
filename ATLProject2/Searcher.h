#pragma once
#include<string>
#include<vector>
using namespace std;
class Searcher
{
public:
	Searcher();
	~Searcher();
	string FindLines(string filename,string reg);
	string FindFiles(string MainDir, string regu);
	void GetMatchedFiles(string path, string regu, vector<string>& result);
	void FindMatchedFiles(string path, string regu, vector<string>& result);
	string FindAllFiles(string path, string regu);
	string FindInOneFile(string filename, string regu);
};

