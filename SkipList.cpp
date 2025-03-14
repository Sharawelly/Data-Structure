#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template<typename T>
class Node {
    T value;
public:
    T *key;
    vector<Node *> forward;

    Node(T Key, int level) {
        value = Key;
        key = &value;
        forward.resize(level + 1, nullptr);
    }
};

template<typename T>
class SkipList {
private:
    int level;
    Node<T> *header;

    int randomLevel() {
        int lvl = 0;
        while ((float) rand() / RAND_MAX < P && lvl < MAXLVL) {
            lvl++;
        }
        return lvl;
    }

    Node<T> *createNode(T key, int lvl) {
        return new Node<T>(key, lvl);
    }

public:
    float P;
    int MAXLVL;

    SkipList(int max_lvl, float probability) {
        MAXLVL = max_lvl;
        P = probability;
        level = 0;
        header = createNode(T(), MAXLVL);
    }

    void insertElement(T key) {
        vector < Node<T> * > update(MAXLVL + 1);
        Node<T> *current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && *current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || *current->key != key) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            Node<T> *newNode = createNode(key, rlevel);

            for (int i = 0; i <= rlevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    void deleteElement(T key) {
        vector < Node<T> * > update(MAXLVL + 1);
        Node<T> *current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && *current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && *current->key == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            while (level > 0 && header->forward[level] == nullptr) {
                level--;
            }
        }
    }

    T *searchElement(T key) {
        Node<T> *current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && (*current->forward[i]->key < key)) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        return (current == NULL ? nullptr : current->key);

    }

    void displayList() {
        cout << "Skip List:\n";
        for (int i = 0; i <= level; i++) {
            Node<T> *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << *node->key << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }

    Node<T> *&begin() {
        return header;
    }

};


class Game {
private:
    SkipList<pair < string, int>> scores;

    vector <pair<string, int>> topN(int n) {
        vector <pair<string, int>> result;
        Node<pair < string, int>>
        *current = scores.begin();

        SkipList<pair < int, string>>
        toSort(scores.MAXLVL, scores.P);

        int cnt = 0;
        while (current && cnt < n) {
            cnt++;
            current = current->forward[0];
            toSort.insertElement({current->key->second, current->key->first});
        }
        Node<pair < int, string>>
        *current2 = toSort.begin();
        while (current2 && result.size() < n) {
            current2 = current2->forward[0];
            result.emplace_back(current2->key->second, current2->key->first);
        }
        return result;

    }

public:
    Game(int maxLevel = 16, float p = 0.5) : scores(maxLevel, p) {

    }

    void addPlayer(const string &name) {

        scores.insertElement({name, 0});
        cout << "> Player IS ADDED SUCCESSFULLY AND ITS name IS " << name << "\n";
    }

    void removePlayer(const string &playerName) {
        auto Data = scores.searchElement({playerName, 0});
        scores.deleteElement(*Data);
    }

    void updateScore(const string &playerName, int Score) {
        auto Data = scores.searchElement({playerName, 0});
        if (Data) {
            Data->second += Score;

        } else {
            cout << "Player not found!\n";
        }
    }

    void getLeaderboard(int n) {
        vector <pair<string, int>> leaderboard = topN(n);
        if (leaderboard.empty())
            cout << "No players\n";
        for (int i = leaderboard.size() - 1; i >= 0; i--) {
            cout << "Player Name : " << leaderboard[i].first << " score : " << leaderboard[i].second
                 << "\n";
        }
    }
};

int main() {
    Game game;
    cout << "Skip List Test ........\n"
    SkipList<int> list(3, 0.5);

    list.insertElement(3);
    list.insertElement(6);
    list.insertElement(7);
    list.insertElement(9);
    list.insertElement(12);
    list.insertElement(19);

    list.displayList();

    auto it = list.searchElement(19);
    if (it == nullptr) {
        cout << "key not found\n";
    } else {
        cout << "key found\n";
        it = list.searchElement(5);
    }
    if (it == nullptr) {
        cout << "key not found\n";
    } else {
        cout << "key found\n";
    }

    list.deleteElement(6);
    list.displayList();

    cout << "\nEnd of the test ..........\n";

    cout << "Welcome to the Interactive Leaderboard Game!" << endl;
    cout << "Commands:" << endl;
    cout << "1. add <Player Name>          - Add a new player" << endl;
    cout << "2. remove <player_id>       - Remove a player" << endl;
    cout << "3. update <playerName> <score> - Update a player's score" << endl;
    cout << "4. leaderboard <n>          - Show top N players" << endl;
    cout << "5. exit                     - Exit the game" << endl;

    string command;
    int cnt = 0;
    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "add") {
            string palyerName;
            cin >> palyerName;
            game.addPlayer(palyerName);
            cnt++;

        } else if (command == "remove") {
            string playerId;
            cin >> playerId;
            game.removePlayer(playerId);
            cnt--;

        } else if (command == "update") {
            string playerName;
            int score;
            cin >> playerName >> score;
            game.updateScore(playerName, score);

        } else if (command == "exit") {
            break;
        }
        game.getLeaderboard(cnt);
        cout << "\n";
    }

    cout << "Good bye!";


}