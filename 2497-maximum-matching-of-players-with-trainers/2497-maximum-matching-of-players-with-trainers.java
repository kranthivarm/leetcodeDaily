class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        // System.out.println(Arrays.toString(trainers));
        int j=0,res=0;
        for(int i=0;i<players.length && j<trainers.length;i++){
            while(j<trainers.length && players[i]>trainers[j])j++;
            if(j<trainers.length && players[i]<=trainers[j]){
                res++;
                j++;
            }
        }
        return res;
    }
}