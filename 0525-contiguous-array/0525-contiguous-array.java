class Solution {
    public int findMaxLength(int[] nums) {
        int cnt=0,res=0;        
        HashMap<Integer,Integer>mp=new HashMap<>();
        mp.put(0,-1);
        for(int i=0;i<nums.length;i++){
            cnt+=(nums[i]==1)?1:-1;
            if(mp.containsKey(cnt)){
                int temp=mp.get(cnt);
                // res=Math.max(res,i-temp+((temp==-1)?-1:0));            
                res=Math.max(res,i-temp+((temp==-1)?0:0));            
            }
            else mp.put(cnt,i);
        }
        return res;
    }
}