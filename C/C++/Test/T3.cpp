#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
    int dist_buses[4]= {470,480,8200,8820};
    float C,Q,S,total,totalsq;
    totalsq=0;
    total=0;
    for (int i=0; i<4;i++) {
        if (i==3) {totalsq+=pow((dist_buses[i]-dist_buses[0]-10000),2); total+=(dist_buses[i]-dist_buses[0]-10000);}
        else{ totalsq+=pow((dist_buses[i]-dist_buses[i+1]),2); total+=(dist_buses[i]-dist_buses[i+1]);}
    }
    cout<<totalsq<<endl;   //630...
    cout<<total<<endl;     //
    Q= abs((totalsq)/4);
    S= abs(total/4);
    C=abs(sqrt(Q-(S*S))/S);
    cout<<C<<endl;
    return 0;
}
