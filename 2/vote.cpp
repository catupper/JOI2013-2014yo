#include<iostream>
#include<algorithm>

using namespace std;
int a[1050], cnt[1050], n, m, b;
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int j = 0;j < m;j++){
	cin >> b;
	for(int i = 0;i < n;i++){
	    if(a[i] <= b){
		cnt[i]++;
		break;
	    }
	}
    }
    cout << max_element(cnt, cnt + n) - cnt + 1 << endl;
    return 0;
}
