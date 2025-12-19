class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>,
                       greater<pair<double, int>>>
            pq;
        for (int i = 0; i < quality.size(); i++) {
            pq.push({(double)wage[i] / quality[i], quality[i]});
        }

        priority_queue<int> maxquality;
        int totalquality = 0;
        double totalCost = DBL_MAX;
        while (!pq.empty()) {
            pair<double, int> x = pq.top();
            pq.pop();
            maxquality.push(x.second);
            totalquality += x.second;
            if (maxquality.size() > k) {
                totalquality -= maxquality.top();
                maxquality.pop();
            }
            if (maxquality.size() == k) {

                double cost = totalquality * x.first;
                totalCost = min(totalCost, cost);
            }
        }

        return totalCost;
    }
};