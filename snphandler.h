#ifndef SNP_HANDLER
#define SNP_HANDLER

#include <vector>
#include <stdio.h>
#include <string>

class SnpHandler{
 public:
  SnpHandler();
  ~SnpHandler();
  void setRowNumber(int n); //Valjda kuzite kaj ovo radi
  void setColNumber(int m); //Ovo isto
  void setSnpMat(std::vector<std::vector<char>> snpMat);
  void setFragmentMat(std::vector<std::vector<char>> fragmentMat);
  std::pair<std::string, std::string> purify(); //Ovo vi implementirate pizde
// private:
  int n, m; // n - retci m - stupci
  std::vector<std::vector<char>> snpMat;
  std::vector<std::vector<char>> fragMat;
};

#endif
