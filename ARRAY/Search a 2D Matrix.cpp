
/*
    Algo:
    Check whether the target is <= last element of each row
    if Yes then there is a possibility our target is present in that row
    run binary search in that row for target
    if found return true
    else return false

    and if target is greater than all the last values of each row
    then return false (means our target is not present int the matrix)
*/

class Solution {
public:
    
    bool binSearch(int l, int r, int key, vector<int> v)
    {
        if(l<=r)
        {
            int mid = (l+r)/2;
            if(v[mid] == key)
                return true;
            else if(key > v[mid])
                return binSearch(mid+1, r, key, v);
            else
                return binSearch(l, mid-1, key, v);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int r = matrix.size(), c = matrix[0].size(), targetRow = -1;
        
        for(int i = 0; i < r; i++)
        {
            if(matrix[i][c-1] >= target)
            {
                targetRow = i;
                break;
            }
        }
        // cout<<target
        if(targetRow != -1)
            return binSearch(0, c-1, target, matrix[targetRow]);
        return false;
    }
};