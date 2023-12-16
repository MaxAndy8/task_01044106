#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <stack>
#include "ProductFactory.h"
#include "Client.h"
#include "Mediator.h"

#define ESC   27
#define UP    72
#define DOWN  80
#define ENTER 13

 // ���������� ���������� ������
extern HANDLE hStdOut; 
extern std::vector< std::shared_ptr<Product> >    products ;
extern std::vector< std::shared_ptr<Client> >     clients  ;
extern std::vector< std::shared_ptr<Mediator> >   mediators;
extern std::vector< std::shared_ptr<ShopOrder> >  orders   ;

void GoToXY(short x, short y);

void ConsoleCursorVisible(bool show, short size);

class MenuState {
protected:
    int                             activeItem = 0;
    const std::vector<std::string>  menuItems;
public:
    MenuState(const std::vector<std::string>& items) : menuItems(items) {}
    virtual void displayMenu() {
        system("CLS");
        for (int i = 0; i < menuItems.size(); i++) {
            if (i == activeItem)
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            else
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

            GoToXY(50, 12 + i);
            std::cout << menuItems[i] << std::endl;
        }
    }
    virtual MenuState* handleInput(char input) = 0;
    virtual ~MenuState() = default;
};

class MainMenuState : public MenuState {

public:
    MainMenuState()
        : MenuState({ 
        "1. ��������� ��������", 
        "2. �볺���", 
        "3. ����������", 
        "4. ������", 
        "5. �������� �� ����������", 
        "6. �����" })
    { }

    MenuState* handleInput(char input) override;

};

class ProductsCreationMenuState : public MenuState {

public:
    ProductsCreationMenuState()
        : MenuState({ 
        "1. �������� ����", 
        "2. �������� ���", 
        "3. �������� ������", 
        "4. ������� ������ ��������", 
        "5. ����������� �����" })
    { }

    MenuState* handleInput(char input) override;

};

class ClientMenuState : public MenuState {

public:
    ClientMenuState()
        : MenuState({
        "1. ��������� �������� ��� �볺��� �� �� ���������",
        "2. �������� �볺���",
        "3. ������� ������ �볺��� �� �� ����������",
        "4. ����������� �����" })
    { }

    MenuState* handleInput(char input) override;

};

class OrderMenuState : public MenuState {

public:
    OrderMenuState()
        : MenuState({
        "1. ������� ����������� �1",
        "2. ������� ����������� �2",
        "3. ������� ������ ���������",
        "4. ����������� �����" })
    { }

    MenuState* handleInput(char input) override;

};

class DiscountMenuState : public MenuState {

public:
    DiscountMenuState()
        : MenuState({
        "1. ������ ������",
        "2. ����������� �����" })
    { }

    MenuState* handleInput(char input) override;

};

class SendPayMenuState : public MenuState {

public:
    SendPayMenuState()
        : MenuState({
        "1. �������� �� ���������",
        "2. ³�������� �� ���������",
        "3. ����������� �����" })
    { }

    MenuState* handleInput(char input) override;

};
