map<string, int> name_to_id;
    map<int, string> id_to_name;
    int current_id= 1;

auto getId = [&](string s) {
        if (name_to_id.find(s) == name_to_id.end()) {
            name_to_id[s] = current_id;
            id_to_name[current_id] = s;
            current_id++;
        }
        return name_to_id[s];
    };





    ///////////////////
    int getans (      vector <vector <pair <int , int >>>adj,int n, int livein, int dest, int m )

{


  
    vector <int > parent (n,-1);
     priority_queue<pair <int, int>, vector <pair <int, int >>,  greater<pair <int , int >>> pq;
    vector <int > dist (n, INF);
    dist[livein]=0;
    pq.push({0,livein});


    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();
        int cost = edge.first;
        int curnode = edge.second;
      if (dist[curnode]< cost) continue; 

      for (auto e: adj[curnode])
      {
        int v = e.first;
        int w= e.second;

        if (dist[curnode]+w< dist[v])
        {
            dist[v]=dist[curnode]+w;
            pq.push({dist[v], v});
          parent[v]= curnode;


        }


      }

    }

    vector<int > path;
    for (int i = dest; i!=-1 ;i = parent[i])
    {
        path.push_back(i);

    }

    reverse(path.begin(), path.end());
    for (int p: path)
    {
        cout << p << " ";
    }

    cout << dist[dest]<< endl;

}





///////////////////////////////
   vector <vector <int >>dist (n+1, vector<int >(k+1, INF));
     priority_queue<vector <int >, vector <vector<int >>, greater<vector <int >>>pq;

//////////////////////////////////////////////

nt cornode=-1;


while (!q.empty())
{
    int u = q.front();
    q.pop();
    inQueue[u]= false;

    for (auto edge: adj[u])
    {
        int node = edge[0];
        int cost = edge[1];


        if (dist[u]+cost < dist[node])
        {
            dist[node]= dist[u]+cost;
             parent[node]=u;

             if (!inQueue[node])
           { q.push(node);
            inQueue[node]= true;
            count[node]++;
             if (count[node]>=n)
        {
            cornode= node;
            cout << "found"<<"\n";
            break;

        }
           

        }

       
    }

    }
    if (cornode!=-1)
    {
        break;

    }


}
int curr= cornode;
for (int i = 0; i<=n ; i++)
{
    curr=parent[curr];

}

int start = curr;
vector<int >path ;
path.push_back(start);


for (int i=parent [curr];i!=start; i=parent[i] )
{
  path.push_back(i);
}
path.push_back(start);
reverse(path.begin(), path.end());
for (int p: path)
{
    cout<<p<<" ";
    
}


}