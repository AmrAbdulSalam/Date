#pragma once

using namespace std;

class Date {
private: int day;
		 int month;
		 int year;

public:
	Date(int d, int m, int y);

	//return function form private field in the class4



	int getDay();
	int getMonth();
	int getYear();




	//setdate function

	void setDate(int d, int m, int y);

	//void setDay(int d, int m);
	//void setYear(int y);

	//overloading funtions

	friend ostream & operator << (ostream &out , Date  &obj1);
	
	friend istream & operator >> (istream &in, Date &obj1);


	void operator ++ (int );

	void operator -- (int);

	bool operator == (Date &obj1);
	bool operator != (Date &obj1);
	bool operator > (Date &obj1);
	bool operator < (Date &obj1);
};

