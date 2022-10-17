class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string array[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int ans=0;
        unordered_map<char,string> map;
        char ch = 'a';
        for(int i =0;i<26;i++){
            map.insert({('a'+i),array[i]});
        }
        unordered_map<string,string> map2;
        set<string> finalSet;
        for(int i=0;i<words.size();i++){
            //for each word:
            if(!map2.count(words[i])){
                for(int j=0;j<words[i].length();j++){
                    map2[words[i]] += map[words[i][j]];
                }
                cout<<map2[words[i]]<<endl;
                finalSet.insert(map2[words[i]]);
            }
        }
        return finalSet.size();
    }
};