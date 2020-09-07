#include<bits/stdc++.h>
using namespace std;
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
void reverserec(string &s,int st){
	if(s=="\0" || st== s.size()){
		return;
	}
	reverserec(s,st+1);
	cout<<s[st];
}
bool isplaindrome(string &s,int st,int end){
	while(st>=end){
		return true;
	}
	return (s[st]==s[end]) and isplaindrome(s,st+1,end-1);
}
// lader problem
int ladder1(int n){
	if(n<0)return 0;
	if(n==0)return 1;
	int ans=0;
	return ans+ladder1(n-1)+ladder1(n-2)+ladder1(n-3);
}
int lad_mod(int i,int n){
	if(i>n){
		return 0;
	}
	if(i==n){
		return 1;
	}
	return lad_mod(i+1,n)+lad_mod(i+2,n);
}
int ladder2(int n){
	return lad_mod(0,n);
}
//tribonacci
int add(int n,int f,int s,int t){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        int sum=f+s+t;
        if(n==3)return sum;
        return add(n-1,s,t,sum);
    }
int tribonacci(int n) {
    return add(n,0,1,1);
}
// Friends pairing problem
int bike(int n){
	if(n==0)return 0;
	if(n==1)return 1;
	if(n==2)return 2;
	return 1*bike(n-1)+2*bike(n-2);
}
//TOH
void TOH(int n,char src,char helper,char des){
	//Base case
	if(n==0)return;
	//1.Move the first plate from src to helper and reduce n-1
	TOH(n-1,src,des,helper);
	//2. now from src to des last one 
	cout<<"Shift "<<n<<" from "<<src<<" to "<<des<<endl;
	//3. now move n-1 plates from helper to a and then to c
	TOH(n-1,helper,src,des);
}
void insert(vector<int>&v,int temp){
	if(v.size()==0 || v[v.size()-1]<=temp){
		v.push_back(temp);
		return;
	}
	int val=v[v.size()-1];
	insert(v,temp);
	v.push_back(val);
	return;
}

void sort(vector<int>&v){
	if(v.size()==1)return;
	int last=v[v.size()-1];
	v.pop_back();
	sort(v);
	insert(v,last);
	return ;
} 
int main(){
	OJ; int n;cin>>n;
	// string s;
	// cin>>s;
	//reverserec(s,0);
	//cout<<isplaindrome(s,0,s.size()-1);
	// int n;cin>>n;
	// cout<<f(n);
	//cout<<tribonacci(37);
	// cout<<ladder2(4);
	// cout<<bike(n);
	//TOH(n,'A','B','C');
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a);
	for(auto x:a){
		cout<<x<<" ";
	}
}
