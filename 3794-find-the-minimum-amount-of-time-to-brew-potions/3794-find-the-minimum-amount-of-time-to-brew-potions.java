class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n=skill.length;
        long[]times=new long[n];
        Arrays.fill(times,0);
        for(int i:mana){
            long prev=0;
            for(int j=0;j<n;j++){
                // time[j]=Math.max(prev,time[j])+((long)skill[j]*(long)i);
                // prev=time[j];
                prev=Math.max(prev,times[j])+((long)skill[j]*(long)i);
            }
            times[n-1]=prev;
            for(int j=n-2;j>-1;j--)times[j]=times[j+1]-((long)skill[j+1]*(long)i);
        }
        return times[n-1];
    }
}
  