#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	protected:
		//Base* root;
	public:
		OpCommand(int val): Command()  {
			root = new Op((double)val);
		};
		
	//OpCommand Code Here
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(Command* left, int val): Command() {
			root = new Add(left->get_root(), new Op(val));
		};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
		SubCommand(Command* left, int val): Command() {
			root = new Sub(left->get_root(), new Op(val));
		};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
		MultCommand(Command* left, int val): Command() {
			root = new Mult(left->get_root(), new Op(val));
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
		SqrCommand(Command* left): Command() {
			root = new Sqr(left->get_root());
		};
};

#endif //__COMMAND_CLASS__
