// 2024 Sept 25

class MyCalendar {
public:

    map<int, int> schedule;     // <start time, end time>
    
    MyCalendar() {}

    bool book(int start, int end) 
    {
        auto next = schedule.lower_bound(start);    // new booking

        // Case where the new booking overlaps with the next event
        if (next != schedule.end() && next->first < end) return false;
        
        // Case where the new booking overlaps with the previous event
        if (next != schedule.begin() && prev(next)->second > start) return false;

        schedule[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/*
Solution Reference
https://leetcode.com/problems/my-calendar-i/solutions/5834347/3-approach-detailed-commented-code-from-sets-brute-force-to-maps-binary-search
*/
