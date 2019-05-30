#include <iostream>
#include <windows.h>
using namespace std;

#define tab "/t"
void InputLine(char str[], const int n);
int StrLen(char str[]);

void UpperCase(char str[]);
void LowerCase(char str[]);
void CapitaLize(char str[]);

void Shrink(char str[]);
void RemoveSpace(char str[]);

bool isPalindrome(char str[]);
bool isNumber(char str[]);
int string_to_int(char str[]);
void main()
{
	setlocale(LC_ALL, "Rus");
	//char str[] = {'H', 'e','l','l','o','\0' };
	//cout << str << endl;
	//char mgs[] = "Hello";
	//cout << mgs << endl;

	const int n = 30;
	char str[n] = {};
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl;
	/*cout << StrLen(str) << endl;
	cout << endl;
	UpperCase(str);
	cout << str << " > CAPS" << endl;;
	LowerCase(str);
	cout << str<< " > nizniy" << endl;
	CapitaLize(str);
	cout << str  << " > Zaglavnaya" << endl;
	Shrink(str);
	cout << str << " > delete space" << endl;
	cout << StrLen(str) << endl;
	RemoveSpace(str);
	cout << str << " > delete all space" << endl;
	cout << StrLen(str) << endl;*/
	cout << "\n-----------------------------------------------\n";
	cout << isPalindrome(str) << endl;
	cout << str << " > Palindrome" << endl;
	cout << "\n-----------------------------------------------\n";
	cout << isNumber(str) << endl;
	cout << str << " > is Number" << endl;
	cout << "\n-----------------------------------------------\n";
	cout << string_to_int(str) +5 << endl;
	cout << str << endl;
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StrLen(char str[])
{
	int C = 0;
	for (; *str; str++)	C++;
	return C;
}

void UpperCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32; // eng

		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32; // Ru
	}
}
void LowerCase(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;

		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
	}
}
void CapitaLize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] <= 'а' && str[0] <= 'я')str[0] -= 32;
	for (int i = 1; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
			if (str[i] >= 'а' && str[i] <= 'я') str[i] -= 32;
		}
	}
}

void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void RemoveSpace(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool isPalindrome(char str[])
{
	int n = StrLen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)
	{
		buffer[i] = str[i];
	}
	LowerCase(buffer);
	RemoveSpace(buffer);
	n = StrLen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			return false;
		}
	}
	return true;
}
bool isNumber(char str[])
{
	int n = StrLen(str);
	char* buf = new char[n + 1]{};

	strcpy_s(buf, n + 1, str);
	cout << buf << endl;
	RemoveSpace(buf);

	/*for (int i = 0; str[i]; i++)
	{
		buf[i] = str[i];
	}
	n = StrLen(buf);

	for (int i = 0; buf[i]; i++)
	{
		if (buf[i] >= 'a' && buf[i] <= 'z' || buf[i] >= 'A' && buf[i] <= 'Z') return false;
		if (buf[i] >= 'а' && buf[i] <= 'я' || buf[i] >= 'А' && buf[i] <= 'Я' || buf[i] >= 'ё' && buf[i] >= 'Ё') return false;
	}*/

	bool contain_point = false;

	for (int i = buf[0] == '+' || buf[0] == '-' ? 1 : 0; i < buf[i]; i++)
	{
		if (buf[i] == '.' && !contain_point)
		{
			contain_point = true;
			continue;

		}
		if (!(buf[i] >= '0' && buf[i] <= '9')) return false;
	}
	return true;
}
int string_to_int(char str[])
{
	if (!isNumber(str))
	{
		cout << "Error is not nubmer" << endl;;
		return 0;
	}

	int n = strlen(str);
	char* buf = new char[n + 1]{};
	strcpy(buf, str);
	RemoveSpace(buf);

	int number = 0;
	for (int i = 0; buf[i]; i++)
	{
		number *= 10;
		number += buf[i] - 48;
	}
	return number;

}