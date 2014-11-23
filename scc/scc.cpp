/*
 * scc.cpp
 *
 *  Created on: Nov 12, 2014
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
#include<stack>
using namespace std;

map<int, vector<int> > edges;
map<int, vector<int> > revEdges;
map<int, int> leader;

stack<int> orderedVertex;
bool *iexplored;
int leaderVertex = 0;
int maxNode = 0;

void addInput()
{
	string lineData;
	int num = 0;
	ifstream input("SCC.txt");
	int mapNo = 0;

	while(getline(input, lineData))
	{
		vector<int> row;

		istringstream iss(lineData);
		iss >> mapNo;
		iss >> num;

		//cout << "vertex " << mapNo << " edge " << num << endl;
		edges[mapNo].push_back(num);
		if(maxNode < mapNo)
			maxNode = mapNo;
		if(maxNode < num)
			maxNode = num;
	}

	cout << "Numberof vertex: " << maxNode << endl;

/*	for( map<int,vector<int> >::iterator it=edges.begin(); it!=edges.end(); ++it)
	{
		cout << (*it).first <<"   ";
		for( vector<int>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			cout << *lit << " ";
		}
		cout << "              ";
	}*/
	cout << endl;
}

void reverseGraph()
{
	for( map<int,vector<int> >::iterator it=edges.begin(); it!=edges.end(); ++it)
	{
		for( vector<int>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			//cout << (*it).first <<"       " << *lit << endl;
			revEdges[*lit].push_back((*it).first);
		}
	}

//	cout << "reverse graph" << endl;

	/*for( map<int,vector<int> >::iterator it=revEdges.begin(); it!=revEdges.end(); ++it)
	{
		cout << (*it).first <<"   ";
		for( vector<int>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			cout << *lit << " ";
		}
		cout << "          ";
	}*/
	cout << endl;
}

void depthFirstSearch(int startVertex)
{
	iexplored[startVertex] = true;

	//cout << endl << "vertex: " << startVertex  << endl;
	for( vector<int>::iterator it = edges[startVertex].begin(); it !=  edges[startVertex].end(); ++it )
	{
		//cout << "edges : "<<*it << " ";
		if(!iexplored[*it])
		{
			//cout << "recursing vertex " << *it << "      ";
			depthFirstSearch(*it);
		}
	}
	orderedVertex.push(startVertex);
	//cout << endl;
}

void firstDFSLoop()
{
	for (int i = 1; i <= maxNode; ++i)
	{
		if(!iexplored[i])
		{
			depthFirstSearch(i);
		}
	}
}

void insertLeader(int leaderVertex)
{
	map<int, int>::iterator it;

	it = leader.find(leaderVertex);

	if(it == leader.end())
	{
		//cout << "vertex doesnt exist" << endl;
		leader[leaderVertex] = 1;
	}
	else
	{
		int count =it->second;
		++count;
		//cout << "value of leadervertex: " << leaderVertex << "      "<<  count << endl;
		leader[leaderVertex] = count;
	}
}

void scc(int startVertex)
{
	iexplored[startVertex] = true;

	insertLeader(leaderVertex);

	//cout << "vertex " << startVertex << "       Leader vertex: " << leaderVertex << endl;

	for( vector<int>::iterator it = revEdges[startVertex].begin(); it !=  revEdges[startVertex].end(); ++it )
	{
		//cout << "edges : "<<*it << " ";
		if(!iexplored[*it])
		{
			//cout << "recursing vertex " << *it << "      ";
			scc(*it);
		}
	}
	//cout << endl;
}


void secondDFSLoop()
{
	int vrtx = 0;

	while(!orderedVertex.empty())
	{
		vrtx = orderedVertex.top();
		orderedVertex.pop();
		//cout << "vertex popped : " << vrtx << endl;
		if(!iexplored[vrtx])
		{
			leaderVertex = vrtx;
			scc(vrtx);
		}
	}
}

void printLeaderMap()
{
	vector<int> vecLeader;
	for (map<int, int>::iterator it = leader.begin(); it!= leader.end(); ++it)
	{
		vecLeader.push_back(it->second);
		//cout << "SCC value is  :  "<<it->first << "    Count is :    " << it->second << endl;
	}

	sort(vecLeader.begin(), vecLeader.end());

	reverse(vecLeader.begin(), vecLeader.end());

	for (int i = 0; i < 5; ++i)
		cout << vecLeader.at(i) << endl;

}

int main(int argc, char** argv)
{
	addInput();

	iexplored = (bool*) malloc(sizeof(bool) * maxNode);

	if(!iexplored)
	{
		cout << "memory allocation failed for explored" << endl;
	}

	for(int i = 1; i <= maxNode; ++i)
	{
		iexplored[i] = false;
	}
	firstDFSLoop();

	cout << "completed First DFS" << endl;
	reverseGraph();

	cout << "reverse graph" << endl;
	for(int i = 1; i <= maxNode; ++i)
	{
		iexplored[i] = false;
	}

	secondDFSLoop();

	printLeaderMap();
	cout << endl;
}

