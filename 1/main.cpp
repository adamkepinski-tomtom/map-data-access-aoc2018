#include <iostream>
#include <fstream>
#include <set>

int main() {


    int result = 0;
    int increment = 0;
    int count = 0;
    std::set<int> reached_frequencies;
    bool found = false;

    while (!found) {
        std::ifstream f("input");
        while (f >> increment) {
            result += increment;
            if (reached_frequencies.contains(result)) {
                found = true;
                break;
            }
            reached_frequencies.insert(result);
            count++;
        }
    }
    std::cout << "set size: " << reached_frequencies.size() << " number of iterations: " << count << '\n';
    std::cout << result << '\n';
    return 0;
}
