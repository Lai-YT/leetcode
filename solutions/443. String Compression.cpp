class Solution {
 public:
  int compress(std::vector<char>& chars) {
    AddSentinel_(chars);
    int compressed_end = 0;
    int count = 0;
    int prev_c = SENTINEL_;
    for (const char c : chars) {
      if (c != prev_c && prev_c != SENTINEL_) {
        chars.at(compressed_end++) = prev_c;
        if (CanBeCompressed_(count)) {
          /* from MSB */
          for (char d : std::to_string(count)) {
            chars.at(compressed_end++) = d;
          }
        }
        count = 0;
      }
      count++;
      prev_c = c;
    }

    return compressed_end;
  }

 private:
  const char SENTINEL_ = '\0';

  // To eliminate the case which the last kind of characters
  // are not compressed.
  void AddSentinel_(std::vector<char>& chars) const {
    chars.push_back(SENTINEL_);
  }

  bool CanBeCompressed_(const int count) const {
    return count > 1;
  }
};
