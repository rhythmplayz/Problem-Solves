/*
    Conical Glass — Volume and Related Formulas (Mathematical Form):
    ----------------------------------------------------------------

    Model: Right circular cone (apex at top, circular base).
    Let:
        r  > 0   be the radius of the base,
        h  > 0   be the vertical height (apex → base),
        π        denote pi.

    1. Full Cone Volume (V):
        V = (1/3) · π · r^2 · h

    2. Linear radius scaling (similar triangles):
        For a horizontal cross-section at distance x from the apex (0 ≤ x ≤ h),
            radius at that level:  ρ(x) = (r / h) · x

    3. Volume of cone portion from apex to height x (0 ≤ x ≤ h):
        V_apex(x) = ∫_{t=0}^{x} π [ρ(t)]^2 dt
                  = (1/3) · π · (r^2 / h^2) · x^3
        (Note: V_apex(h) = full cone volume.)

    4. Volume of liquid when filled to height y measured from the base (0 ≤ y ≤ h):
        Let x = h − y (distance from apex to liquid surface).
        Volume filled from base up to height y:
            V_filled(y) = V − V_apex(x)
                        = (1/3)·π·r^2·h  −  (1/3)·π·(r^2/h^2)·(h − y)^3

    5. Conical Frustum (portion between two parallel planes at distances x1 and x2 from apex,
       with 0 ≤ x1 < x2 ≤ h). Radii:
            R1 = ρ(x1) = (r/h)·x1
            R2 = ρ(x2) = (r/h)·x2
       Height of frustum: H_f = x2 − x1
       Frustum volume:
            V_frustum = (1/3)·π·H_f·(R1^2 + R1·R2 + R2^2)

    6. Validity Conditions:
        r > 0, h > 0.
        For partial volumes, heights must satisfy 0 ≤ x ≤ h (apex-based)
        or 0 ≤ y ≤ h (base-based). Frustum heights satisfy 0 ≤ x1 < x2 ≤ h.

    Remarks:
        - All formulas assume a perfect right circular cone and consistent units.
        - Use π = acos(−1) in numeric code for π.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

double Pi = acos(-1.0);

double b_sc(double r1, double r2, double h, double p, double l, double r)
{
    double q = 1.0 / 3.0;
    double m = l + (r - l) / 2.0;
    double a = q * Pi * h * (r1 * r1 + r2 * r2 + r1 * r2);
    double b = (q * Pi * (h - p) * (r1 * r1 + m * m + r1 * m)) + (q * Pi * p * (m * m + r2 * r2 + m * r2));
    if (abs(a - b) < 0.00000001)
        return q * Pi * p * (m * m + r2 * r2 + m * r2);
    else if (a < b)
        return b_sc(r1, r2, h, p, l, m);
    else
        return b_sc(r1, r2, h, p, m, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t;
    cin >> t;
    t_t = t;

    double r1, r2, h, p, ans;

    while (t--)
    {
        cin >> r1 >> r2 >> h >> p;

        ans = b_sc(r1, r2, h, p, r2, r1);

        cout << fixed << setprecision(8) << "Case " << t_t - t << ": " << ans << "\n";
    }

    return 0;
}

// https://lightoj.com/problem/juice-in-the-glass