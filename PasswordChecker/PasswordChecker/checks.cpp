#include <iostream>
#include <string>
#include "checks.h"

using namespace std;

/*Function called criteriacheck. Doesn't have any parameters.
First you get the password. After that the password will be checked, if it verifys all 6 criteria. This process will loop
If the Password is called "quit", the process will stop and the programm will end*/
void criteriacheck()
{
	string password;																														
	do																																		//Start of do-while loop for "quit"
	{
		std::cout << "Geben Sie ein Passwort ein:\n";																						//Output of Text
		std::cin >> password;																												//Input for password

		if (password.length() >= 12)																										//Check, if the password is min. 12 characters long
		{
			if (doublecheck(password) && countletter(password))																				//calls the functions doublecheck and countletter to check for the criteria
				std::cout << "Passwort ist sicher!\n";																						//Output of Text
		}
		else if (password == "quit")																										//Checks, if the password input is "quit"
			std::cout << "Das Programm wird Beendet\nVielen Dank für die Verwendung";														//Output of Text
		else																																//If the password lenght is to short, return an error
		{
			std::cout << "Passwort zu kurz\n";																								//Output of Error Text
		}
	} while (password != "quit");																											//End of do-while loop for "quit". It loops until the password is "quit"
}

/*Function called doublecheck. Function Parameter is a string called password and it returns a bool (True/ False)
The Function checks, if two characters are the same for each letter of the word. 
When two characters are the same two times in a row, the function returns a false*/
bool doublecheck(string password)
{
	bool isdouble = false;
	for (int i = 1; i < password.length(); i++)																								//Loop for every character of the password. Starts from one
	{
		if (!isdouble)																														//Checks, if the last two characters weren't already the same
		{
			if (password[i] == password[i - 1])																								//Checks, if the current character and the character before are the same
				isdouble = true;																											//If it was the same, isdouble will be set to true
			else
				isdouble = false;																											//If the characters aren't the same, isdouble will be set to false
			
		}
		else																																//If the last two characters were the same
		{
			if (password[i] == password[i - 1])																								//Checks, if the current character and the one before are the same
			{
				std::cout << "Passwort hat zu viele Wiederholungen!\n";																		//Error Output
				return false;																												//returns false
			}
			else																															//Characters aren't the same
				isdouble = false;																											//isdouble will be set to false
		}
	}
	return true;																															//returns true. There were no three same characters
}

/*Function called countletter. Functionparameter is a string called password and it returns a bool.
It counts the type of Letters/Characters the password has.
If the password has under two letters of a type, it returns a false*/
bool countletter(string password)
{
	int capital = 0, lower = 0, number = 0, special = 0;
	for (int i = 0; i < password.length(); i++)																								//loop for every character of password
	{
		if (password[i] >= 'A' && password[i] <= 'Z')																						//checks, if the current letter is between A and Z
			capital++;																														//increase Nr of Capital
		else if (password[i] >= 'a' && password[i] <= 'z')																					//checks, if the current letter is between a and z
			lower++;																														//increase Nr of lower
		else if (password[i] >= '0' && password[i] <= '9')																					//checks, if the current letter is a number
			number++;																														//increase Nr of number
		else																																//checks, if the current letter is a special
			special++;																														//increase Nr of special
	}
	if (capital < 2 || lower < 2 || number < 2 || special < 2)																				//check, if all 4 variables are under two
	{
		if (capital < 2)																													//checks, if under two and then output of error
			std::cout << "Zu wenig Großbuchstaben\n";
		if (lower < 2)
			std::cout << "Zu wenig Kleinbuchstaben\n";
		if (number < 2)
			std::cout << "Zu wenig Zahlen\n";
		if (special < 2)
			std::cout << "Zu wenig Sonderzeichen\n";
		return false;																														//returns false for not safe password
	}
	else
		return true;																														//returns true
}
