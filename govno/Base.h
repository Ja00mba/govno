#ifndef __BASE__H
#define __BASE__H

#include <string>
#include <vector>

class Base;

typedef void (Base::* TYPE_SIGNAL) (std::string&);
typedef void (Base::* TYPE_HANDLER) (std::string);

#define SIGNAL_D( f ) ( TYPE_SIGNAL ) ( & f )
#define HANDLER_D( f ) ( TYPE_HANDLER ) ( & f )

struct Connection {
	TYPE_SIGNAL signal;
	Base* obj;
	TYPE_HANDLER handler;
};

class Base {
private:

	Base* parent;
	std::string name;
	bool state;
	std::vector<Connection*> connections;

	void printTreeInternal(bool, unsigned int);
	void remove_child(Base*);
	Base* findInternal(std::string, unsigned int&);

public:

	std::vector<Base*> children;
	Base(Base* p = nullptr, std::string n = "");
	~Base();

	bool setName(std::string);
	std::string getName();
	Base* getParent();
	void printTree(bool show_state = false);
	
	Base * getChildByName(std::string);
	bool getState();
	void setState(bool state);
	Base* getChildByNameOnTree(std::string);
	Base* getChildByNameOnBranch(std::string);
	
	bool move(Base*);
	void delete_child(std::string);
	Base* coord(std::string str);
	std::string getABSPath();
	bool subordinate(Base*);
	
	void emit(TYPE_SIGNAL, std::string&);
	void connect(TYPE_SIGNAL, Base*, TYPE_HANDLER);
	void disconnect(TYPE_SIGNAL, Base*, TYPE_HANDLER);
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif