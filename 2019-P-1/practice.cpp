#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int beautyCalc(int size, string sections);

int main()
{
    int testCases, size;
    string sections;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> size;
        cin >> sections;        
        cout << "Case #" << i << ": " << beautyCalc(size, sections) << endl;
    }

    exit(EXIT_SUCCESS);
}

int beautyCalc(int size, string sections)
{
    int resultSize = ceil(size/2.00);
    int result = 0;
    int start = 0;
    int end = resultSize - 1;
    int current;

    //Get value from start
    for(int i=0;i < resultSize; ++i)
    {
        result += sections[i] - '0';
    }

    current = result;

    //Get Max Value
    while (end < size - 1)
    {
        current = current - (sections[start] - '0') + (sections[end + 1] - '0');
        ++start;
        ++end;
        result = max(result, current);
    }
    
    return result;
}
