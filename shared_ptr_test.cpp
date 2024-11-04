#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib> // for std::atoi
#include <chrono>  // for timing
#include <functional> // for std::reference_wrapper
#include <optional> // for std::optional

typedef std::shared_ptr<int> IntPtr;
typedef std::reference_wrapper<int> IntRef;
typedef std::optional<IntRef> OptionalIntRef;
typedef std::unique_ptr<int> UniqueIntPtr;
typedef std::reference_wrapper<UniqueIntPtr> UniqueIntRef;

int main(int argc, char** argv) {
    int size = 1000000; // default value

    if (argc > 1) {
        size = std::atoi(argv[1]);
    }

    std::cout << "shared_ptr_size: " << sizeof(IntPtr) << std::endl;
    std::cout << "reference_wrapper_size: " << sizeof(IntRef) << std::endl;
    std::cout << "optional_reference_wrapper_size: " << sizeof(OptionalIntRef) << std::endl;
    std::cout << "unique_ptr_size: " << sizeof(UniqueIntPtr) << std::endl;
    std::cout << "reference_to_unique_ptr_size: " << sizeof(UniqueIntRef) << std::endl;
    std::cout << std::endl;

    std::vector<IntPtr> ptrVec1;
    std::vector<IntPtr> ptrVec2;
    std::vector<IntRef> refVec1;
    std::vector<IntRef> refVec2;    
    std::vector<OptionalIntRef> optionalVec1;
    std::vector<OptionalIntRef> optionalVec2;
    std::vector<UniqueIntPtr> uniquePtrVec1;
    std::vector<UniqueIntRef> uniqueRefVec2;
    std::vector<int> intVec(size);

    // Measure time for shared_ptr assignment
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        ptrVec1.push_back(std::make_shared<int>(intVec[i]));
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "Time for shared_ptr assignment loop: " << elapsed1.count() << " seconds" << std::endl;

    // Measure time for shared_ptr copy
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        ptrVec2.push_back(ptrVec1[i]);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "Time for shared_ptr copy loop: " << elapsed2.count() << " seconds" << std::endl;
    std::cout << "Total time for shared_ptr: " << elapsed1.count() + elapsed2.count() << " seconds" << std::endl << std::endl;

    // Measure time for reference_wrapper assignment
    auto start3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        refVec1.push_back(std::ref(intVec[i]));
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = end3 - start3;
    std::cout << "Time for reference_wrapper assignment loop: " << elapsed3.count() << " seconds" << std::endl;

    // Measure time for reference_wrapper copy
    auto start4 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        refVec2.push_back(refVec1[i]);
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed4 = end4 - start4;
    std::cout << "Time for reference_wrapper copy loop: " << elapsed4.count() << " seconds" << std::endl;
    std::cout << "Total time for reference_wrapper: " << elapsed3.count() + elapsed4.count() << " seconds" << std::endl << std::endl;

    // Measure time for optional reference_wrapper assignment
    auto start5 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        optionalVec1.push_back(std::ref(intVec[i]));
    }
    auto end5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed5 = end5 - start5;
    std::cout << "Time for optional reference_wrapper assignment loop: " << elapsed5.count() << " seconds" << std::endl;

    // Measure time for optional reference_wrapper copy
    auto start6 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        optionalVec2.push_back(refVec1[i]);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed6 = end6 - start6;
    std::cout << "Time for optional reference_wrapper copy loop: " << elapsed6.count() << " seconds" << std::endl;
    std::cout << "Total time for optional reference_wrapper: " << elapsed5.count() + elapsed6.count() << " seconds" << std::endl << std::endl;

    // Measure time for unique_ptr assignment
    auto start7 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        uniquePtrVec1.push_back(std::make_unique<int>(intVec[i]));
    }
    auto end7 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed7 = end7 - start7;
    std::cout << "Time for unique_ptr assignment loop: " << elapsed7.count() << " seconds" << std::endl;

    // Measure time for reference to unique_ptr copy
    auto start8 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size; i++) {
        uniqueRefVec2.push_back(std::ref(uniquePtrVec1[i]));
    }
    auto end8 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed8 = end8 - start8;
    std::cout << "Time for reference to unique_ptr copy loop: " << elapsed8.count() << " seconds" << std::endl;
    std::cout << "Total time for reference to unique_ptr: " << elapsed7.count() + elapsed8.count() << " seconds" << std::endl << std::endl;

    return 0;
}
