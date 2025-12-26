/*
    Depth-First Search (DFS):
    ------------------------

    Given:
        - A graph G = (V, E), where V is the set of vertices
          and E is the set of edges.
        - Graph may be directed or undirected.

    1. Core Idea:
        - Explore as far as possible along one branch before backtracking.
        - Uses a stack discipline (explicit stack or recursion).

    2. DFS Traversal:
        Start from a vertex s ∈ V.
        Recursively (or iteratively) visit an unvisited adjacent vertex
        until no further progress is possible.

    3. Mathematical View:
        - DFS generates a spanning tree (or forest) of G.
        - Each vertex v ∈ V is visited exactly once.

    4. Time and Space Complexity:
        - Time:  O(|V| + |E|)
        - Space: O(|V|)   (recursion stack or explicit stack)

    5. Applications:
        - Connected components
        - Cycle detection
        - Topological sorting
        - Strongly connected components

    3D to 2D Projection with Column-wise Unique Component Aggregation:
    ------------------------------------------------------------------

    A 3D grid is projected onto the (x, y) plane by scanning along the z-axis.
    For each fixed (x, y), all cells (x, y, z) are examined.

    Connected components (reservoirs) are pre-labeled in 3D space.
    While traversing a column, each distinct component id is counted once.

    The column’s value is the sum of sizes of all unique components intersecting it.
    The final result is the maximum such sum over all surface positions (x, y).
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, z, cnt, rsv_num = 0;

vector<vector<vector<ll>>> matrix;
vector<vector<vector<ll>>> vis1, vis2;
vector<vector<vector<ll>>> matrix_rsv_num;
vector<ll> rsv_taken;

void matrix_print()
{
    for (ll i = 0; i < z; i++)
    {
        for (ll j = 0; j < x; j++)
        {
            for (ll k = 0; k < y; k++)
            {
                cout << matrix[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void matrix_rsv_num_print()
{
    for (ll i = 0; i < z; i++)
    {
        for (ll j = 0; j < x; j++)
        {
            for (ll k = 0; k < y; k++)
            {
                cout << matrix_rsv_num[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void dfs_3d(ll X, ll Y, ll Z)
{
    if (!vis1[Z][X][Y] && matrix[Z][X][Y])
    {
        cnt++;
        vis1[Z][X][Y] = 1;

        if (X - 1 >= 0)
            dfs_3d(X - 1, Y, Z);
        if (X + 1 < x)
            dfs_3d(X + 1, Y, Z);
        if (Y - 1 >= 0)
            dfs_3d(X, Y - 1, Z);
        if (Y + 1 < y)
            dfs_3d(X, Y + 1, Z);
        if (Z - 1 >= 0)
            dfs_3d(X, Y, Z - 1);
        if (Z + 1 < z)
            dfs_3d(X, Y, Z + 1);
    }
}

void dfs_3d_2(ll X, ll Y, ll Z)
{
    if (!vis2[Z][X][Y] && matrix[Z][X][Y])
    {
        matrix[Z][X][Y] = cnt;
        matrix_rsv_num[Z][X][Y] = rsv_num;
        vis2[Z][X][Y] = 1;

        if (X - 1 >= 0)
            dfs_3d_2(X - 1, Y, Z);
        if (X + 1 < x)
            dfs_3d_2(X + 1, Y, Z);
        if (Y - 1 >= 0)
            dfs_3d_2(X, Y - 1, Z);
        if (Y + 1 < y)
            dfs_3d_2(X, Y + 1, Z);
        if (Z - 1 >= 0)
            dfs_3d_2(X, Y, Z - 1);
        if (Z + 1 < z)
            dfs_3d_2(X, Y, Z + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, t_t;
    cin >> t;
    t_t = t;

    string y_in;

    while (t--)
    {
        cin >> x >> y >> z;
        rsv_num = 0;

        matrix = vector<vector<vector<ll>>>(z, vector<vector<ll>>(x, vector<ll>(y, 0)));
        matrix_rsv_num = vector<vector<vector<ll>>>(z, vector<vector<ll>>(x, vector<ll>(y, 0)));
        vis1 = vector<vector<vector<ll>>>(z, vector<vector<ll>>(x, vector<ll>(y, 0)));
        vis2 = vector<vector<vector<ll>>>(z, vector<vector<ll>>(x, vector<ll>(y, 0)));

        for (ll i = 0; i < z; i++)
        {
            for (ll j = 0; j < x; j++)
            {
                cin >> y_in;

                for (ll k = 0; k < y; k++)
                {
                    if (y_in[k] == '.')
                    {
                        matrix[i][j][k] = 1;
                    }
                }
            }
        }

        for (ll i = 0; i < z; i++)
        {
            for (ll j = 0; j < x; j++)
            {
                for (ll k = 0; k < y; k++)
                {
                    cnt = 0;
                    if (!vis1[i][j][k] && matrix[i][j][k])
                        rsv_num++;
                    dfs_3d(j, k, i);
                    dfs_3d_2(j, k, i);
                }
            }
        }
        // matrix_print();
        // matrix_rsv_num_print();

        ll ans = 0;
        ll temp = 0;

        for (ll j = 0; j < x; j++)
        {
            for (ll k = 0; k < y; k++)
            {
                rsv_taken = vector<ll>();
                temp = 0;
                for (ll i = 0; i < z; i++)
                {
                    if (vis1[i][j][k])
                    {
                        if (rsv_taken.size())
                        {
                            bool not_taken = true;
                            for (ll r : rsv_taken)
                            {
                                if (r == matrix_rsv_num[i][j][k])
                                {
                                    not_taken = false;
                                    break;
                                }
                            }
                            if (not_taken)
                            {
                                rsv_taken.push_back(matrix_rsv_num[i][j][k]);
                                temp += matrix[i][j][k];
                                ans = max(temp, ans);
                            }
                        }
                        else
                        {
                            rsv_taken.push_back(matrix_rsv_num[i][j][k]);
                            temp += matrix[i][j][k];
                            ans = max(temp, ans);
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

// https://codeforces.com/gym/106270/problem/C