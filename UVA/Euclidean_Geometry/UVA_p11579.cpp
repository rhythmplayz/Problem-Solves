/*
    Triangle Inequality:
    --------------------
    Three sides a, b, c can form a triangle only if:
        a + b > c
        a + c > b
        b + c > a

    Explanation:
    - The sum of any two sides must be greater than the third side.
    - If any one of these conditions fails, a triangle cannot exist.

    Heron’s Formula for Area of a Triangle:
    ---------------------------------------
    Given three sides of a triangle: a, b, c

    1. Compute the semi-perimeter:
           s = (a + b + c) / 2

    2. Area is given by:
           Area = √( s × (s - a) × (s - b) × (s - c) )

    Explanation:
    - Heron's formula allows you to calculate the area
      without needing the height or any angles.
    - Works for all types of triangles as long as
      the triangle inequality is satisfied.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin >> t;
    ll n;

    while (t--)
    {
        cin >> n;
        vector<long double> edges(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> edges[i];
        }
        sort(edges.begin(), edges.end());

        long double ans = 0.0;
        long double temp;

        for (ll i = n - 1; i > 1; i--)
        {
            if (edges[i] < edges[i - 1] + edges[i - 2])
            {
                long double s = (edges[i] + edges[i - 1] + edges[i - 2]) / 2.0;
                temp = sqrt(s * (s - edges[i]) * (s - edges[i - 1]) * (s - edges[i - 2]));
                if (ans < temp)
                    ans = temp;
            }
        }

        cout << fixed << setprecision(2) << ans << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2626