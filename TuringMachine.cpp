#include <iostream>
#include <vector>
#include <string>

struct Transition {
    char currentState;
    char readSymbol;
    char writeSymbol;
    char nextState;
    int direction;  // -1 for left, +1 for right
};

class TuringMachine {
public:
    TuringMachine(const std::string& tapeInput, char startState, char haltState)
        : tape(tapeInput), head(0), state(startState), haltState(haltState) {}

    void addTransition(char currentState, char readSymbol, char writeSymbol, char nextState, int direction) {
        transitions.push_back({currentState, readSymbol, writeSymbol, nextState, direction});
    }

    void run() {
        while (state != haltState) {
            bool transitionFound = false;

            // Find a matching transition
            for (const auto& t : transitions) {
                if (state == t.currentState && tape[head] == t.readSymbol) {
                    // Apply transition
                    tape[head] = t.writeSymbol;
                    head += t.direction;
                    state = t.nextState;
                    transitionFound = true;
                    break;
                }
            }

            if (!transitionFound) {
                std::cerr << "No valid transition found! Halting.\n";
                break;
            }

            // Check bounds and expand tape if needed (optional for finite tape size)
            if (head < 0) {
                tape.insert(tape.begin(), ' ');  // Insert blank on the left
                head = 0;
            } else if (head >= tape.size()) {
                tape.push_back(' ');  // Insert blank on the right
            }
        }
    }

    void printTape() const {
        std::cout << "Final tape: " << tape << "\n";
        std::cout << "Head position: " << head << "\n";
        std::cout << "Final state: " << state << "\n";
    }

private:
    std::string tape;
    int head;
    char state;
    char haltState;
    std::vector<Transition> transitions;
};

int main() {
    // Initialize the Turing machine with a tape, start state, and halt state
    TuringMachine tm("000", 'A', 'H');  // Example initial tape with 3 zeros

    // Define transitions
    tm.addTransition('A', '0', '1', 'A', +1);   // '0' -> '1', move right, stay in 'A'
    tm.addTransition('A', '1', '0', 'B', -1);   // '1' -> '0', move left, switch to 'B'
    tm.addTransition('B', '0', '1', 'H',  0);   // '0' -> '1', halt

    std::cout << "Initial tape: 000\n";

    // Run the Turing machine
    tm.run();

    // Output the final tape
    tm.printTape();

    return 0;
}
