//============================================================================
// Name        : cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& numbers, int windowSize)
{
    vector<int> maxInSlidingWindows;
    if(numbers.size() >= windowSize && windowSize > 1)
    {
        deque<int> indices;

        for(int i = 0; i < windowSize; ++i)
        {
            while(!indices.empty() && numbers[i] >= numbers[indices.back()])
                indices.pop_back();

            indices.push_back(i);
        }

        for(int i = windowSize; i < numbers.size(); ++i)
        {
            maxInSlidingWindows.push_back(numbers[indices.front()]);

            while(!indices.empty() && numbers[i] >= numbers[indices.back()])
                indices.pop_back();
            if(!indices.empty() && indices.front() <= i - windowSize)
                indices.pop_front();

            indices.push_back(i);
        }
        maxInSlidingWindows.push_back(numbers[indices.front()]);
    }

    return maxInSlidingWindows;
}


void printKMax(int arr[], int n, int k){
   //Write your code here.
	vector<int> maxNumbers;
	vector<int> numbers (arr, arr+n);

	maxNumbers = maxInWindows(numbers, k);

	int size = maxNumbers.size();
	for(int i = 0; i < size; ++i) {
		cout << maxNumbers[i] << " ";
	}

}

int main(){

   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}



