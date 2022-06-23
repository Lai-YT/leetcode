class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length() > a.length()) swap(a, b);
        string result = "";
        char carry = '0';
        for (int i = b.length() - 1, j = a.length() - 1; i >= 0; i--, j--) {
            switch (a[j] + b[i] + carry - 144) {
                case 0: result += '0'; carry = '0'; break;
                case 1: result += '1'; carry = '0'; break;
                case 2: result += '0'; carry = '1'; break;
                case 3: result += '1'; carry = '1'; break;
            }
            cout << result << '\n';
        }
        for (int i = a.length() - b.length() - 1; i >= 0; i--) {
            switch (a[i] + carry - 96) {
                case 0: result += '0'; carry = '0'; break;
                case 1: result += '1'; carry = '0'; break;
                case 2: result += '0'; carry = '1'; break;
            }
        }
        if (carry != '0') result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};
