class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)
        return 0;
        if(n>=5 && n<25)
        return n/5;
        if(n>=25 && n<125)
        return n/5+(n/25);
        if(n>=125 && n<625)
        return n/5+(n/25)+(n/125);
        if(n>=625 && n<3125)
        return n/5+(n/25)+(n/125)+(n/625);
        if(n>=3125)
        return n/5+(n/25)+(n/125)+(n/625)+(n/3125);
        return 0;
    }
};