#include<iostream>
#include<algorithm>

using namespace std;

int num(char c){
    if(c == 'J')return 0;
    if(c == 'O')return 1;
    if(c == 'I')return 2;
}

int dp[1050][8];

int main(){
    int n;
    char c;
    cin >> n;
    dp[0][1] = 1;
    for(int i = 1;i <= n;i++){
	cin >> c;
	int ad = num(c);
	for(int j = 0;j < 8;j++){
	    if((j & (1 << ad)) == 0)continue;
	    for(int k = 0;k < 8;k++){
		if((j & k) == 0)continue;
		dp[i][j] += dp[i - 1][k];
	    }
	    dp[i][j] %= 10007;
	}
    }
    int res = 0;
    for(int i = 0;i < 8;i++){
	res += dp[n][i];
	res %= 10007;
    }
    cout << res << endl;
    return 0;
}
