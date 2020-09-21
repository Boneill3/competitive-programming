#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int calc(int* arr, int size);

int main()
{
    int testCases, size;
    int * arr;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> size;
        arr = new int[size];
        cout << "Case #" << i << ": " << calc(arr, size) << endl;
    }

    exit(EXIT_SUCCESS);
}

int calc(int* arr, int size)
{
    if(size < 2)
        return size;

    int difference = arr[0] - arr[1];
    int max = 0;
    int current = 1;

    for(int i = 1; i < size - 1; ++i)
    {
        if(arr[i] - arr[i+1] == difference)
            ++current;
        else
            current = 0;

        max = current > max ? current : max;
    }

    return max;
}