#include<iostream>  
#include<algorithm>  
#include<cmath>  
#include<cstdio>  
using namespace std;  
int n,i,fg;  
char a[22];  
void dfs(int idx,int ret)
{  
    if(idx==n){  
            if(ret==0){  
	              fg=1;  
			      printf("1");  
				  for(i=1;i<=n-1;i++)  
					printf("%c%d",a[i],i+1);  
				  puts("");  
				  } 
			 return;
			 }  
			 a[idx]='+';  
			 dfs(idx+1,ret+idx+1);  										             
			 a[idx]='-';  
			 dfs(idx+1,ret-(idx+1));  
}
int main(){  
    while(scanf("%d",&n)==1){  
	        fg=0;  
			dfs(1,1);  
			if(!fg)  
				printf("None\n");  
	} 
	return 0;  
} 
