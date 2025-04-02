#ifndef _INPUT_H_
#define _INPUT_H_

enum LastInput {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum LastInput getInput(enum LastInput *lastInput);

#endif