#include <algorithm>
#include <cctype>
#include <locale>

namespace trimming {
// trim from start (in place)
static inline void ltrim(std::string &string) {
    string.erase(string.begin(), std::find_if(string.begin(), string.end(), [](int character) {
                     return std::isspace(character) == 0;
                 }));
}

// trim from end (in place)
static inline void rtrim(std::string &string) {
    string.erase(std::find_if(string.rbegin(), string.rend(),
                              [](int character) { return std::isspace(character) == 0; })
                         .base(),
                 string.end());
}

// trim from both ends (in place)
static inline std::string trim(const std::string &s_input) {
    std::string string{s_input};
    ltrim(string);
    rtrim(string);
    return string;
}
}  // namespace trimming
