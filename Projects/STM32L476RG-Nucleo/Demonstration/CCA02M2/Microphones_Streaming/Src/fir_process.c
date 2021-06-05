#include "fir_process.h"
#include <assert.h>

#include "arm_math.h"

#include "cube_hal.h"



#define TEST_LENGTH_SAMPLES   96  //BLOCK_SIZE_float
#define BLOCK_SIZE            96  //BLOCK_SIZE_float
#define NUM_TAPS              17


extern uint16_t PCM_Buffer[];
extern uint16_t I2S_InternalBuffer[];
extern HAL_StatusTypeDef AUDIO_IN_Timer_Init(void);


uint32_t blockSize = BLOCK_SIZE;
uint32_t numBlocks = TEST_LENGTH_SAMPLES/BLOCK_SIZE;

float32_t testOutput[TEST_LENGTH_SAMPLES*2];
float32_t testInput[TEST_LENGTH_SAMPLES*2];
float32_t firStateF32[BLOCK_SIZE + NUM_TAPS - 1];
uint16_t Filtered[TEST_LENGTH_SAMPLES];

// 17 taps low pass, cutoff at about 8000Hz
static float firCoeffs32[NUM_TAPS] = {
		 -0.0021834891907904987,
		  0.023133081888390004,
		  0.03440125360693663,
		  0.054016706019288735,
		  0.07610902012650608,
		  0.09772535709704201,
		  0.11593264129629442,
		  0.12810228628568973,
		  0.13238343618749146,
		  0.12810228628568973,
		  0.11593264129629442,
		  0.09772535709704201,
		  0.07610902012650608,
		  0.054016706019288735,
		  0.03440125360693663,
		  0.023133081888390004,
		  -0.0021834891907904987
};

// 27 taps high pass
//static float firCoeffs32[NUM_TAPS] = {
//-0.023407821791635055,
//0.007483605671744372,
//0.012776270582352792,
//0.0191120618729217,
//0.023280321680242914,
//0.02185571261554037,
//0.012298820160004144,
//-0.00661626100726055,
//-0.034073792449169624,
//-0.0671219042059157,
//-0.10117559002347454,
//-0.13081889276741943,
//-0.1510059949963812,
//0.8418301719223038,
//-0.1510059949963812,
//-0.13081889276741943,
//-0.10117559002347454,
//-0.0671219042059157,
//-0.034073792449169624,
//-0.00661626100726055,
//0.012298820160004144,
//0.02185571261554037,
//0.023280321680242914,
//0.0191120618729217,
//0.012776270582352792,
//0.007483605671744372,
//-0.023407821791635055
//};



arm_fir_instance_f32 S;
float32_t  *inputF32, *outputF32;


void fir_init(void){
	arm_fir_init_f32(&S, NUM_TAPS, &firCoeffs32[0], &firStateF32[0], blockSize);
}

void fir_process(int16_t* inbuff, int16_t* outbuff, size_t size)
{
	assert(size<=TEST_LENGTH_SAMPLES);
	size_t i, index;

    for (index=0;index < size; index++)
    {
    	testInput[index] = (float32_t)(inbuff[index]);
    }
    inputF32 = &testInput[0];
 	outputF32 = &testOutput[0];
 	arm_fir_f32(&S, inputF32, outputF32, blockSize);
    for (i=0;i<size;i++)
    {
    	outbuff[i] = ((int16_t)testOutput[i]);
    }
}

