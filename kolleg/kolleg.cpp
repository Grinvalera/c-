#include <iostream>
#include <fstream>

using namespace std;

class Time {
public:
	int minutes;
	int seconds;
	Time() { minutes = 0; seconds = 0; }
	Time(int a, int b) { minutes = a; seconds = b; }
	//void input();
	void operator-(int);
	void exit();
	//void exeptions();
	friend ostream& operator<<(ostream& ut, const Time& obj);
	friend istream& operator>>(istream& in, Time& obj);
};

ostream& operator<<(ostream& ut, const Time& obj) {
	ut << obj.minutes << ':' << obj.seconds;
	return ut;
}

istream& operator>>(istream& in, Time& obj) {
	char c;
	try
	{
			cout << "minutes = ";
			in >> obj.minutes;
			cout << "seconds = ";
			in >> obj.seconds;
			if (obj.minutes < 0 || obj.seconds < 0)
			{
				throw 1;
			}
	} 
	catch (int)
	{
		cout << "Exeptions number 1 (incorrect number entered)" << endl;
		cout << "Do you want continue?(y or n)" << endl;
		cin >> c;
		if (c == 'y')
		{
			cout << "minutes = ";
			in >> obj.minutes;
			cout << "seconds = ";
			in >> obj.seconds;
			if (obj.minutes < 0 || obj.seconds < 0) {
				throw 1;
			}
		}
		else if (c == 'n')
		{
			exit(1);
		}
		else
		{
			cout << "Sorry" << endl;
			exit(1);
		}
	}
	return in;
}

void Time::operator-(int seconds_new) {
	int minutes_new, nev, lol;
	if (seconds_new > seconds)
	{
		minutes_new = minutes * 60 + seconds;
		nev = minutes_new - seconds_new;
		lol = nev % 60;
		seconds = lol;
		minutes -= 1;
	}
	else
	{
		seconds = seconds - seconds_new;
	} 
	
}

void Time::exit()
{
	cout << minutes << ":" << seconds << endl;
}

int main()
{
	cout << "Input minutes and seconds: " << endl;
	Time obj;
	cin >> obj;
	cout << "You entered : \n" << obj << endl;
	Time obj2;
	int seconds_new;
	cout << "Enter number = ";
	cin >> seconds_new;
	try
	{
		if (seconds_new < 0)
		{
			throw 1;
		}
		else
		{
			obj - seconds_new;
		}

	}
	catch (int i)
	{
		cout << "Exeption number: " << i << " (incorrect number entered)" << endl;
	}
	//obj - seconds_new;
	//obj.exeptions();
	obj.exit();
	//obj.file();
	ofstream out;          
	out.open("C:\\Users\\Grinvalera\\source\\repos\\kolleg\\test.txt", ios::app); 
	if (out.is_open())
	{
		out << obj << "\n";
	}
	return 0;

}
