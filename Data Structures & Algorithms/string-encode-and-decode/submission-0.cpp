class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(string &str : strs) {
            encoded += to_string(str.length());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        int n = s.length();

        while(i<n) {
            int len = 0;

            while(s[i] != '#') {
                len = len * 10 + (s[i]-'0');
                i++;
            }
            i++;

            string temp = s.substr(i, len);
            result.push_back(temp);

            i += len;
        }

        return result;
    }
};
