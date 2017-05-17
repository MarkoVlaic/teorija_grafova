#include "snphandler.h"
#include <string>

SnpHandler::SnpHandler()
{
  n = m = -1; //Ovo nam je flag da vidimo jel imamo inpute
}

SnpHandler::~SnpHandler()
{
  for(int i=0;i<snpMat.size();i++){
    snpMat[i].clear();
  }
  snpMat.clear();

  for(int i=0;i<fragMat.size();i++){
    fragMat[i].clear();
  }
  fragMat.clear();
}

void SnpHandler::setRowNumber(int n)
{
  this->n = n;
}

void SnpHandler::setColNumber(int m)
{
  this->m = m;
}

std::pair<std::string, std::string> SnpHandler::purify()
{

  printf("Started");

  std::string res;

  if(n == -1 || m == -1){ //Ovdje provjeravamo jel imamo podatke unutra
    fprintf(stderr, "Deder unes sve parametre issa ti prcin");
    return std::make_pair("Nemere", "Nemere");
  }

    std::string hapl = "", hapl2 = "";
    bool* flag = new bool[this->fragMat.size()];
    for (int i=0;i<fragMat.size();i++)
    {
        flag[i] = 0;
    }
    int* num = new int[this->fragMat.size() / 2];
    int* num2 = new int[this->fragMat.size() / 2];
    int count = 0;
    while (count != fragMat.size() - 1){
        int t = rand() % fragMat.size();
        if (flag[t] != 1){
            flag[t] = 1;
            if (count < fragMat.size() / 2){
                num[count] = t;
            }
            else{
                num2[count % fragMat.size() / 2] = t;
            }
            count++;
        }
    }


    for (int i=0;i<fragMat.size() / 2;i++){
      std::string s;
      std::string s2;
      for(int j=0;j<fragMat.size()/2;j++){
        s += fragMat[num[i]][j];
        s2 += fragMat[num2[i]][j];
      }

      hapl += s;
      hapl2 += s2;
    }

    delete[] flag;
    delete[] num;
    delete[] num2;
  return make_pair(hapl, hapl2);
  //Ovdje ide magicni algoritam koji vi radite

//  return res;
}

void SnpHandler::setSnpMat(std::vector<std::vector<char>> snpMat)
{
  for(int i=0;i<snpMat.size();i++){
    std::vector<char> vec;
    this->snpMat.push_back(vec);
    for(int j=0;j<snpMat[i].size();j++){
      this->snpMat[i].push_back(snpMat[i][j]);
    }
  }
}

void SnpHandler::setFragmentMat(std::vector<std::vector<char>> fragmentMat)
{
  for(int i=0;i<fragmentMat.size();i++){
    std::vector<char> vec;
    this->fragMat.push_back(vec);
    for(int j=0;j<fragmentMat[i].size();j++){
      this->fragMat[i].push_back(fragmentMat[i][j]);
    }
  }
}
