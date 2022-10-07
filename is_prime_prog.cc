#include <iostream>
#include <string>
#include<vector>

void is_prime(int T)
{
    if (T == 1 || T == 0)
    {
        std::cout << T << " is a prime: False" << std::endl;
        return;
    }
    auto i = 2;
    while (i <= T / 2)    
    {
        if (T % i == 0)
        {
            std::cout << T << " is a prime: False" << std::endl;
            return;
        }
	i++;
    }
    std::cout << T << " is a prime: True" << std::endl;
    return;
}

int main()
{
    std::vector<int> arr;
    std::string line;
    std::getline(std::cin, line);
    std::string tmp = "";
    for (long unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            tmp += line[i];
        }
        if (line[i + 1] == ' ' || line[i + 1] == '\0')
        {
            arr.push_back(std::stoi(tmp));
            tmp = "";
        }
    }
    for (long unsigned int i = 0; i < arr.size(); i++)
    {
        is_prime(arr[i]);
    }
    return 0;
}
