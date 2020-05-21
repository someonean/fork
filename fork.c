#include <stdio.h>

int main()
{
	int i;
	FILE *f;

	while(1)
	{
		f = fopen("fork.txt", "rb");
		if(!f)
		{
			f = fopen("fork.txt", "w");
			fwrite("fork", 4, 1, f);
			fclose(f);
			f = fopen("fork.txt", "r");
		}
		for(i = 0; i < 4; i++)
		{
			switch(i)
			{
				case 0: if(getc(f) != 'f') return 0; break;
				case 1: if(getc(f) != 'o') return 0; break;
				case 2: if(getc(f) != 'r') return 0; break;
				case 3: if(getc(f) != 'k') return 0; break;
			}
		}
		fork();
		fclose(f);
	}

}
