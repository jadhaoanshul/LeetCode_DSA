class Solution {
public:
    string interpret(string command) {
        string goal;
        for(int i=0; i<=command.length()-1;i++){
            if(command[i]=='G')
                goal+='G';
            else if(command[i]=='(' && command[i+1]==')'){
                goal+='o';
                i++;
            }
            else if(command[i]=='(' && command[i+1]=='a')
                {goal += "al";
                    i=i+3;
                }
        }
        return goal;
    }
};