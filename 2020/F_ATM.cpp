#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

void atm(int N, int X);

int main()
{
    int testCases, N, X;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> N >> X;
        cout << "Case #" << i << ":";
        atm(N, X);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

void atm(int N, int X)
{
    multimap<double, int> values;
    for (int i = 0; i < N; ++i)
    {
        double amt;
        cin >> amt;
        amt = ceil(amt/X);
        values.insert(make_pair(amt, i+1));
        
    }

    for(auto iter = values.begin(); iter!=values.end(); ++iter)
        cout << " " << iter->second;
}