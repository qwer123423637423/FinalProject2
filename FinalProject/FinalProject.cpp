#include <iostream>

int count(int a, int b) 
{
    long answer = a + b;
    return answer;
}

int main()
{
    std::cout << count(5, 10);
}
