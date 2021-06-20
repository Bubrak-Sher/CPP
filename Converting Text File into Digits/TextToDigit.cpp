# include <iostream>
# include <string>
# include <conio.h>
using namespace std;

main()
{
	/*
	Consider the following conversion,
	char a = 'A';
 	int num = (int) a;
	In this case, ‘num’ will have the value 65 which is ASCII equivalent of 
	character ‘A’.

	Alternatively, we can use the following operation if we want to convert 
	a number character to an integer value.
	
 	char a = '2';
 	int num = a-48;
	Here, 48 is the ASCII value of 0. What is done here is the second line 
	a-48 implicitly converts char a to its ASCII equivalent and then subtracts 
	it from 48 (50-48) that results in integer value 2.
	*/
	
	// First Task is Done
	char n[] = {};
	int a;
	
	while(true)
	{
		*n = getch();
		a = (int) *n;
		cout << a << " ";
		cout << (char) a << " ";
	}
	
	//98 117 98 114 97 107 32 115 104 101 114 32 105 115 109 121 102 114 105 101 110 100 32
	
	/* Second Task will be after break
	In second Part we will write these digits into file and also we will 
	read this file and we will get back out characters IA.
	*/








	/*
	Other Method is Using stringstream

	#include <iostream>
	#include <string>
	#include <sstream>
	using namespace std;
	main()
	{
    	stringstream Mystring;
    	Mystring << "5"; 
		int Mydigit; 
		Mystring >> Mydigit;
    	cout<<"Converted value of MyString :" << Mydigit;
	}
	*/
}
