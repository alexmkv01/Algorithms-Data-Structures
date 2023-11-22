#include <vector>
#include <queue>

using namespace std;

struct PointWithDistance {
    vector<int> coords;         
    double distance;  
    PointWithDistance(vector<int> coords) {
        this->coords = coords;
        distance = sqrt(coords[0]*coords[0] + coords[1]*coords[1]);
    }
};

// Custom comparison function
bool comparePointWithDistance(PointWithDistance& p1, PointWithDistance& p2) {
    return p1.distance < p2.distance;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> kPoints;
        priority_queue<PointWithDistance, vector<PointWithDistance>, decltype(&comparePointWithDistance)> minHeap(&comparePointWithDistance); // minHeap

        for (vector<int> point : points){
            PointWithDistance pwd = PointWithDistance(point);
            minHeap.push(pwd);
        }
        while (minHeap.size() > k){
            minHeap.pop();
        }
        for (int i=0; i<k; i++){
            PointWithDistance pwd = minHeap.top();
            kPoints.push_back(pwd.coords);
            minHeap.pop();
        }
        return kPoints;
    }
};