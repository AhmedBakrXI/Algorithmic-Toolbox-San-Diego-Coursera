#include <iostream>
#include <vector>

using std::vector;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    int count_weight = 0;

    // write your code here
    double weight_per_pound[weights.size()];

    for (int i = 0; i < weights.size(); i++)
    {
        weight_per_pound[i] = (float)weights[i] / values[i];
    }

    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = i + 1; j < weights.size(); j++)
        {
            if (weight_per_pound[j] < weight_per_pound[i])
            {
                swap(&weights[j], &weights[i]);
                swap(&values[j], &values[i]);
            }
        }
    }

    for (int i = 0; i < weights.size(); i++)
    {
        int w = weights[i];
        for (int j = weights[i]; weights[i] != 0; weights[i]--)
        {
            if (capacity > 0)
            {
                value += (double) values[i]/w;
                capacity--;
            }
        }
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
