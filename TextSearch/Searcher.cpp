#include "stdafx.h"
#include "Searcher.h"
#include<regex>

Searcher::Searcher()
{
}


Searcher::~Searcher()
{
}
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include<vector>
#include<io.h>
string Searcher::FindLines(string filename, string regu) {
	regex reg(regu);
		ifstream infile(filename);
		int line = 1;
		if (!infile) {
			cerr << "Can not open file " << filename << ", maybe it is used by other applications!\n";
			return "[]";
		}
		ostringstream os;
		os<< "[";
		string currline;

		while (getline(infile, currline))
		{
			if (regex_match(currline, reg))
			{
				if (line!=1)
				{
					os << " ";
				}
				os << line;
			}
			line++;
		}

		return os.str();
}
string Searcher::FindFiles(string path, string regu) {
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	ostringstream os;
	regex reg(regu);
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					os<<FindFiles(p.assign(path).append("/").append(fileinfo.name), regu);
			}
			else
			{
				string filename = p.assign(path).append("/").append(fileinfo.name);
				if (regex_match(fileinfo.name,reg))
				{
					os << filename << endl;
				}	
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
		return os.str();
	}
}
string Searcher::FindAllFiles(string path, string regu) {
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	ostringstream os;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					os << FindAllFiles(p.assign(path).append("/").append(fileinfo.name), regu);
			}
			else
			{
				string filename = p.assign(path).append("/").append(fileinfo.name);
				os << FindInOneFile(filename, regu);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
		return os.str();
	}
}
string Searcher::FindInOneFile(string filename, string regu) {
	regex reg(regu);
	ifstream infile(filename);
	int line = 1;
	if (!infile) {
		cerr << "Can not open file " << filename << ", maybe it is used by other applications!\n";
		return "";
	}
	ostringstream os;
	string currline;

	while (getline(infile, currline))
	{
		if (regex_match(currline, reg))
		{
			
			if (line != 1)
			{
				os << " ";
			}
			os << "Line "<<line<<" in file "<<filename<<"."<<endl;
		}
		line++;
	}

	return os.str();
}