#include <bits/stdc++.h>
using namespace std;

/*
 *RPN(逆ポーランド記法)んプログラム。
 *4+5*6を行いたいときは
 * ./a.out 4 5 6 \* +
 * と入力すること。
 * ただし、かけるとき(*を使うとき)はバックスラッシュでのエスケープが必要。
 */


// 計算を行う関数
int calc(string op, int num1, int num2){
   if(op=="+"){
        return num1 + num2;
    }
    else if(op=="-"){
        return num1 - num2;
    }
    else if(op=="*"){
        return num1 * num2;
    }
    else{
        return num1 / num2;
    }
}
    
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    int n  = tokens.size();
    int ans = 0;
    if(!n) return 0; 
    if(n==1) return stoi(tokens[0]);
	
    for(auto c: tokens){
        if(c != "+" && c != "-" && c != "*" && c != "/"){ // 符号のとき
            int tmp = stoi(c);
            stk.push(tmp);
        }
		
        else{  // 数値のとき
            string op = c;
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            ans = calc(op, num1, num2);
            stk.push(ans);
        }
		
    }
	
    return ans;

}

int		main(int argc, char** argv)
{
	vector<string> args;
	for (int i = 1; i < argc; i++)
	{
		args.push_back(argv[i]);
	}
	
	/* デバッグ用
	for (int i = 0; i < argc - 1; i++)
	{
		cout << "args[" << i <<  "]=" << args[i] << endl;
	}
	*/
	cout << evalRPN(args) << endl;
}

