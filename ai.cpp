#include<iostream>
#include<string>
#include<ollama.hpp>
using namespace std;
int main(){
  string s=(string) ollama::generate("deepseek-r1:1.5b", "why the hand of racism is black");
  cout<<s<<endl;
} 
