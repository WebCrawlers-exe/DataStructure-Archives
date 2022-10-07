class Solution {
public:
    int numTrees(int n) {
    long long  ans=1;
    for(int i=1;i<n;i++){
        ans=ans*(2*n-i)/i;
    }
    ans=ans*2*n;
    return ans/(n*(n+1));

    }
};