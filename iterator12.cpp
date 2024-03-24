#include <iostream>
#include <vector>
#include<algorithm>

struct S{
int m_x;
int m_y;

friend std::ostream& operator<<(std::ostream& out,S& s) {
    out<<"m_x: " <<s.m_x<< "m_y: " <<s.m_y;
    return out;
}
};

int main(){
    std::vector<S> vectOfS{{1,2}, {3,4},{7,3},{8,8},{4,5},{7,1},{5,6},{6,7},{8,9},{9,0}};
    //std::vector<S>::iterator it;
    std::vector<std::vector<S>::iterator> vectOfIt;
    auto it{vectOfS.begin()};
    while (true){
    it=std::find_if(it, vectOfS.end(), [](const S& s){return s.m_y<s.m_x;});
    if (it==vectOfS.end()) break;
    vectOfIt.push_back(it);
    ++it;
    }
    for (auto it:vectOfIt) {
        std::cout<<*it<<'\n';
        auto temp{(*it).m_x};
        (*it).m_x = (*it).m_y;
        (*it).m_y = temp;
    }
    std::cout<<"\n\n";
    for (auto el: vectOfS) std::cout<<el<<'\n';
    return 0;
}
