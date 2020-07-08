# sonarHCSR04

Simple lib to use when playing with the HCSR04 module and ATmega328 (+ Arduino Uno, Nano)

### Intructions
Copy the hcsr04 folder inside lib directory to your project directory and include in the main *C* file like this:

```
#include "hcsr04.h"
```

Then, to setup inputs and outputs, you should call:

```
setupHCSR04();
```

To send the Trigger pulse call:

```
sendTrigger();
```

To receive Echo pulse call:

```
waitEcho(double *echotime);
```

And, finally, to convert time into distance, call:

```
pulseWidth(uint16_t *distance, double echotime);
```

Check main.cpp to see how it is working.
