#include <iostream>
#include <stdio.h> //for NULL
#include <stdlib.h> //for rand
#include <time.h> // for pacing
#include <array>

using namespace std;

array<int, 100> ToSort;

array<int, 100> Sort(array<int, 100> a);

int BinSearch(array<int, 100> a, int s);

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

    //Print the array after it's sorted to make it easier to see.
    for (int i = 0; i < 100; i++)
    {
        cout << ToSort[i] << ((i == 99) ? "" : ",");
    }

    int toSearch = 0;

    std::cout << std::endl << "What number should I find? ";
    std::cin >> toSearch;

    std::cout << std::endl;

    int result = BinSearch(ToSort, toSearch);

    std::cout << std::endl << result << std::endl;

    return 0;
}

int BinSearch(const array<int, 100> a, int s)
{
    //I will perform a basic boolean search.

    //-2 == still searching | -1 == not found
    int lo = 0;
    int hi = a.size();
    int toUse = 0;
    int last = -1;

    //Used in loop to reduce calls to the array.
    int value;

    while (true)
    {
        // Search the center of the remaining numbers
        toUse = (hi - lo) / 2 + lo;

        //If not found
        if (lo == hi || last == toUse) return -1;

        //Prevent exceeding array bounds
        if (toUse >= a.size()) toUse = a.size() - 1;

        value = a[toUse];

        if (value == s) return toUse;
        if (value < s) lo = toUse;
        if (value > s) hi = toUse;

        last = toUse;

        std::cout<< "lo: " << lo << " hi: " << hi << std::endl;
    }

    //error
    return -2;
}

array<int, 100> Sort( array<int, 100> a)
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
