
#include <stdio.h>
#include <string.h>
#define ll long long int


//CHARCTER VALUE OF ROMAN NUMBER
ll getValue(char c)
{
    
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

// roman  to decimal 
ll romanToInt(char val[])
{
    ll length = strlen(val);
    ll intVal = 0, i;
    for (i = 0; i < length - 1; i++)
    {
        ll a = getValue(val[i]), b = getValue(val[i + 1]);
        if (a < b)
        {
            intVal += (b - a);
            i++;
        }
        else intVal += a;
    }
    if (i < length) intVal += getValue(val[i]);

    return intVal;
}

int main()
{
   ll intarr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
   char chararr[][2] = {{'0', 'M'}, {'C', 'M'}, {'0', 'D'}, {'C', 'D'}, {'0', 'C'}, {'X', 'C'}, {'0', 'L'}, {'X', 'L'}, {'0', 'X'}, {'I', 'X'}, {'0', 'V'}, {'I', 'V'}, {'0', 'I'}};
  

        printf("\nEnter two roman values \n");
        char val1[100], val2[100];
        
       scanf("%s", val1);
       scanf("%s", val2);
        ll x = romanToInt(val1);
        ll y = romanToInt(val2);
        ll result;
        printf("1: Addition \n2: Multipilcation \n");
        ll opt;
        scanf("%lld", &opt);
        switch(opt){
            case 1: result =x+y;break;
            case 2: result=x*y;break;
         }
       

        char ans[100];
        ll idx = 0;
     
        // decimal to roman 

        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < result / intarr[i]; j++)
            {
                if (chararr[i][0] != '0')
                {
                    ans[idx] = chararr[i][0];
                    idx++;
                }
                ans[idx] = chararr[i][1];
                idx++;
            }
            result %= intarr[i];
        }
        
        for (int i = 0; i < idx; i++)
       
        printf("%c", ans[i]);
   
        printf("\n");
    
    
    return 0;
}
