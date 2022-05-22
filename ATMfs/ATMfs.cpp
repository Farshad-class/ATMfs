#include <iostream>
#include <conio.h>
#include <stdio.h>
//#include <math.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
string name, family, Cardnumber, cardnumber, ca;
int balance, cardpass, pass, pass1, pass2;
int balance2, cardpass2;
int a, b, k, en, ex, id, fi;
bool flag = 0;
void chckbalance();
void menu1();
void checkpass();
void fill1();
void transferMoney1();
void changePass1();
void exit();
int main()
{
	fill1();
	return 0;
	getch();
}

void menu1()
{
	cout << "Welcome " << name << " " << family << "\n";
	cout << "1. Check Balance     2. Transfer Money \n";
	cout << "3. Change Pass       4.exit \n";
	cout << "PLease enter a number for selected service : ";
	cin >> a;
	if (a == 1)
	{
		chckbalance();
	}
	else if (a == 2)
	{
		transferMoney1();
	}
	else if (a == 3)
	{
		changePass1();
	}
	else if (a == 4)
	{
		exit();
	}


}

void chckbalance()
{
	cout << "Mojodi shoma :" << balance << "IRR" << "\n";
	cout << "baraya bazgasht kelid 5 ra vared konid : ";
	cin >> k;
	if (k == 5)
	{
		menu1();
	}
	else
		do {
			cout << "baraya bazgasht kelid 5 ra vared konid : ";
			cin >> k;
			if (k == 5)
			{
				menu1();
				break;
			}
		} while (k != 5);
}





void checkpass()
{
	int j = 0;
	{
		cout << "Please enter your card number : ";
		cin >> cardnumber;
		cout << "Please enter your card pass : ";
		cin >> pass;
		ifstream open("bank.txt");
		while (open >> id)
		{
			open >> name;
			open >> family;
			open >> balance;
			open >> cardpass;
			open >> Cardnumber;
			if (cardnumber == Cardnumber)
			{
				if (pass == cardpass)
				{
					fi = id;
					menu1();


					break;
				}
				else
				{
					cout << "You enter mistake more than 1 times. " << endl;
					for (int j = 2; j <= 3; j++)
					{
						cout << "Please enter your card pass : ";
						cin >> pass;
						if (pass != cardpass)
						{
							cout << "You enter mistake " << j << " times." << endl;
						}
						else
						{
							fi = id;
							menu1();
							break;
						}
						if (j == 3)
						{
							cout << "You enter mistake more than" << j << " times. Your Card is blocked" << endl;
						}
					}
				}


			}

		}
	}
}
void transferMoney1()
{
	cout << "Please enter amount for transfer : ";
	cin >> en;
	if (en > balance)
	{
		cout << "Your request amount more than your balance. " << endl;
	}
	else
	{
		cout << "Please enter new card : " << endl;
		cin >> ca;
		if (ca.length() != 16)
		{
			cout << "your card number is not correct";
			cout << "Please enter new card : ";
			cin >> ca;
		}
		else
		{
			ifstream open("bank.txt");
			fstream temp;
			temp.open("temp.txt", ios::out);
			while (open >> id >> name >> family >> balance >> cardpass >> Cardnumber)
			{
				temp << id << endl;
				temp << name << endl;
				temp << family << endl;
				if (ca == Cardnumber)
				{
					balance += en;
					flag = 1;
					temp << balance << endl;

				}
				else
				{
					temp << balance << endl;
				}
				temp << cardpass << endl;
				temp << Cardnumber << endl;

			}
			ifstream openn("temp.txt");
			fstream bank1;
			bank1.open("bank.txt", ios::out);
			while (openn >> id >> name >> family >> balance >> cardpass >> Cardnumber)
			{
				if (id != fi)
				{
					bank1 << id << endl;
					bank1 << name << endl;
					bank1 << family << endl;
					bank1 << balance << endl;
					bank1 << cardpass << endl;
					bank1 << Cardnumber << endl;
				}
				else
				{
					bank1 << id << endl;
					bank1 << name << endl;
					bank1 << family << endl;
					balance -= en;
					bank1 << balance << endl;
					bank1 << cardpass << endl;
					bank1 << Cardnumber << endl;

				}
			}
		}

	}
	fstream fileobj;
	fileobj.open("bank.txt", ios::in);
	while (fileobj >> id >> name >> family >> balance >> cardpass >> Cardnumber)
	{
		if (id == fi)
		{
			fileobj << id << endl;
			fileobj << name << endl;
			fileobj << family << endl;
			fileobj << balance << endl;
			fileobj << cardpass << endl;
			fileobj << Cardnumber << endl;
			break;
		}
	}
	if (flag == 1)
	{
		cout << en << " IRR successfully transfer. " << endl;
	}
	cout << "baraya bazgasht kelid 5 ra vared konid : ";
	cin >> k;
	if (k == 5)
	{
		menu1();
	}
	else
		do {
			cout << "baraya bazgasht kelid 5 ra vared konid : ";
			cin >> k;
			if (k == 5)
			{
				menu1();
				break;
			}
		} while (k != 5);

}

void changePass1()
{
	cout << "Please enter your current password : ";
	cin >> pass;
	fstream fileobj;
	fileobj.open("bank.txt", ios::in);
	while (fileobj >> id >> name >> family >> balance >> cardpass >> Cardnumber)
	{
		if (id == fi)
		{
			fileobj << id << endl;
			fileobj << name << endl;
			fileobj << family << endl;
			fileobj << balance << endl;
			fileobj << cardpass << endl;
			fileobj << Cardnumber << endl;
			break;
		}
	}
	if (pass != cardpass)
	{
		cout << "You enter pass is incorrect  " << endl;
		do {
			cout << "baraya bazgasht kelid 5 ra vared konid : ";
			cin >> k;
			if (k == 5)
			{
				menu1();
				break;
			}
		} while (k != 5);
	}
	else
	{
		cout << "Please enter your new password : ";
		cin >> pass1;
		cout << "Please enter your new password again : ";
		cin >> pass2;
		if (pass1 != pass2)
		{
			cout << "your eneterd pass not match" << endl;
			do {
				cout << "baraya bazgasht kelid 5 ra vared konid : ";
				cin >> k;
				if (k == 5)
				{
					menu1();
					break;
				}
			} while (k != 5);
		}
		else
		{
			ifstream open1("bank.txt");
			fstream temp;
			temp.open("temp.txt", ios::out);
			while (open1 >> id >> name >> family >> balance >> cardpass >> Cardnumber)
			{
				temp << id << endl;
				temp << name << endl;
				temp << family << endl;
				temp << balance << endl;
				if (id == fi)
				{
					cardpass = pass1;
					temp << cardpass << endl;

				}
				else
				{
					temp << cardpass << endl;
				}
				temp << Cardnumber << endl;

			}
			ifstream openn1("temp.txt");
			fstream bank11;
			bank11.open("bank.txt", ios::out);
			while (openn1 >> id >> name >> family >> balance >> cardpass >> Cardnumber)
			{
				bank11 << id << endl;
				bank11 << name << endl;
				bank11 << family << endl;
				bank11 << balance << endl;
				bank11 << cardpass << endl;
				bank11 << Cardnumber << endl;

			}
			cout << "Your password change successfully." << endl;
			checkpass();


		}
	}

}
void exit()
{
	if (a == 4)
	{
		cout << "Thanks you and good bye. ";
	}
}

void fill1()
{
	checkpass();
}

