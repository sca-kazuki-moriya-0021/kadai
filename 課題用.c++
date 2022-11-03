#include <iostream>
#include<cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

const int MAX_COUNT =10;

int main()
{

    vector<string>::iterator iter;
    vector<string> difficulty;
    difficulty.push_back("NORMAL");
    cout<<"これは文字当てクイズです";
    cout<<"間違えられる回数は限りがあります";

    int hit =0;
    int remove =0;
    vector<string> words;
    words.push_back("DISPLAY");
    words.push_back("May");
    int problemCount;
    int count =0;

    cout<<"問題は2つあります"<<endl;
    
    while(hit != 2 ){
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(words.begin(),words.end());
        const string THE_WORD = words[0];
        int longer = THE_WORD.size();
        string soFar(THE_WORD.size(),'-');
        string used = " ";
        switch (longer){
            case 6:
            cout<< "6文字の英単語を入力してね"<<endl;
            break;
            case 2:
            cout<<"2文字の英単語を入力してね"<<endl;
            break;
        }
        while ((remove < MAX_COUNT)&&(soFar != THE_WORD))
        {
            cout<< "\n\n間違え回数"<<(MAX_COUNT-remove)<<"回";
            cout<<"\n文字表示"<<used<<endl;
            cout<<"\n文字数は"<<soFar<<endl;

            char guess;
            cout<< "貴方の答え：";
            cin >> guess;
            guess = toupper(guess);
            while(used.find(guess!= string::npos)){
                cout<<"この文字は入力してあります"<<endl;
                cout<<"もう一度入力"<<endl;
                cin>> guess;
                guess = toupper(guess);
            }

            uesd += guess;
            if(THE_WORD.find(guess) != string::npos){
                cout<< guess<<endl;
                for(int i =0;i<THE_WORD.length();i++){
                    if(THE_WORD[i]== guess){
                        soFar[i] = guess;
                    }
                }
            }
            else{
                cout<< "間違っているよ"<<endl;
                ++count;
                ++remove;
            }
        }
        if((remove == MAX_COUNT)||count == MAX_COUNT){
            cout<<"終了"<<endl;
            break;
        }
        hit++;
        count++;
        cout<<"答えは"<<THE_WORD<<endl;
    }
    cout<<"クリアおめでとう"<<endl;
}