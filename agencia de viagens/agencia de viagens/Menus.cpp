#include "Menus.h"


void mainMenu(TravelAgency &travelAgency)
{
	unsigned short option;
	bool exit_program = false;
	while (!exit_program)
	{
		cout << BIG_TAB << "Menu Principal" << endl << endl;
		cout << TAB << "1 - Viajar para um destino" << endl;
		cout << TAB << "2 - Viajar para varios destinos" << endl;
		cout << TAB << "3 - Pesquisa por monumentos" << endl;
		cout << TAB << "4 - Visualizar Grafo." << endl;
		cout << TAB << "0 - Sair" << endl << endl; 

		cout << "Escolha uma opcao: ";
		cin >> option;

		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "O input nao e valido. Tente novamente." << endl << endl;
			system("PAUSE");
			clrscr();
			continue;
		}

		switch (option) {
		case 1:
			clrscr();
			callTripToOneCity(travelAgency);
			break;
		case 2:
			clrscr();
			callCustomTrip(travelAgency);
			break;
		case 3:
			clrscr();
			callSearchforMonuments(travelAgency);
			break;
		case 4: 
			graphviewer(travelAgency);
			clrscr();
			break;
		case 0:
			exit_program = true;
			break;
		default:
			cerr << "O input nao e valido. Tente novamente." << endl << endl;
			system("PAUSE");
		}
		clrscr();
	}
	return;
}

static void callTripToOneCity(TravelAgency &travelAgency) {
	try{ 
		travelAgency.TripToOneCity(); 
	}
	catch (exception_or_error &x) {
		cerr << endl << x.get_reason() << endl << endl;
		system("PAUSE");
		clrscr();
	}
	return;
}

static void callCustomTrip(TravelAgency &travelAgency) {
	try {
		travelAgency.CustomTrip();
	}
	catch (exception_or_error &x) {
		cerr << endl << x.get_reason() << endl << endl;
		system("PAUSE");
		clrscr();
	}
	return;
}

static void callSearchforMonuments(TravelAgency &travelAgency) {
	try {
		travelAgency.searchMonumentsCities();
	}
	catch (exception_or_error &x) {
		cerr << endl << x.get_reason() << endl << endl;
		system("PAUSE");
		clrscr();
	}
	return;
}