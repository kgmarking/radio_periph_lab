

/***************************** Include Files *******************************/
#include "radio_tuner.h"

/************************** Constant Defintions ****************************/
#define CLOCK_FREQ  125000000
#define PHASE_SCALE 134217728 // 2^(PHASE WIDTH = 27)

/*************************** Global Definitions ****************************/
float freq_to_pinc = (float) PHASE_SCALE / (float) CLOCK_FREQ;

/************************** Function Definitions ***************************/
void radioTuner_setAdcFreq(u32 BaseAddress, float freq)
{
    double pinc;
    
    pinc = freq * freq_to_pinc;

    RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_FAKE_ADC_PINC_REG_OFFSET, (float) pinc);
     
    return;
}

void radioTuner_tuneRadio(u32 BaseAddress, float tune_frequency)
{
    double pinc;
    
    pinc = tune_frequency * freq_to_pinc;

    RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_TUNER_PINC_REG_OFFSET, (float) pinc);

    return;
}

void radioTuner_controlReset(u32 BaseAddress, u8 resetval)
{
    RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_CONTROL_REG_OFFSET, resetval);  

    return;
}