#include <iostream>
#include <unordered_map>
#include <string>

unsigned long djb2(const std::string &str) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

int main() {
    std::unordered_map<unsigned long, std::string> seen;
    unsigned long i = 0;

    while (true) {
        std::string input = std::to_string(i);
        unsigned long h = djb2(input);

        auto it = seen.find(h);
        if (it != seen.end()) {
            std::cout << "Collision found!\n";
            std::cout << "String 1: " << it->second << "\n";
            std::cout << "String 2: " << input << "\n";
            std::cout << "Hash: " << h << "\n";
            std::cout << "Inputs checked: " << i << "\n";
            break;
        }

        seen[h] = input;
        ++i;
    }

    return 0;
}
