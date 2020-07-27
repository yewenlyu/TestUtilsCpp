#include "test_utils.h"

#include <ctype.h>
#include <type_traits>

namespace test_utils
{
    template <class T>
    std::vector<T> str_to_vector(std::string input_string)
    {
        std::vector<T> output_vector;

        // str_to_vector<int>
        if (std::is_same<T, int>::value)
        {
            int start = 0, end = 0;
            while (start < input_string.size())
            {
                if (!isdigit(input_string[start]))
                {
                    ++start;
                    ++end;
                    continue;
                }
                while (end < input_string.size() && isdigit(input_string[end]))
                {
                    ++end;
                }
                output_vector.push_back(std::stoi(input_string.substr(start, end - start)));
                start = end;
            }
        }

        // str_to_vector<char>
        else if (std::is_same<T, char>::value)
        {
            // check the type of quote used to enclose the element in the input string
            char quote = input_string.find('\'') == std::string::npos ? '\"' : '\'';

            int pos = 0;
            pos = input_string.find(quote, 0);
            while (pos != std::string::npos)
            {
                output_vector.push_back(input_string[pos + 1]);

                pos = input_string.find(quote, pos + 1);
                pos = input_string.find(quote, pos + 1); // find every other quote 
            }
        }

        return output_vector;
    }

    template<class T>
    std::string vector_to_str(std::vector<T> input_vector)
    {
        std::string output_str;

        output_str.append("[");
        for (size_t i = 0; i < input_vector.size(); ++i)
        {
            output_str.append(std::to_string(input_vector.at(i)));
            if (i != input_vector.size() - 1)
                output_str.append(", ");
        }
        output_str.append("]");

        return output_str;
    }

} // namespace test_utils