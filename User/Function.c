// Include
#include <Function.h>

/* Private variables ---------------------------------------------------------*/


/**
  * @brief  InputData for IC
  * @param  Input Binary 1 or 0, 1 is set to High, 0 is set to low
  * @retval None
  */
void InputData(uint8_t Bit)
{
	if (Bit)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

/**
  * @brief  Shift bit of IC
  * @param  None
  * @retval None
  */
void ShiftLED(void)
{
	// Make sure Pin A2 is LOW to set HIGH
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	// SET Pin A3 to send Data
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

/**
  * @brief  Send data to IC
  * @param  none
  * @retval None
  */
void SendData(void)
{
	// Make sure Pin A3 is LOW to set HIGH
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	// SET Pin A3 to send Data
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
}

/**
  * @brief  Clear Data on all IC (LED is shining)
  * @param  none
  * @retval None
  */
void ClearData(void)
{
	// Make sure Pin A4 is High to set LOW
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	// RESET Pin A4 to clear Data
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	// Send Data
	SendData();
}	

/**
  * @brief  Filter data to send data and shift each bit
  * @param  Input in binary. 1 is On, 0 is off
  * @retval None
  */
void DisplayOneIC(uint8_t Data)
{
	if (Data & 0b10000000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b01000000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00100000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	
	if (Data & 0b00010000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00001000)			InputData(1);
	else												InputData(0);
	ShiftLED();

	if (Data & 0b00000100)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00000010)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00000001)			InputData(1);
	else												InputData(0);
	ShiftLED();
}

/**
  * @brief  Config All LED to display
  * @param  5 params input in binary. 1 is On, 0 is off
  * @retval None
  */
void DisplayLine(uint8_t U5, uint8_t U4, uint8_t U3, uint8_t U2, uint8_t U1)
{
	DisplayOneIC(U5);
	DisplayOneIC(U4);
	DisplayOneIC(U3);
	DisplayOneIC(U2);
	DisplayOneIC(U1);
	SendData();
}

/**
  * @brief  Combine with delay to display all LED into a char
  * @param  input a char
  * @retval None
  */
void DisplayChar(char c)
{
	uint8_t i;
	
	if (c=='A')
	{
		uint8_t A[5][10] =
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01111111,0b10010000,0b10010000,0b10010000,0b01111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(A[0][i],A[1][i],A[2][i],A[3][i],A[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='B')
	{
		uint8_t B[5][5]=
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10011001,0b10011001,0b10011001,0b01100110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(B[0][i],B[1][i],B[2][i],B[3][i],B[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='C')
	{
		uint8_t C[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01111110,0b10000001,0b10000001,0b10000001,0b01000010},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(C[0][i],C[1][i],C[2][i],C[3][i],C[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='D')
	{
		uint8_t D[5][5] =
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10000001,0b10000001,0b10000001,0b01111110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(D[0][i],D[1][i],D[2][i],D[3][i],D[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='E')
	{
		uint8_t E[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10011001,0b10011001,0b10011001,0b10000001},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(E[0][i],E[1][i],E[2][i],E[3][i],E[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='F')
	{
		uint8_t F[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10010000,0b10010000,0b10010000,0b10000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(F[0][i],F[1][i],F[2][i],F[3][i],F[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='G')
	{
		uint8_t G[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01111110,0b10000001,0b10010001,0b10010001,0b10011110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(G[0][i],G[1][i],G[2][i],G[3][i],G[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='H')
	{
		uint8_t H[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b00011000,0b00011000,0b00011000,0b11111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(H[0][i],H[1][i],H[2][i],H[3][i],H[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='I')
	{
		uint8_t I[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b10000001,0b10000001,0b11111111,0b10000001,0b10000001},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(I[0][i],I[1][i],I[2][i],I[3][i],I[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='J')
	{
		uint8_t J[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00001110,0b00000001,0b00000001,0b11111111,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(J[0][i],J[1][i],J[2][i],J[3][i],J[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='K')
	{
		uint8_t K[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b00011000,0b00100100,0b01000010,0b10000001},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(K[0][i],K[1][i],K[2][i],K[3][i],K[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	
	if (c=='L')
	{
		uint8_t L[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b00000001,0b00000001,0b00000001,0b00000001},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(L[0][i],L[1][i],L[2][i],L[3][i],L[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='M')
	{
		uint8_t M[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b01000000,0b00110000,0b00000010,0b11111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(M[0][i],M[1][i],M[2][i],M[3][i],M[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='N')
	{
		uint8_t N[5][5] =
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b01100000,0b00110000,0b00001100,0b11111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(N[0][i],N[1][i],N[2][i],N[3][i],N[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='O')
	{
		uint8_t O[5][5] =
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01111110,0b10000001,0b10000001,0b10000001,0b01111110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(O[0][i],O[1][i],O[2][i],O[3][i],O[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='P')
	{
		uint8_t P[5][5] =
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10010000,0b10010000,0b10010000,0b01100000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(P[0][i],P[1][i],P[2][i],P[3][i],P[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='Q')
	{
		uint8_t Q[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01111110,0b10000001,0b10000101,0b10000011,0b01111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(Q[0][i],Q[1][i],Q[2][i],Q[3][i],Q[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='R')
	{
		uint8_t R[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b10010000,0b10011000,0b10010100,0b01100011},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(R[0][i],R[1][i],R[2][i],R[3][i],R[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='S')
	{
		uint8_t S[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b01110001,0b10010001,0b10010001,0b10010001,0b10001110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(S[0][i],S[1][i],S[2][i],S[3][i],S[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='T')
	{
		uint8_t T[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b10000000,0b10000000,0b11111111,0b10000000,0b10000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(T[0][i],T[1][i],T[2][i],T[3][i],T[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='U')
	{
		uint8_t U[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111110,0b00000001,0b00000001,0b00000001,0b11111110},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(U[0][i],U[1][i],U[2][i],U[3][i],U[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='V')
	{
		uint8_t V[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111100,0b00000010,0b00000001,0b00000010,0b11111100},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(V[0][i],V[1][i],V[2][i],V[3][i],V[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='W')
	{
		uint8_t W[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11111111,0b00000010,0b00001100,0b00000010,0b11111111},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(W[0][i],W[1][i],W[2][i],W[3][i],W[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='X')
	{
		uint8_t X[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11000011,0b00100100,0b00011000,0b00100100,0b11000011},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(X[0][i],X[1][i],X[2][i],X[3][i],X[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='Y')
	{
		uint8_t Y[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b11000000,0b00100000,0b00011111,0b00100000,0b11000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(Y[0][i],Y[1][i],Y[2][i],Y[3][i],Y[4][i]);
			DelayUs(TimePerAngle);
		}
	}
	
	if (c=='Z')
	{
		uint8_t Z[5][5] = 
		{
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b10000011,0b10000101,0b10011001,0b10100001,0b11000001},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
		};
		for (i=0; i<5; i++)
		{
			DisplayLine(Z[0][i],Z[1][i],Z[2][i],Z[3][i],Z[4][i]);
			DelayUs(TimePerAngle);
		}
	}
}

/**
  * @brief  Use the DisplayChar function to display into a word
  * @param  Input a string
  * @retval None
  */
void DisplayWord(char *s)
{
	uint8_t i=0;
	while (s[i]!='\n')
	{
		DisplayChar(s[i]);
		DelayUs(TimePerAngle);
		i++;
	}
	DisplayLine(0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000);
}

/**
  * @brief  Turn enable or disable for Timer 
  * @param  TIMx for choose Timer, Bit 1 to set enable, 0 to disable
  * @retval None
  */
void Timer_On(TIM_TypeDef* TIMx, uint8_t Bit)
{
	if (Bit)
	{
		TIM_Cmd(TIMx, ENABLE);
	}
	else
	{
		TIM_Cmd(TIMx, DISABLE);
	}
}

/**
  * @brief  Delay at us
  * @param  Global para TimingDelay, private para TimeDelay for input delay time
  * @retval None
  */
void DelayUs(uint32_t TimeDelay)
{
	TimingDelay = TimeDelay;
	while(TimingDelay);
}

uint8_t StartPos(uint16_t Pos)
{
	int32_t temp=0;
	
	if (TimingPos>=0 && TimingPos <= 180*TimePerAngle)
	{
		temp = TimingPos + 180*TimePerAngle;
	}
	else if (TimingPos>180*TimePerAngle && TimingPos <= 359*TimePerAngle)
	{	
		temp = TimingPos - 180*TimePerAngle;
	}
	
	if (temp >= Pos*TimePerAngle-10 && temp<= Pos*TimePerAngle+10)
		return 1;
	else
		return 0;
}