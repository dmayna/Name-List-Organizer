// midterm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

map<char, int> letters1 = { { 'a',1 },{ 'b',2 },{ 'c',3 },{ 'd',4 },{ 'e',5 },{ 'f',6 },{ 'g',7 },{ 'h',8 },{ 'i',9 },{ 'j',10 },{ 'k',11 },{ 'l',12 },{ 'm',13 },{ 'n',14 },{ 'o',15 },{ 'p',16 },{ 'q',17 },{ 'r',18 },{ 's',19 },{ 't',20 },{ 'u',21 },{ 'v',22 },{ 'w',23 },{ 'x',24 },{ 'y',25 },{ 'z',26 } };
map<int, char> letters2 = { { 1,'A' },{ 2,'B' },{ 3,'C' },{ 4,'D' },{ 5,'E' },{ 6,'F' },{ 7,'G' },{ 8,'H' },{ 9,'I' },{ 10,'J' },{ 11,'K' },{ 12,'L' },{ 13,'M' },{ 14,'N' },{ 15,'O' },{ 16,'P' },{ 17,'Q' },{ 18,'R' },{ 19,'S' },{ 20,'T' },{ 21,'U' },{ 22,'V' },{ 23,'W' },{ 24,'X' },{ 25,'Y' },{ 26,'Z' } };
map<char, int> letters3 = { { 'A',1 },{ 'B',2 },{ 'C',3 },{ 'D',4 },{ 'E',5 },{ 'F',6 },{ 'G',7 },{ 'H',8 },{ 'I',9 },{ 'J',10 },{ 'K',11 },{ 'L',12 },{ 'M',13 },{ 'N',14 },{ 'O',15 },{ 'P',16 },{ 'Q',17 },{ 'R',18 },{ 'S',19 },{ 'T',20 },{ 'U',21 },{ 'V',22 },{ 'W',23 },{ 'X',24 },{ 'Y',25 },{ 'Z',26 } };

class List
{
public:
	List() { arraySize = 100; list = new string[100]; count = 0; }
	List(int inVar)
	{
		// Initilize arraySize then Array
		arraySize = inVar;
		list = new string[arraySize];
		count = 0;
	}
	bool add1(string inVar)
	{
		count++;
		list[count] = inVar;
		return true;
	}
	void listAll()
	{
		for (int n = 0; n < count; n++)
		{
			cout << list[n] << "\n";
		}
	}
private:
	int arraySize; // size of array
	string * list; // create Dynamic array
	int count;
};


/*--------------------------- List Array ------------------------------------------------------*/
class ArrayListClass
{
public:
	ArrayListClass();
	//Write a function that will print out the names starting with a specific letter, prints just ONE list.
	void printByLetter(char x)
	{
		listArray[letters1[x]].listAll();
	}
	//Write a Function that can print out the ALL names found on each list..
	void printAll()
	{
		for (int i = 1; i < arraySize; i++)
		{
			listArray[i].listAll();
		}
	}
private:
	List * listArray;
	int arraySize;
};

ArrayListClass::ArrayListClass()
{
	arraySize = 27;
	listArray = new List[arraySize];
	ifstream names;
	string name;
	names.open("Names.txt"); // file to open
	while (!names.eof())
	{
		getline(names, name);
		for (int i = 1; i < 27; i++) // insert names into correct list
		{
			if (name[0] == letters2[i])
			{
				listArray[letters3[letters2[i]]].add1(name);
				break;
			}
		}
	}

}

/*--------------------------- Main -------------------------------------------------------------------------------------------*/
int main(int argc, const char * argv[])
{
	cout << "Dylan Maynard \t 3/15/18\n\n";
	ArrayListClass A1;
	char input = ' ';
	while (input != ';')
	{
		cout << "\nEnter the letter for the names you want to print( ! to print all or ; to quit) > ";
		cin >> input;
		A1.printByLetter(input);
		if (input == '!')
		{
			A1.printAll();
		}
	}
	return 0;
}
