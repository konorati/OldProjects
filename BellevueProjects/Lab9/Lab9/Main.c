#include "Functions.h"

int main(void){

	int compared = -8, i = 0;
	char str[8] = "bananas";
	char dest[30] = {'\0'};
	char str2[8] = "alfalfa";
	char arrStrings[10][50] = {
		{"cat"}, {"dog"}, {"bird"}, {"horse"}, {"fly"}, {"spider"}, {"dog"}, {"frog"}, {"antelope"}, {"kite"}
	};
	Student student1;

	int arr[4][2] = {{1},{2},{3},{4}};
	int *a, *b, *c, *d;
	int y = 1, z = 8, x = 2;
	a = &x;
	b = &x;
	c = &y;
	d = &z;
	arr[1][1] = (int)a;
	arr[2][1] = (int)b;
	arr[3][1] = (int)c;
	arr[4][1] = (int)d;

	//i = findCEO(arr);
	//printf("CEO is employee number: %d", i+1);

	setStudent(student1, 10874126, 3.8, "Kristin Onorati");


	/*stringReverse(str);
	printf("%s\n", str);
	stringReversePoint(str);
	printf("%s\n", str);
	stringCopy(dest, str);
	printf("%s\n", dest);
	stringCat(dest, str);
	printf("%s\n", dest);
	compared = stringCompare(str, str2);
	printf("%d\n", compared);
	compared = stringCompare(str, dest);
	printf("%d\n", compared);
	compared = stringCompare(str, str);
	printf("%d\n", compared);
	stringSort(arrStrings);
	for(i = 0; i < 10; i++){
		printf("%s\n", arrStrings[i]);
	}*/



	return 0;
}