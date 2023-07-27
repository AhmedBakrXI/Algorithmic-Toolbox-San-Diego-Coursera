/*
 * @author Ahmed Mohammed Bakr
 */

#include <iostream>
using namespace std;

#define PRE_INDEX_INIT -1
long long MaxPairwiseProduct(const long long *numbers, int n);

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << MaxPairwiseProduct(arr, n) << endl;
    return 0;
}

/**
 * @brief Finds the two greatest numbers in array and returns their maximum product
 * @note  This function is not safe and the program can crash for example if the numbers
 *        pointer equals NULL
 * 
 * @param numbers Pointer to an array of elements of type long long
 * @param n       Number of elements of the array
 * @return        The Max product of two elements of the array
 */
long long MaxPairwiseProduct(const long long *numbers, int n)
{
    int max_index1 = -1, max_index2 = -1;

    // search for first greatest number
    for (int firstSearchCounter = 0; firstSearchCounter < n; firstSearchCounter++)
    {
        if ((PRE_INDEX_INIT == max_index1) || (numbers[firstSearchCounter] > numbers[max_index1]))
        {
            max_index1 = firstSearchCounter;
        }
    }

    // search for second greatest number
    for (int secondSearchCounter = 0; secondSearchCounter < n; secondSearchCounter++)
    {
        if ((secondSearchCounter != max_index1) && ((PRE_INDEX_INIT == max_index2) || (numbers[secondSearchCounter] > numbers[max_index2])))
        {
            max_index2 = secondSearchCounter;
        }
    }

    return (long long)(numbers[max_index1] * numbers[max_index2]);
}
