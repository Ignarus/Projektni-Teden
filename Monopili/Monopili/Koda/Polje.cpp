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
	switch (i)
	{
	case 12:
		VrstaPolja = Elektrika;
		break;
	case 28:
		VrstaPolja = Voda;
	default:
		VrstaPolja = Vlak;
		break;
	}
}

GradbenoPolje::GradbenoPolje(int i, Igra TrenutnaIgra)
{
	KvadratPodatki(i, TrenutnaIgra);
	if (i < 10)
	{
		if (i < 5)
			BarvenaSkupina = Rjava;
		else
			BarvenaSkupina = SvetloModra;
	}
	else if (i < 20)
	{
		if (i < 15)
			BarvenaSkupina = Vijolcna;
		else
			BarvenaSkupina = Oranzna;
	}
	else if (i < 30)
	{
		if (i < 25)
			BarvenaSkupina = Rdeca;
		else
			BarvenaSkupina = Rumena;
	}
	else if (i < 35)
	{
		BarvenaSkupina = Zelena;
	}
	else
	{
		BarvenaSkupina = TemnoModra;
	}
}

void GradbenoPolje::BarvniKvadrat(int i, int barva)
{
	switch (i)
	{
	case 1:
		KvadratBarva.x = KvadratPolje.x + (KvadratPolje.w / 5) * 4;
		KvadratBarva.y = KvadratPolje.y;
		KvadratBarva.w = (KvadratPolje.w / 5);
		KvadratBarva.h = KvadratPolje.h;
		break;
	case 2:
		KvadratBarva.y = KvadratPolje.y + (KvadratPolje.h / 5) * 4;
		KvadratBarva.x = KvadratPolje.x;
		KvadratBarva.h = (KvadratPolje.h / 5);
		KvadratBarva.w = KvadratPolje.w;
		break;
	case 3:
		KvadratBarva.x = KvadratPolje.x;
		KvadratBarva.y = KvadratPolje.y;
		KvadratBarva.w = (KvadratPolje.w / 5);
		KvadratBarva.h = KvadratPolje.h;
		break;
	case 4:
		KvadratBarva.y = KvadratPolje.y;
		KvadratBarva.x = KvadratPolje.x;
		KvadratBarva.h = (KvadratPolje.h / 5);
		KvadratBarva.w = KvadratPolje.w;
		break;
	}
	RenderBarva(barva);
}

void RenderBarva(int barva)
{
	switch (barva)
	{
	case Rjava:
		SDL_SetRenderDrawColor(gRenderer, 102, 51, 0, 255);
		break;
	case SvetloModra:
		SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 255);
		break;
	case Vijolcna:
		SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 255);
		break;
	case Oranzna:
		SDL_SetRenderDrawColor(gRenderer, 204, 204, 255, 255);
		break;
	case Rdeca:
		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
		break;
	case Rumena:
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 51, 255);
		break;
	case Zelena:
		SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
		break;
	case TemnoModra:
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
		break;
	default:
		break;
	}
}

void PoljeZAkcijo::narisi() {

}