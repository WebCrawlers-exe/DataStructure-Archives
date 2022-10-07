// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
        // Min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<k-1;i++)
        {
            pq.push(arr[i]);
            cout<<"-1"<<" ";
        }
        pq.push(arr[k-1]);
        cout<<pq.top()<<" ";
        for(int i=k;i<n;i++)
        {
            if(arr[i]>pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
            cout<<pq.top()<<" ";
        }
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends