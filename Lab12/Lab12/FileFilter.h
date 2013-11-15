#ifndef FILE_FILTER_H
#define FILE_FILTER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileFilter
{
	public:
		FileFilter();
		~FileFilter();
		virtual void doFilter(ifstream &in, ofstream &out)=0;
		virtual char transform(char ch)=0;
	private:
};

class Encrypt: public FileFilter
{
	public:
		Encrypt(int newEncrypt = 0);
		~Encrypt();
		void doFilter(ifstream &in, ofstream &out);
		char transform(char ch);
	private:
		int mEncryption;
};

class Uppercase: public FileFilter
{
	public:
		Uppercase();
		~Uppercase();
		void doFilter(ifstream &in, ofstream &out);
		char transform(char ch);
	private:

};

class CarbonCopy: public FileFilter
{
	public:
		CarbonCopy();
		~CarbonCopy();
		void doFilter(ifstream &in, ofstream &out);
		char transform(char ch);
	private:
};

class DoubleSpace: public FileFilter
{
	public:
		DoubleSpace();
		~DoubleSpace();
		void doFilter(ifstream &in, ofstream &out);
		char transform(char ch);
	private:

};


#endif