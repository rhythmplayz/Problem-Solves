/*
    Triangle Validity and Classification (Mathematical Formulation):
    ----------------------------------------------------------------

    Given:
        - Side lengths: a, b, c ∈ ℝ.

    1. Valid Triangle (Existence Conditions):
        A triangle exists iff:
            a > 0,  b > 0,  c > 0
        AND the Triangle Inequality holds:
            a < b + c
            b < a + c
            c < a + b

        If any condition fails → Invalid Triangle.

    2. Equilateral Triangle:
        Defined by:
            a = b = c

    3. Isosceles Triangle:
        Defined by:
            (a = b) ∨ (b = c) ∨ (a = c)
        and triangle inequality must still hold.

    4. Scalene Triangle:
        Defined by:
            a ≠ b,  b ≠ c,  a ≠ c

    Notes:
        - If max(a, b, c) ≥ (sum of the other two), the triangle is non-existent.
        - Zero or negative side lengths violate geometric definition.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string triangleType(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return "Invalid";
    if ((a >= b && a >= c && a < b + c) || (b >= a && b >= c && b < a + c) || (c >= b && c >= a && c < b + a))
    {
        if (a == b && b == c && c == a)
        {
            return "Equilateral";
        }
        if (a == b || b == c || c == a)
        {
            return "Isosceles";
        }
        return "Scalene";
    }
    return "Invalid";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    ll t_t;
    t_t = t;

    double a, b, c;

    while (t_t--)
    {
        cin >> a >> b >> c;

        string st = triangleType(a, b, c);

        cout << "Case " << t - t_t << ": " << st << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2474