#include <iostream>
#include <vector>

struct S {
int m_x; 
int m_y; 
S(): m_x{0}, m_y{0}{std::cout<<"S() called: \n";}
S(const S& s): m_x{s.m_x}, m_y{s.m_y}{std::cout<<"Copy constructor called: \n";}
S(int x, int y): m_x(x), m_y(y){std::cout<<"S(int x, int y) called: \n";}
friend std::ostream& operator<<(std::ostream& out, const S& s){
	out<<"m_x " <<s.m_x<< " m_y " <<s.m_y;
	return out;
}
};
int main(){
    std::vector<S> vectOfS{{2,3}, {}, {4,5}, {7,8}, {1,2}};
    std::cout<<"before vectOfS.push_back({17,6});\n";
    vectOfS.push_back({17,6}); 
    S* s_ptr{nullptr};
    s_ptr = new S(-1,-2);
    std::cout<<" *s_ptr "<<*s_ptr<<'\n';
    std::cout<<"before vectOfS.push_back(*s_ptr);  \n";
    vectOfS.push_back(*s_ptr);
    std::cout<<"after vectOfS.push_back(*s_ptr);  \n";
    for (auto itL{vectOfS.begin()}; itL<vectOfS.end();++itL) std::cout<<"itL is now pointing to: "<<*itL<<'\n';
    delete s_ptr;
    std::cout<<"after s_ptr is deleted, : "<< *s_ptr << " it points at garbage \n";
    for (auto itL{vectOfS.begin()}; itL<vectOfS.end();++itL) std::cout<<"itL is now pointing to: "<<*itL<<'\n';
    std::cout<<"as shown, the contents of the vector are not affected by the delete in line 26.";
    return 0;
}