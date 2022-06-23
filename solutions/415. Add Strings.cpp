class Solution {
    char toChar(int const bit) {
        return (bit % 10) + 48;
    }
    
    int getCarry(int const bit) {
        return bit / 10;
    }
    
public: // int = char - 48
    string addStrings(string num1, string num2) {
        auto rit1 = num1.rbegin(), rit2 = num2.rbegin();
        int carry = 0, bit = 0;
        string result = "";
        while (rit1 != num1.rend() && rit2 != num2.rend()) {
            bit = *rit1++ + *rit2++ + carry - 96;
            carry = getCarry(bit);
            result += toChar(bit);
        }
        while (rit1 != num1.rend()) {
            bit = *rit1++ + carry - 48;
            carry = getCarry(bit);
            result += toChar(bit);
        }
        while (rit2 != num2.rend()) {
            bit = *rit2++ + carry - 48;
            carry = getCarry(bit);
            result += toChar(bit);
        }
        if (carry) {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
