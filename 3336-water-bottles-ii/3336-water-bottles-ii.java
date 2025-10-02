class Solution {
    public int maxBottlesDrunk(int numB, int numEx) {
        int emptyB=0,res=0;
        while(numEx<=numB){
            //int rem=numB%numEx,q=numB/numEx;
            res+=numEx;
            numB-=numEx;
            numB++;
            //System.out.print(numEx);
            numEx++;
        }
        //System.out.print("res "+res);
        return res+numB;
    }
}