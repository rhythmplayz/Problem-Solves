/*
    Law of Cosines:
    ----------------
    cos C = (a² + b² – c²) / (2ab)

    Explanation:
    The angle C lies between sides a and b.
    The opposite side is c.
    This formula relates the three sides of a triangle
    to the cosine of the angle between two of them.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool right_angle_check(double a, double b, double c)
{
    double angleC = acos((a * a + b * b - c * c) / (2 * a * b));
    double angleB = acos((a * a + c * c - b * b) / (2 * a * c));
    double angleA = acos((c * c + b * b - a * a) / (2 * c * b));

    if (angleA == asin((double)1.0) || angleB == asin((double)1.0) || angleC == asin((double)1.0))
        return true;
    else
        return false;
}

int main()
{
    double a, b, c;

    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0, b == 0, c == 0)
            return 0;

        if (right_angle_check(a, b, c))
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2954