#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


// Change this file as you want or add more files

class Vocabulary
{
private:
    // Choose a proper container from STL.
    static int Id;
    std:: map<string, int> Vocabs;//중복되어 삽입되, false 리턴, 즉 삽입되지 않음
public:
    vector<int> insertSentReturnIds(string sentence){
        //Enter your code here.
        //This function should build vocabulary and at the same time return a sentence encoding.
        istringstream 
        ss(sentence);
        string stringBuffer;
        vector<int> res;
        res.clear();
        while(getline(ss,stringBuffer, ' ')){
            if(Vocabs.find(stringBuffer) == Vocabs.end()){//만약 Vocabs에 현재 넣으려는 단어가 존재하지 않는다면,즉, 새로운 Vocab을 찾았다면
                Vocabs.insert(make_pair(stringBuffer,Id));
                res.push_back(Id);
                Id++;
            } else {//이미 존재한다면,
                res.push_back(Vocabs[stringBuffer]);
            }
        }
        return res;
    }
};
int Vocabulary::Id = 1;


class DataLoader{
private:
    vector<int> _rand_order;
    int batch_size=0;
    //Enter your code here
    int m=0;
    vector< vector<int> > sentences;
    vector< int > inDex;
    vector< vector< int> > c_sentences[6];
    
public:
    void setBatchSize(int N){
        this->batch_size = N; // can also change
        for(int i=0;i<_rand_order.size();){
            int j = 0;
            int max_size = 0;
            while(j<N && i+j<_rand_order.size()){
                if(sentences[_rand_order[i+j]].size() > max_size)
                    max_size = sentences[_rand_order[i+j]].size();
                j++;
            }
            for(int k=0;k<j;k++){
                sentences[_rand_order[i+k]].resize(max_size,0);
            }
            i +=j;
        }
        c_sentences[m] = sentences;
        m++;
    }

    void setOrder(vector<int>& x){
        _rand_order = x; // can also change
        for(int i=0;i<sentences.size();i++){
            sentences[i].resize(inDex[i]);
        }
    }

    void addData(vector<int> sent_encoding){
        //Enter you code here;
        sentences.push_back(sent_encoding);
        inDex.push_back(sent_encoding.size());
    }

    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type = vector<vector< int>> ;
        using pointer = vector<vector< int >>*;
        using reference = vector<vector< int >>&;

        //Define your constructor and functions that are needed for a Iterator.
        Iterator(pointer ptr) : m_ptr(ptr) {};
        
        reference operator*() const { return *m_ptr;}
        pointer operator->() {return m_ptr;}
        Iterator& operator++() { m_ptr++; return *this;}
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp;}
        friend bool operator== (const Iterator & a, const Iterator & b) { return a.m_ptr == b.m_ptr;};
        friend bool operator!= (const Iterator & a, const Iterator & b) { return a.m_ptr != b.m_ptr;};
        private:
            pointer m_ptr;
        // Add what where variable you want here to make the Iterator functional.
    };

    Iterator begin() {
        return Iterator(&c_sentences[0]);
    }
    Iterator end() {
        return Iterator(&c_sentences[m-1]);
    }

};




