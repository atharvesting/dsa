#include <vector>
#include <unordered_map>

std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
    std::unordered_map<int, int> map1;
    std::unordered_map<int, int> map2;
    std::vector<int> result;
    int common{ 0 };
    for (size_t i = 0; i < A.size(); i++)
    {
        auto an = A[i]; auto bn = B[i];
        map1[an] = 1; map2[bn] = 1;

        if (map1.find(bn) != map1.end()) {
            common++;
        }
        if (map2.find(an) != map2.end() && an != bn) {
            common++;
        }
        result.push_back(common);
    }
    return result;
}