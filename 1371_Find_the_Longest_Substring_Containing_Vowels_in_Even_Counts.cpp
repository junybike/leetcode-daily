// 2024 Sept 15

class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        int size = s.size();
        int len = 0;  // longest len of substring containing vowels in even counts
        
        for (int v = 0; v < size; v++)
        {
            if (len >= size - v) return len;
            int a = 0, e = 0, i = 0, o = 0, u = 0;  // Even/odd indicator bit. 0 = even, 1 = odd.
            
            for (int j = v; j < size; j++)  // Check vowels in each substring
            {
                switch (s[j])  // If a character is a vowel, change its even/odd indicator bit 
                {
                    case 'a':  
                        a = (a + 1) & 0b1;
                        break;
                    case 'e':
                        e = (e + 1) & 0b1;
                        break;
                    case 'i':
                        i = (i + 1) & 0b1;
                        break;
                    case 'o':
                        o = (o + 1) & 0b1;
                        break;
                    case 'u':
                        u = (u + 1) & 0b1;
                        break;
                    default:
                        break;
                }
                // If all vowels are even
                // and the len is less than (j - v + 1), then update len with (j - v + 1)
                // j - v + 1 is the current length of substring
                if (a == 0 && e == 0 && i == 0 && o == 0 && u == 0 && len < j - v + 1)
                {
                    len = j - v + 1;
                }
            }
        }
        
        return len;
    }
};
