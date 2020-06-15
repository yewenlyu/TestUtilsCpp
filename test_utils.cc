#include "test_utils.h"

#include <ctype.h>

namespace test_utils
{
    template <class T>
    std::vector<T> str_to_vector(std::string input_string, char t)
    {
        std::vector<T> output_vector;

        switch (t)
        {
        // str_to_vector<int>
        case 'i':
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
            break;

        }

        return output_vector;
    }
} // namespace test_utils