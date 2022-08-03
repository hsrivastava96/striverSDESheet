#import <iostream>
#import <string>
#import <vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int ladderLength(const string &source, const string &target, const vector<string>& words) {
  // your code goes here

          unordered_map<string, int> m;

          // set distances of each present words from source to be INT_MAX or 1e9
          for(auto word:words)
            m[word] = 1e9;

          // Set source distance to itself as 0
          m[source] = 0;

        //Check if target is present in our map or not. If not then return -1
          if(m.find(target) == m.end())
            return 0;

          // Now, push source node in queue for BFS traversal to find shortest distance of all nodes from source
          queue<string> q;
          q.push(source);

          while(!q.empty())
          {
            string currWord = q.front();
            int currDistSrc = m[currWord], currWordLen = currWord.length();
            q.pop();

            // Now, look for all neighors of current word, i.e. they should be 1 character different from current node
            for(int i = 0; i < currWordLen; i++)
            {
              // Store current character to be replaced to find possible word in a copChar
              char copyChar = currWord[i];

              // Now, look for all possible characters for current position
              for(char c = 'a'; c <= 'z'; c++)
              {
                  // replace curren index character with c
                  currWord[i] = c;

                  //check if this new word is present in our map or not
                  if(m.find(currWord) != m.end())
                  {
                    int tempDist = currDistSrc + 1;
                    if(tempDist < m[currWord])
                    {
                      m[currWord] = tempDist;
                      q.push(currWord);
                    }
                  }
              }

              // replace current word to it's original state for current index
              currWord[i] = copyChar;
            }
          }
          if(m[target] != 1e9)
            return m[target]+1;
          return 0;    
    }
};
int main() 
{
  string src, target;
  vector<string> words;
  int n;
  cout<<"source = ";
  cin>>src;
  cout<<"target = ";
  cin>>target;
  cout<<"# of Words = ";
  cin>>n;
  for(int i = 1; i <= n; i++)
  {
    string s;
    cout<<"Enter "<<i<<" word: ";
    cin>>s;
    words.push_back(s);
  }
  cout<<shortestWordEditPath(src, target, words);
	return 0;
}
