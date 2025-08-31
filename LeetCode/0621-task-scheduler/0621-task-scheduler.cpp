class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqs(26, 0);

        for(char task : tasks){
            freqs[task-'A']++;
        }

        // struct cmp{
        //     bool operator()(const int& a, const int& b){
        //         return a < b;
        //     }
        // };

        priority_queue<int> pq;

        for(int freq : freqs){
            if(freq > 0){
                pq.push(freq);
            }
        }

        int time = 0;
        while(!pq.empty()){
            int cycle = n + 1;
            vector<int> temp;

            while(cycle > 0 && !pq.empty()){
                time++;
                cycle--;

                int curr = pq.top(); pq.pop();
                if(--curr > 0) temp.push_back(curr);
            }
            
            for(int it : temp){
                pq.push(it);
            }
            if(!pq.empty()) time += cycle;
        }
        
        return time;
    }
};