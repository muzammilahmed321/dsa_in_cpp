#include <iostream>
using namespace std;
int main(){
int n, m;
cin>>n>>m;
int sum = 0;
for(int i = 0; i < n; i++){
int apple;
cin>>apple;
sum+=apple;
}
int baskets=(sum + m - 1)/m;
cout<<baskets;
return 0;
}

