#include<stdio.h>
#include<string.h>
char ans[200];
char* add(char a[],char b[]){
    int wa=strlen(a),wb=strlen(b),w,i,j=0;
    w=wa>wb?wa:wb;
    char ca,cb,carry='0',sum='0';
    for(i=0;i<w;i++){
        if(i<wa)
        ca=a[strlen(a)-1-i];
        else
        ca='0';
        if(i<wb)
        cb=b[strlen(b)-1-i];
        else
        cb='0';
       // printf("ca=%c,cb= %c,carry= %c \n",ca,cb,carry);
        if(ca=='0'&&cb=='0'){
            if(carry=='0'){
            sum=ca;
            ans[j++]=sum;
            carry='0';
            }
            else{
                sum='1';
                ans[j++]=sum;
                carry='0';
            }
        }
     if(ca=='1'&&cb=='0'||ca=='0'&&cb=='1'){
            if(carry=='0'){
            sum='1';
            ans[j++]=sum;
            carry='0';
            }
            else{
                sum='0';
                ans[j++]=sum;
                carry='1';
            }
        }
        if(ca=='1'&&cb=='1'){
            if(carry=='0'){
            sum='0';
            ans[j++]=sum;
            carry='1';
            }
            else{
                sum='1';
                ans[j++]=sum;
                carry='1';
            }
        }
    }
     if(carry=='1')
            ans[j++]='1';
           for(int i=0;i<strlen(ans)/2;i++){
           char t =ans[i];
    ans[i] =ans[strlen(ans) - i - 1]; 
    ans[strlen(ans) - i - 1] = t;
}
            return ans;
}
int main()
{
    char a[100];
    char b[100];
    printf("enter the a and b \n");
    scanf("%s%s",a,b);
   char *s= add(a,b);
   printf("%s",s);

}