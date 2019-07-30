#include<iostream>
#include<unordered_map>


int main(){
    std::tr1::unordered_map<int,int> dict;
    dict[233] = 23333;
    dict[244] = 24444;
    std::cout<<dict[233]<<dict[244]<<std::endl;
    system("PAUSE");
    return 0;
}