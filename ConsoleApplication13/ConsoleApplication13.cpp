// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;


class cat
{
public:
	int age;
};

void Square(int *intPtr)
{
	int y = *intPtr;
	cout << (y*y) << endl;
}
int *BlahBlah(int *z)
{
	int *Blang = z;
	return Blang;
}
void SetAge(cat *pCat, int age)
{
	pCat->age = age;
}
int main()
{
	int x = 7;
	int *ptr2 = new int; //Allocates memory on heap defined as int storage
	*ptr2 = x; //sets heap location of ptr2 equal to 7 (x)
	Square(ptr2);
	cout << &x  << "||" << x << endl;//Mem addr of x == 00EFFEC4 || Value stored == 7
	cout << ptr2 << "||" << *ptr2 << endl;//Mem addr of ptr2 == 013EB2CO || Value stored == 7 (Stored on HEAP)
	delete ptr2;
	ptr2 = 0;
	
	int *ptr1 = BlahBlah(&x); //Method creates pointer to address of x -> line 42 sets *ptr1 equal to the pointer created in BlahBlah method
	cout << ptr1 << "||" << *ptr1 << endl;//Mem addr of ptr1 == 00EFFEC4 || Value stored == 7 (Notice mem address close to x's [stack storage])

//----------------------------------
	//Heap based obj creation
	cat *mCat = new cat;
	mCat->age = 0;
	cout << mCat->age << endl;
	SetAge(mCat, 40);
	cout << mCat->age << endl;
//----------------------------------
	//Stack based obj creation
	cat c;
	c.age = 2;
	cout << c.age << endl;
	SetAge(&c, 40);
	cout << c.age << endl;
    return 0;
}

