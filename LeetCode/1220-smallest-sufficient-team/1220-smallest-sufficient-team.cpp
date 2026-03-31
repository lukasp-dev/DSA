class Solution {
public:
    int target_mask;
    int m;
    // memo[idx][mask]: 해당 상태에서 필요한 '추가' 인원의 최솟값
    // choice[idx][mask]: 현재 사람을 뽑았을 때 최적이었는지 여부
    int memo[61][1 << 16];
    bool choice[61][1 << 16];

    int solve(int idx, int mask, const vector<int>& people_skills) {
        if (mask == target_mask) return 0;
        if (idx == m) return 100; // 실패 케이스

        if (memo[idx][mask] != -1) return memo[idx][mask];

        // 1. 현재 사람을 포함하지 않는 경우
        int res1 = solve(idx + 1, mask, people_skills);

        // 2. 현재 사람을 포함하는 경우
        int res2 = 1 + solve(idx + 1, mask | people_skills[idx], people_skills);

        if (res1 < res2) {
            choice[idx][mask] = false;
            return memo[idx][mask] = res1;
        } else {
            choice[idx][mask] = true;
            return memo[idx][mask] = res2;
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        m = people.size();
        target_mask = (1 << n) - 1;

        // 초기화
        memset(memo, -1, sizeof(memo));
        
        unordered_map<string, int> skill_to_id;
        for (int i = 0; i < n; i++) skill_to_id[req_skills[i]] = i;

        vector<int> people_skills(m, 0);
        for (int i = 0; i < m; i++) {
            for (const string& s : people[i]) {
                if (skill_to_id.count(s)) people_skills[i] |= (1 << skill_to_id[s]);
            }
        }

        solve(0, 0, people_skills);

        // 결과 추적 (Reconstruct)
        vector<int> result;
        int curr_mask = 0;
        for (int i = 0; i < m; i++) {
            if (choice[i][curr_mask]) {
                result.push_back(i);
                curr_mask |= people_skills[i];
            }
            if (curr_mask == target_mask) break;
        }
        return result;
    }
};