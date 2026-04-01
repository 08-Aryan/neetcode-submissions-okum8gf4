class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size()-1;
        sort(people.begin(),people.end());
        int ans = 0;
        while( l < r){
            int sum = people[l]+ people[r];
            if(sum > limit){
                
                r--;
            }
            else{
                l++;
                r--;
               
            }
            ans++;
        }
        if (l==r){
           ans++; 
        }
        return ans;
    }
};