#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <class T>
void selectionSort (T arr[], int size)
{
	int index;
	int unsorted = size;
	for(int i = 0; i < size-1; i++, unsorted--)
	{
		index = 0;
		for(int j = 1; j < unsorted; j++)
		{
			if(arr[index] < arr[j])
			{
				index = j;
			}
		}
		swap(arr, unsorted, index);
	}
};

template <class T>
void swap(T arr[], int unsorted, int index)
{
		T temp = arr[unsorted-1];
		arr[unsorted-1] = arr[index];
		arr[index] = temp;
}

template <class T>
void print(T arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


#endif