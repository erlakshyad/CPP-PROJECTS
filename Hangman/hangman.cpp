#include <iostream>
#include "hangman"

using namespace std;

int main()
{
    

    // Set text color to red
    std::cout << "\033[31m HINT:\033[0m" << std::endl;

    // Set text color to green
    std::cout << "\033[32m MONTH\033[0m" << std::endl;

    // Set text color to blue and bold
    std::cout << "\033[1;34m MAX 10 Letters\033[0m" << std::endl;

    hangman();
    getchar();
    return 0;
}


