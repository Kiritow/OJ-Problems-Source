class Solution {
public:
    int countPoints(string rings) {
        int rods[10] = {};
        for(int i=0; i<rings.size(); i+=2) {
            char c = rings[i];
            int id = rings[i+1] - '0';

            // printf("%c%d\n", c, id);

            switch (c) {
                case 'R':
                rods[id] |= 0x100;
                break;
                case 'G':
                rods[id] |= 0x10;
                break;
                case 'B':
                rods[id] |= 0x1;
                break;
            }
        }

        int c = 0;
        for(int i=0; i<10; i++) {
            // printf("%d %d\n", i, rods[i]);
            if (rods[i] == 0x111) c++;
        }
        return c;
    }
};
