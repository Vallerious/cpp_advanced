#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <string>
#include <sstream>

bool tryParse(const std::string& s, int& output) {
    if (s.empty() || isalpha(s[0])) {
        return false;
    }

    std::istringstream ss(s);

    ss >> output;

    return true;
}

#endif // !TRY_PARSE_H
