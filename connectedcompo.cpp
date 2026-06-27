#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector <vector <int >> adj;

void bfs(int startNode, vector<int > & currentcompo, vector < bool> &visited )
{
    queue<int >q;
    visited[startNode]= true;
    q.push(startNode);
    

    currentcompo.push_back(startNode);

    while (!q.empty())
    {
        int u= q.front();
        q.pop();
        for (int v: adj[u])
        {
            if (visited[ v]!= true)
            {
                visited[v]= true;
                q.push(v);
                currentcompo.push_back(v);

            }
        }


    }

}


int main()
{
    int m;

    cin >>n>>m ; 
    vector< vector <int >> allCompo;
    vector < bool> visited(n, false);
  adj.resize(n);

    for(int i=0; i<m; i++)
    {
        int u,v ; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0; i< n; i++)
    {
        if (!visited[i])

        {  vector <int > currentcompo;

            bfs(i, currentcompo, visited);
            allCompo.push_back(currentcompo);
        }
    }

    cout <<"total connected compo" << allCompo.size() << endl;

    for (int i=0; i<allCompo.size() ; i++ )
    {
        for (int node : allCompo[i])
        {
            cout <<node<< " ";

        }
        cout << "\n"<<endl;
    }

    return 0 ; 
}
