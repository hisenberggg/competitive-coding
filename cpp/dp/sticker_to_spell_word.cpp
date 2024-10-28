#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<char,int>> buildStickerMap(vector<string>& stickers, string target){
    vector<unordered_map<char,int>> stickersMap;

    for(auto it:stickers){ 
        bool isStickerRelevant = false;
        unordered_map<char,int> temp;
        for(auto its:it){
            if(target.find(its) != string::npos) // check if this sticker contains some of the target characters
                isStickerRelevant = true;
            temp[its]++;
        }

        if(isStickerRelevant){ // if this sticker doesnt contain any target character, dont consider it
            stickersMap.push_back(temp);
        }
    }

    return stickersMap;
}

map<char,int> buildTargetMap(string target){
    map<char,int> mpp;
    for(auto it:target){
        mpp[it]++;
    }
    return mpp;
}

string getTargetString(map<char,int> mpp){
    string target = "";
    for(auto it:mpp){
        target += it.first;
    }
    return target;
}

void pickCharFromSticker(unordered_map<char,int> sticker, map<char,int>& targetMap){
    for(auto chCount:sticker){
        char ch = chCount.first;
        if(targetMap.find(ch) != targetMap.end()){
            if(targetMap[ch]>0 && sticker[ch]>0){
                targetMap[ch]--;
                sticker[ch]--;
            }
        }
    }
}

int dfs(vector<unordered_map<char,int>> stickerMap, string target){
    if(target.size() == 0) 
        return 0;
    
    map<char,int> targetMap = buildTargetMap(target);

    int answer = INT_MIN;

    for(int i=0;i<stickerMap.size();i++){

        // char firstCh = sticker.begin()->first;
        // if(targetMap.find(firstCh) != targetMap.end()) 
        //     continue;

        pickCharFromSticker(stickerMap[i],targetMap);


        string remaining_target = getTargetString(targetMap);
        answer = min(answer, 1 + dfs(stickerMap,remaining_target));
    }
    return answer;
}

int getMinWords(vector<string> stickers, string target){
    
    vector<unordered_map<char,int>> stickersMap = buildStickerMap(stickers,target);
    map<string,int> dp;

    return dfs(stickersMap,target);
}

int main()
{
    vector<string> stickers = {"with","example","science"};
    string target = "thehat";

    int words = getMinWords(stickers, target);
    cout<<words;
    return 0;
}
