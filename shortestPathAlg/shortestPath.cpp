/*
 * shortestPath.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: Meenakshi
 */
#include<algorithm>
#include <iostream>
#include<fstream>
#include<sstream>
#include<iterator>
#include<stdlib.h>
#include<conio.h>
#include<map>
#include<vector>
#include<string>
#include<list>

using namespace std;

struct vrtex
{
	int u;
	int v;
	int length;

	// Assignment operator.
	bool operator ==(const vrtex& st)
	{
		return v == st.v;
	}
};

typedef struct vrtex node;
map<int, vector<node> > edges;
list<int> vertexes;
list<int> vrtxProcessed;
list<node> fEList;
vector<int> path;


void addInput()
{
	string lineData;
#if 0
	ifstream input("text.txt");
#else
	ifstream input("dijkstraData.txt");
#endif
	int mapNo = 0;
	node n1, n2;
	char comma;

	while(getline(input, lineData))
	{
		vector<int> row;
		istringstream iss(lineData);

		iss >> mapNo;

		if((iss.rdbuf()->in_avail() == 0))
		{
			cout << "inside if " << endl;
			n2.u = mapNo;
			n2.v = 0;
			n2.length = 0;
			edges[mapNo].push_back(n2);
			vertexes.push_back(mapNo);
		}
		while(iss >> n1.v)
		{
			iss >> comma;
			iss >> n1.length;
			n1.u = mapNo;
			//cout << "vertex " << mapNo << " Edge " << n1.vrtx << " Length " << n1.length << endl;
			edges[mapNo].push_back(n1);
			vertexes.push_back(mapNo);
		}

		iss.str("");
		iss.clear();
	}

	cout << "Numberof vertex: " << mapNo << endl;

/*	for( map<int,vector<node> >::iterator it=edges.begin(); it!=edges.end(); ++it)
	{
		cout << (*it).first <<"   ";
		for( vector<node>::iterator lit = it->second.begin(); lit !=  it->second.end(); ++lit )
		{
			cout << "node u:  "<< lit->u  << "  node v: " <<lit->v << "     " << " length " << lit->length << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	vertexes.unique();
/*	cout << "Nodes :" << endl;
	for(list<int>::iterator it = vertexes.begin(); it!= vertexes.end(); ++it)
	{
		cout << *it << endl;
	}*/
}


bool findVrtxInProcessedList(int vrtx, list<int>vrtxProcessed)
{
	list<int>::iterator lit = find(vrtxProcessed.begin(), vrtxProcessed.end(), vrtx);

	if(vrtxProcessed.end() == lit)
	{
		//cout << "Node:   " << vrtx << "         Not Found in x" << endl;
		return false;
	}
	return true;
}

int updateFrontierEdges()
{
	int shortPath = 0;
	int shortNode = 1;
#if 0
	for(list<node>::iterator it = fEList.begin(); it!= fEList.end(); ++it)
	{
		if(shortPath == 0)
		{
			shortPath = it->length;
			shortNode = it->vrtx;
		}
		else if(shortPath > it->length)
		{
			shortPath = it->length;
			shortNode = it->vrtx;
		}
	}
#else
	for(list<node>::iterator it = fEList.begin(); it!= fEList.end(); ++it)
	{
		if(shortPath == 0)
		{
			shortPath = it->length + path[it->u];
			//cout << "Assigning short path : "  << shortPath << endl;
			shortNode = it->v;
		}
		else if(shortPath > (it->length + path[it->u]))
		{
			shortPath = it->length + path[it->u];
			shortNode = it->v;
		}

		path[it->v] = shortPath;
	}

#endif
/*	cout << "Nodes in Frontier Edge list" << endl;
	for(list<node>::iterator it = fEList.begin(); it!= fEList.end(); ++it)
	{
		cout << it->v  << "  ";
	}
	cout << endl;

	cout << "Short Node:  "  << shortNode <<  "  Short Path: " << shortPath << endl;*/
	return shortNode;
}

void calculateShortestPath()
{
	int size = edges.size();
	int vertex = 1;
	node n1;
	map<int, vector<node> >::iterator it;

	path.assign(size+1, 100000);
	path[0] = 0;
	path[1] = 0;
	vrtxProcessed.push_back(vertex);

	while(vrtxProcessed !=  vertexes)
	{
		it = edges.find(vertex);

		for( vector<node>::iterator vit = it->second.begin(); vit !=  it->second.end(); ++vit )
		{
			//cout << "   node  "<< vit->vrtx << "     " << " length " << vit->length << endl;

			if(findVrtxInProcessedList( vit->v, vrtxProcessed))
			{
				//cout << "vertex found " << vit->v << "  in x" << endl;
				continue;
			}

			fEList.push_back(*vit);
		}
		vertex = updateFrontierEdges();
		//cout << endl;
		vrtxProcessed.push_back(vertex);
		//cout << "Node  " << vertex << "  pushed in x" << endl;
		n1.v = vertex;
		fEList.remove(n1);
		vrtxProcessed.sort();
	}

	for(list<node>::iterator it = fEList.begin(); it!= fEList.end(); ++it)
	{
		cout << it->v  << "  ";
	}
	cout << endl;

	for(vector<int>::iterator it = path.begin(); it!= path.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	addInput();
	calculateShortestPath();
}
