#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool isBipartite(int v, vector <vector <int>> &adj)
{

    vector <int > color (v,-1);

    queue<int >q;


for (int i= 0; i < v ; i++)
{
    if (color[i]== -1)
    {
        color[i]= 0;
    

    q.push(i);
    
while (!q.empty())
{
    int u = q.front();
    q.pop();

    for (int v: adj [ u ])
    {
        if (color[v]== -1)
        {
            color[v]=1-color[u];
            q.push(v);
        }

        else if (color[v]== color[u])
        {
            return false;
        }
    }
}
    }
}


return true;

}


int main()
{
    int n, m ; 
    cin >> n >> m; 

    vector <vector <int >> adj(n);

    for (int i = 0 ; i < m ; i++)
    {
        int a, b; 
       cin>> a >> b; 
       adj[a].push_back(b);
       adj[b].push_back(a);
    }

   
        if (isBipartite(n, adj))   
        {
cout << "bipartite"<<endl;

        }
        else 
        {cout << " not bipartite " << endl;}
        
    
return 0 ;
    
}