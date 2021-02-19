# MontyHall
This is one of my early programs as I was learning c++

The purpose of this program is to simulate the Monty Hall problem. A little background on the Monty Hall problem is that there are 3 doors, 2 have goats behind them and 1 has a new car. A contestant chooses 1 door that they think has the car, then the host reveals one of the doors with the goat. The contestant then can switch his choice to the remaining door, or keep his original selection. The idea is that switching is the better option because you originally have a 33.3% chance of choosing correctly the first time around. But after the host reveals a goat, you then have a 66.6% chance of winning if you switch. 

This program simulates this by first randomly choosing a winning door. Then it randomly chooses a door for a guess, removes a goat door, then switches to the remaining door. Then the program checks to see if the now switched guess matches the winning door and records the result. Currently, the program is set to simulate it 100,000 times then print the results (# of wins, # of losses, win %) to the console. 

This is probably far from "clean code" as they I have heard people say, but it works.
