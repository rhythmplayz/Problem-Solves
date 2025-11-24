/*
    Ratio of Areas of Similar Triangles:
    ------------------------------------
    Consider a smaller triangle formed inside a larger triangle
    by drawing a line parallel to the base. The two triangles
    are similar.

    Let:
        A1 = area of the smaller triangle
        A2 = area of the larger triangle
        h1 = height (or slanted height) of the smaller triangle
        h2 = height (or slanted height) of the larger triangle

    Relationship:
        A1 / A2 = (h1 / h2)²

    Explanation:
    - Similar triangles have proportional sides.
    - If the linear ratio is h1 / h2, then the ratio of areas
      is the square of the linear ratio.
    - This applies to any pair of similar triangles formed
      by a line parallel to one side.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t, t_t;
    cin >> t;
    t_t = t;

    double ab, ac, bc, r, ans;

    while (t--)
    {

        cin >> ab >> ac >> bc >> r;

        ans = sqrt((r * ab * ab) / (1.0 + r));

        cout << fixed << setprecision(8) << "Case " << t_t - t << ": " << ans << "\n";
    }

    return 0;
}

// https://lightoj.com/problem/triangle-partitioning