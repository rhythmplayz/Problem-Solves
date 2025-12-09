/*
    Triangle Validity and Area Using Medians (Pure Mathematical Form):
    -------------------------------------------------------------------

    Let m_a, m_b, m_c ∈ ℝ⁺ be the medians corresponding to sides a, b, c.

    1. Validity of a Triangle from Its Medians:
        A triangle with medians m_a, m_b, m_c exists ⇔
            m_a + m_b > m_c
            m_b + m_c > m_a
            m_c + m_a > m_b
        and
            m_a > 0,  m_b > 0,  m_c > 0

        These are the standard triangle inequalities applied to
        the “median triangle” formed by (m_a, m_b, m_c).

    2. Area of the Triangle (Δ) from the Medians:
        Let
            s = (m_a + m_b + m_c) / 2       (semiperimeter of median-triangle)

        Area of median-triangle:
            Δ_m = √[ s(s − m_a)(s − m_b)(s − m_c) ]

        Relation between the areas:
            Δ_m = (3/4) Δ

        Therefore:
            Δ = (4/3) · √[ s(s − m_a)(s − m_b)(s − m_c) ]

    3. Final Formula (Compact Form):
            Δ = (4/3) √{ s(s − m_a)(s − m_b)(s − m_c) }

    This expresses the exact area of the original triangle solely
    in terms of its three medians.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool triangle_validity(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return false;
    if (a >= b + c)
        return false;
    if (b >= a + c)
        return false;
    if (c >= a + b)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, s, ans;

    while (cin >> a >> b >> c)
    {
        if (triangle_validity(a, b, c))
        {
            s = (a + b + c) / 2.0;
            ans = (4.0 / 3.0) * sqrt(s * (s - a) * (s - b) * (s - c));

            cout << fixed << setprecision(3) << ans << "\n";
        }
        else
        {
            cout << "-1.000\n";
        }
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1288