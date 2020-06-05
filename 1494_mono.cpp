#include <iostream>
using namespace std;

struct stack
{
    int elem[100000];
    int top;
};

void init(stack *st){
    st->top = 0;
}

void push(stack *st, int new_elem){
    st->elem[st->top] = new_elem;
    st->top++;
}

int pop(stack *st){
    
    st->top--;
    int a = st->elem[st->top];
    return a;
}

int main(int argc, char const *argv[])
{
    int n;
    int temp;
    int max = 0;
    stack st;
    init(&st);
    string flag ="Not a proof";
    cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> temp;
    if (temp > max)
    {
        for (int j = max+1; j < temp; ++j)
        {
            push(&st,j);
        }
        max = temp;
    }else{
        if (pop(&st) != temp)
        {
            flag = "Cheater";
        }
    }
  }
    cout << flag;
    return 0;
}