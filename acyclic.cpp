#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int n,m ; 
    cin >> n >> m ; 

    vector <vector<int >> adj(n);
    vector <int > inDegree(n, 0);
    for (int i=0 ; i< m ; i++)
    {
        int u,v ; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        inDegree[v]++;
    }


    queue<int > q;
    for (int i=0 ; i< n ; i++)
    {
        if (inDegree[i]== 0)
        {
            q.push(i);
        }
    }

    int count = 0 ; 
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        count ++; 

        for (int v: adj[ u])
        {
            inDegree[v]--;

            if (inDegree[v]==0)
            {
                q.push(v);

            }
        }

    


}

if (count == n )
{
    cout << " no cycle " << endl;

}
else 
{
    cout << " has cycle "<< endl;
    
}
}



