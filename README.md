# cli rng

A small but easy to use command line tool for generating probability.

## commands

| name | command | description |
| ----- | ----- | ----- |
| usage guide | --h / --help | Lists commands |
| show debug info | --s / --show [next command] | Use before a command to show the debug information |
| coin flip| --c / --coin [number] [number] | Runs a coin flip, by default it is 50-50 but you can add the probability ratio |
| dice roll | --d / --dice [number] [number] | Runs a dice roll, you can specify the faces on the dice and the amount of dice, by default it is one d6 |

## examples
**coin**
```
rng --c

Heads
```

**show+coin**
```
rng --s --c 1 2

probability of heads: 0.333333
Tails
```

**dice**
```
rng --d 64 8

12 16 11 32 55 13 43 35
```

**show+dice**
```
rng --s --d

faces: 6, dices: 1
3 
```

## how to install

**linux**

Move the executable into your /bin/ directory.

<!-- **Windows**

You will have to manually add "rng" to system variables. -->

## licence

GPL-3.0