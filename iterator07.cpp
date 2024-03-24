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

class Vect_S_ptrs{
    std::vector<S*> vectorOfSptr;
    public:
        Vect_S_ptrs(){std::cout<<"Vect_S_ptrs() called \n";}
        void addElement(S* s){vectorOfSptr.push_back(s);}
        void showCont(){for (auto itL{vectorOfSptr.begin()}; itL<vectorOfSptr.end();++itL)std::cout<<*itL<<'\n';}
        ~Vect_S_ptrs(){
            std::cout<<"Delete in destructor. ";
            for (auto itL{vectorOfSptr.begin()}; itL<vectorOfSptr.end();++itL) delete *itL;
            std::cout<<" ~Vect_S_ptrs() called \n";
        }
};

int main()
{
    std::vector<S*> vectorOfSptr{new S(1,2), new S(3,4), new S(5,6)};
    for (auto itL{vectorOfSptr.begin()}; itL<vectorOfSptr.end();++itL) std::cout<<"Address of *itL: " <<*itL<<"Contents of **itL: "<<**itL<<'\n';
    std::cout<<"Don't forget to delete \n";
    for (auto itL{vectorOfSptr.begin()}; itL<vectorOfSptr.end();++itL)delete *itL;
    
    Vect_S_ptrs vSp;
    vSp.addElement(new S(1,2));
    vSp.addElement(new S(3,4));
    vSp.addElement(new S(5,6));
    vSp.showCont();
    return 0;
}