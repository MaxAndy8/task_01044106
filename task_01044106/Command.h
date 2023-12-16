#pragma once
/**
  * Командний інтерфейс оголошує метод для виконання команди.
  */
class Command {
public:
	virtual ~Command() {
	}
	virtual void Execute() const = 0;
};

/**
 * Вивести список замовлень
 */
class PrintOrdersCommand : public Command {
public:
	explicit PrintOrdersCommand();
	void Execute() const override;

};

/**
 * Для замовлення "Сніданок комплексний №1"
 */
class OrderBreakfast1Command : public Command {
public:
	explicit OrderBreakfast1Command();
	void Execute() const override;

};


/**
 * Для замовлення "Сніданок комплексний №2"
 */
class OrderBreakfast2Command : public Command {
public:
	explicit OrderBreakfast2Command();
	void Execute() const override;


};




