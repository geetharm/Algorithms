/*
 * Arrays.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Meenakshi
 */

#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int num = 0;

    scanf("%d\n", &num);

    int array[num] = {0};
    for(int i = 0; i < num; ++i){
        scanf("%d ", &array[i]);
    }

    for(int j = num; j > 0; --j) {
        printf("%d ", array[j-1]);
    }

    return 0;
}


