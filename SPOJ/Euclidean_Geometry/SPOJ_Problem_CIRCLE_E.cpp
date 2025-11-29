/*
    Soddy Circles (Inner and Outer) — Based on Three Mutually Tangent Circles:
    --------------------------------------------------------------------------
    Given:
        - Three mutually tangent circles A, B, C with radii a, b, c.
        - Circle D: the inner Soddy circle (inscribed in the gap between A, B, C).
        - Circle E: the outer Soddy circle (circumscribed around A, B, C).

    1. Inner Soddy Circle (D):
        - Fits inside the gap between the three circles.
        - Radius (d) is given by:
              d = (a * b * c) / (ab + bc + ca + 2 * sqrt(abc * (a + b + c)))
        - This is the smaller circle that touches all three given circles
          from the inside.

    2. Outer Soddy Circle (E):
        - Circumscribes the three given circles.
        - Radius (e) is given by:
              e = (−a * b * c) / (ab + bc + ca − 2 * sqrt(abc * (a + b + c)))
        - This is the larger circle that touches all three given circles
          from the outside.

    Explanation:
    - The formulas use the radii of the original circles directly.
    - The inner circle fills the triangular gap, while the outer circle
      encloses the three original circles.
    - These are special cases of Descartes' Circle Theorem.
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

    double a, b, c, ans;

    while (t--)
    {

        cin >> a >> b >> c;

        ans = (a * b * c) / (a * b + b * c + c * a + (2.0 * sqrt(a * b * c * (a + b + c))));

        cout << fixed << setprecision(6) << ans << "\n";
    }

    return 0;
}

// https://www.spoj.com/problems/CIRCLE_E/