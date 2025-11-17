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

    Difference Between Square and Circle Areas:
    -------------------------------------------
    Consider a circle of radius r inscribed in a square of side 2r.

    - Area of square = 4 times r squared
    - Area of circle = π times r squared

    Therefore, the difference between the areas:

        Difference = Area of square - Area of circle
                   = r² × (4 - π)

    Explanation:
    - This formula gives the area of the square that 
    is not covered by the inscribed circle.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t, t_t;

    double r;

    cin >> t;
    t_t = t;

    while (t--)
    {

        cin >> r;

        cout << fixed << setprecision(2) << "Case " << t_t - t << ": " << (4 * r * r) - (2 * acos(0.0) * r * r) << "\n";
    }

    return 0;
}

// https://lightoj.com/problem/circle-in-square