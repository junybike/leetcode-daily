// 2024 Sept 27

class MyCircularDeque {

private:

    int *elements;   // Stores value
    int capacity;    // Current amount of values in elements
    int size;        // Max size of elements
    int front;       // Front value location
    int last;        // Last value location
    
public:

    MyCircularDeque(int k) 
    {
        elements = new int[k];    
        for (int i = 0; i < k; i++)
        {
            elements[i] = -1;
        }

        size = k;
        capacity = 0;
        front = 0;
        last = 1;
    }
    
    bool insertFront(int value) 
    {
        if (size == capacity) return false;  // Storage full

        elements[front] = value;
        front = (front + size - 1) % size;   // Next location to insert at front
        capacity++;

        return true;
    }
    
    bool insertLast(int value) 
    {
        if (size == capacity) return false;  // Storage full

        elements[last] = value;
        last = (last + size + 1) % size;    // Next location to insert last
        capacity++;

        return true;
    }
    
    bool deleteFront() 
    {
        if (capacity == 0) return false; 

        front = (size + front + 1) % size;   // Next location to insert front
        elements[front] = -1;                // Overwrite current front value with -1
        capacity--;

        return true;
    }
    
    bool deleteLast() 
    {
        if (capacity == 0) return false;

        last = (size + last - 1) % size;    // Next location to insert last
        elements[last] = -1;                // Overwrite current last value with -1
        capacity--;

        return true;
    }
    
    int getFront() 
    {
        return elements[(size + front + 1) % size];
    }
    
    int getRear() 
    {
        return elements[(size + last - 1) % size];
    }
    
    bool isEmpty() 
    {
        return (capacity == 0);
    }
    
    bool isFull() 
    {
        return (capacity == size);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
