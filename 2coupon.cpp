#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include<tuple>

using namespace std;

typedef long long ll;
const ll INF = 1e16;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++)

    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<array<ll, 3>> dist(n + 1, {INF, INF, INF});
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [d, u, c] = pq.top();
        pq.pop();
        if (d > dist[u][c])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v][c] > dist[u][c] + w)

            {
                dist[v][c] = dist[u][c] + w;
                pq.push({dist[v][c], v, c});
            }

            if (c < 2 && dist[u][c] + w / 2 < dist[v][c + 1])
            {
                dist[ v][c + 1] = dist[u][c] + w / 2;
                pq.push({dist[v][c + 1], v, c + 1});
            }

            {
            }
        }
    }
}