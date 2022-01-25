#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

void BuildCharCounters(string a, string b) {
  map <char, int> first_word;
  map <char, int> second_word;
  for (auto i : a) {
    if (first_word[i] == NULL)
      first_word[i] = 1;
    else
      first_word[i] += 1;
  } 
  for (auto i : b) {
    if (second_word[i] == NULL)
      second_word[i] = 1;
    else
      second_word[i] += 1;
  } 
  if (first_word == second_word)
    printf("YES\n");
  else
    printf("NO\n");




}

int main() {
  int n;
  scanf("%d", &n);
  string first, second;
  for (int i = 0; i < n; i++) {
    cin >> first >> second;
    BuildCharCounters(first, second);
  }
  return 0;
}