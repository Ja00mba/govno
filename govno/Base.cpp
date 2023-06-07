#include "Base.h"
#include <string>
#include <vector>
#include <iostream>
Base::Base(Base* p, std::string n) : parent(p), name(n) {
	if (p != nullptr) {
		p->children.push_back(this);
	};
}
bool Base::setName(std::string name) {
	if (!parent) {
		this->name = name;
		return true;
	}
	for (auto child : parent->children) {
		if (child != this && child->getName() == name) {
			return false;
		}
	}
	this->name = name;
	return true;
}
std::string Base::getName() { return name; };
Base* Base::getParent() { return parent; };
void Base::printTree(bool showState) {
	printTreeInternal(showState, 0);
}
void Base::printTreeInternal(bool showState, unsigned int indent) {
	std::string spaces = "";
	if (indent) {
		spaces.append(4 * indent, ' ');
	}
	std::cout << spaces << getName();
	if (showState) std::cout << " " << (getState() ? "is" : "is not") <<
		"ready";
	for (auto c : children) {
		std::cout << '\n';
		c->printTreeInternal(showState, indent + 1);
	}
}
Base* Base::getChildByName(std::string childName) {
	for (auto child : children) {
		if (child->getName() == childName) {
			return child;
			
		};
	};
	return nullptr;
};
bool Base::getState() { return state; }
void Base::setState(bool state) {
	if (getParent() && !getParent()->getState()) {
		this->state = false;
	}
	else {
		this->state = state;
	}
	if (!state) {
		for (auto c : children) {
			c->setState(state);
		}
	}
}
Base* Base::getChildByNameOnTree(std::string name) {
	unsigned int count = 0;
	auto found = findInternal(name, count);
	if (count > 1) return nullptr;
	return found;
}
Base* Base::findInternal(std::string name, unsigned int& count) {
	Base* found = nullptr;
	if (name == getName()) {
		count++;
		found = this;
	}
	for (auto c : children) {
		auto obj = c->findInternal(name, count);
		if (obj) found = obj;
	}
	return found;
}
Base* Base::getChildByNameOnBranch(std::string name) {
	auto p = this;
	while (p->getParent()) {
		p = p->getParent();
	};
	return p->getChildByNameOnTree(name);
}
bool Base::subordinate(Base* obj) {
	for (auto child : children) {
		if (child == obj) return true;
		if (child->subordinate(obj)) return true;
	}
	
		return false;
}
void Base::remove_child(Base* child) {
	for (auto it = children.begin();
		it != children.end();
		++it) {
		if (*it == child) {
			children.erase(it);
			break;
		}
	}
}
bool Base::move(Base* newParent) {
	if (!getParent() || !newParent
		|| newParent->getChildByName(getName())
		|| subordinate(newParent)) return false;
	getParent()->remove_child(this);
	newParent->children.push_back(this);
	parent = newParent;
	return true;
}
void Base::delete_child(std::string child_name) {
	for (auto it = children.begin();
		it != children.end();
		++it) {
		if ((*it)->getName() == child_name) {
			delete* it;
			children.erase(it);
			break;
		}
	}
}
Base* Base::coord(std::string path) {
	if (path.substr(0, 2) == "//") {
		return getChildByNameOnBranch(path.substr(2));
	}
	else if (path == ".") {
		return this;
	}
	else if (path[0] == '.') {
		return getChildByNameOnTree(path.substr(1));
	}
	else if (path[0] == '/') {
		auto new_path = path.substr(1);
		auto cur = this;
		while (cur->getParent()) {
			cur = cur->getParent();
		}
		if (path == "/") return cur;
		return cur->coord(new_path);
	}
	auto pos = path.find('/');
	
		auto child = getChildByName(path.substr(0, pos));
	if (!child || pos == std::string::npos) return child;
	return child->coord(path.substr(pos + 1));
}
Base::~Base() {
	for (auto c : children) {
		delete c;
	}
}
std::string Base::getABSPath() {
	if (!getParent()) return "/";
	auto path = getParent()->getABSPath() + '/' + getName();
	if (path.substr(0, 2) == "//") return path.substr(1);
	return path;
}
void Base::emit(TYPE_SIGNAL signal, std::string& cmd) {
	if (!getState()) return;
	(this->*signal) (cmd);
	for (auto c : connections) {
		if (c->signal == signal
			&& c->obj->getState()) {
			((c->obj)->*c->handler) (cmd);
		}
	}
}
void Base::connect(TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler) {
	for (auto c : connections) {
		if (
			c->signal == signal &&
			c->obj == obj &&
			c->handler == handler
			) return;
	}
	auto con = new Connection{ signal, obj, handler };
	connections.push_back(con);
}
void Base::disconnect(TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler) {
	for (auto it = connections.begin(); it != connections.end(); it++) {
		if (
			(*it)->signal == signal &&
			(*it)->obj == obj &&
			(*it)->handler == handler
			) {
			connections.erase(it);
			break;
		}
	}
}
void Base::signal_f(std::string& cmd) {
	std::cout << "\nSignal from " << this->getABSPath();
	
}
void Base::handler_f(std::string cmd) {
	std::cout
		<< "\nSignal to " << this->getABSPath()
		<< " Text: " << cmd;
}