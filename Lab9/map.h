#pragma once
#include <iostream>
using namespace std;

template<typename K, typename V>
class Map {
	struct entry {
		K key;
		V value;
		int index;
	};
	entry* entri;
	int count;
	int c;
	struct Iterate {
		entry* ptr;
		explicit Iterate(entry* p) {
			ptr = p;
		}
		Iterate& operator++() {
			ptr++;
			return *this;
		}
		bool operator!=(const Iterate& a) const {
			return ptr != a.ptr;
		}
		auto operator*() const {
			return entry{ ptr->key,ptr->value,ptr->index };
		}
	};
public:
	Map() {
		count = 0;
		c = 1;
		entri = new entry[c];
	}
	~Map() {
		delete[] entri;
	}
	Iterate begin() {
		return Iterate(entri);
	}
	Iterate end() {
		return Iterate(entri + count);
	}
	void Set(const K& key, V& value) {
		auto map = this;
		map[key] = value;
	}
	bool Get(const K& key, V& value) {
		for (int i = 0;i < count;i++) {
			if (entri[i].key == key) {
				value = entri[i].value;
				return true;
			}
		}
		return false;
	}
	int Count() const {
		return count;
	}
	void clear() {
		delete[] entri;
		count = 0;
		c = 1;
		entri = new entry[c];
	}
	bool Delete(const K& key) {
		for (int i = 0; i < count;i++) {
			if (entri[i].key == key) {
				int x = entri[i].index;
				for (int j = x;j < count - 1;j++) {
					entri[j + 1].index--;
					entri[j] = entri[j + 1];
				}
				count--;
				return true;
			}
		}
		return false;
	}
	bool Includes(const Map<K, V>& map) {
		for (const auto& entry : map) {
			if (!Get(entry.key, entry.value)) {
				return false;
			}
		}
		return true;
	}
	V& operator[](const K& key) {
		for (int i = 0;i < count;i++) {
			if (entri[i].key == key) {
				return entri[i].value;
			}
		}
		V value;
		if (count == c) {
			c *= 2;
			auto* newentry = new entry[c];
			for (int i = 0;i < count;i++) {
				newentry[i] = entri[i];
			}
			delete[] entri;
			entri = newentry;
		}
		entri[this->count] = { key,value,this->count };
		this->count++;
		return entri[this->count - 1].value;
	}
};
