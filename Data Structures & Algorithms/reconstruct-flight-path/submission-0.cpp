class Solution {
    vector<string> bfs(string src,unordered_map<string,deque<string>> &adj){
        stack<string> stk;
        vector<string> ans;
        stk.push(src);
        while(!stk.empty()){
            string curr = stk.top();
            // finish other paths
            if(adj[curr].empty()){
                stk.pop();
                ans.push_back(curr);
            }
            else{
                string last = adj[curr].back();
                adj[curr].pop_back();
                stk.push(last);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,deque<string>> adj;
        for(auto &ticket:tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto &[src,dest]:adj){
            // Order in decending order
            sort(dest.rbegin(),dest.rend());
        }
        
        return bfs("JFK",adj);
        
    }
    
};
