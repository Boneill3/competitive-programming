#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int boring(int L, int R);
int boring_fast(int L, int R);

int main()
{
    int testCases, L, R;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cout << "Case #" << i << ": ";
        cin >> L >> R;
        cout << boring(L, R);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

int boring(int L, int R)
{
    int x = L;
    int count = 0;
    while(x <= R)
    {
        string val = to_string(x);

        ++count;
        for(int i=0;i<val.size();++i)
        {
            if(val[i] % 2 != (i+1) % 2)
            {
                --count;
                break;
            }
        }
        ++x;
    }
    return count;
}

int boring_fast(int L, int R)
{
}
