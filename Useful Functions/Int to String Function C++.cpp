// I am deferent, I am Scorpio!
# include <iostream>
using namespace std;

string int_to_string(int num)
{
	string res = "";
	int sign = (num < 0) ? -1 : 1;
	//cout << sign << endl;
	num = abs(num);

	while (num > 0)
	{
		res += char(num % 10 + 48);
		num /= 10;
	}
	// if input is a negative number so we have to it put "-" sign!
	if (sign < 0) { res += '-';}

	// using swap function to swap values because in our array values are in
	// reverse order so we have to re-arrange values
	 
	for (int i = 0; i < res.length() / 2; i++)
	{
		swap(res[i], res[res.length() - i - 1]);
	}
	return res;
}

int main()
{
	int number, cnd;
	string converted;

	cout << "Enter the Number: ";
	cin >> number;
	
	converted = int_to_string(number);
	converted += " IS NOW A STRING";
	cout << converted << endl;
	
	system("pause > 0");
	return 0;
}
