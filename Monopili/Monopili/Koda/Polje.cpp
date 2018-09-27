#include "Polje.h"

SDL_Rect IPolje::getKvadrat()
{
	return KvadratPolje;
}

void IPolje::KvadratPodatki(int i, Igra TrenutnaIgra)
{
	ID = i;
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
			KvadratPolje.h = (tmp.h / 24)*2;
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
				KvadratPolje.w = (tmp.w / 24)*2;
			}
		}
		else
			if (i > 20 && i < 31)
			{
				KvadratPolje.x = tmp.x + ((tmp.w / 24) * 21);
				KvadratPolje.y = tmp.y + ((tmp.h / 24)*(21 - (30-i) * 2));
				if (i == 30)
				{
					KvadratPolje.y = tmp.y + ((tmp.h / 24) * 21);
					KvadratPolje.h = (tmp.h / 24) * 3;
				}
				else
				{
					KvadratPolje.h = (tmp.h / 24)*2;
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
	IndexIgralec = 0;
	SteviloParov = 0;
	KvadratPodatki(i, TrenutnaIgra);
	switch (i)
	{
	case 12:
		VelikostParov = 2;
		cena = 1200;
		najem = 400;
		VrstaPolja = Elektrika;
		break;
	case 28:
		VelikostParov = 2;
		cena = 1200;
		najem = 400;
		VrstaPolja = Voda;
	default:
		VelikostParov = 4;
		cena = 1000;
		najem = 300;
		VrstaPolja = Vlak;
		break;
	}
}

GradbenoPolje::GradbenoPolje(int i, Igra TrenutnaIgra)
{
	IndexIgralec = 0;
	SteviloParov = 0;
	KvadratPodatki(i, TrenutnaIgra);
	if (i < 10)
	{
		if (i < 5)
		{
			cena = 500;
			najem = 150;
			VelikostParov = 2;
			BarvenaSkupina = Rjava;
			cenaHiske = 100;
			cenaHotela = 150;
			BarvniKvadrat(1, Rjava);
		}
		else
		{
			cena = 800;
			najem = 250;
			VelikostParov = 3;
			BarvenaSkupina = SvetloModra;
			cenaHiske = 125;
			cenaHotela = 200;
			BarvniKvadrat(1, SvetloModra);
		}
	}
	else if (i < 20)
	{
		if (i < 15)
		{
			cena = 1100;
			najem = 400;
			VelikostParov = 3;
			BarvenaSkupina = Vijolcna;
			cenaHiske = 150;
			cenaHotela = 250;
			BarvniKvadrat(2, Vijolcna);
		}
		else
		{
			cena = 1400;
			najem = 500;
			VelikostParov = 3;
			BarvenaSkupina = Oranzna;
			cenaHiske = 175;
			cenaHotela = 300;
			BarvniKvadrat(2, Oranzna);
		}
	}
	else if (i < 30)
	{
		if (i < 25)
		{
			cena = 1700;
			najem = 650;
			VelikostParov = 3;
			BarvenaSkupina = Rdeca;
			cenaHiske = 200;
			cenaHotela = 350;
			BarvniKvadrat(3, Rdeca);
		}
		else
		{
			cena = 2000;
			najem = 800;
			VelikostParov = 3;
			BarvenaSkupina = Rumena;
			cenaHiske = 225;
			cenaHotela = 400;
			BarvniKvadrat(3, Rumena);
		}
	}
	else if (i < 35)
	{
		cena = 2300;
		najem = 900;
		VelikostParov = 3;
		BarvenaSkupina = Zelena;
		cenaHiske = 250;
		cenaHotela = 450;
		BarvniKvadrat(4, Zelena);
	}
	else
	{
		cena = 2600;
		najem = 1000;
		VelikostParov = 2;
		BarvenaSkupina = TemnoModra;
		cenaHiske = 275;
		cenaHotela = 550;
		BarvniKvadrat(4, TemnoModra);
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

void GradbenoPolje::RenderBarva(int barva)
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
		SDL_SetRenderDrawColor(gRenderer, 255, 102, 0, 255);
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
	SDL_RenderDrawRect(gRenderer, &KvadratPolje);
}

void PosebnoPolje::narisi() {
	SDL_RenderDrawRect(gRenderer, &KvadratPolje);
}

void GradbenoPolje::narisi()
{
	if (ID < 10)
	{
		if (ID < 5)
			RenderBarva(Rjava);
		else
			RenderBarva(SvetloModra);
	}
	else if (ID < 20)
	{
		if (ID< 15)
			RenderBarva(Vijolcna);
		else
			RenderBarva(Oranzna);
	}
	else if (ID< 30)
	{
		if (ID< 25)
			RenderBarva(Rdeca);
		else
			RenderBarva(Rumena);
	}
	else if (ID < 35)
	{
		RenderBarva(Zelena);
	}
	else
	{
		RenderBarva(TemnoModra);
	}
	SDL_RenderFillRect(gRenderer, &KvadratBarva);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(gRenderer, &KvadratBarva);
	SDL_RenderDrawRect(gRenderer, &KvadratPolje);
}
