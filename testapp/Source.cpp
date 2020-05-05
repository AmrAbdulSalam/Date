
#include<iostream>
#include<string>
#include<fstream>
#include "Header.h"

using namespace std;



Date::Date(int d = 1, int m = 1, int y = 2001) {

	

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {

		month = m;
		year = y;

		if (d > 0 && d < 32) {
			day = d;
		}
		else {
			cout << "invalid day " << endl;
		}


	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {


		year = y;
		month = m;

		if (d > 0 && d < 31) {
			day = d;
		}
		else {
			cout << "invalid day" << endl;

		}


	}
	if (m == 2) {

		
		year = y;

		if (y % 4 == 0) {

			if (d > 0 && d < 30) {
				day = d;
				month = m;
			}
			else cout << "invalid day" << endl;
		}
		else if (y % 4) {

			if (d > 0 && d < 29) day = d;

			else cout << "invalid day" << endl;

		}


	}
	if (m < 0 || m > 12) {
		cout << "invalid month" << endl;

	}
	

}

//diffrent functions

int Date::getDay() {
	return day;

}

int Date::getMonth() {

	return month;

}

int Date::getYear() {

	return year;
}

void Date::setDate(int d , int m, int y) {

	//the months with 31 days

	while (1) {

		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {

			

			if (d > 0 && d < 32) {
				day = d;
				month = m;
				year = y;
				break;
			}
			else {
				cout << "invalid input " << endl;
				break;

			}


		}
		//the months with 30 days

		if (m == 4 || m == 6 || m == 9 || m == 11) {


			

			if (d > 0 && d < 31) {
				day = d;
				year = y;
				month = m;
				break;
			}
			else {
				cout << "invalid input" << endl;
				break;

			}


		}
		if (m == 2) {

			if (y % 4 == 0) {

				

				if (d > 0 && d < 30) { 
					
					day = d;
					year = y;
					month = m;
					
				break;
				}

				else {
					cout << "invalid input" << endl;
					break;

				}
			}
			else if (y % 4) {

				if (d > 0 && d < 29) { 
					day = d;
					year = y;
					month = m;
					break;
				}

				else {
					cout << "invalid input" << endl;
					break;

				}
			}


		}

		if (m < 0 || m > 12) {
			cout << "invalid input" << endl;
			break;

		}
	}
}

ostream & operator << (ostream &out, Date &obj1) {



	if (obj1.getMonth() >= 10 && obj1.getDay() >= 10) {

		out << obj1.getYear() << "-" << obj1.getMonth() << "-" << obj1.getDay() << endl;
		return out;
	}
	if (obj1.getMonth() >= 10 && obj1.getDay() < 10 ) {
		
		out << obj1.getYear() << "-" << obj1.getMonth() << "-0" << obj1.getDay() << endl;
		return out;
	}
	if (obj1.getMonth() < 10 && obj1.getDay() < 10) {

		out << obj1.getYear() << "-0" << obj1.getMonth() << "-0" << obj1.getDay() << endl;
		return out;
	}

	if (obj1.getMonth() < 10 && obj1.getDay() >= 10) {

		out << obj1.getYear() << "-0" << obj1.getMonth() << "-" << obj1.getDay() << endl;
		return out;
	}

	
}

istream & operator >> (istream &in, Date &obj2) {
	
	cout << "Type in your date : " << endl;

	int da, mo, ye;
	
	while (1) {

		in >> da >> mo >> ye;

		obj2.setDate(da, mo, ye);
		break;
		
		
	}
	
	return in;
}


void Date :: operator ++ (int) {

	while (1) {

		if (month == 12) {

			if (day == 31) {
				month = 1;
				day = 1;
				year++;
				break;

			}
			else {
				day++;
				break;
			}
		}


		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {

			if (day == 31) {

				month++;
				day = 1;
				break;
			}
			else {
				day++;
				break;
			}



		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {

			if (day == 30) {
				month++;
				day = 1;
				break;

			}
		}
		if (month == 2) {

			if (year % 4 == 0) {

				if (day == 29) {
					month++;
					day = 1;
					break;
				}
				else {
					day++;
					break;
				}
			}
			else if (year % 4) {

				if (day == 28) {
					month++;
					day = 1;
					//cout << "this isss tryeeeeesas " << endl;
					break;
				}
				else {
					day++;
					break;
				}
			}

		}
	}
}

void Date ::operator--(int) {

	while (1) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {

			if (day == 1) {
				month--;
				day = 31;
				break;


			}
			else {
				day--;
				break;
			}
		}
		if (month == 12 || month == 2 || month == 5 || month == 7 || month == 8 || month == 10) {
			if (day == 1) {
				month--;
				day = 31;
				break;
			}
			else {
				day--;
				break;
			}
		}
		if (month == 1) {
			if (day == 1) {
				year--;
				month = 12;
				day = 31;
				break;
			}
		}
		if (month == 3 && day == 1) {
			if (year % 4 == 0) {
				month--;
				day = 29;
				break;
			}
			else if (year % 4) {
				month--;
				day = 28;
				break;
			}
		}
		if (month == 3 && day != 1) {
			day--;
			break;
		}

	}
}
 bool Date :: operator == (Date &obj1)  {
	
	 if (obj1.getDay() == day) {
		 if (obj1.getMonth() == month) {
			 if (obj1.getYear() == year) {
				
				 return true;
			 }
		 }
	 }

 }

 bool Date ::operator!= (Date &obj1) {
 
	 if (obj1.getDay() != day) {
		 if (obj1.getMonth() != month) {
			 if (obj1.getYear() != year) {

				 return true;
			 }
		 }
	 }
 
 }

 bool Date :: operator> (Date &obj1) {

	 if (obj1.getYear() > year) {
		 return true;
	 }
	 if (obj1.getYear() == year) {
		 if (obj1.getMonth() > month) {
			 return true;
		 }
		 if (obj1.getMonth() == month) {
			 if (obj1.getDay() == day) {
				 return true;
			 }
		 }
	 }
	 
 }

 bool Date :: operator < (Date &obj1) {

	 if (obj1.getYear() < year) {
		 return true;
	 }
	 if (obj1.getYear() == year) {
		 if (obj1.getMonth() < month) {
			 return true;
		 }
		 if (obj1.getMonth() == month) {
			 if (obj1.getDay() == day) {
				 return true;
			 }
		 }
	 }

 }


void main() {

	Date date1(31, 1, 2019);
	Date date2(1, 3, 2019);
	Date date3(15, 4, 2019);
	Date date4(15, 4, 2019);
	Date date5;
	cout << "date1 :";
	cout << "Day =" << date1.getDay();
	cout << " , Month = " << date1.getMonth();
	cout << " , Year = " << date1.getYear() << endl;
	cout << "date1 : " << date1 << endl;
	cout << "date2 : " << date2 << endl;
	cout << "date3 : " << date3 << endl;
	cout << "date4 : " << date4 << endl;

	if (date3 == date4) cout << "date3 is equal to date4" << endl;
	if (date3 != date4) cout << "date3 is not equal to date4" << endl;
	if (date1 < date2) cout << "date1 is before date2" << endl;
	if (date3 > date1) cout << "date3 is after date1" << endl;

	cout << "date1 before auto-increment:" << date1 << endl;
	date1++;
	cout << "date1 after auto-increment:" << date1 << endl;
	cout << "date2 before auto-decrement:" << date2 << endl;
	date2--;
	cout << "date2 after auto-decrement:" << date2 << endl;
	cin >> date5; cout << "date5 :" << date5 << endl;
	date1.setDate(1, 12, 2020); cout << "date1 : " << date1 << endl;


	date1.setDate(30, 3, 2019); //invalid day

	cout << "date1 : " << date1 << endl;

	
	system("pause");
}