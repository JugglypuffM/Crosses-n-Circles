//
// Created by Jugglyuser on 27.05.2023.
//

#include "Graph.h"

Graph::Graph(int a, int b) {
    x = a; o = b;
    outcomes = {0, 0, 0};
}

void Graph::build(bool a) {
    int w = 0;
    int win_states[8] = {448, 292, 273, 146, 84, 73, 56, 7};
    for (int i = 0; i < 8; ++i) {
        if((x & win_states[i]) == win_states[i]) w = 0;
        else if ((o & win_states[i]) == win_states[i]) w = 2;
        else if((x|o) == 511) w = 1;
    }
    if(w != 0){
        outcomes[w]++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            if (((((x|o) & (1 << (i * 3 + 1 * j))) == 0))) {
                Graph ch = a ? Graph(this->x, this->o | 1 << (i * 3 + 1 * j)) : Graph(this->x | 1 << (i * 3 + 1 * j), this->o);
                ch.change = to_string(i) + to_string(j);
                ch.build(!a);
                child.push_back(ch);
            }
        }
    }
    for (int i = 0;i<child.size();i++){
        outcomes[0]+=child[i].outcomes[0];
        outcomes[1]+=child[i].outcomes[1];
        outcomes[2]+=child[i].outcomes[2];
    }
}

void traverse_graph(string ** table, Graph* graph){
    if(graph->child.empty()) return;
    double win_max = -1, draw_max = -1, loose_max = -1, all_outcomes;
    string win_turn, draw_turn, loose_turn;
    for (int i = 0; i < graph->child.size(); ++i) {
        traverse_graph(table, &graph->child[i]);
        all_outcomes = graph->child[i].outcomes[0] + graph->child[i].outcomes[1] + graph->child[i].outcomes[2];
        if(graph->child[i].outcomes[0]/all_outcomes >= win_max) {
            win_turn = graph->child[i].change;
            win_max = graph->child[i].outcomes[0]/all_outcomes;
        }
        if(graph->child[i].outcomes[1]/all_outcomes >= draw_max){
            draw_turn = graph->child[i].change;
            draw_max = graph->child[i].outcomes[1]/all_outcomes;
        }
        if(graph->child[i].outcomes[2]/all_outcomes >= loose_max){
            loose_turn = graph->child[i].change;
            loose_max = graph->child[i].outcomes[2]/all_outcomes;
        }
    }
    table[graph->x][graph->o] = win_turn + draw_turn + loose_turn;
}

string** fill_table(){
    Graph graph(0, 0);
    graph.build(false);
    string** table = new string*[512];
    for (int i = 0; i < 512; ++i) {
        table[i] = new string[512];
    }
    traverse_graph(table, &graph);
    return table;
}


