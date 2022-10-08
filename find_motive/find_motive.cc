#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 5)
	{
		return 1;
	}
    std::ifstream input_text;
    input_text.open(argv[1]);
    if (input_text.fail())
    {
	    std::cout << "The file" << " "  << argv[1] << " could not be opened.\n";
        return 1;
    }
    std::string str;
    int count = 0;
    count++;
    while(input_text >> str)
    {
        if (std::string::npos != str.find(argv[2]))
        {
            count += 1;
        }
    }
    std::cout << "The file " << argv[1] << " " << "contains " << count - 1 << " words containing the motive " << argv[2] << "\n";
    return 0;
}
