#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int x = 0, tmp;
    for(int i = 0;i < 5;i++){
	cin >> tmp;
	x += max(40, tmp);
    }
    cout << x / 5 << endl;
    return 0;
}
