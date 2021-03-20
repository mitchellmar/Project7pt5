#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F
    std::transform(cars.cbegin(), cars.cend(), std::back_inserter(taggedCars), [](const Car& car) {
        return car.price() < 10000;
        });

    std::transform(cars.cbegin(), cars.cend(), std::back_inserter(taggedCars), [](const Car& car) {
       return car.vin().front() > 'f';
        });
    

    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened

    auto it = std::partition(cars.begin(), cars.end(), [](Tag<Car> car) {
        return car.isTagged() == true;
        });


    std::cout << "Tagged Cars: " << taggedCars << "\n";
}