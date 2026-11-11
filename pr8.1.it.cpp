#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int FindThirdDot(char* str)
{
    int dotCount = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            if (dotCount == 3)
                return i; 
        }
    }
    return -1; // Менше трьох крапок
}

char* Change(char* str)
{
    size_t len = strlen(str);

    char* tmp = new char[len + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len)
    {
        if ((i + 1) % 4 == 0)
        {
            *t++ = '.';
            *t = '\0';
            i++;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy_s(str, len+1, tmp); 
    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int index = FindThirdDot(str);
    if (index != -1)
        cout << "Index of the 3rd dot (i): " << index << endl;
    else
        cout << "The string contains less than 3 dots." << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}