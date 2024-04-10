#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int nameScore(const std::string &name, int position) {
    int score = 0;
    for (char c : name) {
        score += c - 'A' + 1;
    }
    return score * position;
}

int main() {
    std::ifstream file("names.txt");
    std::string line;
    std::vector<std::string> names;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name;
            while (std::getline(ss, name, ',')) {
                name = name.substr(1, name.length() - 2);
                names.push_back(name);
            }
        }
        file.close();
    }

    std::sort(names.begin(), names.end());

    long long totalScore = 0;
    for (std::size_t i = 0; i < names.size(); ++i) {
        totalScore += nameScore(names[i], i + 1);
    }

    std::cout << "Total of all name scores: " << totalScore << std::endl;

    return 0;
}
