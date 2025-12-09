/*
    Distance Between Two Points in the Euclidean Plane:
    ---------------------------------------------------

    Given:
        Two points:
            P₁ = (x₁, y₁)
            P₂ = (x₂, y₂)

    1. Euclidean Distance:
        The distance d between P₁ and P₂ is:
            d = √[ (x₂ − x₁)² + (y₂ − y₁)² ]

    2. Properties:
        - d ≥ 0
        - d = 0  ⇔  P₁ = P₂
        - Symmetry:  d(P₁, P₂) = d(P₂, P₁)
        - Satisfies the triangle inequality.

    3. Interpretation:
        This is the standard L² (Euclidean) metric in ℝ².
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    double ans, a, b, c, d, x, y;

    while (t--)
    {
        cin >> a >> b >> c >> d;

        x = a - c;
        y = b - d;

        ans = sqrt(x * x + y * y) / 2.0;

        cout << fixed << setprecision(6) << ans << "\n";
    }

    return 0;
}

// https://www.spoj.com/problems/UNIR/