class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> A, B, ans;
        int n = s.size();

        for (int i = 0; i < s.size(); i++) {
            if (s.compare(i, a.size(), a) == 0) {
                A.push_back(i);
            }

            if (s.compare(i, b.size(), b) == 0) {
                B.push_back(i);
            }
        }

        int j = 0;

        for (int i : A) {
            while (j < B.size() && B[j] < i - k) {
                j++;
            }

            if (j < B.size() && B[j] <= i + k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};