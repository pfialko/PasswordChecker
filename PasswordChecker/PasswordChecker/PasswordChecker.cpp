#include <iostream>
#include <cstring>
#include "checks.h"

using namespace std;

int main()
{
    string password;

    std::cout << "Passwort Checker\n Das Passwort muss folgende Kriterien erfüllen:\n\
                1. min. 12 Zeichen lang\n\
                2. Es dürfen nur 2 gleiche Zeichen nebeneinander enthalten\n\
                3. min. 2 Grossbuchstaben\n\
                4. min. 2 Kleinbuchstaben\n\
                5. min. 2 Ziffern\n\
                6. min. 2 Sonderzeichen\n";
    criteriacheck();                                                                                                //Calls "criteriacheck" from checks.cpp. It includes all functions for reviewing the password                                                                                            
    
}
