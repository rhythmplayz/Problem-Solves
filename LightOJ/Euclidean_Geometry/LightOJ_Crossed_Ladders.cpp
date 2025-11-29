/*
    Ratio in Similar Triangles:
    ---------------------------
    When two triangles are similar, all corresponding sides
    are in the same ratio.

    Let:
        Triangle 1 sides = a1, b1, c1
        Triangle 2 sides = a2, b2, c2

    Side Ratio:
        a1 / a2 = b1 / b2 = c1 / c2

    Area Ratio:
        (Area of Triangle 1) / (Area of Triangle 2)
            = (a1 / a2)²
            = (b1 / b2)²
            = (c1 / c2)²

    Explanation:
    - Similar triangles have equal corresponding angles.
    - Their sides are proportional.
    - Areas scale with the square of the side ratio.

    Pythagorean Theorem:
    --------------------
    In a right triangle with legs a and b,
    and hypotenuse c:

        c² = a² + b²

    Explanation:
    - The hypotenuse is the side opposite the right angle.
    - The square of the hypotenuse equals the sum of the squares
      of the other two sides.
    - This property holds only for right-angled triangles.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

double calcu(double x, double y, double h)
{
    double a, b;
    a = sqrt(x * x - h * h);
    b = sqrt(y * y - h * h);
    double c = (a * b) / (a + b);
    return c;
}

double bin_src(double h, double l, double c, double x, double y)
{
    double m = l + (h - l) / 2.0;
    double ans = calcu(x, y, m);
    if (abs(ans - c) < 0.00000001)
        return m;
    if (ans < c)
        return bin_src(m, l, c, x, y);
    return bin_src(h, m, c, x, y);
}

int main()
{
    ll t, t_t;
    cin >> t;
    t_t = t;

    double x, y, c, ans;

    while (t--)
    {

        cin >> x >> y >> c;

        ans = bin_src(min(x, y), 0, c, x, y);

        cout << fixed << setprecision(10) << "Case " << t_t - t << ": " << ans << "\n";
    }

    return 0;
}

// https://lightoj.com/problem/crossed-ladders