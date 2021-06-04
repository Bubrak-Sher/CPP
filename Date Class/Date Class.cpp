// I am deferent, I am Scorpio!
# include <iostream>

using namespace std;

// Class Date

class Date
{
	private:
		int day, month, year;
		
		bool leapYear(int x) const;
		static Date defaultDate;
		
	public:
		
		Date(string a);
		Date(int, int, int);
		~Date();
		
		int setDay(int);
		int setMonth(int);
		int setYear(int);
		
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		
		int addDay(int);
		int addMonth(int);
		int addYear(int);
		
		static void setDefaultDate(int, int, int);
		
		void display();
		
		int calculate();	
};

// static variable defination
Date Date::defaultDate(01, 01, 2021);

// Static Function

void Date::setDefaultDate(int aDay, int aMonth, int aYear)
{
	defaultDate.day = aDay;
	defaultDate.month = aMonth;
	defaultDate.year = aYear;
}

// Constructor and Destructor

Date::Date(int aDay = 0, int aMonth = 0 ,int aYear = 0)
{
	this->day = aDay;
	this->month = aMonth;
	this->year = aYear;
}

Date::Date(string a)
{
	this->day = defaultDate.day;
	this->month = defaultDate.month;
	this->year = defaultDate.year;
}

Date::~Date()
{
	
}

// Accessor Functions

int Date::setDay(int aDay)
{
	this->day = aDay;
}

int Date::setMonth(int aMonth)
{
	this->month = aMonth;
}

int Date::setYear(int aYear)
{
	this->year = aYear;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

// Add Functions

int Date::addDay(int aDay)
{
	day += aDay; // 
	
	opt:
	if(month > 12)
	{	
		int temp = month;
		temp /= 12;
		year += temp;
		month %= 12;
		goto opt;
	}
	
	if (month == 9 || month == 11 || month == 6 || month == 4)
	{
		if(day > 30)
		{
			day -= 30;
			month++;
			goto opt;
		}		
	}
	
	if(month == 7 || month == 10 || month == 12 || month == 8 || month == 5 || month == 1 || month == 3)
	{	
		if(day > 31)
		{
			day -= 31;
			month++;
			goto opt;
		}				
	}
	
	if (month == 2)
	{
		if(day > 29)
		{
			if(leapYear(year))
			{
				day -= 29;
				month++;
				goto opt;
			}
			else
			{
				day -= 28;
				month++;
				goto opt;
			}
		}
	}
}

int Date::addMonth(int aMonth)
{
	month += aMonth;
	if(month > 12)
	{
		year++;
		month -= 12;
	}
}

int Date::addYear(int aYear)
{
	year += aYear;
	if(day == 29 && month == 2 && !leapYear(year))
	{
		day = 1;
		month = 3;	
	}	
}

// LeapYear Test Function

bool Date::leapYear(int x) const
{
	if(x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
	{
		return true;
	}
		
	return false;
}

// Display Function

void Date::display()
{
	cout << "Day = " << day << endl;
	cout << "Month = " << month << endl;
	cout << "Year = " << year << endl << "\n";
}

int main()
{
	Date toDay("default");
	toDay.display();
	Date::setDefaultDate(24, 10, 1985);
	Date myDay("default");
	myDay.display();
	
	myDay.addDay(255);
	myDay.display();
	
	cout << "\n";
	
	system("pause > 0");
	return 0;
}
