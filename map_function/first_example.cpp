#include <bits/stdc++.h>

using namespace std;

map<string, function<void(void**)> > functions;

void soma(void **args){
    cout << "a + b = " << *((int *)args[0]) + *((int *)args[1]) << endl;
}

void subtracao(void **args){
    cout << "a - b = " << *((int *)args[0]) - *((int *)args[1]) << endl;
}

void call_function(string func_name, void **args){
    functions[func_name](args);
}

int main(){

    void **args;

    args = (void **) malloc (10*sizeof(void *));

    int a, b;
    cin >> a >> b;

    args[0] = &a;
    args[1] = &b;

    functions["soma"] = soma;
    functions["subtracao"] = subtracao;

    call_function("soma", args);

    return 0;
}
