#include <algorithm>
using namespace std;
template <typename T1, typename T2>
class HashTable
{
// TODO: Add member variables
    Hash<T1> hash;
    T2 *hashvalue;
    int capacity;
public:
    HashTable(int max);
    void addItem(const T1 &key, const T2 &value);
    void removeItem(const T1 &key);
    T2 *findByKey(const T1 &key);
    ~HashTable();
};

template<typename T1, typename T2>
HashTable<T1,T2>::HashTable(int max) : capacity(max), hash(max){
    hashvalue = new T2[max];
}

template<>
HashTable<int,int>::HashTable(int max) : capacity(max), hash(max){
    hashvalue = new int[max];
    fill(hashvalue, hashvalue + max,-1);
}
template<>
HashTable<string,int>::HashTable(int max) : capacity(max),hash(max){
    hashvalue = new int[max];
    fill(hashvalue, hashvalue+max,-1);
}
template<typename T1, typename T2>
void HashTable<T1,T2>::addItem(const T1 &key, const T2 &value){
    hashvalue[hash(key)] = value;
};

template<>
void HashTable<int,int>::removeItem(const int &key){
    hashvalue[hash(key)] = -1;
}
template<>
void HashTable<int,string>::removeItem(const int &key){
    hashvalue[hash(key)] = "";
}
template<>
void HashTable<string,string>::removeItem(const string &key){
    hashvalue[hash(key)] = "";
}
template<>
void HashTable<string,int>::removeItem(const string &key){
    hashvalue[hash(key)] = -1;
}

template<typename T1, typename T2>
T2 * HashTable<T1,T2>::findByKey(const T1 &key){
    T2 * res = &hashvalue[hash(key)];
    return res;
};

template<>
int * HashTable<int,int>::findByKey(const int &key){
    int * res = &hashvalue[hash(key)];
    if( *res == -1|| res == nullptr ) return nullptr;
    return res;
}
template<>
int * HashTable<string,int>::findByKey(const string &key){
    int * res = &hashvalue[hash(key)];
    if( *res == -1) return nullptr;
    return res;
}
template<>
string * HashTable<int,string>::findByKey(const int &key){
    string * res = &hashvalue[hash(key)];
    if( *res == "") return nullptr;
    return res;
}
template<>
string * HashTable<string,string>::findByKey(const string &key){
    string * res = &hashvalue[hash(key)];
    if( *res == "") return nullptr;
    return res;
}

template<typename T1, typename T2>
HashTable<T1,T2>::~HashTable(){
    if(hashvalue) delete [] hashvalue;
}