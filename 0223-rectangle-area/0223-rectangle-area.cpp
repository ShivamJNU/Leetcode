//The bolow solution is working perfectly fine:

/*class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs((ax2-ax1)*(ay2-ay1));
        int area2 = abs((bx2-bx1)*(by2-by1));

        int overlapping_x = 0;
        int overlapping_y = 0;

        int b_left = min(bx1,bx2);
        int b_right = max(bx1,bx2);

        int a_left = min(ax1,ax2);
        int a_right = max(ax1,ax2);

        if(b_right>=a_left && b_right<=a_right){
            overlapping_x = abs(b_right-max(a_left, b_left));
        }

        if(a_right>=b_left && a_right<=b_right){
            overlapping_x = abs(a_right-max(b_left, a_left));
        }

        int b_bottom = min(by1,by2);
        int b_top = max(by1,by2);

        int a_bottom = min(ay1,ay2);
        int a_top = max(ay1,ay2);

        if(b_top>=a_bottom && b_top<=a_top){
            overlapping_y = abs(b_top-max(a_bottom, b_bottom));
        }

        if(a_top>=b_bottom && a_top<=b_top){
            overlapping_y = abs(a_top-max(b_bottom, a_bottom));
        }

        return area1 + area2 - (overlapping_x*overlapping_y);
    }
};
*/

// This code is also running fine now after debugging:

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs((ax2-ax1)*(ay2-ay1));
        int area2 = abs((bx2-bx1)*(by2-by1));

        int overlapping_x = 0;
        int overlapping_y = 0;

        if(bx1>=ax1 && bx1<=ax2){
            if(bx2>ax2){
                overlapping_x = abs(ax2-bx1);
            }else{
                overlapping_x = abs(bx2-bx1);
            }
        }else if(bx2>=ax1 && bx2<=ax2){
            if(bx1<ax1){
                overlapping_x = abs(ax1-bx2);
            }else{
                overlapping_x = abs(bx2-bx1);
            }
        }

// This case was being left before debugging:
        if(bx1<=ax1 && bx2>=ax2){
            overlapping_x = abs(ax1-ax2);
        }

        if(by1>=ay1 && by1<=ay2){
            if(by2>ay2){
                overlapping_y = abs(ay2-by1);
            }else{
                overlapping_y = abs(by2-by1);
            }
        }else if(by2>=ay1 && by2<=ay2){
            if(by1<ay1){
                overlapping_y = abs(ay1-by2);
            }else{
                overlapping_y = abs(by2-by1);
            }
        }
        
// This case was being left before debugging:
        if(by1<=ay1 && by2>=ay2){
            overlapping_y = abs(ay1-ay2);
        }

        return area1 + area2 - (overlapping_x*overlapping_y);
    }
};
        