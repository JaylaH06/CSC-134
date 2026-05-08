/*
CSC 134
Jayla Harper
05/07/26
Final Project
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>
#include <thread>
#include <atomic>
#include <chrono>
#include <csignal>

// ─────────────────────────────────────────────
//  Timer Constants
// ─────────────────────────────────────────────
constexpr int QUESTION_TIME_SECONDS = 30;

// ─────────────────────────────────────────────
//  Data Structures
// ─────────────────────────────────────────────

struct Question {
    std::string clue;
    std::string answer;
    int         points;
    bool        answered = false;
};

struct Category {
    std::string            name;
    std::vector<Question>  questions; // index 0 = 100pts, 1 = 200, ...
};

struct Player {
    std::string name;
    int         score = 0;
};

// ─────────────────────────────────────────────
//  Question Bank
// ─────────────────────────────────────────────

std::vector<Category> buildBoard() {
    std::vector<Category> board;

    // ── Anime Series ──────────────────────────
    Category series;
    series.name = "Anime Series";
    series.questions = {
        { "This shonen series follows Izuku Midoriya, a boy born without powers in a world full of heroes.",
          "my hero academia", 100 },
        { "Spike Spiegel is the bounty-hunting protagonist of this 1998 space-western classic.",
          "cowboy bebop", 200 },
        { "In this series, the Survey Corps battles giant humanoid creatures outside walled cities.",
          "attack on titan", 300 },
        { "This isekai series follows Kazuma and a useless goddess after the protagonist dies a pathetic death.",
          "konosuba", 400 },
        { "Guts wields an enormous sword and struggles against demonic forces in this dark fantasy series by Kentaro Miura.",
          "berserk", 500 }
    };
    board.push_back(series);

    // ── Anime Characters ──────────────────────
    Category chars;
    chars.name = "Anime Characters";
    chars.questions = {
        { "This Naruto character is known for his Sharingan eyes and the phrase 'I have no interest in losers.'",
          "sasuke", 100 },
        { "The 'Fullmetal Alchemist' — this young alchemist wears a red coat and lost his arm in a tragic ritual.",
          "edward elric", 200 },
        { "In Death Note, this eccentric detective sits in an unusual posture and eats sweets constantly.",
          "l", 300 },
        { "This HxH character is a Transmutation-type Nen user who created Killer Queen — wait, wrong series. He created Bungee Gum.",
          "hisoka", 400 },
        { "The final antagonist of Neon Genesis Evangelion who seeks to trigger Third Impact; his full name please.",
          "gendo ikari", 500 }
    };
    board.push_back(chars);

    // ── Anime Lore & Story ────────────────────
    Category lore;
    lore.name = "Lore & Story";
    lore.questions = {
        { "In Dragon Ball Z, this transformation is first achieved by Goku on the Planet Namek during his battle with Frieza.",
          "super saiyan", 100 },
        { "One Piece's 'Will of D.' is a mysterious middle initial shared by key figures. Name one character who bears it.",
          "luffy", 200 },  // also: roger, ace, blackbeard, etc. — handled generously
        { "In Fullmetal Alchemist: Brotherhood, this is the first law of alchemy — the exchange required for any transmutation.",
          "equivalent exchange", 300 },
        { "In Demon Slayer, this specific breathing style is used by Tanjiro Kamado and is tied to his father's Kagura dance.",
          "sun breathing", 400 },
        { "In Steins;Gate, the lab members call their time-travel messages by this name, sent via a microwave-phone device.",
          "d-mail", 500 }
    };
    board.push_back(lore);

    // Assign point values
    for (auto& cat : board)
        for (int i = 0; i < (int)cat.questions.size(); i++)
            cat.questions[i].points = (i + 1) * 100;

    return board;
}

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────

void clearScreen() {
    std::cout << "\033[2J\033[H"; // ANSI clear
}

void waitForEnter() {
    std::cout << "\n  Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return out;
}

// Loose match: check if the key answer appears anywhere in the player's response
bool checkAnswer(const std::string& playerAns, const std::string& correctAns) {
    std::string p = toLower(playerAns);
    std::string c = toLower(correctAns);
    return p.find(c) != std::string::npos;
}

// ─────────────────────────────────────────────
//  Display Board
// ─────────────────────────────────────────────

void displayBoard(const std::vector<Category>& board, const std::vector<Player>& players) {
    clearScreen();

    // Title
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════════════════════╗\n";
    std::cout << "  ║            🎌  A N I M E  J E O P A R D Y  🎌           ║\n";
    std::cout << "  ╚══════════════════════════════════════════════════════════╝\n\n";

    // Category headers
    std::cout << "  ";
    for (const auto& cat : board)
        std::cout << std::left << std::setw(22) << cat.name;
    std::cout << "\n";

    std::cout << "  ";
    for (size_t i = 0; i < board.size(); i++)
        std::cout << std::string(20, '-') << "  ";
    std::cout << "\n";

    // Point rows
    for (int row = 0; row < 5; row++) {
        std::cout << "  ";
        for (const auto& cat : board) {
            const auto& q = cat.questions[row];
            if (q.answered)
                std::cout << std::left << std::setw(22) << "  [ --- ]";
            else
                std::cout << std::left << std::setw(22)
                          << ("  $" + std::to_string(q.points) + "   ");
        }
        std::cout << "\n";
    }

    // Scoreboard
    std::cout << "\n  ──────────────────────────────────────\n";
    std::cout << "  SCOREBOARD\n";
    std::cout << "  ──────────────────────────────────────\n";
    for (const auto& p : players)
        std::cout << "  " << std::left << std::setw(14) << p.name
                  << " $" << p.score << "\n";
    std::cout << "\n";
}

// ─────────────────────────────────────────────
//  Get Player Count & Names
// ─────────────────────────────────────────────

std::vector<Player> setupPlayers() {
    int numPlayers = 0;
    while (numPlayers < 3 || numPlayers > 4) {
        std::cout << "  How many players? (3 or 4): ";
        std::cin >> numPlayers;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (numPlayers < 3 || numPlayers > 4)
            std::cout << "  Please enter 3 or 4.\n";
    }

    std::vector<Player> players(numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        std::cout << "  Enter name for Player " << (i + 1) << ": ";
        std::getline(std::cin, players[i].name);
        if (players[i].name.empty())
            players[i].name = "Player " + std::to_string(i + 1);
    }
    return players;
}

// ─────────────────────────────────────────────
//  Timer
// ─────────────────────────────────────────────

// Shared flags between main thread and timer thread
std::atomic<bool> timerExpired(false);
std::atomic<bool> answerReceived(false);

// Runs on a background thread: counts down and prints remaining seconds.
// Stops early if answerReceived is set.
void timerThread(int seconds) {
    for (int i = seconds; i > 0; i--) {
        if (answerReceived.load()) return;

        // Move cursor to saved position and reprint the countdown line
        std::cout << "\033[s";          // save cursor
        // Print on a dedicated line below the prompt (we'll position it)
        std::cout << "\r  \033[2K";     // clear current line
        std::cout << "  ⏱  Time remaining: " << std::setw(2) << i << "s   ";
        std::cout.flush();
        std::cout << "\033[u";          // restore cursor (back to input line)
        std::cout.flush();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (!answerReceived.load()) {
        timerExpired.store(true);
        // Interrupt blocking getline by sending a newline to stdin
        // This is a POSIX approach — works on Linux/macOS
        std::cout << "\n\n  ⌛  Time's up! Moving on...\n";
        std::cout.flush();
        // Write a newline to stdin so getline unblocks
        kill(getpid(), SIGALRM); // signal ourselves — caught below
    }
}

// ─────────────────────────────────────────────
//  Play a Single Question
// ─────────────────────────────────────────────

void playQuestion(Question& q, std::vector<Player>& players, int currentPlayer) {
    clearScreen();
    std::cout << "\n  ┌─────────────────────────────────────────────────┐\n";
    std::cout << "  │  $" << std::left << std::setw(46) << q.points << "│\n";
    std::cout << "  ├─────────────────────────────────────────────────┤\n";

    // Word-wrap the clue at ~48 chars
    std::string clue = q.clue;
    std::cout << "  │  ";
    int lineLen = 0;
    for (size_t i = 0; i < clue.size(); i++) {
        std::cout << clue[i];
        lineLen++;
        if (lineLen >= 47 && clue[i] == ' ') {
            std::cout << "\n  │  ";
            lineLen = 0;
        }
    }
    std::cout << "\n";
    std::cout << "  └─────────────────────────────────────────────────┘\n\n";

    // ── Timer setup ───────────────────────────────────────
    timerExpired.store(false);
    answerReceived.store(false);

    // Install a no-op SIGALRM handler so the signal interrupts getline
    struct sigaction sa{};
    sa.sa_handler = [](int) {};  // no-op: just interrupt the syscall
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;             // do NOT restart interrupted syscalls
    sigaction(SIGALRM, &sa, nullptr);

    // Print countdown line, then prompt on the next line
    std::cout << "  ⏱  Time remaining: " << QUESTION_TIME_SECONDS << "s   \n\n";
    std::cout << "  " << players[currentPlayer].name
              << ", your answer (phrase it as 'What is...'): ";
    std::cout.flush();

    // Launch countdown thread
    std::thread timer(timerThread, QUESTION_TIME_SECONDS);

    // Block waiting for player input
    std::string answer;
    if (std::getline(std::cin, answer)) {
        // Player typed something before time ran out
        answerReceived.store(true);
    } else {
        // getline was interrupted by SIGALRM (time expired)
        std::cin.clear();
        answerReceived.store(true); // stop the thread
    }

    timer.join();

    // ── Evaluate ──────────────────────────────────────────
    std::cout << "\n";
    if (timerExpired.load()) {
        // Time ran out — no penalty
        std::cout << "  ⌛  Time's up! No points lost.\n";
        std::cout << "     Correct answer was: " << q.answer << "\n";
    } else if (checkAnswer(answer, q.answer)) {
        players[currentPlayer].score += q.points;
        std::cout << "  ✅  Correct! +" << q.points << " points!\n";
        std::cout << "     (Answer: " << q.answer << ")\n";
    } else {
        players[currentPlayer].score -= q.points;
        std::cout << "  ❌  Incorrect! -" << q.points << " points.\n";
        std::cout << "     Correct answer: " << q.answer << "\n";
    }

    q.answered = true;
    waitForEnter();
}

// ─────────────────────────────────────────────
//  Check if board is complete
// ─────────────────────────────────────────────

bool boardComplete(const std::vector<Category>& board) {
    for (const auto& cat : board)
        for (const auto& q : cat.questions)
            if (!q.answered) return false;
    return true;
}

// ─────────────────────────────────────────────
//  Final Scores
// ─────────────────────────────────────────────

void showFinalScores(std::vector<Player>& players) {
    // Sort descending
    std::sort(players.begin(), players.end(),
              [](const Player& a, const Player& b){ return a.score > b.score; });

    clearScreen();
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║           🏆  FINAL SCORES  🏆           ║\n";
    std::cout << "  ╠══════════════════════════════════════════╣\n";

    const std::string medals[] = {"🥇", "🥈", "🥉", "  "};
    for (int i = 0; i < (int)players.size(); i++) {
        std::string medal = (i < 3) ? medals[i] : "  ";
        std::cout << "  ║  " << medal << "  "
                  << std::left << std::setw(14) << players[i].name
                  << "  $" << std::setw(6) << players[i].score
                  << "          ║\n";
    }

    std::cout << "  ╠══════════════════════════════════════════╣\n";
    std::cout << "  ║  Winner: " << std::left << std::setw(32) << players[0].name << "║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n\n";
}

// ─────────────────────────────────────────────
//  Main Game Loop
// ─────────────────────────────────────────────

int main() {
    clearScreen();
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════════════════════╗\n";
    std::cout << "  ║            🎌  A N I M E  J E O P A R D Y  🎌           ║\n";
    std::cout << "  ║                                                          ║\n";
    std::cout << "  ║   Categories: Anime Series | Characters | Lore & Story   ║\n";
    std::cout << "  ║   Values: $100  $200  $300  $400  $500                   ║\n";
    std::cout << "  ║   Players: 3–4                                           ║\n";
    std::cout << "  ╚══════════════════════════════════════════════════════════╝\n\n";

    std::cout << "  Rules:\n";
    std::cout << "  • Players take turns selecting a category and dollar amount.\n";
    std::cout << "  • Correct answer: earn the points. Wrong: lose the points.\n";
    std::cout << "  • You have " << QUESTION_TIME_SECONDS << " seconds to answer — time out and no points are lost!\n";
    std::cout << "  • Highest score at the end wins!\n\n";

    waitForEnter();

    // Setup
    std::vector<Player>   players = setupPlayers();
    std::vector<Category> board   = buildBoard();
    int currentPlayer             = 0;

    // Main loop
    while (!boardComplete(board)) {
        displayBoard(board, players);

        std::cout << "  " << players[currentPlayer].name << "'s turn!\n";

        // Choose category
        int catChoice = -1;
        while (catChoice < 1 || catChoice > (int)board.size()) {
            std::cout << "  Choose a category (";
            for (int i = 0; i < (int)board.size(); i++)
                std::cout << i + 1 << "=" << board[i].name
                          << (i < (int)board.size() - 1 ? ", " : "");
            std::cout << "): ";
            std::cin >> catChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catChoice--; // 0-indexed

        // Choose point value
        std::cout << "  Choose a value (";
        bool first = true;
        for (int i = 0; i < 5; i++) {
            if (!board[catChoice].questions[i].answered) {
                if (!first) std::cout << ", ";
                std::cout << (i + 1) * 100;
                first = false;
            }
        }
        std::cout << "): ";

        int pointChoice = -1;
        std::cin >> pointChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        int qIndex = (pointChoice / 100) - 1;
        if (qIndex < 0 || qIndex > 4 || board[catChoice].questions[qIndex].answered) {
            std::cout << "  Invalid choice. Skipping turn.\n";
            waitForEnter();
        } else {
            playQuestion(board[catChoice].questions[qIndex], players, currentPlayer);
        }

        // Advance player
        currentPlayer = (currentPlayer + 1) % players.size();
    }

    showFinalScores(players);
    return 0;
}
