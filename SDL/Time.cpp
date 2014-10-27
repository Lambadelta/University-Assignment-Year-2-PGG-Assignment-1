#include "Time.h"

Time::Time()
{
	iStartTick = 0;
	iPausedTick = 0;
	iLastTick = 0;

	bPaused = false;
	bStart = false;
}
Time::~Time()
{

}

void Time::callStart()
{
	bStart = true;
	bPaused = false;

	iStartTick = SDL_GetTicks();
	iPausedTick = 0;

}
void Time::callPause()
{
	if (bStart == true && bPaused == false)
	{
		bPaused = true;

		iPausedTick = SDL_GetTicks() - iStartTick;
		iStartTick = 0;
	}
}

void Time::callUnpause()
{
	if (bStart == false && bPaused == true)
	{
		bPaused = false;

		iStartTick = SDL_GetTicks() - iStartTick;
		iPausedTick = 0;
	}
}

void Time::callStop()
{

}


float Time::getDelta()
{
	return ((fDelta / 100));
}

void Time::updateTime()
{
	if (bStart == true)
	{
		if (bPaused == true)
		{
			iLastTick = iPausedTick;
			fDelta = (iPausedTick - iLastTick);
		}
		else
		{
			
			iStartTick = SDL_GetTicks();
			fDelta = (iStartTick - iLastTick);
			iLastTick = iStartTick;
		}
	}

}

bool Time::isPaused()
{
	return bPaused;
}

bool Time::isStarted()
{
	return bStart;
}

/*16.7 Mil Seconds = 60 fps use SDL_Delay*/