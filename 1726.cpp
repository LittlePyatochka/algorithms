#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int max;
    int num_min;
    int min;
    int num_max;
    int n;
    cin >> n;
    int sign[n];
    int summ=0;

    for (int i = 0; i < n; ++i)
    {
        cin >> sign[i];
        summ += sign[i];
    }

    while(true){
        max = sign[0];
        
        for (int i = 0; i < n; ++i)
        {
            if ((sign[i] >= max) && (sign[i]!= 0)){
               max = sign[i];
               num_max = i;
            }
        }
        min = max;

        for (int i = 0; i < n; ++i)
        {
            if((sign[i] <= min) && (sign[i] != 0)){
                min = sign[i];
                num_min = i;  
            }
            
        }

        if(max == 0 || summ <= 0 || min ==0){
            return 0;
        }

        if (num_min != num_max )
            {
                cout << num_max+1 << " ";
                sign[num_max]--;
                summ--;
            }
 
        cout << num_min+1 << " ";
        sign[num_min]--;
        summ --;
    }
    return 0;
}
