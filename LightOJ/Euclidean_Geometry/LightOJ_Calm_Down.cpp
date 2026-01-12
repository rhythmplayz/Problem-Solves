/*
    Polygon Side Length (Inscribed in a Circle):
    --------------------------------------------
    Given a regular polygon with (n) sides inscribed in a
    circle of radius (R), the length of a single side (s)
    can be determined using trigonometry.

    Variables:
        n = number of sides (n ≥ 3)
        R = circumradius (distance from center to a vertex)
        θ = central angle subtended by one side

    The side length (s) is given by:
        s = 2 * R * sin(180° / n)

    Explanation:
    - A regular polygon can be divided into (n) identical
      isosceles triangles with two sides equal to (R).
    - The central angle θ of each triangle is 360° / n.
    - By bisecting this isosceles triangle into two right
      triangles, the angle at the center becomes 180° / n.
    - Using the sine ratio:
        sin(180° / n) = (opposite) / (hypotenuse) = (s / 2) / R
    - Rearranging for (s) gives the final formula.
    - As (n) approaches infinity, the perimeter (n * s)
      approaches the circumference of the circle (2 * π * R).

    Polygon Inradius (Apothem):
    --------------------------
    Given a regular polygon with (n) sides and a side length (s),
    the inradius (r) is the distance from the center to the
    midpoint of any side. This is also the radius of the circle
    inscribed within the polygon.

    Variables:
        n = number of sides (n ≥ 3)
        s = length of one side
        r = inradius (apothem)

    The inradius (r) is given by:
        r = s / [2 * tan(180° / n)]

    Explanation:
    - The inradius is the perpendicular distance from the center
      to a side, forming a right triangle within the polygon.
    - The central angle subtended by a side is 360° / n.
    - Bisecting this angle creates a right triangle with an
      angle of (180° / n) at the center.
    - In this right triangle:
        * The side opposite the angle is s / 2
        * The side adjacent to the angle is the inradius r
    - Using the tangent ratio:
        tan(180° / n) = (s / 2) / r
    - Solving for r results in the formula above.

    Circumference of a Circle:
    --------------------------
    The circumference (C) is the total linear distance around
    the edge of a circle. It is the one-dimensional perimeter
     of a two-dimensional curved shape.

    Variables:
        r = radius (distance from center to edge)
        d = diameter (distance across circle through center)
        π = pi (constant ≈ 3.14159)

    The circumference (C) is given by:
        C = 2 * π * r
        OR
        C = π * d

    Explanation:
    - The constant π (pi) is defined as the ratio of any
      circle's circumference to its diameter.
    - Since the diameter is exactly twice the radius (d = 2r),
      the formulas are mathematically equivalent.
    - Relationship to Area:
        * The circumference is the derivative of the area
          formula (A = π * r²) with respect to r.
    - In the context of regular polygons, as the number of
      sides (n) increases to infinity, the polygon's perimeter
      converges to the circumference of its circumscribed circle.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double PI = 2 * acos(0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t;

    cin >> t;
    t_t = t;

    double R, n, r;

    while (t--)
    {
        cin >> R >> n;
        double c = sin(PI / n);

        r = (c * R) / (1 + c);

        cout << fixed << setprecision(8) << "Case " << t_t - t << ": " << r << "\n";
    }

    return 0;
}

// https://lightoj.com/problem/calm-down