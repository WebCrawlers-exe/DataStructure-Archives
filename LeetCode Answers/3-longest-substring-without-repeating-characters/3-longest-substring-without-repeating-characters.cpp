class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        map<char, int> map;

        int left = 0;
        int len = 0;

        for (int i = 0; i < s.size(); i++) {
          if (map.count(s[i])) {
            if (left < map[s[i]] + 1) left = map[s[i]] + 1;
          }
          if (i - left + 1 > len) len = i - left + 1;
          map[s[i]] = i;
        }
        return len;
    }
};