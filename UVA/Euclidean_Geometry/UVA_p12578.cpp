/*
    Area of a Rectangle:
    --------------------
    Area = length × width

    Explanation:
    Multiply the two perpendicular sides of the rectangle.
    Result is the total surface covered by the rectangle.

    Area of a Circle:
    -----------------
    Area = π × r²

    Explanation:
    The radius (r) is the distance from the center to the edge.
    Squaring the radius and multiplying by π gives
    the total surface area of the circle.

    Calculating a Number From a Ratio:
    ---------------------------------
    If the ratio of two numbers is a : b,
    and one number is known, the other can be found using:

        If first number (A) is known:
            A / B = a / b
            => B = (A * b) / a

        If second number (B) is known:
            A / B = a / b
            => A = (B * a) / b

    Explanation:
    Ratios represent proportional relationships.
    By cross-multiplying (a / b = A / B),
    you can solve for the missing value.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t;

    double l;

    cin >> t;

    while (t--)
    {

        cin >> l;

        cout << fixed << setprecision(2) << (0.2 * l) * (0.2 * l) * acos((double)-1) << " " << (0.6 * l * l) - ((0.2 * l) * (0.2 * l) * acos((double)-1)) << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4023