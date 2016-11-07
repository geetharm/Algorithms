/*
 * workshops.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Meenakshi
 */

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

typedef struct {
    int start_time;
    int duration;
    int end_time;
}Workshop;

typedef struct {
    int numOfWorkshops;
    Workshop *arrayWorkshop;
}Available_Workshops;



Available_Workshops * initialize(int start_time[], int duration[], int n) {

	Available_Workshops *availWorkshop = NULL;

	availWorkshop = (Available_Workshops*) malloc(sizeof(Available_Workshops));

    availWorkshop->arrayWorkshop = (Workshop*) malloc(n * sizeof (Workshop));
	availWorkshop->numOfWorkshops = n;

    for(int i = 0; i < n; ++i) {
        availWorkshop->arrayWorkshop[i].start_time = start_time[i];
        availWorkshop->arrayWorkshop[i].end_time = start_time[i] + duration[i];
        availWorkshop->arrayWorkshop[i].duration = duration[i];
    }
    return availWorkshop;
}

int CalculateMaxWorkshops (Available_Workshops* pAvailWorkshop) {
    int total = 0;

    int n = pAvailWorkshop->numOfWorkshops;

    for(int i = 0; i < n; ) {

    	for( int j = i + 1; j < n; ++j) {
            if(pAvailWorkshop->arrayWorkshop[i].end_time <= pAvailWorkshop->arrayWorkshop[j].start_time) {
            	cout << "available workshop: " << i << endl;
                total += 1;
                if(j == n - 1){
                	i = n - 2;
                } else {
                	i = j;
                }
                break;
            }
        }
    }
    return total;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}



