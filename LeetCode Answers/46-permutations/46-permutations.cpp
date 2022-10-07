class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> op;
        sort(a.begin(), a.end());
        do {
            op.push_back(a);
        } while (next_permutation(a.begin(), a.end()));
        return op;
    }
};