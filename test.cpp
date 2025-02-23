#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0; i<10; i++){
        float a;
        srand(time(0));
        a = static_cast<float>(rand())/RAND_MAX;
    cout<<a<<"__"<<endl;
    cout<<a*30<<endl;
    // cout<<time(0)<<endl;
    }
}