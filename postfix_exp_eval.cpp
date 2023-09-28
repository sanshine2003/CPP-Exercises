#include <iostream>
#include <stack>

using namespace std;

//Postfix expression evaluation.
//single digit numbers
//Input - 345+*7-
//output - 20

int evaluate (string in)
{
  
  stack<int> pf;

  for(int i = 0; i < in.length(); ++i)
  {
      if(isdigit(in[i]))
      {
         pf.push(stoi(in.substr(i,1)));
      }
      else  
      {
        int op1 = pf.top();
        pf.pop();
        int op2 = pf.top();
        pf.pop();
        //we got an operator
        switch (in[i])
        {
          case '+':
             pf.push(op1 + op2);
          break;

          case '-':
            pf.push(op2 - op1);
          break;

          case '*':
            pf.push(op1 * op2);
          break;

          case '/':
            pf.push(op2 / op1);
          break;

        }
      }
  }
  return pf.top();
}

int main()
{
  std::cout << "Postfix Single digit Binary expression evaluation!\n";
  string in = "345+*7-";
  cout << "result - " << evaluate(in);
  return 0;
}


