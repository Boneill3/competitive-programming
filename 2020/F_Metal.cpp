#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <climits>

using namespace std;

void metal(int N, int K);

int main()
{
    int testCases, N, K;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i)
    {
        cin >> N >> K;
        cout << "Case #" << i << ":";
        metal(N, K);
        cout << endl;
    }

    exit(EXIT_SUCCESS);
}

void metal(int N, int K)
{
    map<int, int> intervals;
    for(int i=0; i<N; ++i)
    {
        int S, E;
        cin >> S >> E;
        intervals.insert(make_pair(S, E));
    }

    int last_deploy = INT_MIN;
    int deploys = 0;
    for(auto interval = intervals.begin(); interval!=intervals.end(); ++interval)
    {
        //Potential edge case issue (overlapping last deploy with current vs new deploy at start)
        if(interval->first > (last_deploy + K))
        {
            last_deploy = interval->first;
            ++deploys;
        }

        int current_deploys = ceil((interval->second - (last_deploy+K)) / (double)K);
        last_deploy = last_deploy + (current_deploys * K);
        deploys += current_deploys;
    }

    cout << " " << deploys;
}