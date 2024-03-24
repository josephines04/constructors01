#include <iostream>
#include <vector>

struct S {
int m_x; 
int m_y;
friend std::ostream& operator<<(std::ostream& out, const S& s){
	out<<"m_x " <<s.m_x<< " m_y " <<s.m_y;
	return out;
}
};

int main(){
    std::vector<S> vectOfS{{2,3}, {}, {4,5}, {7,8}, {1,2}};
    
    std::vector<S>::iterator iterS{&vectOfS[0]};
    std::cout<<"*iterS "<<*iterS<<'\n';
    iterS++; 
    iterS++;
    std::cout<<"iterS++; iterS++; iterS "<<*iterS<<'\n';
    iterS+=2;
    std::cout<<"iterS+=2: "<<*iterS<<'\n';
    
    std::vector<S>:: iterator iterS_end{vectOfS.end()};
    iterS_end=iterS;

    std::vector<S>::iterator it{vectOfS.begin()};
    std::cout<<" To get m_x from (*it).m_x: "<<(*it).m_x<<" and m_y from (*it).m_y: "<<(*it).m_y<<'\n';
    std::advance(it, 2);
    std::cout<<"The iterator has been advanced by 2 positions, and is now pointing at: "<<*it<<'\n';

    std::cout<<"there is a distance of " <<std::distance(vectOfS.begin(), vectOfS.end())<< " elements in the vector "<<'\n';
    std::cout<<"there is a size of "<<vectOfS.size()<< " elements in the vector "<<'\n';
    
    return 0;

}