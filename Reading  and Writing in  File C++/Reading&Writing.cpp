// I am deferent, I am Scorpio!
# include <iostream>
# include <string.h>
# include <fstream>

using namespace std;

main()
{
	/* 
	fstream is used for both input and output instead of fstream 
	we can use istream and ostream also
	*/
	fstream myFile;
	
	/* 
	opening the file if file does not exisit it will create new file.
	where ios::out is using for writing in file.
	NOTE: ios::out will remove previous text it will not append in file.
	*/
	myFile.open("myText.txt", ios::out);
	if(myFile.is_open())
	{
		// \t will tab the first line in text file and \n will create new line
		myFile << "\tScorpio Text File \nHello from @Scorpio!";	
	}
	else
	{
		cout << "File Cannot be open" << endl;
	}
	myFile.close();
	/*
	for reading from text file use ios::in 
	*/
	myFile.open("myText.txt", ios::in);
	if(myFile.is_open())
	{
		string text;
		cout << "First Text: \n";
		while(getline(myFile, text))
		{
			cout << text << endl;
		}
 	}
	else
	{
		cout << "File Cannot be open properly" << endl;
	}
	myFile.close();
	
	/*
	append text in existing file, we use ios::app
	
	*/
	myFile.open("myText.txt", ios::app);
	if(myFile.is_open())
	{
		myFile << "\nAdd Text Here....";	
	}
	else
	{
		cout << "File can not be properly" << endl;
	}
	myFile.close();
	
	// Reading from text file appended text will be there as well. 
	myFile.open("myText.txt", ios::in);
	if(myFile.is_open())
	{
		string text;
		cout << "\nFirst Text + Appended Text: \n"; 
		while(getline(myFile, text))
		{
			cout << text << endl;
		}
 	}
	else
	{
		cout << "File Cannot be open properly" << endl;
	}
	myFile.close();
}
