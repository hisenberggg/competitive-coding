#include<bits/stdc++.h>
using namespace std;
string encryption(string s){
    int len = s.length(), blcount = 0;
    int row, col;
    vector<int> bl;
    string op;
    for(int i=0; i<len;i++){
        if(s[i] == ' ') {
            blcount++;
            bl.push_back(i);
        }
    }
    // for(auto k:bl) cout<<k<<" ";
    len = len-blcount;
    double sq = sqrt(len);
    if(ceil(sq) == floor(sq)){
        row = col =  (int)sq;
    }
    else{
        row = floor(sq);
        col = ceil(sq);
    }
    // cout<<row<<col<<endl;
    int j = 0, cind, ind = 0;
    while(j<col){
        cind = j;
        ind = 0;
        while(cind<len+blcount){
            op += s[cind];
            cind += col;
            if(ind+1<blcount)
            if(cind>=bl[ind]) {
                cind += 1;
                if(s[cind] == ' '){cind++;ind++;}
                ind++;
            }
            if(cind>=len+blcount) break;
        }
        op += ' ';
        j++;
        // cout<<op<<endl;
    }
    return op;
}

int main(int argc, char const *argv[])
{
    string s = "haveaniceday";
    cout<<"Output is :"<<encryption(s);

    return 0;
}
