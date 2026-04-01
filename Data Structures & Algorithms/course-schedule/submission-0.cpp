class Solution {
public:
    bool dfs(vector<int> &visited,vector<vector<int>> &adjmat,int i){
        if(visited[i]==1){
            return true;
        }
        if(visited[i]==2){
            return false;
        }
        visited[i]=1;
        for(auto adj:adjmat[i]){
            
                if(dfs(visited,adjmat,adj)){
                    return true;
            }
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjmat(numCourses);
        for(vector<int> pre:prerequisites){
            adjmat[pre[1]].push_back(pre[0]);
        }
        vector<int> visited(numCourses,0);
        for(int i =0;i<numCourses;i++){
            if(dfs(visited,adjmat,i)){
                return false;
            }
            
        }
        return true;

        
    }
};
