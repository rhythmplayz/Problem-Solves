/*
    Triangle Validity Check:
    ------------------------
    A triangle is possible if and only if
    the sum of any two sides is greater than the third.

        a + b > c
        a + c > b
        b + c > a

    Explanation:
    These conditions ensure that the three line segments
    can physically meet to form a closed triangle.
    If any one of these is false, the sides cannot form a triangle.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool triangle_check(ll a, ll b, ll c){
    if(a+b<=c)return false;
    if(a+c<=b)return false;
    if(c+b<=a)return false;

    return true;
}

int main()
{
    ll t,a,b,c;

    cin >> t;

    while(t--){
        cin>>a>>b>>c;

        if(triangle_check(a,b,c))cout<<"OK\n";
        else cout<<"Wrong!!\n";
    }

    return 0;
}

// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3087