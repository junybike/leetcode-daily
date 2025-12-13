// 2025 Dec 13
class Solution {
public:

    // checks if the code is valid
    bool valid_code(string& str)
    {
        if (str == "") return false;
        for (char c : str)
        {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'))
            {
                return false;
            }
        }
        return true;
    }

    // checks if the type of business is one of the followings
    bool valid_business(string& str)
    {
        return (str == "electronics" || str == "grocery" || str == "pharmacy" || str == "restaurant");
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) 
    {
        // store coupons by their types
        vector<string> e_coupons;
        vector<string> g_coupons;
        vector<string> p_coupons;
        vector<string> r_coupons;

        for (int i = 0; i < code.size(); i++)
        {
            // if coupon is valid, push it to its type's vector
            if (valid_code(code[i]) && valid_business(businessLine[i]) && isActive[i])
            {
                string business = businessLine[i];
                if (business == "electronics") e_coupons.push_back(code[i]);
                else if (business == "grocery") g_coupons.push_back(code[i]);
                else if (business == "pharmacy") p_coupons.push_back(code[i]);
                else if (business == "restaurant") r_coupons.push_back(code[i]);
            } 
        }

        // sort each coupon vectors by lexicographical order of codes
        sort(e_coupons.begin(), e_coupons.end());
        sort(g_coupons.begin(), g_coupons.end());
        sort(p_coupons.begin(), p_coupons.end());
        sort(r_coupons.begin(), r_coupons.end());

        // push all coupons into a single vector 
        vector<string> ans;
        for (string& s : e_coupons) ans.push_back(s);
        for (string& s : g_coupons) ans.push_back(s);
        for (string& s : p_coupons) ans.push_back(s);
        for (string& s : r_coupons) ans.push_back(s);

        return ans;
    }
};
