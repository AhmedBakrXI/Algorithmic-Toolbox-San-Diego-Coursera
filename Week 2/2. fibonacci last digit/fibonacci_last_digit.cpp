#include <iostream>
#include <cstdlib>
using namespace std;

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit(int n)
{
    int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] % 10 + fib[i - 2] % 10) % 10;
    }

    return fib[n];
}

int main()
{
    // Stress Test
    /*
    while (1)
    {
        unsigned int randomNum = (rand() % 100 + 2);
        int a = get_fibonacci_last_digit(randomNum);
        int b = get_fibonacci_last_digit_naive(randomNum);

        if(a==b){
            cout << "OK" << endl;
        }
        else
        {
            cout<< "NOT OK: "<< a << " " << b << " " << randomNum<< endl;
            break;
        }
    }
    */
    
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    int d = get_fibonacci_last_digit(n);
    cout << c << '\n';
    cout << d << '\n';
    return 0;
}
