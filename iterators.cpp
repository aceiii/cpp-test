#include <iostream>
#include <vector>

auto main() -> int {

    int a[] = {1,2,3,5};

    auto ait = std::begin(a);

    while (ait != std::end(a)) {
        std::cout << *ait << std::endl;
        ait++;
    }

    std::cout << "typeof ait: " << typeid(ait).name() << std::endl;

    std::vector<int> v = { 1,2,3,7};

    auto vit = std::begin(v);
    while (vit != std::end(v)) {
        std::cout << *vit << std::endl;
        vit++;
    }

    std::cout << "typeof vit: " << typeid(vit).name() << std::endl;

    std::cout << "typeof a: " << typeid(a).name() << std::endl;
    std::cout << "typeof &a[0]: " << typeid(&a[0]).name() << std::endl;

    return 0;
}

