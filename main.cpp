#include <fstream>
#include <random>
#include <map>
#include <string>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 6);

    std::map<int, int> counts;
    for (int i = 0; i < 100000; ++i) {
        ++counts[dist(mt)];
    }

    std::map<int, std::string> names = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}};
    std::ofstream out("results.csv");
    for (const auto &count : counts) {
        out << names[count.first] << ":" << count.second << "\n";
    }
    out.close();

    return 0;
}