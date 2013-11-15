#include "FileFilter.h"

FileFilter::FileFilter()
{
}
FileFilter::~FileFilter()
{

}
void FileFilter::doFilter(ifstream &in, ofstream &out)
{
	char tempc;
	while(in.good())
	{
		tempc = (char)(in.get());
		tempc = transform(tempc);
		out << tempc;
	}
}
char FileFilter::transform(char ch)
{
	return ch;
}

Encrypt::Encrypt(int newEncrypt)
{
	mEncryption = newEncrypt;
}
Encrypt::~Encrypt()
{
}
void Encrypt::doFilter(ifstream &in, ofstream &out)
{
	char tempc;
	while (in.good())
	{
		tempc = (char)(in.get());
		tempc = transform(tempc);
		out << tempc;
	}
}
char Encrypt::transform(char ch)
{
	if((ch >= 'a') &&  (ch <= 'z'))
	{
		return 'A' + ((ch -'a') + (mEncryption % 25));
	}
	else if ((ch >= 'A') && (ch < 'Z'))
	{
		return 'A' + ((ch-'A') + (mEncryption %25));
	}
	else 
	{
		return ch;
	}
}

Uppercase::Uppercase()
{
}
Uppercase::~Uppercase()
{
}
void Uppercase::doFilter(ifstream &in, ofstream &out)
{
	char tempc;
	while (in.good())
	{
		tempc = (char)(in.get());
		tempc = transform(tempc);
		out << tempc;
	}
}
char Uppercase::transform(char ch)
{
	return toupper(ch);
}

CarbonCopy::CarbonCopy()
{
}
CarbonCopy::~CarbonCopy()
{
}
void CarbonCopy::doFilter(ifstream &in, ofstream &out)
{
	char tempc;
	while (in.good())
	{
		tempc = (char)(in.get());
		tempc = transform(tempc);
		out << tempc;
	}
}
char CarbonCopy::transform(char ch)
{
	return ch;
}

DoubleSpace::DoubleSpace()
{
}
DoubleSpace::~DoubleSpace()
{
}
void DoubleSpace::doFilter(ifstream &in, ofstream &out)
{
	char tempc;
	while (in.good())
	{
		tempc = (char)(in.get());
		if(tempc == '\n' || tempc == ' ')
		{

			out << tempc << tempc;
		}
		else
		{
			out << tempc;
		}
	}
}
char DoubleSpace::transform(char ch)
{
	return 0;
}