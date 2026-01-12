/*
    Area of a Parallelogram (Triangle Expansion Method):
    ----------------------------------------------------
    Given any three points A, B, and C, the area of the
    parallelogram formed by these points is exactly twice
    the area of the triangle ABC.

    Points:
        A = (x1, y1)
        B = (x2, y2)
        C = (x3, y3)

    The area is calculated using the expanded determinant form:

        Area = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|

    Explanation:
    - This formula is derived from the "Shoelace Formula" or
      the determinant of a 3x3 matrix for triangle area.
    - Standard Triangle Area = 0.5 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|.
    - A parallelogram defined by these three points consists
      of two identical triangles joined along a common side.
    - By multiplying the triangle area by 2, we remove the
      0.5 coefficient, leaving the raw expansion.
    - If the resulting area is 0, the three points are
      collinear (they lie on the same straight line).

    Finding the Fourth Vertex of a Parallelogram:
    ---------------------------------------------
    Given three vertices of a parallelogram (A, B, and C)
    in order, the fourth vertex D can be found by applying
    the vector properties of parallel sides.

    Points:
        A = (ax, ay)
        B = (bx, by)
        C = (cx, cy)

    The coordinates for the fourth point D (completing
    the parallelogram ABCD) are:

        Dx = ax + (cx - bx)
        Dy = ay + (cy - by)

    Explanation:
    - In a parallelogram, opposite sides are equal and parallel.
    - This means the vector from B to C must be identical
      to the vector from A to D.
    - Vector BC = (cx - bx, cy - by).
    - To find D, we simply "push" point A by that same vector:
        Dx = ax + VectorBC_x
        Dy = ay + VectorBC_y
    - Note: There are three possible parallelograms that can
      be formed depending on which point is chosen as the
      "pivot" (the middle vertex). The formula above
      assumes B is the vertex between A and C.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t, ax, ay, bx, by, cx, cy;
    cin >> t;
    t_t = t;

    while (t--)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        cout << "Case " << t_t - t << ": " << ax + (cx - bx) << " " << cy - (by - ay) << " " << abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) << "\n";
    }
    return 0;
}

// https://lightoj.com/problem/area-of-a-parallelogram