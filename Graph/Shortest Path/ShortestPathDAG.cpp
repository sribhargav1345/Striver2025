class Solution {
    public:
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          // code here
          vector<vector<pair<int,int>>> adj(V);
          for(int i=0;i<E;i++)
          {
              adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          }
          
          vector<int> dist(V,INT_MAX);
          dist[0] = 0;
          
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          pq.push({0,0});
          
          
          while(!pq.empty())
          {
              auto itr = pq.top();
              pq.pop();
              
              for(auto x:adj[itr.second]){
                  if(dist[x.first] > dist[itr.second] + x.second){
                      dist[x.first] = dist[itr.second] + x.second;
                      pq.push({dist[x.first],x.first});
                  }
              }
          }
          
          for(int x=0;x<V;x++){
              if(dist[x] == INT_MAX) dist[x] = -1;
          }
          return dist;
      }
  };