#include <iostream>
#include <vector>

struct S {
int m_x; 
int m_y; 
S(): m_x{0}, m_y{0}{std::cout<<"S() called: \n";}
S(const S& s): m_x{s.m_x}, m_y{s.m_y}{std::cout<<"S(const S& s) called: \n";}
S(int x, int y): m_x(x), m_y(y){std::cout<<"S(int x, int y) called: \n";}
friend std::ostream& operator<<(std::ostream& out, const S& s){
	out<<"m_x " <<s.m_x<< " m_y " <<s.m_y;
	return out;
}
};

int main(){
	S s1;
	std::cout<<"s1: "<<s1<<"\n\n";	
	S s2(s1);
	std::cout<<"s2: "<<s2<<"\n\n";	
	S s3(2,7);
	std::cout<<"s3: "<<s3<<"\n\n";
	S s4{s3};
	std::cout<<"s4: "<<s4<<"\n\n";
	S s5{3,9};
	std::cout<<"s5: "<<s5<<"\n\n";
	
	return 0;
}


