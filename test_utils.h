#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <vector>
#include <string>

namespace test_utils
{
    template<class T>
    std::vector<T> str_to_vector(std::string);

    template<class T>
    std::vector<std::vector<T>>str_to_vector_2D(std::string);

    template<class T>
    std::string vector_to_str(std::vector<T>);

    template<class T>
    std::string vector_to_str_2D(std::string);

    template<class T>
    void print_vector(std::vector<T>);


}; // namespace test_utils

#endif /* TEST_UTILS_H */