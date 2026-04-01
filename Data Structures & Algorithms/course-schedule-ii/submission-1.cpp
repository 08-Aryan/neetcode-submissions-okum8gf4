class Solution {
public:
    vector<int> indegree;
    vector<vector<int>> adj(vector<vector<int>> matrix,int n){
        vector<vector<int>> res(n);
        indegree.resize(n,0);
        for(auto mat:matrix){
            res[mat[1]].push_back(mat[0]);
            indegree[mat[0]]++;
        }
        return res;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjmat = adj(prerequisites,numCourses);
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto nie:adjmat[x]){
                if(indegree[nie]==1){
                    q.push(nie);
                }
                indegree[nie]--;
            }
        }
        return ans.size()== numCourses? ans: vector<int> {};
    }
};
