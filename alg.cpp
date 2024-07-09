#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    string str="java,c,c++,python";
    int previous =0;
    int current=0;
    vector<string> x;
    x.clear();
    vector<vector<int>> edge(10, vector<int>{});
    current= str.find(',');
    //find는 찾을게 없으면 npos를 리턴함
    while(current!=string::npos){
        string substring=str.substr(previous,current-previous);
        x.push_back(substring);
        previous = current+1;
        current=str.find(',',previous);
    }
    x.push_back(str.substr(previous));
    
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<endl;
    }
    
    
    return 0;
}
