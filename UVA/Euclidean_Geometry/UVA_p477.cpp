/*
    Check if a Point is Inside a Rectangle (Exclusive of Border):
    -------------------------------------------------------------
    Given:
        - Rectangle defined by two points:
            Upper-left: (x1, y1)
            Lower-right: (x2, y2)
        - Test point: (px, py)

    Condition:
        - px must be strictly between x1 and x2:  x1 < px < x2
        - py must be strictly between y2 and y1:  y2 < py < y1
          (assuming y-axis increases upward; adjust if y-axis increases downward)

    Explanation:
    - This ensures the point is strictly inside the rectangle.
    - Points lying exactly on the rectangle's border are not considered inside.
    - The check works for axis-aligned rectangles only.

    Check if a Point is Inside a Circle (Exclusive of Border):
    ----------------------------------------------------------
    Given:
        - Center of the circle: (cx, cy)
        - Radius of the circle: r
        - Test point: (px, py)

    Condition:
        - Compute the squared distance between the point and the center:
              d² = (px - cx)² + (py - cy)²
        - The point is strictly inside the circle if:
              d² < r²

    Explanation:
    - Using squared distance avoids the cost of square roots.
    - If d² equals r², the point lies exactly on the circumference
      and is NOT considered inside.
    - If d² is greater than r², the point lies outside the circle.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct
{
    string type;
    double xul, yul, xbr, ybr;
    double xc, yc, radius;
} REC_D;

int main()
{
    string type_check;
    double xp, yp, xul, yul, xbr, ybr;
    double xc, yc, radius;
    bool fl;
    ll sz, p_cnt = 0;

    vector<REC_D> rec_ds;

    while (1)
    {
        cin >> type_check;
        if (type_check == "*")
            break;
        REC_D rec;
        if (type_check == "r")
        {
            cin >> xul >> yul >> xbr >> ybr;
            rec.type = type_check;
            rec.xul = xul;
            rec.yul = yul;
            rec.xbr = xbr;
            rec.ybr = ybr;
        }
        if (type_check == "c")
        {
            cin >> xc >> yc >> radius;
            rec.type = type_check;
            rec.xc = xc;
            rec.yc = yc;
            rec.radius = radius;
        }

        rec_ds.push_back(rec);
    }

    while (1)
    {
        cin >> xp >> yp;
        p_cnt++;
        if (xp >= 9999.9 && yp >= 9999.9)
            break;
        fl = true;
        sz = rec_ds.size();

        for (ll i = 0; i < sz; i++)
        {
            if (rec_ds[i].type == "r" && rec_ds[i].xul < xp && rec_ds[i].xbr > xp && rec_ds[i].yul > yp && rec_ds[i].ybr < yp)
            {
                fl = false;
                cout << "Point " << p_cnt << " is contained in figure " << i + 1 << "\n";
            }
            if (rec_ds[i].type == "c" && (rec_ds[i].xc - xp) * (rec_ds[i].xc - xp) + (rec_ds[i].yc - yp) * (rec_ds[i].yc - yp) < rec_ds[i].radius * rec_ds[i].radius)
            {
                fl = false;
                cout << "Point " << p_cnt << " is contained in figure " << i + 1 << "\n";
            }
        }
        if (fl)
            cout << "Point " << p_cnt << " is not contained in any figure\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=418