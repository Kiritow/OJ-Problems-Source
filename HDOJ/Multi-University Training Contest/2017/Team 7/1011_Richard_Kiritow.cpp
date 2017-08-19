#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>
std::vector<std::size_t> kolakoski(std::size_t size) {
    std::vector<std::size_t> vec;
    vec.reserve(size);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    std::vector<std::size_t>::iterator it = vec.begin() + 2;
    while (vec.size() < size) {
        if (*it == 1) {
            if (vec.back() == 1) {
                vec.push_back(2);
            }
            else { //if (vec.back() == 2) {
                vec.push_back(1);
            }
        }
        else { //if (*it == 2) {
            if (vec.back() == 1) {
                vec.push_back(2);
                vec.push_back(2);
            }
            else { //if (vec.back() == 2) {
                vec.push_back(1);
                vec.push_back(1);
            }
        }
        ++it;
    }
    return vec;
}

int main() {
    int t;
    int n[5];
    int nmax = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n[i];
        nmax = std::max(n[i], nmax);
    }
    std::vector<std::size_t> vec = kolakoski((std::size_t)nmax);
    //´Ë´¦Êä³ö
    for(int i=0;i<t;i++)
    {
        std::cout<<vec[n[i]-1]<<std::endl;
    }
    return 0;
}