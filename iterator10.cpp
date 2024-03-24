#include<iostream>
#include<vector>
#include<algorithm>
struct S{
    int m_x;
    int m_y;
    friend std::ostream& operator<<(std::ostream& out, const S& s){
        out<<"m_x "<<s.m_x<<" m_y "<<s.m_y;
        return out;
    }
};
bool xIsOne(const S& s){return s.m_x==1;}
int main()
{   
    std::cout<<"std::count_if()\n";
    std::vector<S> vectOfS{{2,3},{1,2},{3,4},{4,5},{5,5},{2,2}};

    auto numOfElements{0};
    auto xIsTwo{[](const S& s){return s.m_x==2;}};
    S s{2,2};
    if(xIsTwo(s))std::cout<<"x is two\n";

    //numOfElements=std::count_if(vectOfS.begin(),vectOfS.end(),xIsTwo);
    //numOfElements=std::count_if(std::next(vectOfS.begin()),vectOfS.end(),xIsTwo);
    std::vector<S>::iterator it{vectOfS.begin()};
    ++it;
    ++it;
    it+=2;
    numOfElements=std::count_if(it,vectOfS.end(),xIsTwo);
    std::cout<<"x == 2: "<<numOfElements<<'\n';
    
    auto howOftenIsFunctionCalled{0u};
    auto xANDyAreEqual{[&howOftenIsFunctionCalled](const S/*&*/ s){ ++howOftenIsFunctionCalled; return s.m_x==s.m_y;}};
    numOfElements=std::count_if(vectOfS.begin(),vectOfS.end(),xANDyAreEqual);
    std::cout<<"x == y: "<<numOfElements<<" the functon xANDyAreEqual was "<<howOftenIsFunctionCalled<<" times called\n";
    
    std::cout<<"y-x = 1: "<<std::count_if(vectOfS.begin(),vectOfS.end(), [](const S& s) { return s.m_y-s.m_x==1;  }   )<<'\n';
    std::cout<<"x == 1: "<<std::count_if(vectOfS.begin(),vectOfS.end(), xIsOne)<<'\n';


    return 0;
} 