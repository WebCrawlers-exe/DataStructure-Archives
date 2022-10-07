class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int i,j,k;
        v1.resize(m);
        v2.resize(n);
        for(i=0;i<n;i++)
            v1.push_back(v2[i]);
        sort(v1.begin(),v1.end());
    }
};