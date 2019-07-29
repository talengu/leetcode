#include <iostream>
#include "SortTestHelper.h"
using namespace std;

using namespace SortTestHelper;

int main(int argc, char const *argv[])
{
    int n = 100;
    int *arr = generateRandomArray(n, 0, n);

    printArray(arr, n);
    printArray(arr, n);

    delete[] arr;
    return 0;
}
