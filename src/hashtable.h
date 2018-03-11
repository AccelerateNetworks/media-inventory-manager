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
      return (idx < (int)kv.size() && kv[idx].first == target)?idx : -1;
    }
    
    /** following the STL general nomenclature for pushing items back into
     *  a container.
     *
     * @param itm the std::pair<K,V> object linking the key to the val
     */
    void push_back(std::pair<K,V> itm){
      kv.push_back(itm);
    }
  };

private:
  // pointer to hash function
  int (*hasher)(const K&);

  // finds correct val in a bucket
  V* getFromBucket(K, bucket*);
  bool isInBucket(K, bucket*);

  // updates a keypair
  void update(K, V, bucket*);

  void update(int idx, K key, V val, bucket *b);
  
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

/**
 *
 * @tparam K
 * @tparam V
 * @param hashFunction
 */
template <class K, class V>
  HashTable<K, V>::HashTable(int(*hashFunction)(const K &)){
  std::cout << "map_end = " << map_end << std::endl;
  this->hasher = hashFunction;
  this->numberOfEntries = 0;
}

/**
 *
 * @tparam K
 * @tparam V
 * @return
 */
template <class K, class V>
  int HashTable<K,V>::getNumberOfEntries(){
  return this->numberOfEntries;
}

/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @param val
 */
template<class K, class V>
void HashTable<K,V>::enroll(K key, V val){

  int index = hasher(key);
  if(index > map_end)index %= map_end;
  if( map[index] == nullptr ){
    map[index] = new bucket();
  }
  
  int idx = map[index]->contains(key);
  if(idx >= 0){
    this->update(idx,key, val, map[index]);
    return;
  }
  map[index]->push_back(std::make_pair(key,val));
  ++(this->numberOfEntries);
}

/**
 *
 * @tparam K
 * @tparam V
 * @param arg
 * @return
 */
template<class K, class V>
int HashTable<K,V>::getHash(K arg){
return hasher(arg);
}

/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @param b
 * @return
 */
template<class K, class V>
  V* HashTable<K, V>::getFromBucket(K key, bucket* b){
    int idx = b->contains(key);
    if(idx >= 0){
      return &(b->kv[idx].second);
    }
    throw "Internal Logic Error: HashTable::getFromBucket()";
}

/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @return
 */
template<class K, class V>
  V* HashTable<K,V>::get(K key){

  int index = hasher(key);
  if(map[index] == nullptr) return nullptr;
  if(!isInBucket(key, map[index])) return nullptr;

  return getFromBucket(key, map[index]);;
}

/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @param b
 * @return
 */
template<class K, class V>
  bool HashTable<K,V>::isInBucket(K key, bucket* b){
    return b->contains(key) >= 0;
}

/**
 *
 * @tparam K
 * @tparam V
 * @param key
 * @param val
 * @param b
 */
template<class K, class V>
  void HashTable<K,V>::update(K key, V val, bucket* b){
    int idx = b->contains(key);
    if(idx >= 0){
      b->kv[idx].second = val;
    }

  throw "Internal Logic Error: HashTable::update()";
}


/**
 *
 * @tparam K
 * @tparam V
 * @tparam V
 * @tparam K
 * @param idx
 * @param key not used in this case other than to let compiler determin K's type
 * @param val
 * @param b
 */
template<class K, class V>
  void HashTable<K,V>::update(int idx,K key, V val, bucket* b){
    if(idx >= 0){
      b->kv[idx].second = val;
    }
    key = key;  // this is just to squelch the warning that key was unused.
    throw "Internal Logic Error: HashTable::update()";
  }

/**
 *
 * @tparam K
 * @tparam V
 */
template<class K, class V>
  HashTable<K,V>::~HashTable(){
  for(int i = 0; i <= 95; ++i){
    if(map[i] != nullptr){
      delete map[i];
    }
  }
//  delete[] map;   // I'm not too certain on delete actually, why not use
                    // delete[] map; ?
}
#endif //HASHTABLE_H
