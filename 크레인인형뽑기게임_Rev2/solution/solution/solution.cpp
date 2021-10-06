// solution.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    if (board.size() < 5 || board.size() > 30)
        return 0;

    int answer = 0;

   
    // 행열 입력 받은 것 반대로 바꿔준다.
    vector <int>::iterator iter;
    vector<vector<int>>::reverse_iterator iter_reverse;
    vector<vector<int>> r_board;
    
    // board[0]이 행의 개수가 된다.
    // [3,5,1,3,1] -> 각 row[0] 값에 해당..
    for (unsigned i = 0; i < board[0].size(); i++)
    {
        vector<int> row;
        // board.size가 열의 값이 된다.
        for (int j = board.size() - 1; j >= 0; j--)
        {
            row.push_back(board[j][i]);
        }

        r_board.push_back(row);
    }


    //vector<int>::reverse_iterator iter2;
    vector<int> box;
    //vector<int>::iterator iter;
    for (iter = moves.begin(); iter != moves.end(); iter++)
    {
        int move = *iter;

        vector<int>* board_cols;
        board_cols = &r_board[move - 1];
        if (board_cols == nullptr)
            continue;

        if (board_cols->size() == 0)
            continue;
        int doll = board_cols->back();

        // 0일 때는 추가 안해야 함
        if (doll == 0)
        {
            while (board_cols->size() != 0)
            {
                board_cols->pop_back();
                if (board_cols->size() == 0)
                    break;

                doll = board_cols->back();
                if (doll != 0)
                    break;
            }
        }
        
        if (board_cols->size() == 0)
            continue;

        board_cols->pop_back();
        box.push_back(doll);

        if (box.size() >= 2)
        {
            int i = box.at(box.size() - 1);
            int j = box.at(box.size() - 2);
            if (i == j)
            {
                box.pop_back();
                box.pop_back();
                answer++;
                answer++;
            }

        }

    }

    return answer;
}

int main()
{
    vector <vector<int>> board;
    vector <int> board2;
    vector <int> board3;
    vector <int> board4;
    vector <int> board5;
    vector <int> board6;
    vector <int> board7;

    vector <int> moves;

    //1, 5, 3, 5, 1, 2, 1, 4
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);
    moves.push_back(2);

    //	[[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]

    board2.push_back(0);
    board2.push_back(0);
    board2.push_back(0);
    board2.push_back(0);
    board2.push_back(0);
    board.push_back(board2);

    board3.push_back(0);
    board3.push_back(1);
    board3.push_back(1);
    board3.push_back(0);
    board3.push_back(3);
    board3.push_back(3);
    board.push_back(board3);

    board4.push_back(0);
    board4.push_back(2);
    board4.push_back(5);
    board4.push_back(0);
    board4.push_back(1);
    board.push_back(board4);

    board5.push_back(4);
    board5.push_back(2);
    board5.push_back(4);
    board5.push_back(4);
    board5.push_back(2);
    board.push_back(board5);

    board6.push_back(3);
    board6.push_back(5);
    board6.push_back(1);
    board6.push_back(3);
    board6.push_back(1);
    board.push_back(board6);

    int a = solution(board, moves);
    std::cout << a << endl;
}

