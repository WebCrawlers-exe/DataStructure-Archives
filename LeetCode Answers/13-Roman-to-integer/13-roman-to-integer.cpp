class Solution {
public:
    int romanToInt(string s) {
        unordered_map<int,int> map;
        int ans=0;
        map.insert({
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}});
        for(int i=0;i<s.length();i++){
            if(map[s[i]]<map[s[i+1]]){
                ans-=map[s[i]];
            }
            else{
                ans+=map[s[i]];
            }
        }
        return ans;
    }
};