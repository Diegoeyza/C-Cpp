#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(std::vector<int>& num, std::vector<std::vector<int>>& matriz){
    std::vector<int> options={num[0]};
    bool condition=false;
    int row=1;
    int column=1;
    for (long unsigned int i=0; i<matriz[0].size();i++){
        row=1;
        for (std::vector<int> i: matriz){
            column=1;
            for (int j:i){
                for (int op:options){
                    //cout<<"row and op="<<row<<" "<<op<<" j="<<j<<" count= "<<(count(options.begin(), options.end(), row)==0)<<endl;
                    if ((row==op && column==num[1])&&j==1) return true;
                    else if (row==op && j==1 && count(options.begin(), options.end(), column)==0) options.push_back(column);
                }
                column++;
            }
            row++;
        }
        //std::cout<<"size:\n->"<<options.size()<<std::endl;
    }
    return condition;
}

int main(){
    std::vector<std::vector<int>> matriz={
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}
        };
    for ( auto i: matriz) {for ( auto j: i){std::cout << j << ' ';}std::cout<<std::endl;}
    std::cout<<std::endl;
    std::vector<int> tup={4,3};
    std::cout<<check(tup,matriz)<<std::endl;

}