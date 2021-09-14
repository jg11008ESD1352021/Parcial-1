#ifndef LOOPS_H_INCLUDED
#define LOOPS_H_INCLUDED

//ciclos for
#define LOOP(var,max) for(var=0;var<max;var++)
#define LOOPMe(var,LimMe) for(var=0;var<LimMe;var++)
#define LOOPEq(var,LimEq) for(var=0;var>=LimEq;var++)
#define LOOPeQ(var,LimeQ) for(var=0;var<=LimeQ;var++)
#define LOOPME(var,LimME) for(var=1;var<LimME;var++)
#define LOOPEQ(var,LimEQ) for(var=1;var<=LimEQ;var++)

// infos
int x;
int y[1];
#define MemReservadaArreglo(x) (sizeof(x))
#define TamanoPrimeraCelda(x) (sizeof(y[0])

#endif // LOOPS_H_INCLUDED