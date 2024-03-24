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
int main()
{   
    std::vector<S> vectOfS{{1,5},{2,3},{3,4},{4,5},{5,4},{4,7},{7,2},{1,6},{3,1},{9,9},{5,1}};
    //std::vector<S>::iterator it; only one iterator
    std::vector< std::vector<S>::iterator > vectOfIter; //vector of iterators
    auto it{vectOfS.begin()}; 
    while(true){
        //std::find_if returns an iterator if condition is true, otherwise it returns iterator vectofS.end()
        
        it=std::find_if(it,vectOfS.end(), [](const S& s) { return s.m_y>s.m_x;  }   ) ;
        if(it==vectOfS.end())break;
        vectOfIter.push_back(it);
        ++it;
    }
    for(auto it:vectOfIter)std::cout<<*it<<'\n';
    return 0;
} 
