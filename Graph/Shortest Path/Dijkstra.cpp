lass Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          // Code here
          int n = adj.size();
          vector<int> ans(n,INT_MAX);
          
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          pq.push({0,src});
          
          ans[src] = 0;
          
          while(!pq.empty())
          {
              auto itr = pq.top();
              pq.pop();
              
              int dis = itr.first;
              int node = itr.second;
              
              for(auto x:adj[node]){
                  if(ans[x.first]>dis+x.second){
                      ans[x.first] = dis + x.second;
                      pq.push({dis+x.second,x.first});
                  }
              }
          }
          
          return ans;
      }
  };