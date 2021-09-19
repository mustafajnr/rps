Breakdown of milestones
=======================

# Milestone 1: Command-line Application

This milestone is concerned with creating a command-line rock-paper-scissor game. The system should consist of a command-line interface allowing the user to create characters, initiate games between them, and tracking the characters progress.

The game will also consist of two modes of competitions: a round-robin and a tournament. Each can be constructed with any number of users.

The interface should provide means of storing the data (including characters, games, and competitions) in persistent storage. The application will also display status messages that communicate the status of the respective commands.

As part of this milestone, the basic rules mentioned in the demo (can be found [here](demo/docs/rules.md)) can be adopted, or the developer can come up with their own set of rules.

Following is a break-down of the milestone.

## Checkpoint 1: basic command-line application

### Requirements

* a 'hello world' command-line application.

This checkpoint does not require in-depth code review, as long as the application is producing a message on the terminal.

### Acceptance criteria

* a program that produces a 'hello world' message.

### Knowledge To-Do

1. choose a programming language to develop with (technology-dependent: programming language)
2. learn about printing simple messages using that programming language (technology-dependent: programming language)
3. learn about how the programming language works to produce the simple message (technology-dependent: programming language)

## Checkpoint 2: core game mechanics

### Requirements

1. coming up with a model that represents rock-paper-scissor
2. coming up with a function that can decide the winner from a rock-paper-scissor game

This checkpoint does not require in-depth code review, but will involve a spike program, and a review of the mechanics produced.

### Acceptance criteria

* a spike program that demonstrates rock-paper-scissor logic

The spike program can be in any form, as long as it tests all possibilities of a rock-paper-scissor game.

### Knowledge To-Do

1. learn about data types
    a. theory
    b. application using programming language (technology-dependent: programming language)
2. learn about control statements
    a. theory
    b. application using programming language (technology-dependent: programming language)
3. learn about functions
    a. theory
    b. application using programming language (technology-dependent: programming language)
4. learn about source control
    a. theory
    b. application using source control technology (technology-dependent: source control technology)
5. (optional) learn about command-line arguments
    a. theory
    b. application using source control technology (technology-dependent: source control technology)

## Checkpoint 3: players class

### Requirements

1. coming up with a representation of players in your application
2. implement the representation using your chosen programming language

This checkpoint involves the first in-depth code review by a peer and an experienced software developer.

### Acceptance criteria

1. A basic project structure corresponding to your programming language
2. A class that represents players with appropriate constructors and functions
3. A string representation of objects from the class
4. A test program that tests the player class

### Knowledge To-Do

1. learn about object-oriented programming
    a. theory
    b. application using programming language (technology-dependent: programming language)
2. learn about strings
    a. theory
    b. application using programming language (technology-dependent: programming language)
3. learn about string representation
    a. theory
    b. application using programming language (technology-dependent: programming language)
4. learn about code reviews

## Checkpoint 4: game class structure

This is the first major checkpoint for this milestone, and for the path in general, as it involves using multiple components and integrating them together.

### Requirements

1. coming up with a representation of games in your application, linking it with the representation for players
2. implement the representation using your chosen programming language

This checkpoint involves code review by a peer and an experienced software developer.

### Acceptance criteria

1. A class that represents players with appropriate constructors and functions
2. A string representation of objects from the class
3. The test program is updated to test the game class.

### Knowledge To-Do

1. learn about memory representation of objects
    a. theory
    b. application using programming language (technology-dependent: programming language)
2. learn about copying and references
    a. theory
    b. application using programming language (technology-dependent: programming language)
3. learn about classes organisation (physical design)
    a. theory
    b. application using programming language (technology-dependent: programming language)
4. learn about interactions between classes (logical design)
    a. theory
    b. application using programming language (technology-dependent: programming language)

## Checkpoint 5: game implementation

This second major checkpoint involves complex business logic and interactions between classes.

### Requirements

1. implement the core game mechanics from checkpoint #2 in the game class
2. complete the implementation of the game class to simulate a full game, without rewards

This checkpoint involves code review by a peer and an experienced software developer.

### Acceptance criteria

1. The game class is updated with core game mechanics
2. The game class is updated with functionality to continue the game until a winner is declared
3. The test program is updated to test the new functionalities of the game class

### Knowledge To-Do

1. learn about loops
    a. theory
    b. application using programming language (technology-dependent: programming language)

## Checkpoint 6: rewards implementation

This third major checkpoint involves adding logic to apply rewards either from winning a point or from spending longer in the game than your lifebar (according to the rules).

### Requirements

1. implement the rewards mechanics

This checkpoint involves code review by a peer and an experienced software developer.

### Acceptance criteria

1. The game class is updated with the rewards game mechanics
2. The test program is updated to test the new functionalities of the game class