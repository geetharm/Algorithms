/*
 * qsort.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: Meenakshi
 */
#include <iostream>
#include <sstream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const string FILENAME = "text.txt";
const int MAX = 10000;

int count = 0;

void swap(int &a, int &b)
{
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

int choosePivot(int array[], int left, int right)
{
	int middle = 0;
	int a,b, c = 0;
	middle = (left+right)/2;

	a = array[left];
	b = array[middle];
	c = array[right];

	cout << "Median" << left << " " << middle << " " << right << endl;
	cout << "Median" << array[left] << " " << array[middle] << " " << array[right] << endl;

	if(middle <= 1)
	{
		return array[middle];
	}
	else
	{
		if(a > b)
		{
			if(a < c)
				return a;
			else 	if(b >= c)
			{
				swap(array[left],array[middle]);
				return b;
			}
		}
		else
		{
			if(b < c)
			{
				swap(array[left],array[middle]);
				return b;
			}
			else if(a >= c)
				return a;
		}
		swap(array[left],array[right]);
		return c;
	}
}

int partition(int array[], int left, int right)
{
	int pivot = 0;
	int i = 0, j = 0;

#if 0
	//swap(array[left], array[right]);
#else
	pivot = choosePivot(array,left,right);
	cout << "pivot - left - right" << pivot << "  " << left << " " << right << endl;
#endif
	pivot = array[left];

	cout << "pivot - left - right" << pivot << "  " << left << " " << right << endl;
	i = left+1;

	for(j = left+1; j <= right; ++j)
	{
		//cout << array[j] << " " << pivot << endl;
		if(array[j] < pivot)
		{
			//cout << "inside swap" << array[j] << array[i] << endl;
			swap(array[i],array[j]);
			i += 1;
		}
	}

	//cout << "swapping pivot" << array[left] << " " << array[i-1] << endl;
	// swapping pivot in its correct position
	swap(array[left], array[i-1]);
	return (i-1);
}


int sort(int array[], int left, int right)
{
	int part =0;
	int length = 0;

	if(left >= right)
		return 0;
	length = (right - left+1);
	count += (length - 1);

	cout << "inside sort  ---  left : " << left << "  right :  " << right << endl;
	part = partition(array, left, right);
	cout << "partition" << part << endl;

	//cout << "count" << count << endl;
	sort(array, left, part-1);
	sort(array, part+1, right);
	return 0;
}


int main(int argc, char** argv)
{

#if 1
	ifstream inData;
	int array[MAX] = {0};
	int length =MAX;

	inData.open (FILENAME.c_str());       // open the file

	if (inData)
	{
		cout << "File opened" << endl;
		while(inData){
			for (int i = 0; i < MAX; ++i)
			{
				inData >> array[i];
			}
		}
		inData.close();          // close the file
	}
	else
	{
		cout << "Error opening text file " << FILENAME << endl;
		return 1;
	}

//	system("PAUSE");
#else
	int array[] = {3, 9, 8, 4, 6, 10, 2, 5, 7, 1};
	int length = 10;
//	int array[] = { 3, 8,4};
//	int length = 3;

	//int array[] = {8, 2, 11, 16, 13, 31, 14, 12, 4, 52, 17, 3,7,34,67,15,98,61,35,30,19,33};
	//int length = 22;

#endif
	sort(array, 0, length-1);

	cout << "sorted array values are" << endl;

	for(int i =0; i < length; ++i)
	{
		cout << array[i] <<  " ";
	}

	cout << endl << "Number of comparisons are:" << count << endl;
	return 0;
}

