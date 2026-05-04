/*
CSC 134
Jayla Harper
M7Lab1
05/04/26
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

// Direction constants
enum Direction {
    NORTH = 1,
    SOUTH = 2,
    EAST = 4,
    WEST = 8
};

const std::pair<int, int> DIRECTION_OFFSETS[] = {
    {0, 0},  // Placeholder for index 0
    {0, -1}, // NORTH
    {0, 1},  // SOUTH
    {0, 0},  // Placeholder
    {1, 0},  // EAST
    {0, 0},  // Placeholder
    {0, 0},  // Placeholder
    {0, 0},  // Placeholder
    {-1, 0}  // WEST
};

const Direction OPPOSITES[] = {
    (Direction)0,
    SOUTH,
    NORTH,
    (Direction)0,
    WEST,
    (Direction)0,
    (Direction)0,
    (Direction)0,
    EAST
};

// Cell class representing a single cell in the maze
class Cell {
private:
    int row;
    int col;
    int links;

public:
    Cell(int row, int col) : row(row), col(col), links(0) {}

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool linked(Direction direction) const {
        return (links & direction) != 0;
    }

    void link(Direction direction) {
        links |= direction;
    }

    void unlink(Direction direction) {
        links &= ~direction;
    }

    std::vector<Direction> getLinks() const {
        std::vector<Direction> result;
        if (linked(NORTH)) result.push_back(NORTH);
        if (linked(SOUTH)) result.push_back(SOUTH);
        if (linked(EAST))  result.push_back(EAST);
        if (linked(WEST))  result.push_back(WEST);
        return result;
    }
};

// Represents a position in the grid as a simple row/col pair
struct Position {
    int row, col;
    bool operator<(const Position& other) const {
        if (row != other.row) return row < other.row;
        return col < other.col;
    }
    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
};

// Grid class representing the entire maze
class Grid {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> cells;
    std::mt19937 rng;

public:
    Grid(int rows, int cols) : rows(rows), cols(cols) {
        rng.seed(static_cast<unsigned int>(std::time(nullptr)));

        cells.resize(rows);
        for (int r = 0; r < rows; r++) {
            cells[r].reserve(cols);
            for (int c = 0; c < cols; c++) {
                cells[r].emplace_back(r, c);
            }
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool isValid(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    Cell& at(int row, int col) {
        return cells[row][col];
    }

    const Cell& at(int row, int col) const {
        return cells[row][col];
    }

    int random(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    void linkCells(int row1, int col1, Direction dir) {
        if (!isValid(row1, col1)) return;

        int row2 = row1 + DIRECTION_OFFSETS[dir].second;
        int col2 = col1 + DIRECTION_OFFSETS[dir].first;

        if (!isValid(row2, col2)) return;

        at(row1, col1).link(dir);
        at(row2, col2).link(OPPOSITES[dir]);
    }

    // --- BFS Pathfinding ---
    // Returns the set of positions on the shortest path from start to end.
    // Returns empty set if no path exists.
    std::vector<Position> findPath(Position start, Position end) const {
        // BFS queue holds positions to visit
        std::queue<Position> frontier;
        // cameFrom maps each visited position back to where we came from
        std::map<Position, Position> cameFrom;

        frontier.push(start);
        cameFrom[start] = start; // Start came from itself (sentinel)

        const Direction allDirs[] = { NORTH, SOUTH, EAST, WEST };

        while (!frontier.empty()) {
            Position current = frontier.front();
            frontier.pop();

            // If we've reached the end, reconstruct the path
            if (current == end) {
                std::vector<Position> path;
                Position step = end;
                // Walk backwards through cameFrom until we reach the start
                while (!(step == start)) {
                    path.push_back(step);
                    step = cameFrom[step];
                }
                path.push_back(start);
                return path; // Note: path is end->start order, display handles it
            }

            // Check each direction for open passages
            for (Direction dir : allDirs) {
                const Cell& cell = at(current.row, current.col);
                if (!cell.linked(dir)) continue; // Wall here, skip

                Position neighbor = {
                    current.row + DIRECTION_OFFSETS[dir].second,
                    current.col + DIRECTION_OFFSETS[dir].first
                };

                // Only visit unvisited neighbors
                if (cameFrom.find(neighbor) == cameFrom.end()) {
                    cameFrom[neighbor] = current;
                    frontier.push(neighbor);
                }
            }
        }

        return {}; // No path found
    }

    // Display the maze, marking path cells with '*'
    void display(const std::vector<Position>& path = {}) const {
        // Build a quick lookup set for path positions
        std::vector<std::vector<bool>> onPath(rows, std::vector<bool>(cols, false));
        for (const Position& p : path) {
            onPath[p.row][p.col] = true;
        }

        // Mark start and end distinctly
        Position start = path.empty() ? Position{-1,-1} : path.back();
        Position end   = path.empty() ? Position{-1,-1} : path.front();

        // Top border
        std::cout << "+";
        for (int c = 0; c < cols; c++) std::cout << "---+";
        std::cout << std::endl;

        for (int r = 0; r < rows; r++) {
            // Western wall and cell contents
            std::cout << "|";
            for (int c = 0; c < cols; c++) {
                Position here = {r, c};
                // Choose the character to display inside the cell
                if (here == start)       std::cout << " S ";
                else if (here == end)    std::cout << " E ";
                else if (onPath[r][c])   std::cout << " * ";
                else                     std::cout << "   ";

                // Eastern wall or passage
                if (c < cols - 1 && cells[r][c].linked(EAST))
                    std::cout << " ";
                else
                    std::cout << "|";
            }
            std::cout << std::endl;

            // Southern wall or passage
            std::cout << "+";
            for (int c = 0; c < cols; c++) {
                if (r < rows - 1 && cells[r][c].linked(SOUTH))
                    std::cout << "   +";
                else
                    std::cout << "---+";
            }
            std::cout << std::endl;
        }
    }
};

// BinaryTree maze generator
class BinaryTreeMaze {
public:
    static void on(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            for (int c = 0; c < grid.getCols(); c++) {
                std::vector<Direction> neighbors;

                if (r > 0)                   neighbors.push_back(NORTH);
                if (c < grid.getCols() - 1)  neighbors.push_back(EAST);

                if (!neighbors.empty()) {
                    int index = grid.random(0, neighbors.size() - 1);
                    grid.linkCells(r, c, neighbors[index]);
                }
            }
        }
    }
};

void print_help(const char* program_name) {
    cout << "MazeBuilder - Maze generation + BFS pathfinding\n\n";
    cout << "Usage: " << program_name << " [OPTIONS] [rows] [columns]\n\n";
    cout << "Arguments:\n";
    cout << "  rows          Number of rows in the maze (default: 10)\n";
    cout << "  columns       Number of columns in the maze (default: 10)\n\n";
    cout << "Options:\n";
    cout << "  -h, --help    Show this help message and exit\n\n";
    cout << "Display:\n";
    cout << "  S = Start (top-left)    E = End (bottom-right)\n";
    cout << "  * = Shortest path\n\n";
    cout << "Algorithm:\n";
    cout << "  Maze: Binary Tree - carves north or east at each cell.\n";
    cout << "  Path: BFS - guarantees the shortest path from S to E.\n";
}

int main(int argc, char* argv[]) {
    int rows = 10;
    int cols = 10;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(argv[0]);
            return 0;
        }
    }

    if (argc > 1) rows = std::atoi(argv[1]);
    if (argc > 2) cols = std::atoi(argv[2]);

    // Generate the maze
    Grid grid(rows, cols);
    BinaryTreeMaze::on(grid);

    // Find shortest path from top-left to bottom-right
    Position start = {0, 0};
    Position end   = {rows - 1, cols - 1};
    std::vector<Position> path = grid.findPath(start, end);

    // Display with path marked
    cout << "\nMaze with shortest path (S=Start, E=End, *=Path):\n\n";
    grid.display(path);
    cout << "\nPath length: " << path.size() << " cells\n";

    return 0;
}