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
  K (*hasher)(K);

  // finds correct val in a bucket
  V getFromBucket(K, bucket*);
  bool isInBucket(K, bucket*);

  // updates a keypair
  void update(K, V, bucket*);

  // number of entries
  int                 numberOfEntries = 0;
  // underlying implementation
  std::vector<bucket*> map;

public:
  // constructor takes a pointer to a
  // hashing function
  HashTable(K(*hashFunc)(K));
  ~HashTable();

  // enroll emplaces a key value pair
  // creates a new bucket if the hash
  // does not already exist
  void enroll(K, V);

  // retrieves a value from a key
  V get(K);

  // returns current number of entries
  int getNumberOfEntries();

  // return all movies sorted like they need to be
  static std::vector<V>
  retrieveAllValues(HashTable<K, V>, bool(*sortComparator)(V, V));

  // helper function for unit testing purposes
  K getHash(K);
};

template <class K, class V>
HashTable<K, V>::HashTable(K(*hashFunction)(K)){
  this->hasher = hashFunction;
  this->numberOfEntries = 0;
}

template <class K, class V>
  int HashTable<K,V>::getNumberOfEntries(){
  return this->numberOfEntries;
}

template<class K, class V>
void HashTable<K,V>::enroll(K key, V val){
  K hashval = hasher(key);

  for(bucket* b : this->map){
    if(b->hash == hashval){
      if(isInBucket(key, b)){ this->update(key, val, b); return; }
      b->Keys.push_back(key);
      b->Values.push_back(val);
      ++this->numberOfEntries;
      return;
    }
  }

  bucket* b = new bucket();
  b->hash = hashval;
  b->Values.push_back(val);
  b->Keys.push_back(key);
  ++this->numberOfEntries;
  this->map.push_back(b);
}

template<class K, class V>
K HashTable<K,V>::getHash(K arg){
return hasher(arg);
}

template<class K, class V>
  V HashTable<K, V>::getFromBucket(K key, bucket* b){

  for(int i = 0; i < b->Keys.size(); i++){
    if(b->Keys[i] == key) return b->Values[i];
  }

    throw "Internal Logic Error: HashTable::getFromBucket()";
}

template<class K, class V>
  V HashTable<K,V>::get(K key){
  for(bucket* b : this->map){
    if(this->hasher(key) == b->hash){
      return getFromBucket(key, b);
    }
  }

  // maybe throw something?
  return {};
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
  for(bucket* b : this->map){
    delete b;
  }
}

#endif //HASHTABLE_H
