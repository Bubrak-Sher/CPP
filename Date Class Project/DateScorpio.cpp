// class Date by Scorpio
# include <iostream>
# include "DateScorpio.h"
using namespace std;
//
//class Date
//{
//	
//	private:
//		
//		int day, month, year;
//		
//		bool leapYear(int x) const;
//		
//	public:
//		
//		Date();
//		Date(int, int, int);
//		~Date();
//		
//		int setDay(int);
//		int setMonth(int);
//		int setYear(int);
//		
//		int getDay() const;
//		int getMonth() const;
//		int getYear() const;
//		
//		int addDay(int);
//		int addMonth(int);
//		int addYear(int);
//		
//		void display();
//		
//};

// static variable defination

// Constructor and Destructor



Date::Date(int aYear, int aMonth = 0, int aDay = 0)
{
	
	this->day = aDay;
	this->month = aMonth;
	this->year = aYear;
	
}

Date::Date()
{
	
	this->day = 0;
	this->month = 0;
	this->year = 0;
	
}

Date::~Date()
{
	
	
}

// Accessor Functions

int Date::setDay(int aDay)
{
	
	if(aDay <= 0 || aDay >31)
	{
		aDay = 0;
	}
	this-> day = aDay;
	
}

int Date::setMonth(int aMonth)
{
	if(aMonth <= 0 || aMonth > 12)
	{
		aMonth = 0;
	}
	this->month = aMonth;
	
}

int Date::setYear(int aYear)
{
	if(aYear <= 0)
	{
		aYear = 0;
	}
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
	if(aDay <= 0)
	{
		aDay = 0;
	}
	
	day += aDay; 
	
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

void Date::display()
{
	
	cout << "Day = " << day << endl;
	cout << "Month = " << month << endl;
	cout << "Year = " << year << endl;

}
