#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    vector <char> text;

    char symbol;
    cin >> noskipws;

    while(cin >> symbol)
    {
        text.push_back(symbol);
    }

    vector <string> words;

    string word = "";

    for(int i = 0; i < text.size(); i++)
    {
        if(isalpha(static_cast<unsigned char>(text[i])) != 0)
        {
            word += text[i];
        }
        else if(word != "")
        {
            words.push_back(word);
            word = "";
        }
    }
    if(word != "")
    {
        words.push_back(word);
    }

    if(words.size() == 0) {
        return 0;
    }

    sort(words.begin(), words.end());
    words.erase( unique( words.begin(), words.end() ), words.end() );
    int maxCount = 1, counter = 1;
    for(int i = 1; i < words.size(); i++) {
        if(words[i] == words[i - 1]) {
            counter++;
        }
        else {
            maxCount = max(maxCount, counter);
            counter = 1;
        }
    }
    maxCount = max(maxCount, counter);
    counter = 1;
    for(int i = 1; i < words.size(); i++) {
        if(words[i] == words[i - 1]) {
            counter++;
        }
        else {
            if(counter == maxCount) {
                cout << words[i - 1] << " ";
            }
            counter = 1;
        }
    }
    if(counter == maxCount) {
        cout << words[words.size() - 1];
    }
    return 0;
}
