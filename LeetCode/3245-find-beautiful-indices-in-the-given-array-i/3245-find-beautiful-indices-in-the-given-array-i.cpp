class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aIndices;
        vector<int> bIndices;
        vector<int> ans;

        size_t idx = 0;

        // Find all indices of a 
        while(true) {
            size_t pos = s.find(a, idx);
            
            if(pos == string::npos) break;

            aIndices.push_back(static_cast<int>(pos));
            idx = pos + 1;
        }

        // Find all indices of b
        idx = 0;

        while(true) {
            size_t pos = s.find(b, idx);

            if (pos == string:: npos) break;

            bIndices.push_back(static_cast<int>(pos));
            idx = pos + 1;
        }

        // For each a index, chexk if a b index exists within distance k
        for(int aIndex : aIndices) {
            int left = aIndex - k;
            int right = aIndex + k;

            auto it = lower_bound(
                bIndices.begin(),
                bIndices.end(),
                left
            );

            if(it != bIndices.end() && *it <= right) {
                ans.push_back(aIndex);
            }
        }


        return ans;
    }
};

/**
string s
string a
string b
int k

for searching |j - i|,
I can use vector upper_bound.
return type of upper_bound: iterator of the item / vector.end()

find(a, second_parameter)
the second_paramter is the position to search from.
*/