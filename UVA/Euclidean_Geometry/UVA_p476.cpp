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
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct
{
    double xul, yul, xbr, ybr;
} REC_D;

int main()
{
    string rec_check;
    double xp, yp, xul, yul, xbr, ybr;
    bool fl;
    ll sz, p_cnt = 0;

    vector<REC_D> rec_ds;

    while (1)
    {
        cin >> rec_check;
        if (rec_check == "*")
            break;
        cin >> xul >> yul >> xbr >> ybr;
        REC_D rec;
        rec.xul = xul;
        rec.yul = yul;
        rec.xbr = xbr;
        rec.ybr = ybr;
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
            if (rec_ds[i].xul < xp && rec_ds[i].xbr > xp && rec_ds[i].yul > yp && rec_ds[i].ybr < yp)
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

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=417