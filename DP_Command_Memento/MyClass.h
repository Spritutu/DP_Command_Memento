#pragma once

class Memento
{
	friend class Player;
public:
	Memento(const int& hp, const int& exp);
private:
	int hp;
	int exp;
};

class Caretaker
{
public:
	Caretaker();
	~Caretaker();
	Memento* GetMemento();
	void SetMemento(Memento* pMemento);
private:
	Memento* pMementoPlayer;
};

class Player
{
public:
	Player();
	void Battle();
	void ReverseBattle();
	int GetHP();
	int GetEXP();
	Memento* SaveToMemento();
	void LoadFromMemento(Memento* pMemento);
private:
	int hp;
	int exp;
};

class Command
{
public:
	virtual void execute() = 0;
};

class BattleCommand : public Command
{
public:
	BattleCommand(Player* pPlayer);
	virtual void execute();
private:
	Player* pPlayer;
};

class SaveCommand : public Command
{
public:
	SaveCommand(Player* pPlayer, Caretaker* pCaretaker);
	virtual void execute();
private:
	Player* pPlayer;
	Caretaker* pCaretaker;
};

class LoadCommand : public Command
{
public:
	LoadCommand(Player* pPlayer, Caretaker* pCaretaker);
	virtual void execute();
private:
	Player* pPlayer;
	Caretaker* pCaretaker;
};

class UndoCommand : public Command
{
public:
	UndoCommand(Player* pPlayer);
	virtual void execute();
private:
	Player* pPlayer;
};
