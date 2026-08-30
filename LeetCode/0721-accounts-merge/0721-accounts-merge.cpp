class Solution {
private:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x] == x) return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return false;
        
        if(size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];

        return true;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_to_id;
        vector<string> id_to_email;
        unordered_map<string, string> email_to_name;
        int id = 0;

        // 1. Give each unique email an ID
        for (vector<string>& person_accounts : accounts) {
            string name = person_accounts[0];

            for (int i = 1; i < person_accounts.size(); ++i) {
                string email = person_accounts[i];

                email_to_name[email] = name;

                if (!email_to_id.count(email)) {
                    email_to_id[email] = id++;
                    id_to_email.push_back(email);
                }
            }
        }

        // 2. Initialize Union Find
        parent.resize(id);
        size.assign(id, 1);
        iota(parent.begin(), parent.end(), 0);

        // 3. Union emails with the same account
        for (vector<string>& person_accounts : accounts) {
            int firstEmailId = email_to_id[person_accounts[1]];

            for (int i = 2; i < person_accounts.size(); ++i) {
                int emailId = email_to_id[person_accounts[i]];
                unite(firstEmailId, emailId);
            }
        }

        // 4. root -> emails
        unordered_map<int,vector<string>> groups;

        for(int i=0; i < id; ++i) {
            int root = find(i);
            groups[root].push_back(id_to_email[i]);
        }

        // 5. build answer
        vector<vector<string>> ans;

        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());

            vector<string> account;

            string name = email_to_name[emails[0]];
            account.push_back(name);

            for (string& email : emails) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};