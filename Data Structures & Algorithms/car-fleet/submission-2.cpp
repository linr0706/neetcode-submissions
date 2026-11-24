class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> speedAt(target, 0);     // speedAt[p] = 起點 p 那台車的速度，0 代表沒車
        for (int i = 0; i < n; i++) {
            speedAt[position[i]] = speed[i];
        }

        int fleets = 0;
        double slowest = 0;
        for (int pos = target - 1; pos >= 0; pos--) {   // 從離終點最近的開始
            if (speedAt[pos] == 0) continue;
            double time = (double)(target - pos) / speedAt[pos];
            if (time > slowest) {
                fleets++;
                slowest = time;
            }
        }
        return fleets;
    }
};
