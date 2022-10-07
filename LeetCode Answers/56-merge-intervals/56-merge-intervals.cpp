class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=st.top().at(1))
            {
//                 Overlap
                vector<int> v;
                v.push_back(st.top().at(0));
                if(intervals[i][1]>st.top().at(1))
                    v.push_back(intervals[i][1]);
                else
                    v.push_back(st.top().at(1));
                st.pop();
                st.push(v);
            }
            else
            {
//                 Not overlap
                st.push(intervals[i]);
            }
        }
        vector<vector<int>> out;
        
        while(!st.empty())
        {
            vector<int> v = st.top();
            st.pop();
            out.push_back(v);
        }
        return out;
    }
};