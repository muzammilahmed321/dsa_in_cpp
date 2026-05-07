#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {
int rows = board.size();
int cols = board[0].size();
for (int i = 0; i < rows; ++i) {
for (int j = 0; j < cols; ++j) {
if (dfs(board, word, i, j, 0)) {
return true;
} }
}
return false;
}

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
    if (index == word.size()) return true;
if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
return false;
        }
char temp = board[i][j];
board[i][j] = '#';
bool found = dfs(board, word, i + 1, j, index + 1) ||
dfs(board, word, i - 1, j, index + 1) ||
dfs(board, word, i, j + 1, index + 1) ||
dfs(board, word, i, j - 1, index + 1);
board[i][j] = temp;
return found;
    }
};

int main() {
Solution sol;
vector<vector<char>> board = {
{'A', 'B', 'C', 'E'},
{'S', 'F','C', 'S'},
{'A', 'D', 'E'}
};
string word1 = "ABCCED";
string word2 = "ABCB";
cout << "Searching for '" << word1 << "': " << (sol.exist(board, word1)? "true": "false") << endl;
cout << "Searching for '" << word2 << "': " << (sol.exist(board, word2)? "true": "false") << endl;
    return 0;
}
