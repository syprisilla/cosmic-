#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;

class RockPaperScissors {
private:
    string answer_1;
    string answer_2;
    string RockScissorsPaper[3] = { "가위","바위","보" };
    bool playAgain;

public:
    RockPaperScissors() {
        srand(static_cast<unsigned int>(time(0)));
        playAgain = true;
    }

    void playGame() {
        while (playAgain) {
            int ComputerNum = rand() % 3;
            cout << "청개구리 가위, 바위, 보를 시작합니다." << endl;
            cout << "가위, 바위, 보를 입력해주세요: ";
            cin >> answer_1;
            cout << "상대방은 [" << RockScissorsPaper[ComputerNum] << "]를 냈습니다" << endl;
            time_t time_start = time(NULL);
            cin >> answer_2;

            if (time(NULL) > time_start + 3) {
                cout << "시간 초과입니다" << endl;
            }
            else {

                if (answer_1 == RockScissorsPaper[ComputerNum]) {
                    if (answer_2 == "개굴")
                        cout << "승리하셨습니다!" << endl;
                    else
                        cout << "졌습니다!" << endl;
                }
                else if (((answer_1 == "가위") && (RockScissorsPaper[ComputerNum] == "보")) || ((answer_1 == "보") && (RockScissorsPaper[ComputerNum] == "바위")) || ((answer_1 == "바위") && (RockScissorsPaper[ComputerNum] == "가위"))) {
                    if (answer_2 == "졌다")
                        cout << "승리하셨습니다!" << endl;
                    else
                        cout << "졌습니다!" << endl;
                }
                else if (((answer_1 == "가위") && (RockScissorsPaper[ComputerNum] == "바위")) || ((answer_1 == "보") && (RockScissorsPaper[ComputerNum] == "가위")) || ((answer_1 == "바위") && (RockScissorsPaper[ComputerNum] == "보"))) {
                    if (answer_2 == "이겼다")
                        cout << "승리하셨습니다!" << endl;
                    else
                        cout << "졌습니다!" << endl;
                }

                cout << "새로 시작하려면 : 1, 중지하려면 : 2" << endl;
                int choice;
                cin >> choice;
                playAgain = (choice == 1);
            }
        }
    }
};

int main() {
    RockPaperScissors game;
    game.playGame();

    return 0;
}
