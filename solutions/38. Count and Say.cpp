class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while (--n) {
            char con = str[0];
            int t = 0;
            string newStr = "";
            for (char c : str) {
                if (c == con) t++;
                else {
                    newStr += to_string(t) + con;
                    con = c;
                    t = 1;
                }
            }
            newStr += to_string(t) + con;
            str = newStr;
​
        }
        return str;
    }
};
