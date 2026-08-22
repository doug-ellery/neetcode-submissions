class Solution {
public:
    struct Task{
        char name;
        int freq;
        Task(char n, int f) : name(n), freq(f){}
    };
    struct customLess{
        bool operator()(Task a, Task b){
            return a.freq < b.freq;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> char_freqs{};
        priority_queue<Task, vector<Task>, customLess> next_ups;
        queue<pair<Task,int>> cool_offs;
        for(const auto& task : tasks){
            char_freqs[(int)task - 65]++;
        }
        for(auto i = 0; i < 26; i++){
            char task = (char)(i + 65);
            if(char_freqs[i] > 0){
                next_ups.push(Task(task, char_freqs[i]));
            }
        }
        int cycles = 0;
        while(!next_ups.empty() || !cool_offs.empty()){
            if(!next_ups.empty()){
                Task curr_task = next_ups.top();
                curr_task.freq--;
                next_ups.pop();
                if(curr_task.freq > 0){
                    cool_offs.push({curr_task, cycles});
                }
            }
            while(!cool_offs.empty() && cycles - cool_offs.front().second >= n){
                Task curr_task = cool_offs.front().first;
                cool_offs.pop();
                next_ups.push(curr_task);
            }
            cycles++;
        }
        return cycles;
    }
};
