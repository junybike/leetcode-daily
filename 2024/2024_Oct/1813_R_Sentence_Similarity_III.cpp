class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        // To split words in a sentence and store the words into a vector
        auto splitwords = [](const string& sentence)
        {
            vector<string> words;
            string word = "";

            for (char c : sentence)
            {
                if (c == ' ')
                {
                    if (!word.empty())
                    {
                        words.push_back(word);
                        word = "";
                    }
                }
                else word += c;
            }
            if (!word.empty()) words.push_back(word);
            return words;
        };

        // Split the two sentences
        vector<string> words1 = splitwords(sentence1);
        vector<string> words2 = splitwords(sentence2);

        // Let words1 hold the longer length of words vector
        if (words1.size() < words2.size()) swap(words1, words2);

        int start = 0;  // Amount of consecutive same words from words1 and words2 vector starting at the first index to onwwards  
        int end = 0;    // Amount of consecutive same words from words1 and words2 vector starting at the last index to backwards

        int n1 = words1.size();
        int n2 = words2.size();

        // When the word at index 'start' for both words vector is the same, increment start.
        // Stops when the two words are different or 'start' exceeds length of smaller size word vector.
        while (start < n2 && words1[start] == words2[start]) start++;
        // When the word at index 'end' from the last, increment end.
        // Stops when the two words are different or 'end' exceeds length of smaller size word vector.
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;

        // start + end exceeding or equal to n2 indicates that all words in words2 exists in word1 
        // and sentence2 can be identical to sentence1 by adding a word or some words.
        return start + end >= n2;
    }
};

/*
Solution reference
https://leetcode.com/problems/sentence-similarity-iii/solutions/5875276/step-by-step-guide-to-cracking-sentence-similarity
*/

class Solution2 {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        deque<string> v1, v2;
        string s;

        // Gets vector of splitted words from sentence1
        stringstream ss(sentence1);
        while(getline(ss,s,' '))
        {
            v1.push_back(s);
        }

        // Gets vector of splitted words from sentence2
        stringstream ss2(sentence2);
        while (getline(ss2,s,' '))
        {
            v2.push_back(s);
        }

        // Lets v2 have larger length of vector
        if (v1.size() > v2.size()) swap(v1,v2);
        while (v1.size())
        {
            // If words from v1 and v2 at front is same, remove those words
            if (v1.front() == v2.front())
            {
                v1.pop_front();
                v2.pop_front();
            } 
            // If words from v1 and v2 at the back is same, remove those words
            else if (v1.back() == v2.back())
            {
                v1.pop_back();
                v2.pop_back();
            } 
            else break;
        }
        // Empty v1 vector indicates that all words in v1 appears in v2.
        // Therefore, some words can be added to v1 in one of pairs of two words to make it equal to v2
        return v1.empty();
    }
};

/*
Solution reference
Leetcode code sample
*/
