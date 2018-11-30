#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

//	if (StartPos(0))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(90))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(180))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(270))
//		DisplayLine(255,255,255,255,255);
//	ClearData();
	uint32_t time,i;
	uint8_t loop;
	uint16_t TempPos=0;
	while (1)
	{
		time=500000;
		while(time>0)
		{
			DisplayLightBulb(255);
			DisplayWordGlobe(63,"","","SISI","","");
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=255; i!=254; i++)
			{
				time=10000;
				while(time<=10000)
				{
					DisplayLightBulb(i);
					TempPos = i + 168;
					if (TempPos>362)
					{
						TempPos = TempPos - 360;
					}
					DisplayWordGlobe(TempPos,"","","SISI","","");
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		time=1000000;
		while(time>0)
		{
			DisplayLightBulb(255);
			DisplayWordGlobe(63,"","","SISI","","");
			time--;
		}
		
		// display logo VNU HCM
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=280; i!=279; i++)
			{
				time=7500;
				while(time<=7500)
				{
					DisplayLogoVNU(i);
					time--;
				}
				if (i==363)
					i=0;
			}
		}
		time=1000000;
		while(time>0)
		{
			DisplayLogoVNU(280);
			time--;
		}
	}
}
