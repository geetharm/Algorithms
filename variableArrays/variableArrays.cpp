/*
 * variableArrays.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Meenakshi
 */


#include <iostream>
using namespace std;

int main() {

	int numSeq = 0;
	int numQueries = 0;

	cin >> numSeq >> numQueries;

	int **ppArr = new int*[numSeq];

	for(int i = 0; i < numSeq; ++i) {
		int numSeqArr = 0;
		cin >> numSeqArr;

		ppArr[i] = new int[numSeqArr];

		for(int j = 0; j < numSeqArr; ++j) {
			cin >> ppArr[i][j];
		}
	}

	for(int i = 0; i < numQueries; ++i) {
		int arrCount, seqCount = 0;
		cin >> arrCount >> seqCount;

		cout << ppArr[arrCount][seqCount] << endl;
	}

	for(int i = 0; i < numSeq; ++i) {
		delete ppArr[i];
	}

	delete ppArr;
	return 0;
}



