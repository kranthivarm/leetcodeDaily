class Solution {
    public int maxProduct(String[] words) {
        // ArrayList<boolean[]>fre=new List<>();
        // for(int i=0;i<words.length;i++){
        //     fre.add(new boolean[26]);
        //     for(int j=0;j<i.length();i++){
        //         int ind=(int)((word[i].charAt(j))-'a');
        //         fre[i][ind]=true;
        //     }
        // }
        // for(int i=0;i<words.length;i++){
        //     for(int j=i+1;)
        // }
        int n=words.length;
        int[]con=new int[n];
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<words[i].length();j++){
                int ind=(int)(words[i].charAt(j)-'a');
                a=(a|(1<<ind));
            }
            con[i]=a;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)if((con[i]&con[j])==0)res=Math.max(res,((words[i].length())*(words[j].length())));
        }
        return res;
    }
}