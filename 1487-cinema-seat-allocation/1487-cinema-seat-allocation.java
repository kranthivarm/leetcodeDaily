class Solution {
    public int maxNumberOfFamilies(int n, int[][] r) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int cnt=0,val;
        for(int i=0;i<r.length;i++){
            val=mp.getOrDefault(r[i][0],0);
            val=val|(1<<r[i][1]);
            mp.put(r[i][0],val);
        }
        for(int key:mp.keySet()){
            val=mp.get(key);
            // System.out.println(key+" "+val);
            int i=2;
            boolean ptr=true;
            while(i<6 && (val&(1<<i))==0)i++;
            if(i==6){cnt++;ptr=false;}
            i=6;
            while(i<10 && (val&(1<<i))==0)i++;
            if(i==10){cnt++;ptr=false;}
            if(ptr){
                i=4;
                while(i<8 && (val&(1<<i))==0)i++;
                if(i==8)cnt++;
            }            
        }    
        // System.out.println(cnt+" "+mp.size());
        return cnt+(n-mp.size())*2;        
    }
}