class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ranges{};
        std::size_t begin = 0;
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (i + 1 == nums.size() || nums.at(i + 1) != nums.at(i) + 1) {
                if (begin == i) {
                    ranges.push_back(FormatString("%d", nums.at(i)));
                } else {
                    ranges.push_back(FormatString("%d->%d", nums.at(begin), nums.at(i)));
                }
                begin = i + 1;
            }
        }
        return ranges;
    }

private:
    template<typename ... Args>
    std::string FormatString(const char* format, Args... args) {
        const std::size_t strlen = std::snprintf(nullptr, 0, format, args...);
        char buf[strlen + 1];
        std::snprintf(buf, sizeof(buf), format, args...);
        return buf;
    }
};
