/*
    Arc and Chord Length on a Circle:
    ---------------------------------
    Given:
        - Radius of the circle: r
        - Central angle between two points: θ (in degrees or radians)

    1. Arc Length:
       - The arc length is the distance along the circumference
         between the two points.
       - Formula: Arc Length = r × θ (if θ is in radians)
       - If θ is in degrees, convert to radians first:
             θ_rad = θ_deg × (π / 180)
             Arc Length = r × θ_rad

    2. Chord Length:
       - The chord is the straight line connecting the two points on the circle.
       - Formula: Chord Length = 2 × r × sin(θ / 2) (θ in radians)

    Explanation:
    - Arc length follows the circle's curve, chord length is straight.
    - Both formulas depend only on the radius and the angle between the points.
    - Remember to convert degrees to radians if needed when using trigonometric functions.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    double h, a, arc_l, chord_l;
    ll a_ll;
    string s;
    double pi = 2 * acos(0.0);

    while (cin >> h >> a >> s)
    {
        h += 6440.0;
        if (s == "min")
            a /= 60.0;

        // if internal angle goes over 360º
        if (a > 360.0)
        {
            a_ll == (ll)(a / 360.0);
            a -= (360.0 * (double)a_ll);
        }

        // if internal angle is over 180º then (360º - internal angle) is the closest distance
        if (a > 180.0)
            a = 360.0 - a;

        arc_l = h * pi * (a / 180.0);
        chord_l = 2 * h * sin((pi * (a / 180.0)) / 2.0);

        cout << fixed << setprecision(6) << arc_l << " " << chord_l << "\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1162