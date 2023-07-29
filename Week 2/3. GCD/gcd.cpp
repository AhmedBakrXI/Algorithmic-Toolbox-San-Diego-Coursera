#include <iostream>
#include <algorithm>
using namespace std;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

/**
 * @brief Calculates greatest common divisor using Euclidean GCD Theory Recursively
 * 
 * @param a First Parameter
 * @param b Second Parameter
 * @return Greatest common divisor of a and b
 */
int gcd(int a, int b)
{
  int c = max(a, b);
  int d = min(a, b);

  if (d == 0)
    return c;

  return gcd(d, c % d);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
