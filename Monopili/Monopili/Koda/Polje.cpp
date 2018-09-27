#include "Polje.h"

SDL_Rect IPolje::getKvadrat()
{
	return KvadratPolje;
}

void IPolje::KvadratPodatki(int i, Igra TrenutnaIgra)
{
	SDL_Rect tmp = TrenutnaIgra.GetIgralnoPolje();
	if (i < 10) {
		KvadratPolje.x = tmp.x;
		KvadratPolje.y = tmp.y + ((tmp.h / 24)*(21 - i * 2));
		if (i == 0)
		{
			KvadratPolje.h = (tmp.h / 24)*3;
		}
		else
		{
			KvadratPolje.h = tmp.h / 24;
		}
		KvadratPolje.w = (tmp.w / 24) * 3;

	}
	else
	{
		if (i > 9 && i < 21)
		{
			KvadratPolje.y = tmp.y;
			KvadratPolje.h = (tmp.h / 24) * 3;
				if (i == 10)
				{
					KvadratPolje.x = tmp.x;
				}
				else
				{
					KvadratPolje.x = tmp.x + ((tmp.w / 24)*(3 + (i - 11) * 2));
				}
				if (i % 10 == 0)
				{
					KvadratPolje.w= (tmp.w / 24) * 3;
				}
				else
				{
					KvadratPolje.w = (tmp.w / 24);
				}
		}
		else
			if (i > 20 && i < 31)
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24) * 21);
				KvadratPolje.y = tmp.y + ((tmp.h / 24)*(21 - (i-20) * 2));
				if (i == 30)
				{
					KvadratPolje.h = (tmp.h / 24)*3;
				}
				else
				{
					KvadratPolje.h = tmp.h / 24;
				}
				KvadratPolje.w = (tmp.w / 24) * 3;
			}
			else
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24)*(21 - (i - 30) * 2));
				KvadratPolje.y = tmp.y + ((tmp.h / 24) * 21);
				KvadratPolje.h = (tmp.h / 24) * 3;
				KvadratPolje.w = (tmp.w / 24) * 2;
			}
	}
}

void ILastniskoPolje::KvadratPodatki(int i, Igra TrenutnaIgra)
{
	SDL_Rect tmp = TrenutnaIgra.GetIgralnoPolje();
	if (i < 10) {
		KvadratPolje.x = tmp.x;
		KvadratPolje.y = tmp.y + ((tmp.h / 24)*(21 - i * 2));
		if (i == 0)
		{
			KvadratPolje.h = (tmp.h / 24) * 3;
		}
		else
		{
			KvadratPolje.h = tmp.h / 24;
		}
		KvadratPolje.w = (tmp.w / 24) * 3;

	}
	else
	{
		if (i > 9 && i < 21)
		{
			KvadratPolje.y = tmp.y;
			KvadratPolje.h = (tmp.h / 24) * 3;
			if (i == 10)
			{
				KvadratPolje.x = tmp.x;
			}
			else
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24)*(3 + (i - 11) * 2));
			}
			if (i % 10 == 0)
			{
				KvadratPolje.w = (tmp.w / 24) * 3;
			}
			else
			{
				KvadratPolje.w = (tmp.w / 24);
			}
		}
		else
			if (i > 20 && i < 31)
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24) * 21);
				KvadratPolje.y = tmp.y + ((tmp.h / 24)*(21 - (i - 20) * 2));
				if (i == 30)
				{
					KvadratPolje.h = (tmp.h / 24) * 3;
				}
				else
				{
					KvadratPolje.h = tmp.h / 24;
				}
				KvadratPolje.w = (tmp.w / 24) * 3;
			}
			else
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24)*(21 - (i - 30) * 2));
				KvadratPolje.y = tmp.y + ((tmp.h / 24) * 21);
				KvadratPolje.h = (tmp.h / 24) * 3;
				KvadratPolje.w = (tmp.w / 24) * 2;
			}
	}
}

PoljeZAkcijo::PoljeZAkcijo(int i, Igra TrenutnaIgra)
{
	KvadratPodatki(i, TrenutnaIgra);
	switch (i)
	{
	case 0:
		Vrsta_Akcije = Zacetek;
		break;
	case 2:
	case 17:
	case 33:
		Vrsta_Akcije = DrzavnaBanka;
		break;
	case 7:
	case 22:
	case 36:
		Vrsta_Akcije = Piloznost;
		break;
	case 4:
		Vrsta_Akcije = DavekNaDohodek;
		break;
	case 38:
		Vrsta_Akcije = DavekNaPremozenje;
		break;
	case 10:
		Vrsta_Akcije = Zapor;
		break;
	case 20:
		Vrsta_Akcije = Parking;
		break;
	case 30:
		Vrsta_Akcije = PojdiZapor;
		break;
	default:
		break;
	}
}

PosebnoPolje::PosebnoPolje(int i, Igra TrenutnaIgra)
{
	KvadratPodatki(i, TrenutnaIgra);

}

void PoljeZAkcijo::narisi() {

}