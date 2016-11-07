/*
 * bitArrays.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Meenakshi
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */



/*	a[0] = S (modulo 2^31)
	for i = 1 to N-1
	    a[i] = a[i-1]*P+Q (modulo 2^31)*/
	int N, S, P, Q = 0;

	cin >> N >> S >> P >> Q;
	vector <int> array;

	array.push_back(S);

	for(int i = 0; i < N -1; ++i) {
		array.push_back(P + Q);
	}


	return 0;
}

