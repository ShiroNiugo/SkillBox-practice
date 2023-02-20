#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

auto task2 = [](std::vector<int> vec){
    if(vec.empty())
        return std::unique_ptr<std::vector<int>>{};

    std::unordered_set<int> find;
    for(auto digit : vec)
        find.insert(digit);
    vec.clear();
    for(auto digit : find)
        vec.push_back(digit);
    std::unique_ptr<std::vector<int>> result = std::make_unique<std::vector<int>>(vec);
    return result;
};

int main(){
    std::vector<int> temp{1,2,6,2,4,6,7,9,5,4,3};
    auto result = task2(temp);
    for(auto r : *result)
        printf("%i\n", r);
    return 0;
}