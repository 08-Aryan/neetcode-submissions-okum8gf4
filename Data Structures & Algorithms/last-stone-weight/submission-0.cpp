class Solution {
public:
    void collidestones(priority_queue<int> &maxheap){
        int y = maxheap.top();
        maxheap.pop();
        int x = maxheap.top();
        maxheap.pop();
        maxheap.push(finddiff(x,y));
    }
    int finddiff(int x,int y){
        return y-x;
    }
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(auto stone:stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            collidestones(maxheap);
        }
        return maxheap.top();
    }
};
