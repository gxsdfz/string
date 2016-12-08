#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
char s[30005];
bool flag[300];
int main(){
    int n;
    cin>>n;getchar();
    while(n--){
        cin.getline(s,30000);
        for(int i=0;i<256;i++)flag[i]=false;
        int i=0,j=0,len=strlen(s),ans=1;
        //printf("len:%d\n",len);
        if(len<=1){
            printf("%d\n",len);
            continue;
        }
        int x;flag[(int)s[0]]=true;
        for(j=1;j<len;j++){
            x=(int)s[j];
            if(flag[x]){
                ans=max(ans,j-i);
                while(s[i]!=s[j]){
                    flag[(int)s[i]]=false;
                    i++;
                }
                i++;
            }
            else flag[x]=true;
        }
        ans=max(ans,j-i);
        printf("%d\n",ans);
    }
    return 0;
}
