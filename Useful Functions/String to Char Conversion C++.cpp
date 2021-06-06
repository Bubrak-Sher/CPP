// I am deferent, I am Scorpio!
# include <iostream>
using namespace std;

int main()
{	
	/*
	First Method is for dynamic memory, where you can put anything you want
	to put in string it will be converted into char Array where spaces, special character
	are included also 
	*/
	
	string sd;
	
	cout << "Enter String/Paragraph 1: ";
	getline(cin, sd);
	
	char *cha;
	cha = new char;
	
	for(int i = 0; i < sd.length(); i++)
	{
		cha[i] = sd[i]; 	
		cout << cha[i] << " ";
	}
	
	delete cha;
	cha = NULL;
	cout << "\n";
	
	/*
	Second Method is for dynamic memory
	*/
	
	string s;
	cout << "\nEnter Only String without Space 2: ";
	cin >> s;
	char *c;
	c = new char;
	
	for(int i = 0; i < sizeof(s); i++)
	{
		c[i] = s[i]; 	
		cout << c[i] << " ";
	}
	
	delete c;
	c = NULL;
	cout << "\n";
	
	/* Third Method is for where you cant include spaces and Array length is 
	defined on compile time */
	
	string sc;
	
	cout << "\nEnter Only String without Space 3: ";
	cin >> sc;
	
	char ch[s.length()];
	
	for(int i = 0; i < sizeof(sc); i++)
	{
		ch[i] = sc[i]; 	
		cout << ch[i] << " ";
	}
	
	system("pause > 0");
	return 0;
}
