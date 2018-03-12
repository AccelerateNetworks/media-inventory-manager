#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include <functional>

template<class K, class V>
class HashTable {
  
  static const int map_end = {96};
  
  // nested struct to keep everything nice and civil
  struct bucket {
    bucket() = default;

    std::vector<std::pair<K,V>> kv;
    /** determines if the given key, target, is in this bucket
     * If hash properly distributes items across table, this should
     * have O(1) time.
     * @param target
     * @return index position of target if found, else -1
     */
    int contains(const K& target)const {
      int idx = 0;
      while(idx < (int)kv.size() && kv.at(idx).first != target)++idx;
      return (idx < (int)kv.size() && kv.at(idx).first == target)? idx : -1;
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

  /**
   *
   * @param v
   * @return
   */
  void allValsHelper(std::vector<V> &v);
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
  /**
   *
   * @param kType placeholder for type inference
   * @param vType placeholder for type inference
   *
   * @return a vector of V values.
   */
  std::vector<V> retrieveAllValues(K kType, V vType);

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
  this->hasher = hashFunction;
  this->numberOfEntries = 0;
  for(int i = 0; i < map_end; ++i){
    map[i]->kv = std::vector<std::pair<K,V>>(20);
  }
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
  if(index >= map_end)index %= map_end;
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

  if(index < 0 || index >= 96) throw "hash index out of bounds";

  if(map[index] == nullptr) return nullptr;
  if(!isInBucket(key, map[index])) return nullptr;

  return getFromBucket(key, map[index]);
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
  void HashTable<K,V>::update(int idx, K key, V val, bucket* b){
    if(idx >= 0){
      b->kv[idx].second = val;
      return;
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
  for(int i = 0; i < map_end; ++i){
    if(map[i] != nullptr){
      delete map[i];
    }
  }
//  delete[] map;   // I'm not too certain on delete actually, why not use
//                    // delete[] map; ?
}

/**
 *
 * @tparam K
 * @tparam V
 * @param v
 */
template<class K, class V>
  void HashTable<K,V>::allValsHelper(std::vector<V> &v){

    int insert_if_bellow = 10;

    auto swap = [&v](const int &low, const int &hi) -> void {
      V tmp = v.at(low);
      v.at(low) = v.at(hi);
      v.at(hi) = tmp;
    };

    auto insertionLambda = [swap,&v](const int &first,
                                     const int &last)-> void {
      for (unsigned int i = (unsigned int)first; i < last; ++i){
        unsigned int  smallest = i;
        for (unsigned int  j = i+1; j <= last; ++j ) {
          smallest = (v[j] >= 0 && v[j] < v[smallest])? j : smallest ;
        }
        if(smallest > i) {
          swap(smallest,i);
        }
      }// end of for i
    };// end of combineArrays(v,first,last) function
    std::function<void(int, int, int)> pivSorterLambda;
    pivSorterLambda = [&](int l, int mid, int r){
      if (r - l + 1 < insert_if_bellow)
      {
        insertionLambda( l, r );
      }
      else
      {
        while(l < r){
          if(l != mid && v.at(l) <= v.at(mid))++l;
          else if(v.at(r) >= v.at(mid))--r;
          else {
            if(l == r ){
              r = mid;
              mid = l;
            }
            swap(l,r);
          }
        }
        if(l != mid - 1)pivSorterLambda(l,(mid - 1 + l)/2 , mid - 1);
        if(r != mid + 1)pivSorterLambda(mid + 1, (mid+1+r), r);
      }  // end if
    };

    pivSorterLambda(0,(int)(v.size())/2,(int)v.size());

  }

/**
 *
 * @tparam K key type
 * @tparam V value type
 * @param kType placeholder for type inference
 * @param vType placeholder for type inference

 * @return a vector of V values.
 */
template<class K, class V>
  std::vector<V> HashTable<K, V>::retrieveAllValues(K kType, V vType) {
    // this assumes that we are being given a movie object for v;
    std::vector<V> ret(static_cast<unsigned long long int>(numberOfEntries));
    for(int i = 0; i < map_end; ++i){
      auto iterf = map[i]->kv.begin();
      auto iterb = map[i]->kv.end();
      while(iterf != iterb ) ret.push_back(iterf->second);
    }
    allValsHelper(ret);

    return ret;
  }

#endif //HASHTABLE_H
