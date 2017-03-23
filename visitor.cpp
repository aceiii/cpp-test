#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BaseVisitor;

class BaseNode;
class LeafNode;
class UnaryNode;
class BinaryNode;
class TernaryNode;

class BaseNode {
public:
    BaseNode(const std::string &name):_name{name}
    {
    }

    const std::string& getName() const {
        return _name;
    }

    virtual void accept(BaseVisitor* visitor) = 0;

private:
    std::string _name;
};

class BaseVisitor {
public:
    virtual void visit(BaseNode *node) = 0;
    virtual void visit(LeafNode *node) = 0;
    virtual void visit(UnaryNode *node) = 0;
    virtual void visit(BinaryNode *node) = 0;
    virtual void visit(TernaryNode *node) = 0;
};

class UnaryNode : public BaseNode {
public:
    explicit UnaryNode(const std::string &name)
        :BaseNode{name}
    {
    }

    explicit UnaryNode(const std::string &name, std::shared_ptr<BaseNode> node)
        :BaseNode{name}, _node{node}
    {
    }

    virtual void accept(BaseVisitor* visitor)
    {
        visitor->visit(this);
    }

    BaseNode* getNode() const {
        return _node.get();
    }

protected:
    std::shared_ptr<BaseNode> _node;
};

class BinaryNode : public BaseNode {
public:
    BinaryNode(const std::string &name):BaseNode{name}
    {
    }

    BinaryNode(const std::string &name, std::shared_ptr<BaseNode> left, std::shared_ptr<BaseNode> right):BaseNode{name}, _left{left}, _right{right}
    {
    }

    virtual void accept(BaseVisitor* visitor)
    {
        visitor->visit(this);
    }

    BaseNode* getLeft() const {
        return _left.get();
    }

    BaseNode* getRight() const {
        return _right.get();
    }

protected:
    std::shared_ptr<BaseNode> _left;
    std::shared_ptr<BaseNode> _right;
};

class TernaryNode : public BaseNode {
public:
    TernaryNode(const std::string &name):BaseNode{name}
    {
    }

    TernaryNode(const std::string &name, std::shared_ptr<BaseNode> left, std::shared_ptr<BaseNode> middle, std::shared_ptr<BaseNode> right):BaseNode{name},_left{left},_middle{middle},_right{right}
    {
    }

    virtual void accept(BaseVisitor* visitor)
    {
        visitor->visit(this);
    }

    BaseNode* getLeft() const {
        return _left.get();
    }

    BaseNode* getMiddle() const {
        return _middle.get();
    }

    BaseNode* getRight() const {
        return _right.get();
    }

protected:
    std::shared_ptr<BaseNode> _left;
    std::shared_ptr<BaseNode> _middle;
    std::shared_ptr<BaseNode> _right;
};

class LeafNode : public BaseNode {
public:
    LeafNode(const std::string& name):BaseNode{name}
    {
    }

    virtual void accept(BaseVisitor* visitor)
    {
        visitor->visit(this);
    }

    BaseNode* getNode() const {
        return _node.get();
    }

protected:
    std::shared_ptr<BaseNode> _node;
};

class MainVisitor : public BaseVisitor {
public:
    MainVisitor() {
    }

    virtual void visit(BaseNode *node) override {
        std::cout << "Visiting Node: " << node->getName() << std::endl;
    }

    virtual void visit(LeafNode *node) override {
        std::cout << "Visting LeafNode: " << node->getName() << std::endl;
    }

    virtual void visit(UnaryNode *node) override {
        std::cout << "Visiting UnaryNode: " << node->getName() << std::endl;

        if (node->getNode()) {
            node->getNode()->accept(this);
        }
    }

    virtual void visit(BinaryNode *node) override {
        std::cout << "Visiting UnaryNode: " << node->getName() << std::endl;

        if (node->getLeft()) {
            std::cout << "Going left:" << std::endl;
            node->getLeft()->accept(this);
        }

        if (node->getRight()) {
            std::cout << "Going right:" << std::endl;
            node->getRight()->accept(this);
        }
    }

    virtual void visit(TernaryNode *node) override {
        std::cout << "Visiting UnaryNode: " << node->getName() << std::endl;

        if (node->getLeft()) {
            std::cout << "Going left:" << std::endl;
            node->getLeft()->accept(this);
        }

        if (node->getRight()) {
            std::cout << "Going right:" << std::endl;
            node->getRight()->accept(this);
        }
    }

};

auto main() -> int {

    auto a = std::make_shared<LeafNode>("A");
    auto b = std::make_shared<LeafNode>("B");
    auto c = std::make_shared<LeafNode>("C");

    auto d = std::make_shared<BinaryNode>("D");

    auto f = std::make_shared<TernaryNode>("F", a, b, c);

    auto g = std::make_shared<UnaryNode>("G", d);
    auto h = std::make_shared<UnaryNode>("H", d);

    auto e = std::make_shared<BinaryNode>("E", g, f);

    auto head = std::make_shared<UnaryNode>("HEAD", e);

    auto visitor = std::make_shared<MainVisitor>();

    head->accept(visitor.get());

    return 0;
}

