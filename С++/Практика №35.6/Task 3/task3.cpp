#include <iostream>
#include <filesystem>

int main(){

    auto recursiveGetFileNameByExtension = [](std::filesystem::path path, const std::string extension){
        for(auto& p : std::filesystem::recursive_directory_iterator(path))
            if(p.is_regular_file() && p.path().extension().compare(extension) == 0)
                std::cout << p.path() << std::endl;
    };

    recursiveGetFileNameByExtension("D:\\Downloads", ".png");
    return 0;
}