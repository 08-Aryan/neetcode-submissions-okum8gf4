class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose  TC= O(n*n)
        for(int row=0;row<n;row++){
            for(int col=0;col<=row;col++){
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
        // reversing all row TC= (n*n)
        for(int row=0;row<n;row++){
            int l= 0,r = n-1;
            while(l<r){
                matrix[row][l]=matrix[row][r]+matrix[row][l];
                matrix[row][r]=matrix[row][l]-matrix[row][r];
                matrix[row][l]=matrix[row][l]-matrix[row][r];
                l++,r--;
            }
        }
        // TC = O(n*n)
        
    }
};
