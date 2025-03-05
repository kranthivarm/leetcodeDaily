class Solution {
public:
    long long coloredCells(int n) {
        long long num=n;
        return (num*num)+((num-1)*(num-1));
    }
};