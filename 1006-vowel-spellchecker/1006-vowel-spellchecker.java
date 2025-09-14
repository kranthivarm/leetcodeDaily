class Solution {
    boolean isVowel(char ch){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return true;
            return false;
        }
        String vowelErrorConvertor(String s){    
            s=s.toLowerCase();
            // System.out.print(s);
            char[] a=s.toCharArray();
            for(int i=0;i<a.length;i++){
                if(isVowel(a[i]))a[i]='-';                
            }
            return Arrays.toString(a);
        }
        String capitalConvertor(String s){
            s=s.toLowerCase();
            return Character.toUpperCase(s.charAt(0))+s.substring(1);
        }
    public String[] spellchecker(String[] wordlist, String[] q) {
        HashMap<String,Integer>mp=new HashMap<>(),
        capitalMap=new HashMap<>(),
        vowelError=new HashMap<>();
        
        for(int i=0;i<wordlist.length;i++){
            mp.put(wordlist[i],i);
            String temp=capitalConvertor(wordlist[i]);
            if(capitalMap.containsKey(temp)==false)capitalMap.put(temp,i);
            temp=vowelErrorConvertor(wordlist[i]);
            if(vowelError.containsKey(temp)==false)vowelError.put(temp,i);
        }
        String[]res=new String[q.length];
        for(int i=0;i<q.length;i++){
            if(mp.containsKey(q[i])){
                res[i]=q[i];
                continue;
            }
            String temp=capitalConvertor(q[i]);
            if(capitalMap.containsKey(temp)){
                res[i]=wordlist[capitalMap.get(temp)];
                continue;
            }
            String temp2=vowelErrorConvertor(q[i]);
            // System.out.print(temp2);
            if(vowelError.containsKey(temp2)){
                res[i]=wordlist[vowelError.get(temp2)];                
            } 
            else res[i]=new String();
        }
        return res;
    }
}