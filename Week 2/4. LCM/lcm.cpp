#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
/**
 * @brief Calculates greatest common divisor using Euclidean GCD Theory Recursively
 *
 * @param a First Parameter
 * @param b Second Parameter
 * @return Greatest common divisor of a and b
 */
long long gcd(long long a, long long b)
{
    long long c = max(a, b);
    long long d = min(a, b);

    if (d == 0)
        return c;

    return gcd(d, c % d);
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}
