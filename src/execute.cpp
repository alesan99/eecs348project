#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>

//basics w/ multiplication only, not yet implemented w/ Aidan B's Operators
int execute(std::vector<int> &values, std::vector<char> &operators)
{
    int lengthOfOperators = std::size(operators);
    int lengthOfValues = lengthOfOperators + 1;
    auto multiplication = find(operators.begin(), operators.end(), '*');


    //this will be generalized to all operators Soon(tm)
    if (multiplication == operators.begin())
    {
        if (values.size() == 2)
        {
            return values[0] * values[1];
        }
        else
        {

            auto nextValues = std::vector<int>(values.begin() + 1, values.end());
            auto nextOperators = std::vector<char>(operators.begin() + 1, operators.end());

            return values[0] * execute(nextValues, nextOperators);
        }
    }
    else
    {
        auto prevValues = std::vector<int>(values.begin() , values.begin() + (multiplication - operators.begin() - 1) );
        auto prevOperators = std::vector<char>(operators.begin() , multiplication - 1);

        auto nextValues = std::vector<int>(values.begin() + (multiplication - operators.begin() + 1), values.end());
        auto nextOperators = std::vector<char>(multiplication + 1, operators.end());

        return execute(prevValues,prevOperators) * execute(nextValues, nextOperators);
    }

    return 0;
}






/*
int main()
{
    std::vector<int> values({4, 2, 3});
    std::vector<char> operators({'*','*'});

    printf("%d",execute(values, operators));
}
*/
