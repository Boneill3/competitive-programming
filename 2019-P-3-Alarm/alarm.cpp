#include <iostream>
#include <tgmath.h>

using namespace std;

int *create_array(int n, int x1, int y1, int C, int D, int E1, int E2, int F);
int calc(int C, int D, int E1, int E2, int F, int last_xi, int last_yi, bool xi);

int main()
{
    //We are reading in a file in the following format
    int num_tests;
    int array_size; //N is documentation
    int calls;      //K in documentation
    int x1;
    int y1;
    int C;
    int D;
    int E1;
    int E2;
    int F;
    //End input data

    int * data_array = NULL;

    cin >> num_tests;
    cin.ignore(100,'\n');

    for (int test_case = 0; test_case < num_tests; ++test_case)
    {
        cin >> array_size;
        cin >> calls;
        cin >> x1;
        cin >> y1;
        cin >> C;
        cin >> D;
        cin >> E1;
        cin >> E2;
        cin >> F;
        cin.ignore(100,'\n');

        data_array = create_array(array_size, x1, y1, C, D, E1, E2, F);

        //For each array look at each contiguous array 
        // 1*1^2 + 2*2^2 + 4*3^2

        double total = 0;

        for(int power=1; power <= calls; ++power)
        {
            double current = 0;
            int size = 1;
            int start = 0;

            for(size=1; size <= array_size; ++size)
            {
                current = 0;
                int end = size - 1;

                for(int i=0; i < size - 1; ++i)
                {
                    current += data_array[i];
                }

                while(end < array_size)
                {
                    total += current + (data_array[end] * pow(size, power)); 
                    current += data_array[end];
                    current -= data_array[start];
                    start++;
                    ++end;
                }
            }
        }

        cout << "Case #" << test_case + 1 << ": " << total << endl;

    }

    exit(EXIT_SUCCESS);
}

int *create_array(int n, int x1, int y1, int C, int D, int E1, int E2, int F)
{
    //Formula to create array from input
    //x1 = C xi-1 + Dyi-1 + E1 mod f
    //y1 D xi-1 + Cyi-1 + e2 mod f
    //Ai = (xi+yi)
    int *result = new int[n];
    int last_xi = x1;
    int last_yi = y1;
    int xi;
    int yi;

    result[0] = (x1 + y1) % F;
    for (int i = 1; i < n; ++i)
    {
        xi = calc(C, D, E1, E2, F, last_xi, last_yi, true);
        yi = calc(C, D, E1, E2, F, last_xi, last_yi, false);
        result[i] = (xi + yi) % F;
        last_xi = xi;
        last_yi = yi;
    }

    return result;
}

int calc(int C, int D, int E1, int E2, int F, int last_xi, int last_yi, bool xi)
{
    if (xi)
        return (C * last_xi + D * last_yi + E1) % F;
    else
        return (D * last_xi + C * last_yi + E2) % F;
}
