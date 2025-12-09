/*
    Point-Inside-Rectangle Condition (Strict, No Boundary Inclusion):
    -----------------------------------------------------------------

    Given:
        - Rectangle defined by two opposite corners:
              (x1, y1) = lower–left corner
              (x2, y2) = upper–right corner
        - A point P = (px, py)

    1. Valid Rectangle:
        Requires:
            x1 < x2
            y1 < y2

    2. Strict Interior Condition (Point on boundary is NOT allowed):
        A point P lies strictly inside the rectangle iff:
            x1 < px < x2
            y1 < py < y2

    3. Meaning:
        - Inequalities are strict (“<”), excluding edges.
        - Any point with px = x1, px = x2, py = y1, or py = y2 is *not* inside.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t;
    cin >> t;
    t_t = t;

    ll a, b, c, d, m, x, y;

    while (t--)
    {
        cout << "Case " << t_t - t << ":\n";
        cin >> a >> b >> c >> d;
        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            if (x > a && x < c && y > b && y < d)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}

// https://lightoj.com/problem/how-cow