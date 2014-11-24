/*
 * =====================================================================================
 *
 *       Filename:  analyse.cpp
 *
 *    Description:  Analyze the orphant blocks of the output of parser.cpp
 *
 *        Version:  1.0
 *        Created:  07/07/2014 12:36:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Jie Feng (http://hey.i-feng.org/), jiefeng.hopkins@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
/*
 * naming rule: 
 *      block: actually hash value of the block
 */


#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;


struct blockInfo{
    int height;
    bool mainChain;
    blockInfo(){
        height = -1;
        mainChain = false;
    }
};
map<string, vector<string> > sons;
map<string, string> parent;
map<string, blockInfo> blocks;
int maxHeight = -1;
string maxHeightBlock = "";
void getHeight(string cur){
    stack<string> st;

    while(blocks[cur].height == -1 && parent.find(cur) != parent.end()){
        st.push(cur);
        cur = parent[cur];
    }
    int height = 0;
    if (blocks[cur].height == -1)
        blocks[cur].height = 0;
    else 
        height = blocks[cur].height;

    while(!st.empty()){
        cur = st.top();
        st.pop();
        blocks[cur].height = ++height;
    }
/*     if (blocks[cur].height != -1) return blocks[cur].height;
 * 
 *     if (parent.find(cur) == parent.end()) return blocks[cur].height = 0;
 *     else {
 *         int ph =  parHeight(parent[cur], level+1);
 *         return  blocks[cur].height = ph+1;
 *     }
 */
}
void calcHeights(){
    for (auto i = parent.begin(); i != parent.end(); i++){
        if (blocks[i->first].height == -1){
            getHeight(i->first);
        }
        int curHeight = blocks[i->first].height;
        if (curHeight > maxHeight){
            maxHeight = curHeight;
            maxHeightBlock = i->first;
        }
    }
}

/*
 * The address is reversed like 0x45052c17bbe97c8edcae100d2732b7ebdf6a87e31963fd130000000000000000  
 * But inorder to search the information of the real address(http://blockchain.info/), you need to reverse it
 */
string reverseBlock(string block){
    reverse(block.begin(), block.end());
    for (int i = 0; i < block.size(); i += 2){
        swap(block[i], block[i+1]);
        //question: jie@maicoin.com
    }
    return block;
}
void printChain(stringstream& bout, string block){
    bout << "\t\t";
    while(true){
        bout << reverseBlock(block) << ' ';
        if (sons.find(block) == sons.end()) break;
        block = sons[block][0];
    }
    bout << endl;
}
string explore(string par){
    stringstream bout;
    bout << "Branch at:" << reverseBlock(par) << " of height: " << blocks[par].height << endl;
    for (int i = 0; i < sons[par].size(); i++){
        if (!blocks[sons[par][i]].mainChain) {
            printChain(bout, sons[par][i]);
        }
    }
    return bout.str();
}

void parseMainChain(string& block){
    while(true){
        blocks[block].mainChain = true;
        auto i = parent.find(block);
        if (i == parent.end()) break;
        else block = i->second;
    }
}

bool allZero(string& s){
    for (int i = 0; i < s.size(); i++) if (s[i] != '0') return false;
    return true;
}
int main(){
    ifstream cin("parser.output");
    ofstream bout("branch.out");
    string cur, par; 
    int h;
    while(cin >> cur >> par >> h){
        if (allZero(cur) || allZero(par)) continue;
        //cout << reverseBlock(cur) << ' ' << reverseBlock(par) << endl;
        parent[cur] = par;
        blocks[cur] = blockInfo();
        if (sons.find(par) == sons.end()){
            sons[par] = vector<string>();
        }
        sons[par].push_back(cur);
    }
    calcHeights();
    cout << maxHeight << endl;


    map<int, string> sortedOutput;
    parseMainChain(maxHeightBlock);
    for (auto i = sons.begin(); i != sons.end(); i++){
        if (i->second.size() > 1) {
            sortedOutput[blocks[i->first].height] = explore(i->first);
        }
    }
    for (auto i = sortedOutput.begin(); i != sortedOutput.end(); i++){
        bout << i->second << endl;
    }
}
