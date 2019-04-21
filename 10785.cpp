#include <bits/stdc++.h>
using namespace std;

string word="AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR";

int main(){
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string vowel="";
        string consonant="";
        for(int i=0; i<n; i+=2){
            vowel+=word[i];
        }
        for(int i=1; i<n; i+=2){
            consonant+=word[i];
        }

        sort(vowel.begin(),vowel.end());
        sort(consonant.begin(),consonant.end());

        string res="";
        int j=0,k=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                res+=vowel[j];
                j++;
            }
            else{
                res+=consonant[k];
                k++;
            }
        }
        printf("Case %d: ",cs++);
        cout<<res<<endl;
    }
    return 0;
}
