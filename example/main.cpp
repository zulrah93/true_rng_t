#include <true_rng_t.hpp>
#include <iostream>

int main(int argument_count, char** arguments) {
    true_rng_t rng(1ul);
    for(size_t _ = 0; _ < 100000000; _++) {
        //std::cout << rng.next_random_value() << " ";
    }
    std::cout << std::endl;
    return 0;
}