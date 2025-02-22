class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          // code here
          int n = adj.size();
          vector<int> ans(n,INT_MAX);
          
          ans[src] = 0;
          
          queue<pair<int,int>> q;
          q.push({0,src});
          
          while(!q.empty())
          {
              auto itr = q.front();
              q.pop();
              
              int dis = itr.first;
              int node = itr.second;
              
              for(auto x:adj[node]){
                  if(ans[x] > dis+1){
                      ans[x] = dis + 1;
                      q.push({dis+1,x});
                  }
              }
          }
          
          for(int i=0;i<n;i++){
              if(ans[i] == INT_MAX) ans[i] = -1;
          }
          return ans;
      }
  };