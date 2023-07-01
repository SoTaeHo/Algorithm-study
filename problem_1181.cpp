//#include "iostream"
//#include "algorithm"
//using namespace std;
//
//int main(void) {
//    int count;
//    cin >> count;
//    string* before = new string[count];
//    for(int i = 0; i < count; i++) {
//        cin >> before[i];
//    }
//
//    sort(before, before + count);
//
//    for(int i = 0; i < count; i++) {
//        cout << before[i] << endl;
//    }
//
//    cout << int(before[0][1]) << endl;
//    return 0;
//
//}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

// 중복된 단어를 제거하는 함수
std::vector<std::string> removeDuplicates(const std::vector<std::string>& words) {
    std::unordered_set<std::string> uniqueWords;
    std::vector<std::string> result;

    for (const std::string& word : words) {
        if (uniqueWords.find(word) == uniqueWords.end()) {
            uniqueWords.insert(word);
            result.push_back(word);
        }
    }

    return result;
}

// 정렬 비교 함수
bool compare_two_string(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> words(N);

    for (int i = 0; i < N; i++) {
        std::cin >> words[i];
    }

    std::sort(words.begin(), words.end(), compare_two_string);
    std::vector<std::string> uniqueSortedWords = removeDuplicates(words);

    for (const std::string& word : uniqueSortedWords) {
        std::cout << word << std::endl;
    }

    return 0;
}
