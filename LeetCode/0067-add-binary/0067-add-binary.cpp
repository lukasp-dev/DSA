class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        if (a.size() < n) a.insert(0, n - a.size(), '0');
        if (b.size() < n) b.insert(0, n - b.size(), '0');

        string res;
        int carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            res.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
