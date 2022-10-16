

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        // stack<int>s;
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(s.size()==0) ans.push_back(1);
        //     else if(s.size()>0 && s.top()<price[i]){
        //         int c=1;
        //         vector<int>temp;
        //         while(s.size()>0 && s.top()<price[i]){
        //             c++;
        //             temp.push_back(s.top());
        //             s.pop();
        //         }
        //         reverse(temp.begin(),temp.end());
        //         for(int j=0;j<temp.size();j++){
        //             s.push(temp[j]);
        //         }
        //         ans.push_back(c);
        //     }
        //     else if(s.size()>0 and s.top()>=price[i]) ans.push_back(1);
        // s.push(price[i]);
        // }
        // return ans;
        
        
        stack<pair<int,int>> s;
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(s.size()==0) idx.push_back(-1);
            else if(s.size()>0 && s.top().first>price[i]) idx.push_back(s.top().second);
            else if(s.size()>0 and s.top().first<=price[i]){
                while(s.size()>0 and s.top().first<=price[i]){
                    s.pop();
                }
                if(s.size()==0) idx.push_back(-1);
                else if(s.top().first>price[i]) idx.push_back(s.top().second);
        }
        s.push({price[i],i});
       // Your code here
    }
    vector<int>ans(n,1);
    for(int i=0;i<n;i++){
        ans[i]=abs(i-idx[i]);
    }
    return ans;}
    
};

//  1 2 3 4 5
//  1 2 3 4 5
 
//  5 4 3 2 1
//  1 1 1 1 1
 
//  5 5 5 5 5
//  1 1 1 1 1
