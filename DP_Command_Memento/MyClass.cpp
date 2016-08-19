#include "stdafx.h"
#include "MyClass.h"


Player::Player() :
	hp(9999),
	exp(0)
{

}

void Player::Battle()
{
	this->hp -= 5;
	this->exp += 10;
}

void Player::ReverseBattle()
{
	this->hp += 5;
	this->exp -= 10;
}

int Player::GetHP()
{
	return hp;
}

int Player::GetEXP()
{
	return exp;
}

Memento* Player::SaveToMemento()
{
	return new Memento(this->hp, this->exp);
}

void Player::LoadFromMemento(Memento* pMemento)
{
	this->hp = pMemento->hp;
	this->exp = pMemento->exp;
}




BattleCommand::BattleCommand(Player* pPlayer) :
	pPlayer(pPlayer)
{

}

void BattleCommand::execute()
{
	this->pPlayer->Battle();
}

SaveCommand::SaveCommand(Player* pPlayer, Caretaker* pCaretaker) :
	pPlayer(pPlayer),
	pCaretaker(pCaretaker)
{

}

void SaveCommand::execute()
{
	this->pCaretaker->SetMemento(this->pPlayer->SaveToMemento());
}

LoadCommand::LoadCommand(Player* pPlayer, Caretaker* pCaretaker) :
	pPlayer(pPlayer),
	pCaretaker(pCaretaker)
{

}

void LoadCommand::execute()
{
	this->pPlayer->LoadFromMemento(pCaretaker->GetMemento());
}

UndoCommand::UndoCommand(Player* pPlayer) :
	pPlayer(pPlayer)
{

}

void UndoCommand::execute()
{
	pPlayer->ReverseBattle();
}

Memento::Memento(const int& hp, const int& exp) :
	hp(hp),
	exp(exp)
{

}

Caretaker::Caretaker() :
	pMementoPlayer(NULL)
{

}

Caretaker::~Caretaker()
{
	if (this->pMementoPlayer)
		delete this->pMementoPlayer;
}

void Caretaker::SetMemento(Memento* pMemento)
{
	if (this->pMementoPlayer)
		delete this->pMementoPlayer;

	this->pMementoPlayer = pMemento;
}

Memento* Caretaker::GetMemento()
{
	return this->pMementoPlayer;
}
