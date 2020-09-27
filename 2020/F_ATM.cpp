#include <iostream>
#include <string>
#include <math.h>
#include <queue>

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

struct person
{
    int index;
    int amt;
};

void atm(int N, int X)
{
    queue<person> line;
    queue<person> result;
    for (int i = 0; i < N; ++i)
    {
        int amt;
        cin >> amt;
        person new_person;
        new_person.amt = amt;
        new_person.index = i + 1;
        line.push(new_person);
    }

    while(!line.empty())
    {
        person current_person = line.front();
        line.pop();
        current_person.amt -= X;
        if(current_person.amt <= 0)
            cout << " " << current_person.index;
        else
            line.push(current_person);
    }
}