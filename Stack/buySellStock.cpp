// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit possible by buying
// and selling stocks any number of times
int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	if (n < 2)
		return 0;
	int sellingDate = 0;
	int buyingDate = 0;
	int totalProfit = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] >= prices[i - 1])
			sellingDate++;
		else {
			totalProfit += (prices[sellingDate] - prices[buyingDate]);
			sellingDate = buyingDate = i;
		}
	}
	totalProfit += (prices[sellingDate] - prices[buyingDate]);
	return totalProfit;
}

// Driver Code
int main()
{
	// Given prices
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	// Function Call to calculate maximum profit possible
	int ans = maxProfit(prices);
	// Print the total profit
	cout << ans << endl;
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
