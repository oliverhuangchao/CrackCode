#include <iostream>
#include <cstring>

class string {
public:
  string(int n = 0) : buf(new char[n+1]) {
    buf[0] = '\0';
  }
  string(const char* b) : buf(new char[strlen(b)+1]) {
    strcpy(buf, b);
  }
  string(const string& s) : buf(new char[strlen(s.buf)+1]) {
    strcpy(buf, s.buf);
  }
  ~string() { delete [] buf; }
  char* getBuf() const { return buf; }
  void setBuf(const char* b) {
    delete [] buf;
    buf = new char[strlen(b)+1];
    strcpy(buf, b);
  }
  string operator+(const string&) const;
  string& operator=(const string&);
private:
  char* buf;
};
std::ostream& operator<<(std::ostream& out, const string& s) {
  return out << s.getBuf();
}

string string::operator+(const string& rhs) const {
  string temp(strlen(buf)+strlen(rhs.buf));
  strcpy(temp.buf, buf);
  strcat(temp.buf, rhs.buf);
  return temp;
}

string& string::operator=(const string& rhs) {
  if ( this == &rhs ) return *this;
  delete [] buf;
  buf = new char[strlen(rhs.buf)+1];
  strcpy(buf, rhs.buf);
  return *this;
}

void print(const string& s) {
  std::cout << s << std::endl;
}

int main( ) {
  string s("cat");
  string t("alog");
  print(s);
  print(s+t);
  return 0;
}
