#pragma once
/**
  * ��������� ��������� ������� ����� ��� ��������� �������.
  */
class Command {
public:
	virtual ~Command() {
	}
	virtual void Execute() const = 0;
};

/**
 * ������� ������ ���������
 */
class PrintOrdersCommand : public Command {
public:
	explicit PrintOrdersCommand();
	void Execute() const override;

};

/**
 * ��� ���������� "������� ����������� �1"
 */
class OrderBreakfast1Command : public Command {
public:
	explicit OrderBreakfast1Command();
	void Execute() const override;

};


/**
 * ��� ���������� "������� ����������� �2"
 */
class OrderBreakfast2Command : public Command {
public:
	explicit OrderBreakfast2Command();
	void Execute() const override;


};




