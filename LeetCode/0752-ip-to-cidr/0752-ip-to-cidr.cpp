using ll = long long;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        ll x = 0;
        stringstream ss(ip);
        string part;

        while(getline(ss, part, '.')) {
            x = (x << 8) | stoll(part);
        }

        vector<string> answer;

        while(n > 0) {
            ll block = x & -x;
            if (block == 0) block = 1LL << 32;

            while(block > n) {
                block /= 2;
            }

            int prefix = 32;
            for(ll size = block; size > 1; size/=2) {
                prefix--;
            }

            string address =
                to_string((x>>24) & 255) + "." + 
                to_string((x>>16) & 255) + "." + 
                to_string((x>>8) & 255) + "." + 
                to_string(x & 255);
            
            answer.push_back(address + "/" + to_string(prefix));

            x += block;
            n -= block;
        }

        return answer;
    }
};