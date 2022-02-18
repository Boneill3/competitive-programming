#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int retype(int N, int K, int S);

int main()
{
    int testCases, N, K, S;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cout << "Case #" << i << ": ";
        cin >> N >> K >> S;
        cout << retype(N, K, S);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

int retype(int N, int K, int S)
{
    return min(K - S + N - S, N) + K;
}
