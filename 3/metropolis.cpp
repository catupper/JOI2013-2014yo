#include<iostream>
#include<algorithm>

using namespace std;
int n, w, h, x, y;
int dist(int x1, int y1, int x2, int y2){
    int res = 0;
    if(x1 < x2 && y1 < y2){
	res += min(x2 - x1, y2 - y1);
	x1 += res;
	y1 += res;
    }
    res += abs(x2 - x1) + abs(y2 - y1);
    return res;
}

int main(){
    cin >> w >> h >> n;
    int nowx, nowy;
    long long res = 0;
    cin >> nowx >> nowy;
    for(int i = 1;i < n;i++){
	cin >> x >> y;
	res += min(dist(nowx, nowy, x, y), dist(x, y, nowx, nowy));
	nowx = x;
	nowy = y;
    }
    cout << res << endl;
    return 0;
}
