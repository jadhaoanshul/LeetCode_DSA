class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int width = 0;
        string line = "";
        vector<string> lineW;
        int index = 0;
        
        for(int i = 0; i<words.size(); i++){
            if(words[i].size() == maxWidth && width == 0){
                lineW.push_back(words[i]);
                width = width + words[i].size();
            }
            else if(width + words[i].size()< maxWidth){
                if(index != 0){
                    width++;
                    lineW.push_back(" ");
                } 
                lineW.push_back(words[i]);
                width = width + words[i].size();
                index++;
            }
            else{
                int spacing = maxWidth - width;
                int sIndex = 1;
                for(int i = 0; i< spacing; i++){
                    if(lineW.size()>1){
                        lineW[sIndex] += " ";
                        if(sIndex + 2 < lineW.size())sIndex = sIndex+2;
                        else sIndex = 1;
                    }
                    else lineW[0] += " ";
                }
                for(int i = 0; i<lineW.size(); i++){
                    line += lineW[i];
                }
                res.push_back(line);
                width = 0;
                line="";
                lineW.clear();
                index = 0;
                i--;
            }
        }
        
        int spacing = maxWidth - width;
        int sIndex = lineW.size()-1;
        for(int i = 0; i< spacing; i++){
            lineW[sIndex] += " ";
        }
        for(int i = 0; i<lineW.size(); i++){
            line += lineW[i];
        }
        res.push_back(line);
        return res;
    }
};