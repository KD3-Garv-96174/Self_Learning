#include <iostream>
using namespace std;

int getLength(const char *input)
{
    int length = 0;

    while (input[length] != '\0')
    {
        length++;
    }

    return length;
}

void copyString(char *destination, const char *source)
{
    int index = 0;

    while (source[index] != '\0')
    {
        destination[index] = source[index];
        index++;
    }

    destination[index] = '\0'; 
}

int main()
{
    char originalString[] = "Hello";
    char copiedString[20];

    cout << "Length: " << getLength(originalString) << endl;

    copyString(copiedString, originalString);
    cout << "Copied string: " << copiedString << endl;

    return 0;
}