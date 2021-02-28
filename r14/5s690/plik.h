struct daneos
{
	char imie[20];
	char nazwisko[20];
};

struct student 
{
	struct daneos dane;
	float oceny[5];
	float srednia_ocen;
};