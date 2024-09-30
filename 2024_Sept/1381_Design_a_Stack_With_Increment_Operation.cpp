// 2024 Sept 29

class CustomStack {

    int* stack; 
    int size;
    int count;

public:
    CustomStack(int maxSize) 
    {
        stack = new int[maxSize];
        size = maxSize;
        count = 0;
    }

    void push(int x) 
    {
        if (count == size) return;  // If the stack is full, stop.

        stack[count] = x;    
        count++;
    }
    
    int pop() 
    {
        if (count == 0) return -1;  // If the stack is empty, return -1.

        count--;
        int val = stack[count];
        stack[count] = -1;

        return val;
    }
    
    void increment(int k, int val) 
    {
        int i = 0;
        // Increment first k values by val.
        // If number of values in stack is less than val, increment all values by val.
        while (i < k && i < count)   
        {
            stack[i] = stack[i] + val;
            i++;
        }    
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
