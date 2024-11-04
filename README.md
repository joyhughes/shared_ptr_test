# shared_ptr_test
Speed and size tests of shared_ptr and alternatives

to build: 
`c++ -std=c++17 shared_ptr_test.cpp -o shared_ptr_test`

speed test for 10^7 size vectors on old Mac:

shared_ptr_size: 16
reference_wrapper_size: 8
optional_reference_wrapper_size: 16
unique_ptr_size: 8
reference_to_unique_ptr_size: 8

Time for shared_ptr assignment loop: 2.52649 seconds
Time for shared_ptr copy loop: 1.08788 seconds
Total time for shared_ptr: 3.61438 seconds

Time for reference_wrapper assignment loop: 0.806521 seconds
Time for reference_wrapper copy loop: 0.618535 seconds
Total time for reference_wrapper: 1.42506 seconds

Time for optional reference_wrapper assignment loop: 0.959393 seconds
Time for optional reference_wrapper copy loop: 0.731422 seconds
Total time for optional reference_wrapper: 1.69081 seconds

Time for unique_ptr assignment loop: 2.43285 seconds
Time for reference to unique_ptr copy loop: 0.601326 seconds
Total time for reference to unique_ptr: 3.03418 seconds
