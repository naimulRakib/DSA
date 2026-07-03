#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);

    if (rootx != rooty)
    {
        parent[rootx] = rooty;
        return true;
    }
    else
        return false;
}

vector<array<int, 4>> edges;

void resetparent(int n)
{
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}
int main()
{
    int primarycost = 1;
    int edgecount = 0;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, x, y, i});
    }
    vector<bool> visited(m, false);

    sort(edges.begin(), edges.end());
    resetparent(n);

    set<int> serials;
    for (auto e : edges)
    {

        if (unite(e[1], e[2]))
        {
            primarycost *= e[0];
            visited[e[3]] = true;

            edgecount++;
        }
    }

    if (edgecount != n - 1)
    {
      
        cout << "-1" << endl;
    }

    int best = -1;

    for (auto e : edges)
    { resetparent(n);
        int current = 1;
        int currentedge = 0;

        if (visited[e[3]] == false)
        {
            int d= e[0];

            int x = e[3];
            if (unite(e[1], e[2]))
            {
                current *= e[0];
                currentedge++;

            }


             for (auto e: edges)
        {
            if (d==e[3])continue;

            if (unite(e[1], e[2]))
            {
                current *=e[0];
                currentedge ++;

            }
            
        }

        }

if (current>primarycost)
    serials.insert(current);
      
    }


    for (auto s: serials)

    {
        cout <<s<<" ";
    }

    cout<<endl;

    return 0;
}