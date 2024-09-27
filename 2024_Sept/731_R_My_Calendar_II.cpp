// 2024 Sept 27

struct Node {   // Binary Tree
    int start, end;
    Node *left;
    Node *right;
    
    Node(int start, int end): start(start), end(end), left(NULL), right(NULL) {}
};

class MyCalendarTwo {

    vector<pair<int, int>> S1;  // Stores all events
    Node *S2;   // Stores event which overlaps with an event.

public:

    MyCalendarTwo(): S2(NULL)
    {
        S1.reserve(1000);   // Max 1000 events can be added  
    }

    bool dfs(int s, int e, Node* &curr, bool add = 0)
    {
        if (!curr)  // S2 is empty or the node has reached its end. 
        {
            if (add) curr = new Node(s, e);  // This event overlaps with an event. Add to S2. 
            return 1;   
        }

        if (e <= curr->start) return dfs(s, e, curr->left, add);         // This event ends before some event's start time
        else if (s >= curr->end) return dfs(s, e, curr->right, add);     // This event starts after some event's end time
        else return 0;  // This event overlaps with some event in S2. Therefore, tripple booking.
    }

    bool book(int start, int end) 
    {
        if (!dfs(start, end, S2)) return 0;     // If this event overlaps with some event in S2, then this event cannot be added

        for (auto& [s, e]: S1)
        {
            int s0 = max(s, start);
            int e0 = min(e, end);
            
            if (s0 < e0)    // Case where this event overlaps with some event,
            {
                dfs(s0, e0, S2, 1);     // Add this event in S2.
            }
        }

        S1.emplace_back(start, end);    // Add this event in S1.
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/*
Solution reference
https://leetcode.com/problems/my-calendar-ii/solutions/5838073/use-2-containers-over-pairs-binary-tree-54-ms-beats-99-48
*/
