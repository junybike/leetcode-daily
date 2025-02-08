// 2025 Feb 8

class NumberContainers {
public:

    unordered_map<int, int> container;      // Records each container's value
    unordered_map<int, set<int>> location;  // For each value, records its location

    NumberContainers() {}
    
    void change(int index, int number) 
    {
        // If the container is already holding a value, 
        // remove the [container's value]'s location 'index' from the 'location' 
        if (container[index]) 
        {
            location[container[index]].erase(index);
        }
        container[index] = number;          // write/overwrite container's value
        location[number].insert(index);     // records the location of value (the index)
    }
    
    int find(int number) 
    {
        if (location[number].empty()) return -1;    // if the value's location set is empty, return -1.
        auto num = location[number].begin();        // gets the container with lowest index that this value is located at
        return *num;
    }
};
