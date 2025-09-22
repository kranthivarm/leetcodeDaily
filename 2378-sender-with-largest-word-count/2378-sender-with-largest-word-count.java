class Solution {
    public String largestWordCount(String[] mssg, String[] snd) {
        HashMap<String,Integer>mp=new HashMap<>();
        int ma=0;
        String res="";
        for(int i=0;i<mssg.length;i++){
            int cnt=1;
            for(int j=0;j<mssg[i].length();j++)if(mssg[i].charAt(j)==' ')cnt++;
            mp.put(snd[i],(mp.getOrDefault(snd[i],0)+cnt));
            ma=Math.max(ma,mp.get(snd[i]));
        }
        for(String key:mp.keySet()){
            if(ma==mp.get(key)){
                if(res.length()==0){
                    res=key;
                    continue;
                }
                if(key.compareTo(res)>0)res=key;
            }            
        }
        return res;
    }
}