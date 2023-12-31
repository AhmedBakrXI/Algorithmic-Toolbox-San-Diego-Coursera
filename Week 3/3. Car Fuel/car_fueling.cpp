#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    if (dist <= tank)
        return 0;

    stops.push_back(dist);
    int distance_covered = 0;
    bool flag = false;
    int i = 0;
    int current_stop = 0;
    int num_of_stops = 0;
    while (distance_covered < dist)
    {
        while (i < stops.size() && (stops[i] - current_stop) <= tank)
        {
            /* code */
            i++;
            flag = true;
        }
        if (flag)
        {
            if (i == stops.size())
                break;
            current_stop = stops[i - 1];
            distance_covered = stops[i - 1];
            num_of_stops++;
        }
        else
        {
            return -1;
        }
        flag = false;
    }
    return num_of_stops;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
