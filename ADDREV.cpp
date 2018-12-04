#include<bits/stdc++.h>
using namespace std;

int t;
unsigned long long int res,a,b,tmp;
string s1,s2;
int str1,str2;
int c,i,zc;
int mn,mx;

int min(int a, int b) {
	return a<b?a:b;
}

int max(int a, int b) {
	return a>b?a:b;
}

int main() {
	cin>>t;
	while(t--) {
		zc=0;
		str1=0;str2=0;
		cin>>s1>>s2;
		mn=min(s1.length(),s2.length());
		mx=max(s1.length(),s2.length());
		c=0;
		res=0;
		for(i=0;i<mn;i++) {
			int curr = (s1[i]-'0'+s2[i]-'0'+c);
			if(curr>9) {
				curr-=10;
				c=1;
			} else {
				c=0;
			}
			res*=10;
			res+=curr;
			if(curr==0&&c==0) {
				zc++;
			} else {
				zc=0;
			}
		}
		if(s1.length()>s2.length()) {
			for(i=s2.length();i<s1.length();i++) {
				int curr = (s1[i]-'0'+c);
				if(curr>9) {
					curr-=10;
					c=1;
				} else {
					c=0;
				}
				res*=10;
				res+=curr;
				if(curr==0&&c==0) {
					zc++;
				} else {
					zc=0;
				}
			}
		} else {
			for(i=s1.length();i<s2.length();i++) {
				int curr = (s2[i]-'0'+c);
				if(curr>9) {
					curr-=10;
					c=1;
				} else {
					c=0;
				}
				res*=10;
				res+=curr;
				if(curr==0&&c==0) {
					zc++;
				} else {
					zc=0;
				}
			}
		}
		if(c!=0) {
			res*=10;
			res+=c;
			c=0;
			zc=0;
		}
		tmp=1;
		while(zc--) {
			tmp*=10;
		}
		res/=tmp;
		cout<<res<<endl;
	}
	return 0;
}