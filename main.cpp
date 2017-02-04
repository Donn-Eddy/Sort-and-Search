#include <iostream>
#include <stdio.h> //for NULL
#include <stdlib.h> //for rand
#include <time.h> // for pacing
#include <array>

using namespace std;

array<int, 100> ToSort;

array<int, 100> Sort(array<int, 100> a);

int main()
{
    srand (time(NULL));

    for (int i = 0; i < 100; i++)
    {
        ToSort[i] = abs(rand());
        cout << ToSort[i] << ((i == 99) ? "" : ",");
    }

    cout << endl << endl;

    ToSort = Sort(ToSort);

    for (int i = 0; i < 100; i++)
    {
        cout << ToSort[i] << ((i == 99) ? "" : ",");
    }
    return 0;
}

array<int, 100> Sort(array<int, 100> a)
{
    bool sorted = true;
    do
    {
        sorted = true;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] < a[i-1])
            {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                sorted = false;
            }
            //No statistics have been done, but from the looks of it, adding this step keeps the time spent on sorting more consistent than just the above check.
            if (i != a.size())
            {
                if (a [i] > a[i+1])
                {
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    sorted = false;
                }
            }
        }

    } while (!sorted);
    return a;
}
