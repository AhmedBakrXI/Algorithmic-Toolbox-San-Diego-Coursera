/*
 * @author: Ahmed Mohammed Bakr
 */

#include <iostream>
using namespace std;

long long calc_fib(unsigned int n);

int main()
{
    int n;
    cin >> n;
    cout << calc_fib(n) << endl;
    return 0;
}


/**
 * @brief This function is used to calculate F(n) in fibonacci series
 * 
 * @param n is the index at which we want to calculate the number
 * @return F(n)
 */
long long calc_fib(unsigned int n)
{
    long long fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}