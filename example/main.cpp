#include <true_rng_t.hpp>
#include <iostream>
#include <chrono>

int main(int argument_count, char** arguments) {
    std::cout << "Is RDSEED64 supported? " << (true_rng_t::rdseed64_instruction_supported() ? "yes" : "no") << std::endl;
    auto start = std::chrono::steady_clock().now();
    true_rng_t rng(10000ul / 1000);
    for(size_t iteration = 0; iteration < 10000; iteration++) {
        rng.next_random_value();
    }
    std::cout <<  std::chrono::duration_cast<std::chrono::milliseconds>
                                    (std::chrono::steady_clock().now() - start).count() << " millisecond(s)" << std::endl;
    return 0;
}