// GFG POTD 2024/01/23
// Course Schedule
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> g(n);
        vector<int> ind(n, 0), ans;
        queue<int> q;
        
        for(auto x: prerequisites) {
            g[x[1]].push_back(x[0]);
            ind[x[0]]++;
        }
        
        for(int i = 0; i < n; i++)
            if(ind[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto x: g[f]) {
                ind[x]--;
                if(ind[x] == 0) q.push(x);
            }
        }
        
        if(ans.size() != n) return {};
        return ans;
    }
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
        map[res[i]] = i;
    
    for (int i = 0; i < V; i++)
        for (int v : adj[i])
            if (map[i] > map[v]) return 0;

    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        int u, v;
        vector<vector<int>> prerequisites;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else cout << check(n, res, adj) << endl;
    }
    
    return 0;
}

/* Sample Input:
2

2 1
1 0

4 4
1 0
2 0
3 1
3 2

Sample Output:
1
1

*/