#include <iostream>
#include <vector>
#include <algorithm>
struct S {
int m_x; 
int m_y; 
};

int main()
{
    std::vector<S> vectOfS{{2,3}, {}, {4,5}, {7,8}, {1,2}};

    auto numOfElements{0};
    auto xIsTwo{[](const S& s){return s.m_x ==2;}};
    numOfElements = std::count_if(vectOfS.begin(), vectOfS.end(), xIsTwo);
    
    std::cout<<"xIsTwo: "<<numOfElements<<'\n';
    auto xANDyAreEqual{[] (const S /*&*/s){return s.m_x == s.m_y;}};
    numOfElements = std::count_if(vectOfS.begin(), vectOfS.end(), xANDyAreEqual);
    std::cout<<"xANDyAreEqual "<<numOfElements<<'\n';

    std::cout<<"y = x-1: "<<
    std::count_if(vectOfS.begin(), vectOfS.end(), [](const S& s){return s.m_y -s.m_x==1;}) <<'\n';
    return 0;
}