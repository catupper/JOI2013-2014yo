#include<iostream>
#include<algorithm>

using namespace std;

int dp[15][5040][5040];
bool done[15];
int num1[15], num2[15], num[15];
int a[105], d[105], n;
int solve(int x){
    for(int i = 0;i < 14;i++){
	num[i] = (i >= 7);
    }int ans = 0;
    int tt = 0;
    do{
	int res = 0;
	int p = 0, q = 0, t;
	for(int i = 0;i < 14;i++)done[i] = false;
	for(int i = 0;i < 14;i++){
	    if(i == 0){
		t = num1[p] + x;
		p++;
	    }
	    else{
		t = num2[q] + x + 7;
		q++;
	    }
	    done[t] = true;
	    if(t >= n)continue;
	    for(int j = max(x, t - d[t]);j <= min(n - 1, min(x + 13, t + d[t]));j++){
		if(done[j])continue;
		res += a[t];
	    }
	}
	ans = max(ans, res);
    }while(next_permutation(num, num + 14));
    return ans;
}

int main(){
    int ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)cin >> d[i];
    for(int j = 0;j < n;j++)cin >> a[j];
    for(int k = 0;k < n / 7 - !(n%7);k++){
	int p = 0;
	for(int i = 0;i < 7;i++)num1[i] = i;
	do{
	    for(int i = 0;i < 7;i++)num2[i] = i;
	    int q = 0;
	    int res = 0;
	    if(k)
		for(int i = 0;i < 5040;i++)res = max(res, dp[k - 1][i][p]);
	    do{
		dp[k][p][q] = res + solve(7 * k);
		ans = max(ans, dp[k][p][q]);
		q++;
	    }while(next_permutation(num2, num2 + 7));
	    p++;
	cout << p << endl;
	}while(next_permutation(num1, num1 + 7));
    }
    cout << ans << endl;
    
    return 0;
}
