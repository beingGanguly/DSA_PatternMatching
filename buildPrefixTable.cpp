#include<iostream>
#include<vector>
using namespace std;

vector<int>buildPrefixTable(string pattern){
    vector<int>prefixTable(pattern.size());
    int j=0;
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]==pattern[j]){
            j++;
            prefixTable[i] = j;
        }
        else{
            if(j!=0){
                j=prefixTable[j-1];
                i--;
            }
            else{
                prefixTable[i] = 0;
            }
        }
    }
    return prefixTable;
}

bool patternExists(const string& modifiedText, const string& pattern){
    vector<int>prefixTable = buildPrefixTable(pattern);
    int i=0;
    for(int j=0;j<modifiedText.size();j++){
        if(modifiedText[j]==pattern[i]){
            i++;
            if(i==pattern.size()){
                return true;
            }
            else{
                if(i != 0){
                    i = prefixTable[i-1];
                    j--;
                }
            }
        }
        return false;
    }
}