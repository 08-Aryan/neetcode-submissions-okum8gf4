class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // sort and traverse
        // make a set and see
        unordered_set<int> unique;
        for(auto &num:nums){
            if(unique.find(num)==unique.end()){
                unique.insert(num);
            }
            else{
                return true;
            }

        }
        return false;
    }
};