// 2025 Feb 14

class ProductOfNumbers {
public:

    vector<short> v;    // to store values

    ProductOfNumbers() {
        
    }
    
    void add(int num) 
    {
        v.push_back(num);   // add 'num' to 'v'
    }
    
    int getProduct(int k) 
    {
        int product = 1;                    // total product of the last k values in 'v'
        for (int i = 0; i < k; i++)
        {
            product *= v.end()[-(i + 1)];   // access the values from the back of 'v' 
        }    
        return product;
    }
};

// Sample solution (improved time cost)
class ProductOfNumbers2 {
public:

    vector<int> v;

    ProductOfNumbers2() 
    {
        v.push_back(1);    // initialize 'v' with 1. 
    }
    
    void add(int num) 
    {
        if (num == 0)   // If 'num' is 0, reset 'v' and insert value 1
        {
            v.clear();      
            v.push_back(1); 
        }
        else v.push_back(num * v.back());    // insert the product of last element and 'num' to back of 'v' 
    }
    
    int getProduct(int k) 
    {
        if (k >= v.size()) return 0;            // if k is greater than size of v, product must be 0 
        return v.back() / v[v.size() - 1 - k];  // returns the division of the end value of 'v' by kth last value in 'v'.
    }
};
