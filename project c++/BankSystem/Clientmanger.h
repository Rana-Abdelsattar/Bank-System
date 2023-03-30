#pragma once
#include"Client.h"
#include"FileManager.h"
class  ClientManger {
public:
	static void printClientMenu() {
		system("cls");
		cout << "---------Client Option-----------\n";
		cout << "(1) Update password \n";
		cout << "(2) Deposit \n";
		cout << "(3) Withdraw \n";
		cout << "(4) transfer to another account \n";
		cout << "(5) check balance \n";
		cout << "(6) Display My Info \n";
		cout << "(7) Logout\n";

	}
	static void back(Client* client)
	{
		cout << endl;
		system("pause");
		clientOptions(client);

	}
	static void updatePassword(Person* person) {
		person->setPassword(Validation::EnterPassword());
		cout << "Password Updated \n";

	}
	static Client* login(int id, string password) {
		for (int i = 0; i < allClient.size(); i++)
		{
			if (allClient[i].getId_Client() == id && allClient[i].getPassword() == password)
			{
				Client* c = &allClient[i];
				return c;
			}
		}
		return nullptr;
	}
	static bool clientOptions(Client* client) {
		printClientMenu();
		int num;
		double amount;
		int id;
		Employee e;
		cout << "Enter your choice";
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			updatePassword(client);
			FileManager::UpdateClient();
			break;
		case 2:
			system("cls");
			cout << "Enter the amount to deposit: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::UpdateClient();
			break;
		case 3:
			system("cls");
			cout << "Enter the amount to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::UpdateClient();
			break;
		case 4:
			system("cls");
			cout << "Enter the id of recipient: ";
			cin >> id;
			while (e.searchClient(id) == nullptr)
			{
				cout << "Invalid id \n";
				cout << "Enter the id of recipient: ";
				cin >> id;
			}
			cout << "Enter the amount you want to transfer: ";
			cin >> amount;
			client->tranferTo(amount, *e.searchClient(id));
			FileManager::UpdateClient();
			break;
		case 5:
			client->checkBalance();
			break;
		case 6:
			client->printInfo();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		back(client);
		return true;
	}

};
