#include <iostream>
#include <string.h>

using namespace std;

class String {
private:
  char* _chrs;
  size_t _size;
public:
  size_t size() { return strlen(this->_chrs); }

  // Empty initilizer
  String(size_t init_size) {
    _chrs = new char[init_size];
    _size = init_size;

    if (_chrs != NULL) {
      for(size_t i=0; i < init_size; i++) {
        _chrs[i] = '\0';
      }
    }
  }

  // Char*
  String(const char* chrs) {
    size_t size = strlen(chrs);

    _chrs = new char[size];
    _size = size;

    if (_chrs != NULL) {
      strncpy(_chrs, chrs, size);
    }
  }

  void setText(const char* text) {
    delete[] this->_chrs;

    this->_size = strlen(text);
    this->_chrs = new char[this->_size];

    strncpy(this->_chrs, text, this->_size);
  }

  void setLength(size_t size) {
    size_t old_length = this->size();
    char* old_data = this->_chrs;

    this->_size = size;
    this->_chrs = new char[size];

    // Copy the characters (or add \0 if there are no characters anymore).
    for (size_t i = 0; i < size; i++) {
      if (i < old_length) {
        this->_chrs[i] = old_data[i];
      } else {
        this->_chrs[i] = '\0';
      }
    }

    // Destroy the old data
    delete[] old_data;

    // Ensure that the last element is \0
    this->_chrs[size] = '\0';
  }

  void add(const String &text) {
    size_t new_size = this->_size + text._size;
    setLength(new_size);

    size_t length = size();
    for (size_t i = length; i < new_size; i++) {
      this->_chrs[i] = text._chrs[i - length];
    }
  }

  String operator+(String const & rhs) const {
    String s(_chrs);
    s.add(rhs);

    return s;
  }

  friend String operator+(String const & a, String const & b) {
    String s(a._chrs);

    s.add(b);
    return s;
  }

  String &operator+=(String const & rhs) {
    add(rhs);
    return *this;
  }

  String& operator=(const String& rhs) {
    _chrs = rhs._chrs;
    _size = rhs._size;
    return *this;
  }

  friend bool operator==(String const & lhs, String const & rhs) {
    if (lhs._size != rhs._size) return false;

    for(size_t i = 0; i<lhs._size; i++) {
      if (lhs._chrs[i] != rhs._chrs[i]) return false;
    }

    return true;
  }

  friend bool operator<(String const & lhs, String const & rhs) {
    int lm = min(lhs._size, rhs._size);

    for(size_t i = 0; i<lm; i++) {
      if (lhs._chrs[i] > rhs._chrs[i]) return false;
    }

    return true;
  }

  void print(char end_char='\n') {
    printf("%s%c", _chrs, end_char);
  }

  
};

int main(int argc, char const *argv[])
{
  char* alireza = new char[7]{'a', 'l', 'i', 'r', 'e', 'z', 'a'};
  char* jafartash = new char[9]{'j', 'a', 'f', 'a', 'r', 't', 'a', 's', 'h'};
  String s(alireza);
  String t(jafartash);

  String q(new char[2]{'a', 'b'});
  q.print();
  q += alireza;
  q.print();

  q = jafartash;
  q.print();

  cout << (q == jafartash) << endl;

  cout << (alireza < jafartash) << endl;

}


// = += == <
