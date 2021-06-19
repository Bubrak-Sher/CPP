// I am deferent, I am Scorpio!
# include <iostream>
using namespace std;

main()
{
	int row = 5;
	int array[row];
	int number;
	
	for(int i = 1; i <= row; i++)
	{
		array[i] = i;
	}
	
	for(int i = 1; i <= row; i++)
	{
		cout << array[i] << " ";
	}
	
	cout << "\nWhich Element you want to Remove: ";
	cin >> number;
	
	for(int j = number; j <= row; j++)
	{
		array[j] = array[j+1];
		
	}
	row--;
	
	for(int i = 1; i <= row; i++)
	{
		cout << array[i] << " ";
	}
}
