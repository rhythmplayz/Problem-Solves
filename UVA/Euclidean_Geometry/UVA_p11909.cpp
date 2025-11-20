/*
    Alternate Interior and Exterior Angles:
    ---------------------------------------
    When two parallel lines are cut by a transversal:

    1. Alternate Interior Angles:
       - These angles lie between the two parallel lines
         and on opposite sides of the transversal.
       - They are equal in measure.

    2. Alternate Exterior Angles:
       - These angles lie outside the two parallel lines
         and on opposite sides of the transversal.
       - They are also equal in measure.

    Explanation:
    - The equality of alternate interior and exterior angles
      is a key property used to prove lines are parallel
      and appears frequently in geometric problems.

    Tangent of an Angle (tan θ) Using Triangle Sides:
    -------------------------------------------------
    In a right triangle, tan θ is defined as:

                (length of the opposite side)
        tan θ = -----------------------------
                (length of the adjacent side)

    Explanation:
    - The opposite side is the side across from angle θ.
    - The adjacent side is the side next to angle θ,
      but not the hypotenuse.
    - This ratio describes how steep the angle is.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    double l, w, h, θ, ans;

    double π = acos((double)-1);

    while (cin >> l >> w >> h >> θ)
    {

        if (tan(π * (θ / 180.0)) <= h / l)
        {
            ans = ((l * w * h) - (0.5 * l * l * tan((double)π * (θ / 180.0)) * w));
            cout << fixed << setprecision(3) << ans << " mL\n";
        }
        else
        {
            ans = ((0.5 * h * h * w) / tan((double)π * (θ / 180.0)));
            cout << fixed << setprecision(3) << ans << " mL\n";
        }
    }
    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3060