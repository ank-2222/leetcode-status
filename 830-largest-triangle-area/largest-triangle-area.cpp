class Solution {

    double calculateSize(vector<int> a, vector<int> b, vector<int> c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }

public:
   double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;   // initialize
        int n = points.size();

        for (int i = 0; i < n; i++) {             // pick first point
            for (int j = i + 1; j < n; j++) {     // pick second point
                for (int k = j + 1; k < n; k++) { // pick third point
                    // calculate area of triangle points[i], points[j], points[k]
                    double area = abs(
                        (points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) -
                        (points[j][1] - points[i][1]) * (points[k][0] - points[i][0])
                    ) * 0.5;

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};