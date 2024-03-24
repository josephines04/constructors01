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
    std::cout<<"std::find_if()\n";
    std::vector<S> vectOfS{{2,3},{1,2},{3,4},{4,5},{1,5},{2,2}};
    std::vector<S>::iterator it {std::find_if(vectOfS.begin(), vectOfS.end(),[](const S& s){return s.m_x==1;}   )};
    std::cout<<*it<<'\n';

   
    std::vector<S>::iterator it2 {std::find_if(std::next(it), vectOfS.end(),[](const S& s){return s.m_x==1;}   )};
    std::cout<<*it2<<'\n';
    return 0;
} 
