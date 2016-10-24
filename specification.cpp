#include <iostream>
#include <vector>
#include <string>

enum class Color { Red, Blue, Green };
enum class Size { Small, Medium, Large };

struct Product
{
    std::string name;
    Color color;
    Size size;

    Product(const std::string& name, Color col, Size s):
        name(name), color(col), size(s)
    {
    }
};

template <typename T>
struct ISpecification
{
    virtual bool is_satisfied(const T& t) const = 0;
};

template <typename T>
struct IFilter
{
    virtual std::vector<T*> filter(const std::vector<T*>& v, ISpecification<T>& spec) = 0;
};

struct BetterFilter: IFilter<Product>

{
    typedef std::vector<Product*> Items;

    virtual std::vector<Product*> filter(const std::vector<Product*>& v, ISpecification<Product>& spec) override
    {
        Items result;
        for (auto& p: v) {
            if (spec.is_satisfied(*p)) {
                result.push_back(p);
            }
        }
        return result;
    }
};

struct ColorSpecification: ISpecification<Product>
{
    Color color;

    ColorSpecification(Color color):color{color}
    {
    }

    virtual bool is_satisfied(const Product& product) const override
    {
        return product.color == color;
    }
};

struct SizeSpecification: ISpecification<Product>
{
    Size size;

    SizeSpecification(Size size):size{size}
    {
    }

    virtual bool is_satisfied(const Product& product) const override
    {
        return product.size == size;
    }
};

template <typename T>
struct AndSpecification: ISpecification<T>
{
    ISpecification<T>& spec1;
    ISpecification<T>& spec2;

    AndSpecification(ISpecification<T>& s1, ISpecification<T>& s2):
        spec1{s1}, spec2{s2}
    {
    }

    virtual bool is_satisfied(const T& t) const override
    {
        return spec1.is_satisfied(t) && spec2.is_satisfied(t);
    }
};

auto main() -> int {

    Product apple { "name", Color::Green, Size::Small };
    Product tree { "tree", Color::Green, Size::Large };
    Product house { "house", Color::Blue, Size::Large };

    std::vector<Product*> all { &apple, &tree, &house };

    BetterFilter bf;
    ColorSpecification green(Color::Green);

    auto green_things = bf.filter(all, green);
    for (auto& x: green_things) {
        std::cout << x->name << " is green" << std::endl;
    }

    SizeSpecification big(Size::Large);
    AndSpecification<Product> green_and_big { big, green };

    auto green_and_big_things = bf.filter(all, green_and_big);
    for (auto& x: green_and_big_things) {
        std::cout << x->name << " is green and big" << std::endl;
    }

    return 0;
}


