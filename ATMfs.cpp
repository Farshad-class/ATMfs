#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<windows.h>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
string name, family, Cardnumber, cardnumber, ca;
string  cardpass, pass, pass1, pass2;
int balance, balance2, cardpass2;
int a, b, k, en, ex, id, fi, acc, rl;
bool Activeflag = 1, lettransfer = 1, cardblock = 0, flag = 0;
void chckbalance();
void menu1();
void checkpass();
void fill1();
void transferMoney1();
void changePass1();
void exit();
void exit2();
int cls();
char pa[4];
void passchangetostar();
string passchangetostar1();
string passchangetostar2();
void returnmainmenu();
int main()
{
	fill1();
	return 0;
}
void fill1()
{
	checkpass();
}

void menu1()
{
	cout << endl;
	cout << endl;
	cls();
	cout << "          Welcome " << name << " " << family << "\n";
	cout << endl;
	cout << endl;
	cout << "1. Check Balance     2. Transfer Money \n";
	cout << endl;
	cout << "3. Change Pass       4.exit \n";
	cout << endl;
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
	else
	{
		cout << "Enterd number is not correct." << endl;
		void returnmainmenu();
	}
}

void chckbalance()
{
	cout << endl;
	cout << "Your account balance is :" << balance << " IRR" << "\n";
	cout << endl;
	returnmainmenu();
}
void checkpass()
{
	int j = 0;
	{
		cout << "Please enter your card number : ";
		cin >> cardnumber;

		do {
			if (cardnumber.length() != 16)
			{
				cout << "your card number is not correct " << endl;
				cout << "Please enter your card number : ";
				cin >> cardnumber;
			}
		} while (cardnumber.length() != 16);


		passchangetostar();
		do {
			if (pass.length() != 4)
			{
				cout << "your password should be 4 digit" << endl;
				cout << "Please enter your card pass : ";
				cin >> pass;
			}
		} while (pass.length() != 4);
		ifstream open("bank.txt");
		while (open >> id)
		{
			open >> name;
			open >> family;
			open >> balance;
			open >> cardpass;
			open >> Cardnumber;
			open >> Activeflag;
			if (Activeflag != 0)
			{
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
						cout << endl;
						cout << "You enter mistake 1 times. " << endl;
						for (int j = 2; j <= 3; j++)
						{
							cout << endl;
							passchangetostar();
							if (pass != cardpass)
							{
								cout << endl;
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
								ifstream open("bank.txt");
								fstream fobjtemp;
								fobjtemp.open("temp.txt", ios::out);
								while (open >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
								{
									fobjtemp << id << endl;
									fobjtemp << name << endl;
									fobjtemp << family << endl;
									fobjtemp << balance << endl;
									fobjtemp << cardpass << endl;
									fobjtemp << Cardnumber << endl;
									if (cardnumber == Cardnumber)
									{
										Activeflag = 0;
										fobjtemp << Activeflag << endl;

									}
									else
									{
										fobjtemp << Activeflag << endl;
									}
								}
								ifstream openn("temp.txt");
								fstream fobj;
								fobj.open("bank.txt", ios::out);
								while (openn >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
								{

									fobj << id << endl;
									fobj << name << endl;
									fobj << family << endl;
									fobj << balance << endl;
									fobj << cardpass << endl;
									fobj << Cardnumber << endl;
									fobj << Activeflag << endl;

								}
								cout << endl;
								cout << "You enter mistake more than " << j << " times. Your Card is blocked" << endl;
								cardblock = 1;
								break;
							}

						}
					}
				}

			}
			else
			{
				if (cardblock == 1)
				{
					cardblock = 0;
					exit2();
				}
				else
				{
					cout << endl;
					cout << "Your card is blocked for security resoan, Please contact with bank administrator" << endl;
					exit2();
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
		cout << endl;
		cout << "Your request amount more than your balance. " << endl;
		cout << endl;
	}
	else
	{
		cout << "Please enter new card : ";
		cin >> ca;
		if (ca.length() != 16)
		{
			cout << "your card number is not correct. " << endl;
			cout << endl;
			cout << "Please enter new card : ";
			cin >> ca;
		}
		else if (ca != Cardnumber)
		{
			fstream fileobj2;
			fileobj2.open("bank.txt", ios::in);
			while (fileobj2 >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
			{
				if (ca == Cardnumber)
				{
					fileobj2 << id << endl;
					fileobj2 << name << endl;
					fileobj2 << family << endl;
					fileobj2 << balance << endl;
					fileobj2 << cardpass << endl;
					fileobj2 << Cardnumber << endl;
					fileobj2 << Activeflag << endl;
					if (Activeflag == 0)
					{
						lettransfer = 0;
						cout << endl;
						cout << "Sorry, Destination card is block for security resaon." << endl;
						break;
					}

				}
				else
				{
					lettransfer = 1;
				}
			}
			fstream fileobj22;
			fileobj22.open("bank.txt", ios::in);
			while (fileobj22 >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
			{
				if (ca == Cardnumber)
				{
					fileobj22 << id << endl;
					fileobj22 << name << endl;
					fileobj22 << family << endl;
					fileobj22 << balance << endl;
					fileobj22 << cardpass << endl;
					fileobj22 << Cardnumber << endl;
					fileobj22 << Activeflag << endl;

					cout << "Destination Customer name : " << name << endl;
					cout << "Destination Customer family : " << family << endl;
					cout << "Destination Customer Cardnumber : " << Cardnumber << endl;
					cout << "Transfer Amount : " << en << " IRR" << endl;
					cout << endl;
					cout << "Do you want to continue : (Y=1/N=0): ";
					cin >> acc;
					if (acc == 1)
					{
						if (lettransfer != 0)
						{
							ifstream open("bank.txt");
							fstream temp;
							temp.open("temp.txt", ios::out);
							while (open >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
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
								temp << Activeflag << endl;

							}
							ifstream openn("temp.txt");
							fstream bank1;
							bank1.open("bank.txt", ios::out);
							while (openn >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
							{
								if (id != fi)
								{
									bank1 << id << endl;
									bank1 << name << endl;
									bank1 << family << endl;
									bank1 << balance << endl;
									bank1 << cardpass << endl;
									bank1 << Cardnumber << endl;
									bank1 << Activeflag << endl;
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
									bank1 << Activeflag << endl;

								}
							}
						}
					}
					else
					{
						fstream fileobj;
						fileobj.open("bank.txt", ios::in);
						while (fileobj >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
						{
							if (id == fi)
							{
								fileobj << id << endl;
								fileobj << name << endl;
								fileobj << family << endl;
								fileobj << balance << endl;
								fileobj << cardpass << endl;
								fileobj << Cardnumber << endl;
								fileobj << Activeflag << endl;
								break;
							}
						}
					}
				}
			}

		}
		fstream fileobj;
		fileobj.open("bank.txt", ios::in);
		while (fileobj >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
		{
			if (id == fi)
			{
				fileobj << id << endl;
				fileobj << name << endl;
				fileobj << family << endl;
				fileobj << balance << endl;
				fileobj << cardpass << endl;
				fileobj << Cardnumber << endl;
				fileobj << Activeflag << endl;
				break;
			}
		}
	}
	if (flag == 1)
	{
		cout << endl;
		cout << en << " IRR successfully transfer. " << endl;
		flag = 0;
	}
	cout << endl;
	returnmainmenu();
}

void changePass1()
{
	cout << endl;
	passchangetostar();
	fstream fileobj;
	fileobj.open("bank.txt", ios::in);
	while (fileobj >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
	{
		if (id == fi)
		{
			fileobj << id << endl;
			fileobj << name << endl;
			fileobj << family << endl;
			fileobj << balance << endl;
			fileobj << cardpass << endl;
			fileobj << Cardnumber << endl;
			fileobj << Activeflag << endl;
			break;
		}
	}
	if (pass != cardpass)
	{
		cout << "You enter pass is incorrect  " << endl;
		returnmainmenu();
	}
	else
	{
		for (int i = 1; i <= 2; i++)
		{
			if (i == 1)
			{
				pass1 = passchangetostar1();
			}
			else if (i == 2)
			{
				pass2 = passchangetostar2();
			}
			 
		}
		if (pass1 != pass2)
		{
			cout << "your enterd pass not match" << endl;
				cout << endl;
				returnmainmenu();
		}
		else
		{
			ifstream open1("bank.txt");
			fstream temp;
			temp.open("temp.txt", ios::out);
			while (open1 >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
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
				temp << Activeflag << endl;
			}
			ifstream openn1("temp.txt");
			fstream bank11;
			bank11.open("bank.txt", ios::out);
			while (openn1 >> id >> name >> family >> balance >> cardpass >> Cardnumber >> Activeflag)
			{
				bank11 << id << endl;
				bank11 << name << endl;
				bank11 << family << endl;
				bank11 << balance << endl;
				bank11 << cardpass << endl;
				bank11 << Cardnumber << endl;
				bank11 << Activeflag << endl;
			}
			cout << endl;
			cout << "Your password change successfully." << endl;
			checkpass();
		}
	}
}
void exit()
{
	if (a == 4)
	{
		//cls();
		cout << endl;
		cout << "            Thanks you and good bye. ";
		cout << endl;
		cout << "Do you want login with another card : (Y=1/N=0)";
		cin >> rl;
		if (rl == 1)
		{
			fill1();
		}
	}
}
void exit2()
{
	cout << endl;
	cout << "                Thanks you and good bye. ";
	cout << endl;
	cout << "Do you want login with another card : (Y=1/N=0)";
	cin >> rl;
	if (rl == 1)
	{
		fill1();
	}
}

int cls()
{
	system("cls");
	return 0;
}

void passchangetostar()
{
	{
		int c = 0;
		char a[4];
		printf("\nPlease enter your card pass ");
		for (; c < 4;)
		{
			a[c] = getch();

			if (a[c] != 8)
			{
				printf("*");
				c++;
			}
			else
			{

				cout << "\b";
				cout << " ";
				cout << "\b";
				c--;
			}
		}
		string str(a, 4);
		pass = str;
	}

}

string passchangetostar1()
{
	{
		int c = 0;
		char a[4];
		printf("\nPlease enter your new password : ");
		for (; c < 4;)
		{
			a[c] = getch();

			if (a[c] != 8)
			{
				printf("*");
				c++;
			}
			else
			{

				cout << "\b";
				cout << " ";
				cout << "\b";
				c--;
			}
		}
		string str(a, 4);
		pass = str;
		return pass;
	}

}

string passchangetostar2()
{
	{
		int c = 0;
		char a[4];
		printf("\nPlease enter your new password agine : ");
		for (; c < 4;)
		{
			a[c] = getch();

			if (a[c] != 8)
			{
				printf("*");
				c++;
			}
			else
			{

				cout << "\b";
				cout << " ";
				cout << "\b";
				c--;
			}
		}
		string str(a, 4);
		pass = str;
		return pass;
	}

}

void returnmainmenu()
{
	cout << "For return to main menu, please enter number 5 : ";
	cin >> k;
	if (k == 5)
	{
		cls();
		menu1();
	}
	else
		do {
			cout << "For return to main menu, please enter number 5 : ";
			cin >> k;
			if (k == 5)
			{
				cls();
				menu1();
				break;
			}
		} while (k != 5);
}

