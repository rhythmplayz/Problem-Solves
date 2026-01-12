/*
    Inradius of a Triangle (Incircle):
    ----------------------------------
    The inradius (r) is the radius of the largest circle that
    can fit inside a triangle. This circle (the incircle) is
    tangent to all three sides of the triangle.

    Variables:
        a, b, c = lengths of the three sides
        Area    = total area of the triangle
        s       = semi-perimeter

    The semi-perimeter is calculated as:
        s = (a + b + c) / 2

    The inradius (r) is given by:
        r = Area / s

    Explanation:
    - The center of this circle (the incenter) is the point
      where the three angle bisectors of the triangle intersect.
    - Heron's Formula is used to find Area from side lengths:
        Area = √[s(s - a)(s - b)(s - c)]
    - Combining these, the direct formula for inradius is:
        r = √[((s - a)(s - b)(s - c)) / s]
    - Geometrically, the triangle is composed of three smaller
      triangles with height (r) and bases (a, b, c).
      Summing their areas gives: (1/2)ar + (1/2)br + (1/2)cr = rs.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;

    while (cin >> a >> b >> c)
    {
        double s = (a + b + c) / 2.0;

        // For a possible edge case: If the area is 0.000
        if (a == 0.000 || b == 0.000 || c == 0.000)
            cout << fixed << setprecision(3) << "The radius of the round table is: 0.000\n";
        else
            cout << fixed << setprecision(3) << "The radius of the round table is: " << sqrt(s * (s - a) * (s - b) * (s - c)) / s << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1136