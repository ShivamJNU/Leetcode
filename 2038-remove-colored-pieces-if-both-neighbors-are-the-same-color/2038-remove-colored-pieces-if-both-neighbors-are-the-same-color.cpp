class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice_count=0;
        int bob_count=0;

        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]==colors[i-1]&&colors[i]==colors[i+1]&&colors[i]=='A'){
                alice_count++;
            }

            if(colors[i]==colors[i-1]&&colors[i]==colors[i+1]&&colors[i]=='B'){
                bob_count++;
            }
        }

        if(alice_count>bob_count){
            return true;
        }

        return false;

    }
};