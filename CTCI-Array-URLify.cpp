#include <bits/stdc++.h>
using namespace std;

char* URLify(char* str1, int len){
    int spaceCount = 0;
    for(int i = 0;i<len;i++){
        spaceCount+=(str1[i]==' ');
    }
    int index = len + (2 * spaceCount);
    if(len<strlen(str1)) str1[len] = '\0';
    for(int i = len-1;i>=0;i--){
        //cout<<str1[i];
        if(str1[i] == ' '){
            str1[index-1] = '0';
            str1[index-2] = '2';
            str1[index-3] = '%';
            index = index - 3;
        }else{
            str1[index-1] = str1[i];
            index--;
            
            
        }
    }
    return str1;
    
}

int main() {
	char str1[100] = "cat dog  ";
	int len;
	cin>>len;
	char* res = URLify(str1,len);
    int i = 0;
	while(*(res+i)!='\0'){
	    cout<<*(res+i);
	    i++;
	}

	return 0;
}
