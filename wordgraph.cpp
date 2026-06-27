/**
the problem is like that hit >> hot >> dot >> dog >> cog 
this type of here every bit changes take 1 distance between them
**/


#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool isNeighbour (
    const string &a, const string &b
)


{ int diff= 0;

    for (int i=0 ; i<(int)a.size();i++)
    {
        if (a[i]!=b[i]){diff++;
        }

        if (diff>1)
        return false ;

    }
    return diff==1;

}


int main()
{
    int n; 
    cin >>n ; 
    vector <string > words(n);

    for (int i=0; i<n; i++)
    {
        cin >>words[i];

    }

    string start, target ;

    cin >>start>> target;
    int src, dist; 

    if (start == target )
    {
        cout <<-1; return true ;

    }


    for (int i =0; i< n; i++ )
    {
        if (words[i]== start) src=i;
        if (words[i]==target) dist =i;

    }


    vector <vector <int >> adj (n);

    for (int i = 0 ; i< n; i++)
    {
        for (int j= i+1; j<n; j++)
        {
            if (isNeighbour(words[i], words[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                
            }
        }
    }


     vector <int > distance(n,-1);
    queue<int > q;

distance[src]=0;
q.push(src);

while (!q.empty())
{

    int u =q.front();
    q.pop()
;

for (int v: adj[u])
{
    if (distance[v]==-1)
    {
        distance[v]= distance[u]+1;
        if (v==dist )
        {
            cout <<distance[v]<<endl;;
            return 0; 
           

        }

         q.push(v);
    }
}
}
cout <<-1<<endl;



}