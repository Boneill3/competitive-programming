#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void calc(int N, int A, int B, int C);

int main()
{
    int testCases, N, A, B, C;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> N >> A >> B >> C;
        cout << "Case #" << i << ": ";
        calc(N, A, B, C);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

void calc(int N, int A, int B, int C)
{
    int gaps = N - A - B + C;
    int exclusiveA = A - C;
    int exclusiveB = B - C;
    int current = 0;
    int valA = 2;
    int valB = 3;

    if (gaps < 0 || exclusiveA < 0 || exclusiveB < 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    if (gaps + exclusiveA + exclusiveB + C > N || gaps + exclusiveA + exclusiveB + C < N ||
        (gaps > 0 && C == 1 && exclusiveA == 0 && exclusiveB == 0))
    {
        cout << "IMPOSSIBLE";
        return;
    }

    if (C == 0)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    if (N == 2)
    {
        if (gaps > 0)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        if (C != N)
        {
            valA = exclusiveA < exclusiveB ? 2 : 1;
            valB = exclusiveB <= exclusiveA ? 2 : 1;
        }
    }

    if (N == 3)
    {
        if (C == B == A == 1)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        valA = valB = 2;
    }

    for (int i = 0; i < exclusiveA; ++i)
    {
        cout << valA;
        ++current;
        if (current < N)
            cout << " ";
    }

    if (exclusiveA > exclusiveB)
    {
        for (int i = 0; i < gaps; ++i)
        {
            cout << 1;
            ++current;
            if (current < N)
                cout << " ";
        }
    }

    for (int i = 0; i < C; ++i)
    {
        if (exclusiveA == 0 && exclusiveB == 0 && i == C - 1)
        {
            for (int j = 0; j < gaps; ++j)
            {
                cout << 1;
                ++current;
                if (current < N)
                    cout << " ";
            }
        }

        cout << N;
        ++current;

        if (current < N)
            cout << " ";
    }

    //if eA == aB == 0, split C

    if (exclusiveA <= exclusiveB && (exclusiveA != 0 && exclusiveB != 0))
    {
        for (int i = 0; i < gaps; ++i)
        {
            cout << 1;
            ++current;
            if (current < N)
                cout << " ";
        }
    }

    for (int i = 0; i < exclusiveB; ++i)
    {
        cout << valB;

        ++current;
        if (current < N)
            cout << " ";
    }
}
