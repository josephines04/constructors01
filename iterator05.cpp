#include <iostream>
#include <vector>

struct S {
int m_x; 
int m_y; 
S(): m_x{0}, m_y{0}{std::cout<<"S() called \n";}
S(const S& s): m_x{s.m_x}, m_y{s.m_y}{std::cout<<"Copy constructor called \n";}
S(int x, int y): m_x(x), m_y(y){std::cout<<"S(int x, int y) called \n";}

friend std::ostream& operator<<(std::ostream& out, const S& s){
	out<<"m_x " <<s.m_x<< " m_y " <<s.m_y;
	return out;
}
};

int main(){
    std::vector<S> vectOfS{{2,3}, {}, {4,5}, {7,8}, {1,2}};
    std::cout<<"\n\n";
    for (auto itL{vectOfS.begin()}; itL<vectOfS.end();++itL) std::cout<<"itL is pointing on "<<*itL<<'\n';
    for (auto el: vectOfS)std::cout<<"The element: " <<el<<'\n';
    return 0;
}