/*
 * BoxIt.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: Meenakshi
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box {
    private:
        int length;
        int breadth;
        int height;
    public:

    Box(){
        length = breadth = height = 0;
        BoxesCreated += 1;
        cout << "empty constructor called" << endl;
    }

    Box(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
        BoxesCreated +=1;
        cout << "value constructor called" << endl;
    }

    Box(const Box& t) {
        length = t.length;
        breadth = t.breadth;
        height = t.height;
        BoxesCreated += 1;
        cout << "copy constructor called" << endl;
    }

    ~Box() {
        length = 0;
        breadth = 0;
        height = 0;
        BoxesDestroyed += 1;
        cout << BoxesDestroyed << endl;
    }

    int getLength() {
        return length;
    }

    int getBreadth() {
        return breadth;
    }

    int getHeight() {
        return height;
    }

    long long CalculateVolume() {
        return (long long)(length) * breadth * height;
    }

    bool operator<(Box& b) {
        if(length < b.length) {
            return true;
        } else if ((breadth < b.breadth) && (length == b.length)) {
            return true;
        } else if ((height < b.height) && (breadth == b.breadth) && (length == b.length)) {
            return true;
        }
        return false;
    }

    friend ostream &operator<< ( ostream& out, const Box& B) {
        out << B.length << "," << B.breadth << "," << B.height;
        BoxesCreated += 1;
        BoxesDestroyed +=1;
        return out;
    }
};
//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)

        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}


