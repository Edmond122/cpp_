#include <iostream>
#include <string>
#include<vector>

bool is_prime(long long t)
{
    if (t < 2){
	    return false;
    }
    if (t <= 3){
	    return true;
    }
    if (t % 2 == 0 || t % 3 == 0)
    {
	    return false;
    }
    long long i = 5;
    while (i * i <= t)    
    {
        if (t % i == 0)
        {
            return false;
        }
	i += 1;
    }
    return true;
}

int main()
{
    long long number;
    while(std::cin >> number)
    {
        if(false == is_prime(number))
	{
		std::cout << number << " is a prime: False\n";
	}
	else
	{
		std::cout << number << " is a prime: True\n";
	}
    }
    return 0;
}
