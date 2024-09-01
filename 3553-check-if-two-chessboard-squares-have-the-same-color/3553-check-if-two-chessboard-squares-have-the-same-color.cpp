class Solution {
public:
    bool checkTwoChessboards(string cordinate1, string cordinate2) {
        int count1 = 0; // BLACK
        int count = 0;  // WHITE
        if (cordinate1[1] % 2 == 0) {
            if (cordinate1[0] == 'a' || cordinate1[0] == 'c' ||
                cordinate1[0] == 'e' || cordinate1[0] == 'g') {
                count++;
            } else {
                count1++;
            }
        } else {
           
                if (cordinate1[0] == 'b' || cordinate1[0] == 'd' ||
                    cordinate1[0] == 'f' || cordinate1[0] == 'h') {
                    count++;
                } else {
                    count1++;
                }
            }
            if (cordinate2[1] % 2 == 0) {
                if (cordinate2[0] == 'a' || cordinate2[0] == 'c' ||
                    cordinate2[0] == 'e' || cordinate2[0] == 'g') {
                    count++;
                } else {
                    count1++;
                }
            }

            else {
                if (cordinate2[0] == 'b' || cordinate2[0] == 'd' ||
                    cordinate2[0] == 'f' || cordinate2[0] == 'h') {
                    count++;
                } else {
                    count1++;
                }
            }
            if (count1 == 2 || count == 2)
                return true;
            else
                return false;
        }
    };