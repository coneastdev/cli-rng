# cli rng

A small but easy to use command line tool for generating probability.

## commands

| name | command | description |
| ----- | ----- | ----- |
| help | rng --h | Lists commands |
| show | rng --s [next command] | Use before a command to show the debug information |
| coin flip| rng --c / rng -c [number] [number] | Runs a coin flip, by default it is 50-50 but you can add the probability ratio |
| dice roll | rng --d [number] [number] | Runs a dice roll, you need to specify the number of faces the die has, you can also specify the amount of dice to roll |

## examples
**coin**
```
rng --c
```
**potential output**
```
Heads
```

**show+coin**
```
rng --s --c 1 2
```
**potential output**
```
probability of heads: 0.333333
Tails
```

**dice**
```
rng --d 64 8
```
**potential output**
```
12 16 11 32 55 13 43 35
```

**show+dice**
```
rng --s --d
```
**potential output**
```
faces: 6, dices: 1
3 
```

## how to install

**linux**

Move the executable into your /bin/ directory.

**Windows**

You will have to manually add "rng" to system variables.

## licence

GPL-3.0