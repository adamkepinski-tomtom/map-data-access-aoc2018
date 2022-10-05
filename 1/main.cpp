#include <iostream>
#include <fstream>
#include <map>
#include <array>

struct claim {
    int id = -1;
    int left_of = -1;
    int top_of = -1 ;
    int width = -1;
    int height = -1;
};


struct coord{
    int x;
    int y;
};

int main() {
    std::array<int, 1000*1000> fabric;
    std::ifstream f("input");
    std::string line;
    claim current_claim;
    std::map<int, bool> claims;
    std::map<std::pair<int,int>, int> coord_to_ids;

//#1 @ 387,801: 11x22
    do  {
        f.ignore(1);
        f >> current_claim.id;
        f.ignore(2);
        f >> current_claim.left_of;
        f.ignore(1);
        f >> current_claim.top_of;
        f.ignore(1);
        f >> current_claim.width;
        f.ignore(1);
        f >> current_claim.height;
        f.ignore(1);

//        std::cout << current_claim.id << " " << current_claim.left_of << " " << current_claim.top_of << " ";
//        std::cout << current_claim.width << " " << current_claim.height << std::endl;

        for (int x = current_claim.left_of; x < current_claim.left_of + current_claim.width; ++x) {
            for (int y = current_claim.top_of; y < current_claim.top_of + current_claim.height; ++y) {
                int index = y*1000 + x;
                fabric[index]++;
//                if (coord_to_ids.contains({x,y})) {
//
//                    coord_to_ids[{x,y}] = current_claim.id;
//                    claims[coord_to_ids[{x,y}]] = false;
//                } else {
//                    coord_to_ids[{x,y}] = current_claim.id;
//                    claims[current_claim.id] = true;
//                }
            }
        }
    } while (!f.eof());

    f = std::ifstream("input");
    do  {
        f.ignore(1);
        f >> current_claim.id;
        f.ignore(2);
        f >> current_claim.left_of;
        f.ignore(1);
        f >> current_claim.top_of;
        f.ignore(1);
        f >> current_claim.width;
        f.ignore(1);
        f >> current_claim.height;
        f.ignore(1);

//        std::cout << current_claim.id << " " << current_claim.left_of << " " << current_claim.top_of << " ";
//        std::cout << current_claim.width << " " << current_claim.height << std::endl;

        bool dirty = false;
        for (int x = current_claim.left_of; x < current_claim.left_of + current_claim.width; ++x) {
            for (int y = current_claim.top_of; y < current_claim.top_of + current_claim.height; ++y) {
                if (fabric[y*1000+x] > 1) {
                    dirty = true;
                    break;
                }
            }
            if (dirty)
                break;

        }
        if (!dirty) std::cout << current_claim.id << '\n';
    } while (!f.eof());

//    for(auto const& claim : claims) {
//        if (claim.second == true) {
//            std::cout << claim.first << std::endl;
//        }
//    }
}
