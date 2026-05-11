# Rock Paper Scissors

A simple C console game that lets you play Rock Paper Scissors against the computer.

## Description

This program randomly generates the computer's choice and compares it against the player's input. After each round, you can choose to replay or exit. When you finish, the program optionally displays a scorecard with wins, losses, draws, and overall accuracy.

## How to Compile

Use `gcc` to compile the program:

```bash
gcc rockPaperScissors.c -o rockPaperScissors
```

## How to Run

```bash
./rockPaperScissors
```

## How to Play

1. Start the program.
2. Enter `0` to play or `1` to exit.
3. If you play, choose:
   - `1` for Rock
   - `2` for Paper
   - `3` for Scissors
4. The computer will reveal its choice and the result of the round.
5. After each round, choose `0` to replay or `1` to exit.
6. At the end, choose whether to print the scorecard.

## Game Rules

- Rock beats Scissors
- Scissors beats Paper
- Paper beats Rock
- Same choice results in a draw

## Scorecard

If you choose to print the scorecard after exiting, the program shows:

- Total wins
- Total losses
- Total draws
- Overall win percentage

## Notes

- The computer choice is randomly generated using `rand()` seeded with the current time.
- Input is read from standard input using `scanf`.
- The program clears the console between rounds when replaying.

Enjoy playing!
