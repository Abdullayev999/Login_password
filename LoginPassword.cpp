#include <iostream>
#pragma warning (disable: 4996)
#include <cstdio>

using namespace std;

/*
		 Задание 1: Контроль доступа
		 - При первом запуске программы пользователь установить логин и пароль
		 - В следующий раз при запуске программы должен требоваться ввод логина и пароля,
		 - которые были выбраны при первом запуске программы
		 - На все действия пользователя должна быть ответная реакция
*/

struct Account
{
	int password;
	char login[30];
};

int main()
{
	Account person;
//	char location[50];

	cout << "Sign up \n\nPlease , enter login\n";
	cin >> person.login;

	cout << "Please , enter password\n";
	cin >> person.password;


	//	cout << "Enter file location :\n";
	//	cin >> location;		
	//  "Abdullayev.txt"


	FILE* creatFile = fopen("Abdullayev.txt", "wb");
	if (creatFile) {
		cout << "Record saved\n";
		fwrite(&person, sizeof(Account), 1, creatFile);
		fclose(creatFile);
	}
	else {
		perror("Error message");
	}

	Account check, enter;

	FILE* file = fopen("Abdullayev.txt", "rb");
	if (file)
	{
		cout << "Information read \n";
		fread(&check, sizeof(Account), 1, file);
	}
	else {
		perror("Error message");
	}

	cout << "login = " << check.login << '\n';
	cout << "password = " << check.password << '\n';


	do
	{
		cout << "Enter Sign in \n\nPlease , enter login\n";
		cin >> enter.login;

		cout << "Please , enter password\n";
		cin >> enter.password;

		if (enter.password == check.password && strcmp(enter.login, check.login) == 0) {
			cout << "Welcome\n";
			break;
		}
		else {
			cout << "Please try again\n";
		}
	} while (true);


}