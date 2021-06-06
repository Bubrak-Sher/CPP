// class Date by Scorpio
#ifndef DATESCORPIO_H
#define DATESCORPIO_H
class Date
{
	
	private:
		
		int day, month, year;
		
		bool leapYear(int x) const;
		
	public:
		
		Date();
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
		
		void display();
		
};
#endif
