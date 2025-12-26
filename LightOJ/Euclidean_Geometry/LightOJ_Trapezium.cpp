/*
    Angle Between Two Sides of a Triangle (Given All Three Sides):
    --------------------------------------------------------------

    Let a, b, c > 0 be the side lengths of a triangle.
    Let the angle θ be the angle between sides a and b
    (opposite to side c).

    1. Triangle Validity:
        |a − b| < c < a + b

    2. Law of Cosines:
        c² = a² + b² − 2ab cosθ

    3. Angle Formula:
        cosθ = (a² + b² − c²) / (2ab)

        θ = arccos( (a² + b² − c²) / (2ab) )

    4. Domain Condition:
        −1 ≤ (a² + b² − c²) / (2ab) ≤ 1

    Remarks:
        - The angle is uniquely determined for a valid triangle.
        - Cyclic permutation of (a, b, c) yields the other angles.

    Tangent of an Angle in a Right Triangle:
    ---------------------------------------

    Consider a right triangle with one angle equal to 90°.
    Let θ be one of the two acute angles.

    1. Side Definitions:
        - Opposite side to θ:  opp
        - Adjacent side to θ:  adj
        - Hypotenuse:          hyp

    2. Tangent Definition:
        tanθ = opp / adj

    3. Pythagorean Relation:
        hyp² = opp² + adj²

    4. Domain:
        0 < θ < 90°
        tanθ > 0

    Remarks:
        - tanθ depends only on the ratio of the two legs.
        - Scaling the triangle does not change tanθ.

    Area of a Trapezium (Trapezoid):
    -------------------------------

    Let:
        - a, b be the lengths of the two parallel sides (a ∥ b),
        - h be the perpendicular distance (height) between them.

    1. Area Formula:
        Area = (1/2) · (a + b) · h

    2. Validity Conditions:
        a > 0,  b > 0,  h > 0

    Remarks:
        - The area equals the average of the parallel sides
          multiplied by the height.
        - Formula is independent of the non-parallel sides.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t;
    cin >> t;
    t_t = t;
    double a, b, c, d;
    while (t--)
    {
        cin >> a >> b >> c >> d;

        double diff_a_c = abs(a - c);

        double θ1 = acos((b * b + diff_a_c * diff_a_c - d * d) / (2 * b * diff_a_c));
        double θ2 = acos((d * d + diff_a_c * diff_a_c - b * b) / (2 * d * diff_a_c));

        double h = diff_a_c / (1.0 / tan(θ1) + 1.0 / tan(θ2));

        double ans = 0.5 * h * (a + c);

        cout << fixed << setprecision(8) << "Case " << t_t - t << ": " << ans << "\n";
    }
    return 0;
}

// https://lightoj.com/problem/trapezium