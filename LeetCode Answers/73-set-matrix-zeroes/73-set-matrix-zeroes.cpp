class Solution {
public:
    
    void setZero(vector<vector<int>>& matrix,int r,int c,int n,int m)
    {
//         row ko 0
        for(int i=0;i<m;i++)
        {
            matrix[r][i] = 0;
        }
//         column ko 0
        for(int i=0;i<n;i++)
        {
            // cout<<matrix[c]
            matrix[i][c] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
// n :- Rows ; m :- Column  
        int n=matrix.size(),m=matrix[0].size();
        vector<pair<int,int>> p;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j]==0)
                {
                    p.push_back(make_pair(i,j));
                }
            }
            cout<<endl;
        }
        
        for(auto i : p)
        {
            cout<<i.first<<" "<<i.second<<endl;
            setZero(matrix,i.first,i.second,n,m);
        }
    }
};