#include <true_rng_t.hpp>
#include <iostream>
#include <chrono>
#include <charconv>

int main(int argument_count, char** arguments) {

    size_t max_iteration_count{1000000};
    size_t reseed_rate{1};
    if (argument_count > 1) {
        std::string iteration_count_string{arguments[1]};
        auto result = std::from_chars(iteration_count_string.data(), iteration_count_string.data() + iteration_count_string.size(), max_iteration_count);
        if (0 != static_cast<size_t>(result.ec)) {
            max_iteration_count = 1000000;
        }
    }
    if (argument_count > 2) {
        std::string reseed_rate_string{arguments[2]};
        std::from_chars(reseed_rate_string.data(), reseed_rate_string.data() + reseed_rate_string.size(), reseed_rate);
    }
    bool print{false};
    if (argument_count > 3) {
        std::string command{arguments[3]};
        print = command == "print";
    }
    
    bool rdseed_supported{true_rng_t::rdseed64_instruction_supported()};
    std::cout << "Is RDSEED64 supported? " << (rdseed_supported ? "yes" : "no") << std::endl;
    if (!rdseed_supported) {
        return 1; // Remove this if you want to run UB x86 instruction hehe :P
    }
    auto start = std::chrono::steady_clock().now();
    true_rng_t rng(reseed_rate);
    for(size_t iteration = 0; iteration < max_iteration_count; iteration++) {
        auto rand_value = rng();
        [[unlikely]]
        if (print) {
            std::cout <<  rand_value << ((iteration > 0 && (iteration % 10 == 0)) ? "\n" : " ");
        }
    }
    std::cout << "\nDid " << max_iteration_count
                << " RDSEED64 instruction(s) in " 
                <<  std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::steady_clock().now() - start).count() 
                << " millisecond(s)" << " with a reseed rate of 1 in " << reseed_rate << std::endl;
    return 0;
}