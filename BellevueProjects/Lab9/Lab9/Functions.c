#include "Functions.h"

int strLen(const char* str){
	int i = 0;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}


char *stringReverse(char *str){
	int i = 0, j = 0;
	char temp = '\0';
	for(i = 0, j = strLen(str)-1; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}

char *stringReversePoint(char *str){
	int i = 0, j = 0;
	char temp = '\0';
	char *tmpStr = str;
	char *tmpEnd = str + strLen(str) - 1;
	for(tmpStr, tmpEnd; tmpStr < tmpEnd; tmpStr++, tmpEnd--){
		temp = *tmpStr;
		*tmpStr = *tmpEnd;
		*tmpEnd = temp;
	}
	return str;
}

void setStudent(Student student, unsigned int id, double gpa, char *name){
	student.idNum = id;
	student.name = name;
	student.gpa = gpa;
}

char *stringCopy(char *destination, const char *source){
	int i = 0;
	for(i = 0; i < strLen(source); i++){
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

char *stringCat(char *destination, const char *source){
	int i = 0, j = 0;
	for(i = strLen(destination), j = 0; j < strLen(source); i++, j++){
		destination[i] = source[j];
	}
	destination[i] = '\0';
	return destination;
}

int stringCompare(const char *str1, const char *str2){
	int result = 0;
	int i = 0;
	while(result == 0 && i <= strLen(str1) && i <= strLen(str2)){
		if(str1[i] < str2[i]){
			result = -1;
		}
		else if(str1[i] > str2[i]){
			result = 1;
		}
		i++;
	}
	return result;
}

void stringSort(char str[][50]){
	int start = 0, end = 9, i = 0;
	char temp[50] = {'\0'};
	for(start = 0; start < end; end--){
		for(i = 0; i < end; i++){
			if(stringCompare(str[i], str[i+1]) == 1){
				strcpy(temp, str[i]);
				strcpy(str[i], str[i+1]);
				strcpy(str[i+1], temp);
			}
		}

	}
}

int findCEO(int list[4][2]){
	int i = 0, j = 0, found = 0;
	int *boss;
	while(found == 0 && i < 4){
		boss = (int *)list[i][1];
		if(*boss == list[i][0]){
			found = 1;
		}
		i++;
	}
	return i;
}