// 2024 Dec 18

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {   
        vector<int> ans;        // To store the discounted prices
        int n = prices.size();  // The size of 'prices'

        for (int i = 0; i < n; i++)
        {
            bool discount = false;  // An indicator that the price is discounted

            for (int j = i + 1; j < n; j++)
            {
                // If another price that is less or equal to the current price is found that appears afterhand,
                // add the discounted price to 'ans'. Set 'discount' to true.
                if (prices[i] >= prices[j]) 
                {
                    ans.push_back(prices[i] - prices[j]);
                    discount = true;
                    break;
                }
            }

            // If the price at 'i' is not discounted, append the price it self to 'ans' 
            if (!discount) ans.push_back(prices[i]);
        } 

        return ans;
    }
};
