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
