/*
 * mincut.cpp
 *
 *  Created on: Nov 7, 2014
 *      Author: Meenakshi
 */
#include<algorithm>
#include <iostream>
#include<fstream>
#include<sstream>
#include<iterator>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<map>
#include<vector>
#include<string>
#include<list>

using namespace std;

map<int, vector<int> > edges;
list<int>  vertexes;

int contractEdge(int vrtx1, int vrtx2)
{
	vector<int> vector1, vector2, newVector;
	int mapNo = 0;
	int links = 0;

	//vrtx1 = 1;
	//vrtx2 = 3;

	//cout << "vertexes to be contracted" << vrtx1 << vrtx2 << endl;
	vector1 = edges[vrtx1];
	vector2 = edges[vrtx2];

	newVector.reserve(newVector.size() + vector1.size() + vector2.size());
	newVector.insert(newVector.end(), vector1.begin(), vector1.end());
	newVector.insert(newVector.end(), vector2.begin(), vector2.end());

	/*cout << "before erasing " << endl;
	vector<int>::iterator vec = newVector.begin();
	while(vec != newVector.end())
	{
		cout << *vec << " ";
		++vec;
	}
	cout << endl;*/

	newVector.erase(remove(newVector.begin(), newVector.end(), vrtx1), newVector.end());
	newVector.erase(remove(newVector.begin(), newVector.end(), vrtx2), newVector.end());

	/*cout << "after erasing " << endl;
	vec = newVector.begin();
	while(vec != newVector.end())
	{
		cout << *vec << " ";
		++vec;
	}
	cout << endl;*/

	// add in the last position
	mapNo = vertexes.back();

	++mapNo;
	edges[mapNo] = newVector;
	vertexes.push_back(mapNo);

	//cout << "size after adding " << edges.size() << endl;

	edges.erase(vrtx1);
	edges.erase(vrtx2);
	vertexes.remove(vrtx1);
	vertexes.remove(vrtx2);

	// replace values
	for( map<int,vector<int> >::iterator it=edges.begin(); it!=edges.end(); ++it)
	{
		links = 0;
		//cout << (*it).first <<"   ";
		for( vector<int>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			//cout << *lit << " ";
			if((*lit == vrtx1 ) || (*lit == vrtx2))
			{
				*lit = mapNo;
				//cout << *lit << " ";
			}
			++links;
		}
		//cout << "          ";
	}
	//cout << "Links : " << links << endl;
	return links;
}

int getRandomEdge()
{
/*1. parse through the map sequentially with the iterator
2. get the size of the vector and feed as input for srand funtion
3. get the random number and contract this 2 vertices
*/
	int size = 0;
	int random = 0;
	int vrtx = 0;
	int links = 0;

	while(edges.size() > 2)
	{
		vrtx = vertexes.front();
		//cout << "vertex" << vrtx << endl;
		vector<int> vec = edges[vrtx];

		if(vec.empty())
		{
			cout << "container is empty" << endl;
			continue;
		}
		size = vec.size();
		//cout << "size of edges: " << size << endl;
		random = rand() % size + 0;
		//cout << "random " << random << " ";
		links = contractEdge(vrtx, vec[random]);
	}
	//cout << " No Of links: " << links << endl;
	return links;
}

void addInput()
{
	string lineData;
	int num = 0;
	ifstream input("numbers.txt");

	while(getline(input, lineData))
	{
		vector<int> row;
		int mapNo = 0;

		istringstream iss(lineData);
		iss >> mapNo;

		while(iss >> num)
			row.push_back(num);
		edges[mapNo] = row;
		vertexes.push_back(mapNo);
	}

	cout << "Numberof vertex: " << edges.size() << endl;

	/*for( map<int,vector<int> >::iterator it=edges.begin(); it!=edges.end(); ++it)
	{
		cout << (*it).first <<"   ";
		for( vector<int>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			cout << *lit << " ";
		}
		cout << "            ";
	}
	cout << endl;*/
}


int main(int argc, char** argv)
{
	int links = 0;
	srand (time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		edges.clear();
		vertexes.clear();
		addInput();
		links = getRandomEdge();
		cout << "Links: " << links << endl;
	}
}
