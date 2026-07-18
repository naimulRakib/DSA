#include <iostream>
#include <algorithm>
#include <map>

using namespace std ; 
const int INF = 1e8;

int main()
{
    int n;
    cin >>n; 
    vector <string > names(n);
    map <string , int> idx ;
 for (int i= 0 ; i< n ; i++)
 {
    cin >> names[i];
    idx[names[i]]= i ; 

 }

 int m;
 cin >> m ; 
 const double inf= 1e9 ; 
 vector <vector <double >> dist (n, vector <double >(n, INF));
 for (int i = 0 ; i < n ; i++)
 {
dist[i][i] = 0 ; 

 }


 for (int i = 0 ; i <m ; i++)
 {
string from , to;double rate;
cin >> from >> rate>> to ; 
int u = idx[from];
int v= idx[to];
double w= -log(rate);
if (w<dist[u][v])
{
    dist[u][v]= w;

}
 }

 for (int k = 0 ; k < n ; k++)
 {
    for (int i=0 ; i <n; i++)
    {
        if (dist[i][k]>= INF) continue; 
        for (int j = 0 ;j< n ; j++)
        {
             if (dist[k][j]>= INF) continue; 
             if (dist[i][k]+ dist[k][j]< dist[i][j])
             {
                 dist[i][j]= dist[i][k]+ dist[k][j];

             }
        }

    }
 }

 vector <bool> negcycle (n, false);
 for (int i =0 ; i< n ; i++)

 {
    
if (dist[i][i]<-1e-9)
{
    negcycle[i]= true;

}


 }

 vector <string > result;
 for (int i = 0 ; i<n ; i++)
 {
    bool canarbitage = false;
    for (int k = 0 ; k< n ; k++)
    {
        if (dist[i][k]<INF && negcycle[k])
        {
            canarbitage = true;
            break;

        }
    }

    if (canarbitage )
    {result.push_back({names[i]});

 }




}
}
