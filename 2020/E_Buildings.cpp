#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void calc(int N, int A, int B, int C);
void printGaps(int N, int A, int B, int C);

int main()
{
    int testCases, N, A, B, C;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> N >> A >> B >> C;
        cout << "Case #" << i << ":";
        calc(N, A, B, C);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

void calc(int N, int A, int B, int C)
{
    if (A + B - C > N || (A == 1 && B == 1 && C == 1 && N > 1))
    {
        cout << " IMPOSSIBLE";
        return;
    }

    if (N < 3)
    {
        if (N == 1)
            cout << " 1";

        else if (N == 2 && C == 2)
            cout << " 2 2";

        else if (N == 2 && A == 1)
            cout << " 2 1";

        else if (N == 2 && B == 1)
            cout << " 1 2";
        else
            cout << " IMPOSSIBLE";
        
        return;
    }

    //Exclusive A
    for (int i = 0; i < (A - C); ++i)
        cout << " 2";

    //Gaps Between A nd C
    if (C == 1 && (A - C) > (B - C))
        printGaps(N, A, B, C);

    //Both (C not printing when C == 1)
    for (int i = 0; i < floor(C / 2.0); i++)
        cout << " 3";

    //Gaps between C
    if (C > 1)
        printGaps(N, A, B, C);

    //Rest of Both
    for (int i = 0; i < ceil(C / 2.0); i++)
        cout << " 3";

    //Gaps Between C and B
    if (C == 1 && (A - C) <= (B - C))
        printGaps(N, A, B, C);

    //Exclusive B
    for (int i = 0; i < (B - C); i++)
        cout << " 2";
}

void printGaps(int N, int A, int B, int C)
{
    for (int i = 0; i < (N - A - B + C); i++)
        cout << " 1";
}