#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm tính bình phương khoảng cách giữa hai điểm
int squaredDistance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<pair<int, int>> coordinates(n);

    for (int i = 0; i < n; ++i) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    int maxCovered = 0;

    for (int i = 0; i < n; ++i) {
        int covered = 1; // Tính cả tổ dân phố i hiện tại
        for (int j = 0; j < n; ++j) {
            if (i != j && squaredDistance(coordinates[i].first, coordinates[i].second,
                                          coordinates[j].first, coordinates[j].second) <= r * r) {
                covered++;
            }
        }
        maxCovered = max(maxCovered, covered);
    }

    cout << maxCovered << endl;

    return 0;
}