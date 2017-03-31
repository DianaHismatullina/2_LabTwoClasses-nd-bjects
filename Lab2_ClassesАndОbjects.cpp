
#include "stdafx.h"
#include <tchar.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Co_worker
	{
		char full_name[128], position[128];
		double salary, hours;
		public:
			Co_worker()
			{
				salary = hours = full_name[0] = position[0] = 0;
			}
			void set(char name[], double sal, char pos[], double h) 
			{
				strcpy_s(full_name, name);
				strcpy_s(position, pos);
				salary = sal;
				hours = h;
			}
			Co_worker (char name[], double sal, char pos[], double h) 
			{
				strcpy_s(full_name, name);
				strcpy_s(position, pos);
				salary = sal;
				hours = h;
			}
			double salarypert(double t)
			{
				return (salary*t)/4.348;
			}
			double hoursypert(double t)
			{
				return hours*t;
			}
			void print() 
			{
				cout << "\nFull Name:" << full_name << endl;
				cout << "Position:" << position << endl;
				cout << "Salary:" << salary << endl;
				cout << "Hours:" << hours << endl;
			}
	};


int main()
{
	int n; 
	cout << "Enter the number of objects: "; cin >> n;
	double year, month, week, T;
	cout << "Enter the number of years in the required time interval: "; cin >> year;
	cout << "Enter the number of months in the required time interval: "; cin >> month;
	cout << "Enter the number of weeks in the required time interval: "; cin >> week;
	T = year*52.142 + month* 4.348 + week;

	char name[128], pos[128];
	double h, sal, sumsalary = 0, sumhours = 0;

	Co_worker **ppW; 
	ppW = new Co_worker*[n]; 
	for (int i = 0; i<n; i++)
	{
		cout << "\nObject N = " << (i + 1);
		cout << "\nFull Name: "; cin >> name;
		cout << "Position: "; cin >> pos;
		cout << "Salary: "; cin >> sal;
		cout << "Hours: "; cin >> h;

	
		ppW[i] = new Co_worker(name, sal, pos, h);
								
	}
	
	for (int i = 0; i<n; i++) ppW[i]->print(); 
	for (int i = 0; i<n; i++) sumsalary += ppW[i]->salarypert(T);
	for (int i = 0; i<n; i++) sumhours += ppW[i]->hoursypert(T);

	cout << "\n\nSalary of all employees for the required period of time = " << sumsalary;
	cout << "\nNumber of working hours of all employees for the required period of time = " << sumhours;
	system("pause");

    return 0;
}

