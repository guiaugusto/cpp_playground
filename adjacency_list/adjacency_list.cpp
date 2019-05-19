#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int index;
        vector<int> list;
        bool visited;
};

vector<Node> nodes;

void marked_as_visited(int c){
    nodes[c].visited = true;
    vector<int>::iterator begin = nodes[c].list.begin();

    for(int i = 0; i < nodes[c].list.size(); i++){
        if(!nodes[nodes[c].list[i]].visited){
            marked_as_visited(nodes[c].list[i]);
            nodes[c].list.erase(begin+i);
            i--;
        }
    }
}

int main(){

    int n, q, qc, c, res = 0;
    int from, to;
    Node node_aux;
    vector<int> vazio;

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        node_aux.index = i;
        node_aux.list = vazio;
        node_aux.visited = false;
        nodes.push_back(node_aux);
    }

    for(int i = 0; i < q; i++){
        cin >> from >> to;

        nodes[from-1].list.push_back(to-1);
        nodes[to-1].list.push_back(from-1);
    }

    cin >> qc;

    for(int i = 0; i < qc; i++){
        cin >> c;

        marked_as_visited(c-1);
    }

    for(int i = 0; i < nodes.size(); i++){
        if(!nodes[i].visited){
            marked_as_visited(i);
            res++;
        }
    }

    cout << res << endl;

}
