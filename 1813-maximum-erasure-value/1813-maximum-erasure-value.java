class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        HashMap<Integer,Integer>mp =  new HashMap<>();
        int prefix[]=new int[nums.length];
        prefix[0]=nums[0];
        for(int i=1;i<nums.length;i++)prefix[i]=prefix[i-1]+nums[i];
        int st=0,en=0,res=0;
        for(int i=0;i<nums.length;i++){
            int x=prefix[en]-prefix[st]+nums[st];
            // System.out.print(i + " " + st+" "+ en+ " ; ");
            res=Math.max(res,x);            
            if(mp.containsKey(nums[i])){
                int inex=mp.get(nums[i]);
                for(int j=st;j<=inex;j++)mp.remove(nums[j]);
                st=inex+1;
            }
            mp.put(nums[i],i);  
            // System.out.print("askmkemm")          ;
            en=i;
        }        
        return Math.max(res,(prefix[en]-prefix[st]+nums[st]));
    }
}