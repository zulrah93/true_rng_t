# Purpose

A simple header only C++ library for true random using a modern x86 64-bit instruction if its not supported then unfortunately this libary is not for you


# Potential Uses

For one, this library was meant for fun and learning but it could be use for gaming if you care less about performance and more true random whether its true random is up to debate the seed is supposed to be true random but the rest depends on reseed rate and stuff, its not designed by academic :P

# Example benchmark (not scientific nor should this be your first choice for production)

```

palestine_will_be_free@unix-pc:~/true_rng$ ./build.sh 
palestine_will_be_free@unix-pc:~/true_rng$ bin/true_rng_example 1000000
Is RDSEED64 supported? yes
Did 1000000 RDSEED64 instruction(s) in 16625 millisecond(s) with a reseed rate of 1 in 1
palestine_will_be_free@unix-pc:~/true_rng$ bin/true_rng_example 1000000 8
Is RDSEED64 supported? yes
Did 1000000 RDSEED64 instruction(s) in 2015 millisecond(s) with a reseed rate of 1 in 8


```