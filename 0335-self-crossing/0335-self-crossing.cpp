#include <assert.h>

static const int xMove[4] = {0, -1, 0, 1};
static const int yMove[4] = {1, 0, -1, 0};

void move(int& x, int& y, int dis, int& cur) {
    x += xMove[cur] * dis;
    y += yMove[cur] * dis;
    cur = (cur+1)%4;
    return;
}

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int x = 0, y = 0, cur = 0, i = 0, n = distance.size();
        if (n <= 3) return false;

        int limits[4]; // right, up, left, down
        limits[cur] = 0;
        move(x, y, distance[i++], cur); // moved up.
        limits[cur] = y;
        move(x, y, distance[i++], cur); // moved left.
        limits[cur] = x;
        move(x, y, distance[i++], cur); // moved down.
        limits[cur] = y;
        if (y < 0) {
            // Outward spiral. We can't hit limits here.
            while (i < n) {
                move(x, y, distance[i++], cur);
                // Did we move past our limit?
                bool inward = false;
                switch (cur) {
                    case 0: // moved right.
                        inward = x <= limits[cur];
                        limits[cur] = x;
                        break;
                    case 1: // moved up.
                        inward = y <= limits[cur];
                        limits[cur] = y;
                        break;
                    case 2: // moved left.
                        inward = x >= limits[cur];
                        limits[cur] = x;
                        break;
                    case 3: // moved down.
                        inward = y >= limits[cur];
                        limits[cur] = y;
                        break;
                    default:
                        assert(false);
                }
                if (inward) {
                    // Correct the limits.
                    if (i > 4) {
                        switch (cur) {
                            case 0: // moved right.
                                if (distance[i-1] + distance[i-5] >= distance[i-3])
                                    limits[(cur+1)%4] = y + distance[i-2] - distance[i-4];
                                break;
                            case 1: // moved up.
                                if (distance[i-1] + distance[i-5] >= distance[i-3])
                                    limits[(cur+1)%4] = x - distance[i-2] + distance[i-4];
                                break;
                            case 2: // moved left.
                                if (distance[i-1] + distance[i-5] >= distance[i-3])
                                    limits[(cur+1)%4] = y - distance[i-2] + distance[i-4];
                                break;
                            case 3: // moved down.
                                if (distance[i-1] + distance[i-5] >= distance[i-3])
                                    limits[(cur+1)%4] = x + distance[i-2] - distance[i-4];
                                break;
                            default:
                                assert(false);
                        }
                    }
                    break;
                }
            }
        }
        // Inward spiral.
        while (i < n) {
            move(x, y, distance[i++], cur);
            // Did we move past our limit?
            bool crossed = false;
            switch (cur) {
                case 0: // moved right.
                    crossed = x >= limits[cur];
                    limits[cur] = x;
                    break;
                case 1: // moved up.
                    crossed = y >= limits[cur];
                    limits[cur] = y;
                    break;
                case 2: // moved left.
                    crossed = x <= limits[cur];
                    limits[cur] = x;
                    break;
                case 3: // moved down.
                    crossed = y <= limits[cur];
                    limits[cur] = y;
                    break;
                default:
                    assert(false);
            }
            if (crossed) return true;
            if (x == 0 && y == 0) return true;
        }
        return false;
    }
};