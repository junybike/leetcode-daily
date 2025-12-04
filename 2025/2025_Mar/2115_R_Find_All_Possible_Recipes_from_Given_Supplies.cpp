// 2025 Mar 21

class SolutionTLE {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        vector<vector<string>> cant_make = ingredients;
        vector<string> can_make;
        int cnt = 0;

        while (supplies.size() != cnt)
        {  
            cnt = supplies.size();
            for (int i = 0; i < cant_make.size(); i++)
            {
                if (find(supplies.begin(), supplies.end(), recipes[i]) != supplies.end()) continue;

                bool make = true;
                for (string& s : cant_make[i])
                { 
                    if (find(supplies.begin(), supplies.end(), s) == supplies.end())
                    {
                        make = false;
                        break;
                    }
                }
                if (make) 
                {
                    supplies.push_back(recipes[i]);
                    can_make.push_back(recipes[i]);
                }
            }
        }

        return can_make;
    }
};

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> can_make(supplies.begin(), supplies.end());   // keep track of things it can make 
        queue<int> recipe_q;    // keep track of things it cannot make yet
        
        for (int i = 0; i < recipes.size(); i++)
        {
            recipe_q.push(i);   // initialize 'recipe_q' with things in 'recipes'
        }

        vector<string> ans;     // things it can make from 'recipes'
        int cnt = -1;           // keep track of last size of 'can_make'

        while (static_cast<int>(can_make.size()) > cnt)
        {
            cnt = can_make.size();      // updates 'cnt'
            int n = recipe_q.size();    // current size of 'recipe_q'

            while (n-- > 0)
            {
                int i = recipe_q.front();   // bring a recipe index
                recipe_q.pop();

                bool make = true;
                for (string& s : ingredients[i])    // check if I have all ingredients for recipe at 'index' 
                {
                    if (!can_make.count(s))
                    {
                        make = false;
                        break;
                    }
                }

                if (!make) recipe_q.push(i);        // if I cannot make this, push it back to 'recipe_q'
                else                                // update can_make and ans if I can make it
                {
                    can_make.insert(recipes[i]);    
                    ans.push_back(recipes[i]);
                }
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/editorial
*/
