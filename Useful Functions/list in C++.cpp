// I am deferent, I am Scorpio!
# include <iostream>
# include <list>

using namespace std;
class Scorpio
{
public:
	list<string> myFamily = { "Baba", "Mama", "Ayra", "Manaar" };
};

int main()
{
	Scorpio meScorpio;
	//meScorpio.myFamily = { "Baba", " Mama", " Ayra", " Manaar" };
	cout << "'Scorpio Family'" << endl;
	for (string Family : meScorpio.myFamily)
	{
		cout << Family << endl;
	}
	system("pause > 0");
	return 0;
}
