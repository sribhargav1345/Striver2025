class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int n, vector<vector<int>> adj[]) {
          // code here
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          pq.push({0,0});
          
          vector<int> visited(n,0);
          int sum = 0;
          
          while(!pq.empty())
          {
              auto itr = pq.top();
              pq.pop();
              
              int wt = itr.first;
              int node = itr.second;
              
              if(visited[node]) continue;
              
              visited[node] = 1;
              sum += wt;
              
              for(auto x:adj[node]){
                  int adjNode = x[0];
                  int dis = x[1];
                  
                  if(!visited[adjNode]){
                      pq.push({dis,adjNode});
                  }
              }
          }
          return sum;
      }
  };