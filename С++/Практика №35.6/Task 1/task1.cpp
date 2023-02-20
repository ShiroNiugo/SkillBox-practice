#include <iostream>
#include <vector>

class task1
{
private:
    std::vector<int> digits;
public:
    task1(std::initializer_list<int> temp) : digits(temp){}
    void show(){
        for(auto d : digits)
            std::cout << d << std::endl;
    }
};

int main(){
    auto task = task1{1, 2, 3, 4, 5};
    task.show();
    return 0;
}