#include <iostream>
#include <thread>
#include <chrono>



struct background_task {
    int & attribute;
    background_task(int & attribute_) : attribute (attribute_)
    {
        
    }
    
    auto operator ()() -> void
    {
        for (;;) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << attribute << std::endl;
        }
    }
};

void oops()
{
    int local_variable = 10;
    std::thread thread { background_task(local_variable) };
    thread.detach();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main(int argc, const char * argv[]) {
    
    oops();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    
    return 0;
}
