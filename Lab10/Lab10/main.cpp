#include "Life.h"

int main (void)
{
	Life lump(20.0, 10000.0);
	for (int i = 0; i < 5; i++)
	{
		lump.simulateWeek();
		cout << lump.getSize() << " " << lump.getRate() << endl;
	}

	lump.setRate(-8000.0);

	while(lump.isAlive())
	{
		lump.simulateWeek();
		cout << lump.getSize() << " " << lump.getRate() << endl;
	}
	return 0;
}