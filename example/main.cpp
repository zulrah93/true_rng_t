#include <true_rng_t.hpp>
#include <iostream>

int main(int argument_count, char** arguments) {
    true_rng_t rng(10ul);
    for(size_t iteration = 0; iteration < 100; iteration++) {
        std::cout << rng.next_random_value() << " ";
        if (iteration > 0 && ((iteration % 10) == 0)) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}