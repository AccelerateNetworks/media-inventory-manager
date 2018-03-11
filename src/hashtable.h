#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template<class K, class V>
class HashTable {

  // nested struct to keep everything nice and civil
  struct bucket {
    K              hash;
    std::vector<K> Keys;
    std::vector<V> Values;
  };

private:
  // pointer to hash function
  int (*hasher)(K);

  // finds correct val in a bucket
  V* getFromBucket(K, bucket*);
  bool isInBucket(K, bucket*);

  // updates a keypair
  void update(K, V, bucket*);

  // number of entries
  int                 numberOfEntries = 0;
  // underlying implementation
  bucket* map[96];

public:
  // constructor takes a pointer to a
  // hashing function
  HashTable(int(*hashFunc)(K));
  ~HashTable();

  // enroll emplaces a key value pair
  // creates a new bucket if the hash
  // does not already exist
  void enroll(K, V);

  // retrieves a value from a key
  V* get(K);

  // returns current number of entries
  int getNumberOfEntries();

  // return all movies sorted like they need to be
  static std::vector<V>
  retrieveAllValues(HashTable<K, V>, bool(*sortComparator)(V, V));

  // helper function for unit testing purposes
  int getHash(K);
};

template <class K, class V>
  HashTable<K, V>::HashTable(int(*hashFunction)(K)){
  this->hasher = hashFunction;
  this->numberOfEntries = 0;
}

template <class K, class V>
  int HashTable<K,V>::getNumberOfEntries(){
  return this->numberOfEntries;
}

template<class K, class V>
void HashTable<K,V>::enroll(K key, V val){

  int index = hasher(key);

  if(map[index] == nullptr){
    map[index] = new bucket();
  }

  if(this->isInBucket(key,map[index])){
    this->update(key, val, map[index]);
    return;
  }

  map[index]->Keys.push_back(key);
  map[index]->Values.push_back(val);
  ++this->numberOfEntries;
  return;
}

template<class K, class V>
int HashTable<K,V>::getHash(K arg){
return hasher(arg);
}

template<class K, class V>
  V* HashTable<K, V>::getFromBucket(K key, bucket* b){

  for(int i = 0; i < b->Keys.size(); i++){
    if(b->Keys[i] == key) return &b->Values[i];
    V* a = &(b->Values[i]);
    return a;
  }

  throw "Internal Logic Error: HashTable::getFromBucket()";
}

template<class K, class V>
  V* HashTable<K,V>::get(K key){

  int index = hasher(key);
  if(map[index] == nullptr) return nullptr;
  if(!isInBucket(key, map[index])) return nullptr;

  V* a = getFromBucket(key, map[index]);
  return a;
}

template<class K, class V>
  bool HashTable<K,V>::isInBucket(K key, bucket* b){
  for(K keymaybe : b->Keys){
    if(keymaybe == key) return true;
  }

  return false;
}

template<class K, class V>
  void HashTable<K,V>::update(K key, V val, bucket* b){
  for(int i = 0; i < b->Keys.size(); i++){
    if(b->Keys[i] == key){
      b->Values[i] = val;
      return;
    }
  }

  throw "Internal Logic Error: HashTable::update()";
}

template<class K, class V>
  HashTable<K,V>::~HashTable(){
  for(int i = 0; i <= 95; ++i){
    if(map[i] != nullptr){
      delete map[i];
    }
  }
}

#endif //HASHTABLE_H
