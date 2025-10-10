class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int dp[]=new int[energy.length];
        Arrays.fill(dp,0);
        for(int i=energy.length-1;i>-1;i--){
            dp[i]=energy[i]+((i+k<energy.length)?dp[i+k]:0);
        }
        return Arrays.stream(dp).max().getAsInt();
    }
}