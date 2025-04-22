#include <iostream>
#include <stdexcept>
#include <vector>

class AP {
public:
    AP(double first, double diff, const std::vector<double> values) //инициализируем члены класса
        : firstElement(first), difference(diff), array(values) {//присваиваем значения
        if (array.empty()) {//проверяем на пустой вектор
            throw std::invalid_argument("Переданный массив пустой.");
        }
        if (!isValidProgression()) {
            throw std::invalid_argument("Переданный массив не является арифметической прогрессией.");
        }
    }

    void printProgression() const {//выволим сам вектор
        for (const auto value : array) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    double firstElement;
    double difference;
    std::vector<double> array;

    bool isValidProgression() const {//функция для проверки на прогрессию
        for (size_t i = 1; i < array.size(); ++i) {
            if (array[i] - array[i - 1] != difference) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    try {

        std::vector<double> validArray = { 1, 3, 5, 8, 9 };
        AP ap(validArray[0], 2, validArray);
        ap.printProgression();


        std::vector<double> empjty={};
        AP varempty(0,2,empjty);

        //std::vector<double> invalidArray = { 1, 3, 5, 7, 10 };
        //AP apInvalid(invalidArray[0], 2, invalidArray);

    } catch (const std::invalid_argument ot) {
        std::cout<<"Будет ошибка."<<ot.what()<<std::endl;
    }

    return 0;
}
