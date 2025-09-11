class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<Integer>>mp=new HashMap<>()        ;
        for(int i=0;i<strs.length;i++){
            String s=strs[i];
            // String sortedS=Arrays.toString(Arrays.sort(s.toCharArray()));
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sortedS = new String(chars);

            if(!mp.containsKey(sortedS))mp.put(sortedS,new ArrayList<>());
            (mp.get(sortedS)).add(i);
        }
        List<List<String>>result =new ArrayList<>();
        for(String key:mp.keySet()){
            List<String>t=new ArrayList<>();
            for(int i:mp.get(key))t.add(strs[i]);
            result.add(t);
        }
        return result;
    }
}