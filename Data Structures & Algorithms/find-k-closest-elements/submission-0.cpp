struct comp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

        int n = arr.size();

        for(int i = 0; i < n; i++){

            pq.push({abs(arr[i] - x), arr[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};