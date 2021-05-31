/* I was recently faced a question Word Count Engine:
let's go through the question:-
Implement a document scanning function wordCountEngine, which receives a string document and returns a list of all unique words in it and their number of occurrences, sorted by the number of occurrences in descending order. If two or more words have the same count, they should be sorted according to their order in the original sentence. Assume that all letters are in the English alphabet. Your function should be case-insensitive, so for instance, the words “Perfect” and “perfect” should be considered the same word.
The engine should strip out punctuation (even in the middle of a word) and use whitespaces to separate words.
Analyze the time and space complexities of your solution. Try to optimize for a time while keeping a polynomial space complexity.
Example:-
input: document = “Practice makes perfect. you’ll only get Perfect by practice. just practice!”
output: [ [“practice”, “3”], [“perfect”, “2”], [“makes”, “1”], [“youll”, “1”], [“only”, “1”], [“get”, “1”], [“by”, “1”], [“just”, “1”] ]
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;
unordered_map<string,int> dict; // for maintaining frequency
unordered_map<string,int> dict2; // for maintaining positions
// for custom comparator , ordering high frequecy words and maintaing position //for same frequecy words
struct comp{
bool operator()(const string &a,const string &b){
if(dict[a]==dict[b])
return dict2[a]>dict2[b];
else return dict[a]<dict[b];
}};
vector<vector<string>> wordCountEngine( const string& document )
{
dict.clear(); // clearing so that no residue data after running for next time
dict2.clear();
vector<vector<string>> ans;

string temp="";
for(int i=0;i<document.size();i++){
temp="";
// for extracting words
while(i<document.size() && document[i]!=' '){
if(isalpha(document[i]))
temp.push_back(tolower(document[i]));
i++;
}
if(temp.size())
dict[temp]++;
if(!dict2[temp])
dict2[temp]=i;

}

priority_queue<string,vector<string>,comp> pq;


for (auto it=dict.begin();it!=dict.end();it++){
pq.push(it->first);
}
while(!pq.empty()){
ans.push_back({pq.top(),to_string(dict[pq.top()])});
pq.pop();
}

return ans;
}
int main(){
    string str="Cause I'm Slim Shady, yes I'm the real Shady, All you other Slim Shadys are just imitating So won't the real Slim Shady, please stand up, Please stand up, Please stand up";

    vector<vector<string>> ans=wordCountEngine (str);
    for(auto c:ans){
        for(auto w: c){
            cout<<w<<" ";
        }
        cout<<endl;
    }
    return 0;
}
