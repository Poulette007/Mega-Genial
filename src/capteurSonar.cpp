#include "capteurSonar.h"
#include "libRobus.h"

#define max 50
#define min 0

int getCapteurSonar()
{
    float cm;
    cm = SONAR_GetRange(0);
    if(cm > 0 && cm < 50)
    {
        return 1;
    }
    return 0;
}