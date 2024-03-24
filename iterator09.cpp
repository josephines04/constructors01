#include<iostream>
#include<vector>

struct S{
    int m_x;
    int m_y;
    S():m_x{0},m_y{0}{std::cout<<"S() called \n";}
    S(const S& s):m_x{s.m_x},m_y{s.m_y}{std::cout<<"Copy constructor called\n";}
    S(int x, int y):m_x{x},m_y{y}{std::cout<<"S(int x, int y) called: \n";}
    friend std::ostream& operator<<(std::ostream& out, const S& s){
        out<<"m_x "<<s.m_x<<" m_y "<<s.m_y;
        return out;
    }
};
int main()
{   
    std::vector<S> vectOfS_A{{2,3},{4,5},{1,2}};
    std::cout<<"before vectOfS_A.push_back({7,6});\n";
    vectOfS_A.push_back({7,6});
    std::cout<<"after vectOfS_A.push_back({7,6});\n";
   
    std::cout<<"before vectOfS_A.push_back({7,9});\n";
    vectOfS_A.push_back({7,9});
    std::cout<<"after vectOfS_A.push_back({7,9});\n";
    
    std::cout<<"\n\n";
    std::vector<S> vectOfS_B;
    std::cout<<"before vectOfS_B.resize(10);\n";
    vectOfS_B.resize(10);
    std::cout<<"after vectOfS_B.resize(10);\n";
    vectOfS_B[0]={2,3};
    vectOfS_B[1]={4,5};
    vectOfS_B[2]={1,2};
    for(auto a{0u};a<10;++a)std::cout<<vectOfS_B[a]<<'\n';
    std::cout<<"before vectOfS_B.push_back({7,6});\n";
    vectOfS_B.push_back({7,6});
    std::cout<<"after vectOfS_B.push_back({7,6});\n";
 
    std::cout<<"before vectOfS_B.resize(20);\n";
    vectOfS_B.resize(20);
    std::cout<<"after vectOfS_B.resize(20);\n";
    
    std::cout<<"before vectOfS_C.resize(20);\n";
    std::vector<S>vectOfS_C(20);
    std::cout<<"after vectOfS_B.resize(20);\n";
     
    return 0;
} 
