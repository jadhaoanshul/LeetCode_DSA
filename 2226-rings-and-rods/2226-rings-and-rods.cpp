class Solution {
public:
    int countPoints(string rings) {
        int rods[10] = {0};  // Each element is a bitmask

        for (int i = 0; i < rings.length(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';

            if (color == 'R') {
                rods[rod] |= 1;  // bit 0
            } else if (color == 'G') {
                rods[rod] |= 2;  // bit 1
            } else if (color == 'B') {
                rods[rod] |= 4;  // bit 2
            }
        }

        int count = 0;
        for (int i = 0; i < 10; ++i) {
            if (rods[i] == 7) { // 111 in binary means all 3 colors are present
                count++;
            }
        }

        return count;
    }
};
