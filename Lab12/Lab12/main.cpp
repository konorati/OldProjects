#include "FileFilter.h"


int main (void)
{
	ifstream in;
	ofstream out;
	FileFilter *file;

	in.open("Text.txt");
	out.open("Text2.txt");
	file = new Uppercase();
	file->doFilter(in, out);
	

	return 0;
}