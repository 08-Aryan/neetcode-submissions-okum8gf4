class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        int end = rows*cols-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            int midrow = mid/cols;
            int midcol = mid%cols;
            if(matrix[midrow][midcol]>target){
                end = mid-1;
            }
            else if(matrix[midrow][midcol]<target){
                start = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
