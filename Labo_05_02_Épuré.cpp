#include <iostream>	// pour le cout
#include <iomanip>	// pour les manipulateurs (setw(), setprecision(), etc
#include <conio.h>	// pour le _getch
#include <string>	//Pour le type string
#include "D:\Users\Wyllas\Documents\VS CODE\Solution\cvm 21.h"

using namespace std;

int main()
{
	//CONSTANTES
	const double PRIX_8X11R = 31;		
	const double PRIX_8X11RV = 60;
	const double PRIX_11X17R = 61;
	const double PRIX_11X17RV = 100;
	const double PRIX_PAPIER_1 = 20.50;		
	const double PRIX_PAPIER_2 = 67.34;
	const double PRIX_PAPIER_3 = 122.94;
	const double PRIX_BROCHE = 0.03;		
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.10;
	const double PRIX_PERFORER = 3;
	const double TPS = 0.05;	
	const double TVQ = 0.09975;

	//VARIABLES 
	char formatPapier;						
	char typeImpression;
	int nbOri;
	int nbExe;
	int nbImpR;
	int nbImpRV;
	int reste;
	double coutR;							
	double coutRV;
	char typePapier;						
	double coutPapier;
	char aPerforer;							
	char typeFaconnage;
	double coutFaconnage;
	double coutProduction;					
	double coutTotal;
	int espacementIntroPage,		espacementIntroPage			= 36;
	int espacementVotreChoix,		espacementVotreChoix		= 37;
	int espacementPerforation,		espacementPerforation		= 45;
	int espacementDebutFacture,		espacementDebutFacture		= 2;
	int espacementFactureDescrip,		espacementFactureDescrip	= 48;
	int espacementFactureCout$,		espacementFactureCout$		= 10;

	//Input
	cout << setw(espacementIntroPage) << left << "Nombre d'originaux" << ": ";
	cin >> nbOri;

	cout << setw(espacementIntroPage) << "Nombre d'exemplaires \205 reproduire" << ": ";
	cin >> nbExe;
	cout << "\n";

	cout << "Format du papier :" << "\n" <<
		"\t" << "1. 8\253x11" << "\n"
		"\t" << "2. 8\253x14" << "\n"
		"\t" << setw(espacementVotreChoix) << "3. 11x17" << "Votre choix : ";
	cin >> formatPapier;
	cout << "\n";

	cout << "Type d'impression :" << "\n" <<
		"\t" << "R. recto" << "\n"
		"\t" << setw(espacementVotreChoix) << "V. recto - verso" << "Votre choix : ";
	typeImpression = toupper(_getch());
	cout << typeImpression << "\n\n";

	cout << "Type de papier :" << "\n" <<
		"\t" << "1. Repro + gris" << "\n"
		"\t" << "2. Rolland \202volution glacier" << "\n"
		"\t" << setw(espacementVotreChoix) << "3. Wausau royal, fibre tetxe \202tain" << "Votre choix : ";
	cin >> typePapier;
	cout << "\n";

	cout << setw(espacementPerforation) << "Voulez-vous des documents perfor\202s ? (O/N) " << "Votre choix : ";
	aPerforer = toupper(_getch());
	cout << aPerforer << "\n\n";

	cout << "Type de fa\200onnage :" << "\n" <<
		"\t" << "1. Broche en coin" << "\n"
		"\t" << "2. Encoller avec ruban" << "\n"
		"\t" << "3. Tablettes" << "\n"
		"\t" << "4. Broche \205 dos de cheval" << "\n"
		"\t" << setw(espacementVotreChoix) << "5. Aucun" << "Votre choix : ";
	cin >> typeFaconnage;
	cout << "\n\n";

	cout << "Appuyez sur une touche pour continuer ...";

	_getch(), clrscr();

	//Calculs


		if (formatPapier == '1' || formatPapier == '2')
		{
			if (typeImpression == 'R')
			{
				nbImpR = nbOri * nbExe;
				nbImpRV = 0;
			}
			else
			{
				if (nbOri % 2 != 0)
				{
					nbImpR = nbExe;
					nbImpRV = ((nbOri - 1) * nbExe) / 2;
				}

				else
				{
					nbImpR = 0;
					nbImpRV = (nbOri * nbExe) / 2;
				}
			}
		}

		else
		{
			if (typeImpression == 'R')
			{
				if (nbOri % 2 != 0)
					nbOri = nbOri + 1;

					nbImpR = (nbOri * nbExe) / 2;
					nbImpRV = 0;

			}

			else
			{
				reste = nbOri % 4;
				if (reste == 0)
				{
					nbImpR = 0;
					nbImpRV = (nbOri * nbExe) / 4;
				}
				if (reste == 1 || reste == 2)
				{
					nbImpR = nbExe;
					nbImpRV = (nbOri - reste) * nbExe / 4;
				}
				if (reste == 3)
				{
					nbImpR = 0;
					nbImpRV = (nbOri + 1) * nbExe / 4;
				}
			}

		}



		coutR = 0;
		coutRV = 0; 
		if (formatPapier == '1' || formatPapier == '2')
		{
			if (typeImpression == 'R')
				coutR = (nbImpR * PRIX_8X11R)/1000;
			else
			{
				coutR = (nbImpR * PRIX_8X11R) / 1000;
				coutRV = (nbImpRV * PRIX_8X11RV) / 1000;
			}
		}
		else
		{
			if (typeImpression == 'R')
				coutR = (nbImpR * PRIX_11X17R) / 1000;
			else
			{
				coutR = (nbImpR * PRIX_11X17R) / 1000;
				coutRV = (nbImpRV * PRIX_11X17RV) / 1000;
			}
		}


		switch (typePapier)
		{
		case '1':
			if (formatPapier == '2' || formatPapier == '3')
				coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_1) / 1000;
			else
				coutPapier = (((nbImpR + nbImpRV) * PRIX_PAPIER_1) / 2) / 1000;
			break;
		case '2':
			if (formatPapier == '2' || formatPapier == '3')
				coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_2) / 1000;
			else
				coutPapier = (((nbImpR + nbImpRV) * PRIX_PAPIER_2) / 2) / 1000;
			break;
		case '3':
			if (formatPapier == '2' || formatPapier == '3')
				coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_3) / 1000;
			else
				coutPapier = (((nbImpR + nbImpRV) * PRIX_PAPIER_3) / 2) / 1000;
			break;
		}

		if (aPerforer == 'O')
			coutFaconnage = ((nbImpR + nbImpRV) * PRIX_PERFORER) / 1000;
		else
			coutFaconnage = 0;

		switch (typeFaconnage)
		{
		case '1' :
			coutFaconnage = (PRIX_BROCHE * nbExe) + coutFaconnage;

			break;
		case '2' :
			if (formatPapier == '1' || formatPapier == '2')
				coutFaconnage = (PRIX_ENCOLLER * nbExe) + coutFaconnage;

			break;
		case '3' :
			coutFaconnage = (PRIX_TABLETTE * nbExe) + coutFaconnage;

			break;
		case '4' :
			if (formatPapier == '3')
			coutFaconnage = (PRIX_DOSCHEVAL * nbExe) + coutFaconnage;

			break;
		case '5':
			break;
		}

		coutProduction = coutFaconnage + coutPapier + coutR + coutRV;
		coutTotal = coutProduction + (coutProduction * TVQ) + (coutProduction * TPS);

	// Output

	cout << "\n\n\n" << "FACTURE" << "\n\n\n" << fixed << setprecision(2) <<
		setw(espacementDebutFacture) << "" << setw(espacementFactureDescrip) << "Co\226t des impressions recto :" << setw(espacementFactureCout$) << right << coutR << " $" << "\n" <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "Co\226t des impressions recto-verso :" << setw(espacementFactureCout$) << right << coutRV << " $" << "\n\n" <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "Co\226t du papier :" << setw(espacementFactureCout$) << right << coutPapier << " $" << "\n" <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "Co\226t du fa\200onnage :" << setw(espacementFactureCout$) << right << coutFaconnage << " $" << "\n" <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "" << setfill('-') << setw(espacementFactureCout$ + 2) << "" << "\n\n" << setfill(' ') <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "Co\226t de production :" << setw(espacementFactureCout$) << right << coutProduction << " $" << "\n" <<
		setw(espacementDebutFacture) << left << "" << setw(espacementFactureDescrip) << "" << setfill('=') << setw(espacementFactureCout$ + 2) << "" << "\n\n" << setfill(' ') <<
		setw(espacementDebutFacture + espacementFactureDescrip) << left << "Co\226t total :" << setw(espacementFactureCout$) << right << coutTotal << " $";

	_getch();
}
