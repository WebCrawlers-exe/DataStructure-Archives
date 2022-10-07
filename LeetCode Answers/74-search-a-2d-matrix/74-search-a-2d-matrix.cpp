class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int ser) {
        vector<int> v;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                v.push_back(matrix[i][j]);
            }
        }
        
        vector<int>::iterator it;
        it = find (v.begin(), v.end(), ser);
        if(it!=v.end())
        {
            return true;
        }
        return false;
    }
};