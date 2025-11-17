/*
    Quadrilateral Type Check (Given 4 Sides):
    ----------------------------------------
    Let the four sides be a, b, c, d.

    1. Quadrilateral Validity:
       - The sum of any three sides must be greater than the fourth side.
       - This ensures the four sides can form a closed quadrilateral.

    2. Rectangle Check:
       - Opposite sides must be equal: a == c and b == d
       - Knowing only side lengths, angles cannot be confirmed.
       - So, with sides only, this is a necessary but not sufficient condition.

    3. Square Check:
       - All four sides must be equal: a == b == c == d
       - Knowing only sides, angles cannot be confirmed.
       - With sides alone, this is necessary but not sufficient to guarantee a square.

    Explanation:
    - Side lengths alone can help identify potential quadrilateral types,
      but angles (or diagonals) are needed to fully confirm rectangles and squares.
    - Always first check if the sides satisfy the quadrilateral inequality.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll type_quadrangle_checker(ll a, ll b, ll c, ll d)
{
    if (a == b && b == c && c == d)
        return 1; // square
    if ((a == c && b == d) || (a == b && c == d) || (a == d && b == c))
        return 2; // rectangle
    if (a + b + c > d && a + b + d > c && a + c + d > b && c + b + d > a)
        return 3; // quadrangle
    return 4;     // banana
}

int main()
{
    ll t, a, b, c, d;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> d;

        switch (type_quadrangle_checker(a, b, c, d))
        {
        case 1:
            cout << "square\n";
            break;

        case 2:
            cout << "rectangle\n";
            break;

        case 3:
            cout << "quadrangle\n";
            break;

        case 4:
            cout << "banana\n";
            break;
        }
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2450