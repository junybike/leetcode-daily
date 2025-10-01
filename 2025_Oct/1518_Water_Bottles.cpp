// 2025 Oct 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int drink = numBottles;  // number of drinks in total
        while (numBottles / numExchange > 0)
        {
            drink += numBottles / numExchange; // get number of drinks I can exchange
            numBottles = numBottles / numExchange + numBottles % numExchange; // numBottles now keep track of the empty bottle
        }    
        return drink;
    }
};
