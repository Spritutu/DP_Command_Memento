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

void Player::RegisterObserver(Observer* pObserver)
{
	if (pObserver)
		this->listObservers.AddTail(pObserver);
}

void Player::RemoveObserver(Observer* pObserver)
{
	if (pObserver != NULL)
	{
		POSITION pos = this->listObservers.Find(pObserver);
		if(pos)
		{
			this->listObservers.RemoveAt(pos);
		}
	}
}

void Player::NotifyObservers(UINT uMsg, LPVOID pParam)
{
	POSITION pos = this->listObservers.GetHeadPosition();
	Observer* pObserver = NULL;
	while(pos)
	{
		pObserver = this->listObservers.GetNext(pos);
		pObserver->Update(uMsg, pParam);
	}
}

void Player::Rest()
{
	this->hp += 10;
}

void Player::ReverseRest()
{
	this->hp -= 10;
}




BattleCommand::BattleCommand(Player* pPlayer) :
	pPlayer(pPlayer)
{

}

void BattleCommand::execute()
{
	this->pPlayer->Battle();
	this->pPlayer->NotifyObservers(INNER_MSG_BATTLE);
}

void BattleCommand::unexecute()
{
	this->pPlayer->ReverseBattle();
	this->pPlayer->NotifyObservers(INNER_MSG_UNDO);
}

SaveCommand::SaveCommand(Player* pPlayer, Caretaker* pCaretaker) :
	pPlayer(pPlayer),
	pCaretaker(pCaretaker)
{

}

void SaveCommand::execute()
{
	this->pCaretaker->SetMemento(this->pPlayer->SaveToMemento());
	this->pPlayer->NotifyObservers(INNER_MSG_SAVE);
}

void SaveCommand::unexecute()
{
	//do nothing
}

LoadCommand::LoadCommand(Player* pPlayer, Caretaker* pCaretaker) :
	pPlayer(pPlayer),
	pCaretaker(pCaretaker)
{

}

void LoadCommand::execute()
{
	this->pPlayer->LoadFromMemento(pCaretaker->GetMemento());
	this->pPlayer->NotifyObservers(INNER_MSG_LOAD);
}

void LoadCommand::unexecute()
{
	//do nothing
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

RestCommand::RestCommand(Player* pPlayer) :
	pPlayer(pPlayer)
{

}

void RestCommand::execute()
{
	this->pPlayer->Rest();
	this->pPlayer->NotifyObservers(INNER_MSG_REST);
}

void RestCommand::unexecute()
{
	this->pPlayer->ReverseRest();
	this->pPlayer->NotifyObservers(INNER_MSG_UNDO);
}
