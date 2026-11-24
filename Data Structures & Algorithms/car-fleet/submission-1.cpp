class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());   // 由大到小，先比 first（起點）;r代表reverse

        stack<double> st;                      // 每個車隊的抵達時間
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (st.empty() || time > st.top()) { // 沒有前車，或追不上前面的車隊
                st.push(time);
            }
        }
        return st.size();                         // 有幾個車隊
    }
};
