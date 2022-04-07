#include <stdio.h>
#include <stdbool.h>
int ip = 0;
bool running = true;
int sp = -1;

typedef enum{
PSH,
ADD,
POP,
SET,
HLT
} instrSet;
typedef enum{A,B,C,D,E,F,IP,SP,NUM_OF_REGISTERS} Registers;

int registers[NUM_OF_REGISTERS];
int stack[256];

const int program[] = {
PSH, 7,
PSH, 8,
ADD,
POP,
HLT
};

int fetch()
{
  return program[ip];
}

void eval(int instr) {
  switch (instr)
  {
    case PSH:
    {
      sp++;
      stack[sp]=program[++ip];
      break;
    }
    case ADD:
    {
      stack[sp-1] = stack[sp-1]+stack[sp];
      sp--;
      break;
    }
    case POP:
    {
      int val = stack[sp--];
      printf("Value: %d\n", val);
      break;
    }
    case SET:
    {
      int r = program[ip++];
      int val = program[ip++];
      registers[r]=val;
      break;
    }
    case HLT:
    {
      running = false;
      break;
    }
  }
}

int main()
{
  registers[IP]=0;
  registers[SP]=-1;
  while(running)
  {
    int instr = fetch();
    eval(instr);
    ip++;
  }
  return 0;
}
