#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define ll long long
#define MOD 1000000007
using namespace std;

ll n;

//nCr=n-1Cr-1+n-1Cr
ll comb[1600][1600]; //comb[x][y]: x->전체 자리수, y->5의 개수

//15의 배수: 일의 자리는 0 또는 5, 각 자리수 합이 3의 배수

void combination(){ //1과 5로 만들 수 있는 n자리수의 개수
	
	comb[0][0]=1;
	comb[1][0]=1;
	comb[1][1]=1;
	
	for(ll i=2;i<=n;i++){
		comb[i][0]=1;
		comb[i][i]=1;
	}
	
	for(ll i=2;i<=n;i++){ //자리수
		for(ll j=1;j<=n;j++){ //5의 개수
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
			//cout<<"comb["<<i<<"]"<<"["<<j<<"]: "<<comb[i][j]<<endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n;
	
	//n=10;
	
	combination();
	
	ll cnt=0;
	
	//cout<<comb[2][1];
	
	for(ll i=0;i<n;i++){ //5의 개수
		if((n-i-1+5*i+5)%3==0){ //일의 자리는 5로 고정->따로 5 더해줌
			
			cnt+=comb[n-1][i]; //일의 자리는 5로 고정했기 때문에 n-1자리수에서 찾음
		}
	}
	
	cout<<cnt%MOD; 
}
