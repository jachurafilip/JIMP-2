#include "Palindrome.h"
#include <iostream>

using namespace std;
int main()
{
    cout <<"1 - Sprawdz palindrom\n";
    cout <<"2 - Wyjscie\n\n";

    char key;
    string slowo;
    cin >> key;
    while (key != '2')
    {
        if (key == '1')
        {
            cout << "Podaj slowo: \n";
            cin >> slowo;
            cout << IsPalindrome(slowo) << endl;
        }
    cout <<"1 - Sprawdz palindrom\n";
    cout <<"2 - Wyjscie\n\n";
    cin >> key;
    }
}
