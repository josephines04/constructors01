#include <iostream>
#include <vector>

struct S {
int m_x; 
int m_y; 
S(): m_x{0}, m_y{0}{std::cout<<"S() called: \n";}
S(const S& s): m_x{s.m_x}, m_y{s.m_y}{std::cout<<"Copy constructor called: \n";}
S(int x, int y): m_x(x), m_y(y){std::cout<<"S(int x, int y) called: \n";}


S& operator=(const S& s){
    std::cout<<"Assignment operator called \n";
    return *this;
}

friend std::ostream& operator<<(std::ostream& out, const S& s){
	out<<"m_x " <<s.m_x<< " m_y " <<s.m_y;
	return out;
}
};

int main(){
    std::cout<<"S s1: {9,8}, s2;\n ";
    S s1{9,8}, s2;
    s2 = s1;
    return 0;
}
