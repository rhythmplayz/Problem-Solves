/*
    Equidistribution Modulo 1 (Discrepancy of a Sequence):
    ------------------------------------------------------

    Given:
        - A sequence of real numbers x_0, x_1, ..., x_{n-1}.
        - Goal: Measure how uniformly the fractional parts {x_i} are
          distributed in the interval [0,1).

    1. Fractional Part Distribution:
        - Compute the fractional part of each term: frac(x_i) = x_i - floor(x_i)
        - A sequence is equidistributed modulo 1 if, for any subinterval [a, b] ⊆ [0,1),
          the proportion of terms falling in [a, b] approaches (b - a) as n → ∞.

    2. Discrepancy (D_n):
        - Discrepancy measures deviation from perfect uniformity:
              D_n = max_{0 ≤ a < b ≤ 1} | (# of {x_i} in [a,b])/n - (b-a) |
        - Smaller D_n indicates more uniform distribution.

    3. Application in the Code:
        - The code calculates the normalized sum of fractional deviations
          when distributing points evenly.
        - This is directly related to the concept of equidistribution and
          quantifies the sequence's discrepancy.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n;
    double dis, temp;

    while (cin >> n >> m)
    {
        m += n;
        dis = 0;

        for (ll i = 0; i < n; i++)
        {
            temp = (double)i * m / n;
            dis += abs(temp - round(temp)) / m;
        }

        cout << fixed << setprecision(4) << dis * 10000 << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4134