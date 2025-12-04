// 2025 Sept 19

class Spreadsheet {

    unordered_map<string, int> umap;

public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) 
    {
        umap[cell] = value;
    }
    
    void resetCell(string cell) 
    {
        umap[cell] = 0;
    }
    
    int getValue(string formula) 
    {
        string a = "";
        string b = "";
        bool insert_to_b = false;
        for (char c : formula)
        {
            if (c == '+')
            {
                insert_to_b = true;
                continue;
            }
            if (c == '=') continue;
            if (insert_to_b) b += c;
            else a += c;
        }

        int x = 0;
        int y = 0;
        if (a[0] >= '0' && a[0] <= '9') x = stoi(a);
        else x = umap[a];
        if (b[0] >= '0' && b[0] <= '9') y = stoi(b);
        else y = umap[b];

        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
