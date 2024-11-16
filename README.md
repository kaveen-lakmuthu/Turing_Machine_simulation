# Turing Machine simulation

Explanation of the Code

    Transition Structure:
        Stores the conditions and actions for a single transition, including the current state, read symbol, write symbol, next state, and direction of movement.

    TuringMachine Class:
        Encapsulates the Turing machine's properties and behavior.
        tape: A std::string representing the tape, initialized with an input value.
        head: Tracks the position of the head on the tape.
        state: Tracks the current state.
        haltState: The state at which the machine should halt.
        transitions: A vector that stores all transitions.

    addTransition:
        A method that lets you add transitions to the machine. Each transition is appended to the transitions vector.

    run:
        The main loop of the Turing machine.
        For each step, it looks for a transition that matches the current state and the symbol under the head.
        If a match is found, it updates the tape, moves the head, and changes the state based on the transition.
        If no match is found, it stops the machine.
        It also manages bounds by expanding the tape to the left or right as needed.

    printTape:
        Prints the final state of the tape, the head position, and the final state of the machine.
