#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    int check;
    cout << "Choose any one operation of the string" << endl;
    cout << "1. length of string " << endl;
    cout << "2. Concatenate two strings " << endl;
    cout << "3. Revrse of a string " << endl;
    cout << "4. Copying a string " << endl;
    cin >> check;
    switch (check)
    {
    case 1:
        int i;
        cout << "enter the string for finding length" << endl;
        cin.ignore();
        getline(cin, str1);
        for (i = 0; str1[i]; i++)
            ;
        cout << i << endl;
        break;
    case 2:
        cout << "For concatenate two string " << endl;
        cout << "Enter a string" << endl;
        cin.ignore();
        getline(cin, str1);
        cout << "Enter another string" << endl;
        getline(cin, str2);
        str1 = str1 + str2;
        cout << str1 << endl;
        break;
    case 3:
        int j, len;
        cout << "For  reverse of the string " << endl;
        cout << "enter the string " << endl;
        cin.ignore();
        getline(cin, str1);
        for (j = 0; str1[j]; j++)
            ;
        len = j;
        cout << "printing reverse of string" << endl;
        for (int i = len - 1; i >= 0; i--)
        {
            cout << str1[i];
        }
        break;
    case 4:
        int l;

        cout << "For copying first string to second  string " << endl;
        cout << "Enter the first string" << endl;
        cin.ignore();
        getline(cin, str1);
        for (l = 0; str1[l]; l++)
        {

            str2[l] = str1[l];
        }
        cout << "first string =" << str1 << endl;
        cout << "second  string =" << endl;
        for (l = 0; str2[l]; l++)
        {
            cout << str2[l];
        }
        break;
    default:
        cout << "NONE OF THE ABOVE CHOOSEN PLEASE SELECT ONE " << endl;
    }

    return 0;
}