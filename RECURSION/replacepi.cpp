#include<iostream>
using namespace std;
void replacepi(char s[],int i){
    if(s[i]=='\0' and s[i+1]=='\0'){
        return;
    }
    if(s[i]=='p' and s[i+1]=='i'){
        int j=i+2;
        while(s[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            s[j+2]=s[j];
            j--;
        }
        s[i]='3';
        s[i+1]='.';
        s[i+2]='1';
        s[i+3]='4';
        replacepi(s,i+4);
    }
    else{
        replacepi(s,i+1);
    }
    return;
}
int main(){
    char s[1000];
    cin>>s;
    replacepi(s,0);
    cout<<s;
}