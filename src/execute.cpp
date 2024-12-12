#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

//finds a split location with given operator, i.e.  the second '+' in  (3+4) + (8*3^4), returns -1 if none possible
int findSplit(std::vector<char> &operators, char op)
{
    int lengthOfOperators = std::size(operators);
    int parenthesesLayers = 0;
    for (int i = 0; i < lengthOfOperators; i++)
    {
        if (operators[i] == '(')
        {
            parenthesesLayers++;
        }
        else if (operators[i] == ')')
        {
            parenthesesLayers--;
        }
        else if (operators[i] == op && parenthesesLayers == 0)
        {
            return i;
        }
    }
    return -1;
}

//determines if the entire expression is surrounded by parentheses
bool parenthesesSurround(std::vector<char> &operators)
{
    int lengthOfOperators = std::size(operators);
    if (lengthOfOperators < 2)
    {
        return false;
    }
    int parenthesesLayers = 0;
    for (int i = 0; i < lengthOfOperators - 1; i++)
    {
        if (operators[i] == '(')
        {
            parenthesesLayers++;
        }
        else if (operators[i] == ')')
        {
            parenthesesLayers--;

        }
        if (parenthesesLayers == 0)
        {
            return false;
        }
    }
    return true;
}

//since for expression with parenthesis, operators do not always separate values, this finds where the value is given the operator index
int valueIndexFromOperatorIndex(int opIndex, std::vector<int> &values, std::vector<char> &operators)
{
    int valueIndex = 0;
    for (int i = 0; i < opIndex; i++)
    {
        if (operators[i] != '(' && operators[i] != ')')
        {
            valueIndex++;
        }
    }
    return valueIndex;
}



int execute(std::vector<int> &values, std::vector<char> &operators)
{
    int lengthOfOperators = std::size(operators);
    int lengthOfValues = std::size(values);

    if (lengthOfValues == 1)
    {
        return values[0];
    }

    if (parenthesesSurround(operators))
    {
        auto i = operators.begin() + 1;
        auto j = operators.end() - 2;
        auto nextOperators = std::vector<char>(operators.begin() + 1, operators.end() - 1);
        return execute(values , nextOperators);
    }


    char reversePemdas[] = {'+', '-', '*', '/', '^'};

    for (int i = 0; i < std::size(reversePemdas); i++ )
    {
        int split = findSplit(operators, reversePemdas[i]);

        if (split != -1)
        {
            int valueSplitConversion = valueIndexFromOperatorIndex(split, values, operators);
            auto prevValues = std::vector<int>(values.begin() , values.begin() + valueSplitConversion + 1);
            auto prevOperators = std::vector<char>(operators.begin() , operators.begin() + split);

            auto nextValues = std::vector<int>(values.begin() + valueSplitConversion + 1, values.end());
            auto nextOperators = std::vector<char>(operators.begin() + split + 1, operators.end());


            switch (i)
            {
                case 0:
                    return execute(prevValues,prevOperators) + execute(nextValues,nextOperators);
                case 1:
                    return execute(prevValues,prevOperators) - execute(nextValues,nextOperators);
                case 2:
                    return execute(prevValues,prevOperators) * execute(nextValues,nextOperators);
                case 3:
                    return execute(prevValues,prevOperators) / execute(nextValues,nextOperators);
                case 4:
                    return  pow(execute(prevValues,prevOperators), execute(nextValues,nextOperators)) ;
            }
        }
    }




    return 0;
}



/*
int main()
{
    std::vector<int> values({10,5,2});
    std::vector<char> operators({'*','/'});

    printf("%d",execute(values, operators));
}

 */