class CountSquares {
    unordered_map<int,unordered_map<int,int>> pointCount;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0],y = point[1];
        pointCount[x][y]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0],y1 = point[1];
        int ans = 0;
        for(auto & [ y2,cnt] : pointCount[x1]){
            int side = y2 - y1;
            if(side == 0){
                continue;

            }
            
            // search in right side
            int x3 = x1 + side;
            // search in left side
            int x4 = x1 - side;
            int op1 = pointCount[x3][y1]*pointCount[x3][y2];
            int op2 = pointCount[x4][y1]* pointCount[x4][y2];
            int inc = (op1 + op2) * cnt;
            ans += inc;
        }
        return ans;
    }
};
