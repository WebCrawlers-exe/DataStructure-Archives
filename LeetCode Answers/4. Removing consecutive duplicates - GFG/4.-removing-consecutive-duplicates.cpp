// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        // Your code here
        int i,j,n=s.size();
        stack<char> st;
        st.push(s[0]);
        
        for(i=1;i<n;i++)
        {
            if(st.top()==s[i])
                continue;
            else
                st.push(s[i]);
        }
        string final="";
        while(!st.empty())
        {
            final+=st.top();
            st.pop();
        }
        reverse(final.begin(),final.end());
        return final;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends