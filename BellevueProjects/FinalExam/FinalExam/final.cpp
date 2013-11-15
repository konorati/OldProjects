#include <iostream>
#include <string>

using namespace std;
double cube(double aNum, double bNum, double cNum)
{	
     return aNum * bNum * cNum;
}


void  moreValues(int aNum, int bNum = 3, float cNum = 4.3)
{
     int nNum;
     aNum = aNum + static_cast<int>(2 * bNum + cNum);
     nNum = aNum + bNum * cNum;
     cout << "aNum = " << aNum;
     return;
}
int main(){
	double num1, num2, num3;
	int int1, int2, int3;
	int value = 0;

	int June1997 = 8;

	num1 = 5.0; num2 = 6.0; num3 = 3.0;
	int1 = 4; int2 = 7; int3 = 8;
	value = cube (num1, int2, num3);
     moreValues(3, 0, 2.8);
	string number = "hello";
    //cout << number << endl;
	//moreValues(2, 3);
	

	system("pause");
	return 0;

}
