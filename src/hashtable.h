#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>

template<class K, class V>
class HashTable {
  static const int map_end = {96};
  // nested struct to keep everything nice and civil
  struct bucket {
    std::vector<std::pair<K,V>> kv;
    /** determines if the given key, target, is in this bucket
     * If hash properly distributes items across table, this should
     * have O(1) time.
     * @param target
     * @return index position of target if found, else -1
     */
    int contains(const K& target)const {
      int idx = 0;
      while(idx < (int)kv.size() && kv[idx].first != target)++idx;
      return (idx < kv.size() && kv[idx].first == target)?idx : -1;
    }
    
    /** following the STL general nomenclature for pushing items back into
     *  a container.
     *
     * @param itm the std::pair<K,V> object linking the key to the val
     */
    void push_back(std::pair<K,V> itm){
      kv.push_back(itm);
    }
//    std::vector<K> Keys;
//    std::vector<V> Values;
  };

private:
  // pointer to hash function
  int (*hasher)(const K&);

  // finds correct val in a bucket
  V* getFromBucket(K, bucket*);
  bool isInBucket(K, bucket*);

  // updates a keypair
  void update(K, V, bucket*);

  // number of entries
  int                 numberOfEntries = 0;
  // underlying implementation
  bucket* map[map_end];

public:
  // constructor takes a pointer to a
  // hashing function
  HashTable(int(*hashFunc)(const K &));
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
//  static std::vector<V>
//  retrieveAllValues(HashTable<K, V>, bool(*sortComparator)(V, V));

  // helper function for unit testing purposes
  int getHash(K);
};

template <class K, class V>
  HashTable<K, V>::HashTable(int(*hashFunction)(const K &)){
  std::cout << "map_end = " << map_end << std::endl;
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
  if(index > map_end)index %= map_end;
  if( map[index] == nullptr ){
    map[index] = new bucket();
  }

  if(this->isInBucket(key,map[index])){
    this->update(key, val, map[index]);
    return;
  }
  map[index]->push_back(std::make_pair(key,val));
//  map[index]->Keys.push_back(key);
//  map[index]->Values.push_back(val);
  ++(this->numberOfEntries);
}

template<class K, class V>
int HashTable<K,V>::getHash(K arg){
return hasher(arg);
}

template<class K, class V>
  V* HashTable<K, V>::getFromBucket(K key, bucket* b){

//  for(int i = 0; i < b->Keys.size(); i++){
//    if(b->Keys[i] == key) return &b->Values[i];
//    V* a = &(b->Values[i]);
//    return a;
//  }
    int idx = b->contains(key);
    if(idx >= 0){
      return &(b->kv[idx].second);
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
//  for(K keymaybe : b->Keys){
//    if(keymaybe == key) return true;
//  }
//  return false;
    return b->contains(key) >= 0;
}

template<class K, class V>
  void HashTable<K,V>::update(K key, V val, bucket* b){
//  for(int i = 0; i < b->Keys.size(); i++){
//    if(b->Keys[i] == key){
//      b->Values[i] = val;
//      return;
//    }
//  }
    
    int idx = b->contains(key);
    if(idx >= 0){
      b->kv[idx].second = val;
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
