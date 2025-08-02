class Solution {
    public long minCost(int[] b1, int[] b2) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        long minVal=Long.MAX_VALUE;
        for(int i=0;i<b1.length;i++){
            //+1 for b1 , -1 for b2
            //because 
            mp.put(b1[i] , mp.getOrDefault(b1[i] , 0 )+1);
            mp.put(b2[i] , mp.getOrDefault(b2[i] , 0 )-1);
            minVal=(long)(Math.min(minVal,(long)Math.min(b1[i],b2[i])));
        }         
        System.out.println(minVal);
        int i=0,j=0;
        for(Map.Entry<Integer, Integer>entry: mp.entrySet()){
            int key=entry.getKey();
            int val=entry.getValue();
            if(val%2==1)return -1;
            while(val!=0){
                if(val>0){
                    b1[i]=key;
                    val--;
                    i++;
                }
                else if(val<0){
                    b2[j]=key;
                    val++;
                    j++;
                }
            }
        }
        // mp.forEach((key,val)->{
            //local variables can't be change in the foreach loop
        //     while(val!=0){
        //         if(val>0){
        //             b1[i++]=key;
        //             val--;
        //         }
        //         else if(val<0){
        //             b2[j++]=key;
        //             val++;
        //         }
        //     }
        // });
        Arrays.sort(b1,0,i);
        Arrays.sort(b2,0,i);    
        for(int k=0;k<i;k++)    System.out.print(b1[k]+" "+ b2[k]+" ");
        int n=i;
        i=0;j--;
        long res=0;
        while(i<n && j>-1){
            boolean ptr=false;
            if(i!=0){
                if(b1[i]==b1[i-1]){
                    b1[i]=-1;
                    i++;
                    ptr=true;
                }
            }
            if(j!=n-1){
                if(b2[j]==b2[j+1]){
                    b2[j]=-1;
                    j--;
                    ptr=true;
                }
            }
            if(ptr)continue;
            long x=(long)(Math.min(2*minVal,(long)Math.min(b1[i],b2[j])));
            i++;
            j--;
            // System.out.print(x+" ");
            res+=x;
        }
        return res;
    }
}