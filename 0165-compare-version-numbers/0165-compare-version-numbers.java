class Solution {
    public int compareVersion(String v1, String v2) {
        int i=0, j=0;
        while(i<v1.length() || j<v2.length()){
            // int a=0,b=0;
            // while(i<v1.length() && v1.charAt(i)!='.')a=(a*10)+((int)(v1.charAt(i++)-'0'));            
            // while(j<v2.length() && v2.charAt(j)!='.')a=(a*10)+((int)(v2.charAt(j++)-'0'));            
            // i++;j++;
            // System.out.println(a+" "+b);
            // if(a>b)return 1;
            // else if(a<b)return -1;
            while(i<v1.length() && v1.charAt(i)=='0')i++;
            while(j<v2.length() && v2.charAt(j)=='0')j++;
            if(i<v1.length() && j<v2.length()){
                // lengths comparision
                int cnt1=0,cnt2=0;
                for(int k=i;k<v1.length() && v1.charAt(k)!='.';k++)cnt1++;
                for(int k=j;k<v2.length() && v2.charAt(k)!='.';k++)cnt2++;                
                if(cnt1>cnt2)return 1;
                if(cnt2>cnt1)return -1;
                while(i<v1.length() && j<v2.length()){
                    if(v1.charAt(i)=='.' && v2.charAt(j)=='.'){
                        i++;j++;
                        break;
                    }
                    if(v2.charAt(j)=='.')return 1;
                    if(v1.charAt(i)=='.')return -1;

                    if(v1.charAt(i)>v2.charAt(j))return 1;
                    else if(v1.charAt(i)<v2.charAt(j))return -1;
                    i++;j++;
                }
            }
            else if(i<v1.length()){
                if(v1.charAt(i)=='.')i++;
                else return 1;
            }
            else if(j<v2.length()){
                if(v2.charAt(j)=='.')j++;
                else return -1;
            }
           
            System.out.println(i+" "+j);
        }
        return 0;
    }
}